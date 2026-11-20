#include "C6D6SensitiveDetector.hh"

C6D6SensitiveDetector::C6D6SensitiveDetector(G4String SDname)
    : G4VSensitiveDetector(SDname), hitsCollection(NULL), collectionID(-1) {
  G4cout << "Creating SD with name: " << SDname << G4endl;
  collectionName.insert(SDname);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

C6D6SensitiveDetector::~C6D6SensitiveDetector() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6SensitiveDetector::Initialize(G4HCofThisEvent *HCE) {
  hitsCollection =
      new C6D6HitCollection(SensitiveDetectorName, collectionName[0]);
  if (collectionID < 0) {
    collectionID =
        G4SDManager::GetSDMpointer()->GetCollectionID(hitsCollection);
  }
  HCE->AddHitsCollection(collectionID, hitsCollection);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6SensitiveDetector::EndOfEvent(G4HCofThisEvent *HCE) {
#ifdef DEBUG_C6D6_SD_HH
  G4int nofHits = hitsCollection->entries();
  G4cout << G4endl << "-------->SSDHits Collection: in this event they are "
         << nofHits << " hits: " << G4endl;
  for (G4int i = 0; i < nofHits; i++) {
    (*hitsCollection)[i]->Print();
  }
#endif
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool C6D6SensitiveDetector::ProcessHits(G4Step *step,
                                          G4TouchableHistory *ROhist) {
  // Not energy deposited
  if (step->GetTotalEnergyDeposit() == 0.) return false;

  // Some energy deposited
  C6D6Hit *hit = new C6D6Hit();
  hit->SetDepositedEnergy(step->GetTotalEnergyDeposit() / MeV);
  hit->SetTimeInteraction(step->GetTrack()->GetGlobalTime() / ns);
  hit->SetPositionInteracion(step->GetTrack()->GetPosition() / cm);
  hit->SetCopyNumber(
      step->GetTrack()->GetTouchable()->GetVolume(1)->GetCopyNo());
  hit->SetParticleName(step->GetTrack()
                           ->GetDynamicParticle()
                           ->GetDefinition()
                           ->GetParticleName());

  // G4cout << " particle "
  //        << step->GetTrack()
  //               ->GetDynamicParticle()
  //               ->GetDefinition()
  //               ->GetParticleName()
  //        << G4endl;
  // G4cout << " Edep " << step->GetTotalEnergyDeposit() / MeV << G4endl;
  //G4cout<<step->GetTrack()->GetTouchable()->GetVolume(1)->GetCopyNo()<<"  "<<step->GetTotalEnergyDeposit()/MeV<<G4endl; getchar();

  hitsCollection->insert(hit);
  return true;
}
