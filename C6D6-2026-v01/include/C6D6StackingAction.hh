#ifndef C6D6StackingAction_h
#define C6D6StackingAction_h 1

#include "G4UserStackingAction.hh"
#include "globals.hh"
#include "C6D6InputManager.hh"

class G4Track;

class C6D6StackingAction : public G4UserStackingAction
{
  public:
    C6D6StackingAction();
    virtual ~C6D6StackingAction();

    // Este es el método virtual que Geant4 llama para cada nueva partícula
    virtual G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track* aTrack) override;


 private:
  C6D6InputManager *theInputManager=0;
  G4LogicalVolume *logic_target=0;
  G4int CaptureOpt=0; //0: do nothing, 1: kill nCapture secondaries in the logic_target
};

#endif
