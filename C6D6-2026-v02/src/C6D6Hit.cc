#include "C6D6Hit.hh"

G4ThreadLocal G4Allocator<C6D6Hit>* C6D6HitAllocator = 0;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

C6D6Hit::C6D6Hit()
    : eDep(0),
      time(0),
      //                   fPos(0),
      copy_number(-1) {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

C6D6Hit::~C6D6Hit() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6Hit::Draw() {
  G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
  if (pVVisManager) {
    G4Circle circle(fPos);
    circle.SetScreenSize(4.);
    circle.SetFillStyle(G4Circle::filled);
    G4Colour colour(1., 0., 0.);
    G4VisAttributes attribs(colour);
    circle.SetVisAttributes(attribs);
    pVVisManager->Draw(circle);
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6Hit::Print() {
  G4cout << "Edep: " << G4BestUnit(eDep, "Energy")
         << " time: " << G4BestUnit(time, "Time")
         << " Position: " << G4BestUnit(fPos, "Length") << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
