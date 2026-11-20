
#include "C6D6StackingAction.hh"
#include "G4Track.hh"
#include "G4VProcess.hh"
#include "G4HadronicProcessType.hh"

C6D6StackingAction::C6D6StackingAction()
  : G4UserStackingAction()
{
  theInputManager=C6D6InputManager::getInstance();
  CaptureOpt=theInputManager->GetPhysicsListOpt3();
}

C6D6StackingAction::~C6D6StackingAction()
{
}

G4ClassificationOfNewTrack C6D6StackingAction::ClassifyNewTrack(const G4Track* aTrack)
{

  if(CaptureOpt==0){
    return fUrgent;
  }
  if(logic_target==0){
    logic_target=theInputManager->Getlogic_target();
  }
  // 1. Si es una partícula primaria, se trackea normalmente
  if (aTrack->GetParentID() == 0) {
    return fUrgent;
  }

  // 2. Obtener el volumen lógico donde NACIÓ la partícula secundaria
  G4LogicalVolume* currentLogVolume = nullptr;
  if (aTrack->GetVolume() != nullptr) {
    currentLogVolume = aTrack->GetVolume()->GetLogicalVolume();
  }

  // 3. Comprobar si el volumen coincide con tu "logic_target"
  // NOTA: Asegúrate de que 'fLogicTarget' sea un puntero guardado/pasado a tu StackingAction
  if (currentLogVolume == logic_target) {
        
    // 4. Obtener el proceso que creó esta partícula secundaria
    const G4VProcess* creatorProcess = aTrack->GetCreatorProcess();
        
    if (creatorProcess != nullptr) {
      G4String processName = creatorProcess->GetProcessName();
      G4int subType = creatorProcess->GetProcessSubType();
            
      // 5. Si fue generada por captura neutrónica DENTRO del blanco, la eliminamos
      if (processName == "nCapture" || 
	  processName == "neutronCapture" || 
	  subType == fCapture) {
	return fKill; 
      }
    }
  }

  // 6. Cualquier otra secundaria de otros procesos o de otros volúmenes sigue su curso
  return fUrgent;
  
}
