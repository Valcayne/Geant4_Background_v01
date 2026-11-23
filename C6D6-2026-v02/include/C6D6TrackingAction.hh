#ifndef C6D6TrackingAction_h
#define C6D6TrackingAction_h

#include "G4UserTrackingAction.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"
//#include <map>

struct NeutronHistory {
    G4int trackID;
    G4ThreeVector vertexPosition; // Dónde se generó
    G4ThreeVector endPosition;    // Dónde acabó su track
    G4double Eini,Efin;
    G4String creatorProcess;      // Proceso de creación
    G4String endProcess;          // Proceso de finalización
    G4String volumeCreated;   // <--- NUEVO: Volumen de creación
    G4String volumeDied;      // <--- NUEVO: Volumen de muerte
    G4String targetIsotope;
};

class C6D6EventAction; // Forward declaration

class C6D6TrackingAction : public G4UserTrackingAction {
public:
    C6D6TrackingAction(C6D6EventAction* eventAction);
    virtual ~C6D6TrackingAction() = default;

    virtual void PreUserTrackingAction(const G4Track*) override;
    virtual void PostUserTrackingAction(const G4Track*) override;

private:
    C6D6EventAction* fEventAction;
  //std::map<G4int, G4String> fCaptureNuclei; // Mapea ParentID -> Nombre del núcleo
};


#endif
