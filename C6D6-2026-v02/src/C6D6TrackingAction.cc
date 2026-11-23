

#include "C6D6TrackingAction.hh"
#include "C6D6EventAction.hh"
#include "G4Track.hh"
#include "G4Neutron.hh"
#include "G4VProcess.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh" // Importante para manejar los volúmenes
#include "G4HadronicProcess.hh"
#include "G4Nucleus.hh"

C6D6TrackingAction::C6D6TrackingAction(C6D6EventAction* eventAction)
: G4UserTrackingAction(), fEventAction(eventAction) {}

void C6D6TrackingAction::PreUserTrackingAction(const G4Track*) {

}

void C6D6TrackingAction::PostUserTrackingAction(const G4Track* track) {
    // Filtro eficiente de neutrones
    if (track->GetDefinition() == G4Neutron::NeutronDefinition()) {
        
        NeutronHistory history;
        history.trackID = track->GetTrackID();
        history.vertexPosition = track->GetVertexPosition();
        history.endPosition = track->GetPosition();
	history.Eini=track->GetVertexKineticEnergy();
	history.Efin=track->GetKineticEnergy();

        // 1. Proceso creador
        if (track->GetCreatorProcess()) {
            history.creatorProcess = track->GetCreatorProcess()->GetProcessName();
        } else {
            history.creatorProcess = "Primary Particle";
        }

        // 2. NUEVO: Volumen donde se creó el neutrón
        if (track->GetLogicalVolumeAtVertex()) {
            history.volumeCreated = track->GetLogicalVolumeAtVertex()->GetName();
        } else {
            history.volumeCreated = "Unknown Volume";
        }

        // 3. Proceso de finalización y NUEVO: Volumen donde murió
        const G4Step* lastStep = track->GetStep();
        if (lastStep) {
	  auto postStepPoint = lastStep->GetPostStepPoint();
	  history.Efin = lastStep->GetPreStepPoint()->GetKineticEnergy();
	  
	  // Proceso del fin del track
	  const G4VProcess* endProc = postStepPoint->GetProcessDefinedStep();
	  if (endProc) {
	    history.endProcess = endProc->GetProcessName();

	    // <--- NUEVO: Extraer el Isótopo Diana --->
	    // Intentamos castear el proceso a un proceso hadrónico genérico
	    auto hadProcess = const_cast<G4HadronicProcess*>(dynamic_cast<const G4HadronicProcess*>(endProc));
	    if (hadProcess) {
	      // Obtenemos el núcleo diana guardado en la última interacción de este proceso
	      const G4Nucleus* targetNucleus = hadProcess->GetTargetNucleus();
	      if (targetNucleus) {
                G4int Z = targetNucleus->GetZ_asInt();
                G4int A = targetNucleus->GetA_asInt();
                // Alternativa 1: Guardar formato texto (Ej: "Isotope: Z=6, A=12")
                //history.targetIsotope = "Z=" + std::to_string(Z) + " A=" + std::to_string(A);
		history.targetIsotope = std::to_string(1000*Z+A);

                // Alternativa 2: Si prefieres el nombre del elemento químico (Ej: "C12")
		//G4String elName = targetNucleus->GetIsotope() ? targetNucleus->GetIsotope()->GetName() : "";
	      } else {
                history.targetIsotope = "No Hadronic Target";
	      }
	    } else {
	      history.targetIsotope = "Not a Hadronic Process"; // Ej: Decaimiento, transporte, etc.
	    }
	  } else {
	    history.endProcess = "Out of World / Limit";
	    history.targetIsotope = "None";
	  }

            // Volumen físico del fin del track
            G4VPhysicalVolume* endVolume = postStepPoint->GetPhysicalVolume();
            if (endVolume) {
                history.volumeDied = endVolume->GetName();
            } else {
                // Si sale del "World", el volumen físico es nulo (nullptr)
                history.volumeDied = "OutOfWorld"; 
            }
        } else {
            history.endProcess = "No steps recorded";
            history.volumeDied = "Unknown";
	    history.targetIsotope = "Unknown";
        }

        // Enviar historial al EventAction
        fEventAction->AddNeutronHistory(history);
    }

}
