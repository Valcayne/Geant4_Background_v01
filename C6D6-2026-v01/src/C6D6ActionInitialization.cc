
#include "C6D6ActionInitialization.hh"

C6D6ActionInitialization::C6D6ActionInitialization()
    : G4VUserActionInitialization() {
  theInputManager=C6D6InputManager::getInstance();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

C6D6ActionInitialization::~C6D6ActionInitialization() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6ActionInitialization::BuildForMaster() const {
  C6D6PrimaryGeneratorAction *myPrimaryGenerator =
      new C6D6PrimaryGeneratorAction();

  C6D6RunAction *myRunAction =
      new C6D6RunAction(myPrimaryGenerator);
  SetUserAction(myRunAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6ActionInitialization::Build() const {
  C6D6PrimaryGeneratorAction *myPrimaryGenerator =
      new C6D6PrimaryGeneratorAction();
  SetUserAction(myPrimaryGenerator);

  C6D6RunAction *myRunAction =
      new C6D6RunAction(myPrimaryGenerator);
  SetUserAction(myRunAction);

  C6D6EventAction *myEventAction =
      new C6D6EventAction(myPrimaryGenerator);
  SetUserAction(myEventAction);

  if(theInputManager->GetTrackNeutronHistory()==1){
    C6D6TrackingAction *myTrackingAction=new C6D6TrackingAction(myEventAction);
    SetUserAction(myTrackingAction);
  }

  
  C6D6StackingAction* myStackingAction=new C6D6StackingAction();
  SetUserAction(myStackingAction);
}
