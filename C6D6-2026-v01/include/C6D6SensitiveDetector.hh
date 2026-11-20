#ifndef C6D6SensitiveDetector_h
#define C6D6SensitiveDetector_h

#include "C6D6Hit.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4Step.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "G4VProcess.hh"
#include "G4VSensitiveDetector.hh"

// Define to debug hits
// #define DEBUG_C6D6_SD_HH

class C6D6SensitiveDetector : public G4VSensitiveDetector {
 public:
  C6D6SensitiveDetector(G4String SDname);
  virtual ~C6D6SensitiveDetector();

 public:
  virtual G4bool ProcessHits(G4Step *step, G4TouchableHistory *ROhist);
  virtual void Initialize(G4HCofThisEvent *HCE);
  virtual void EndOfEvent(G4HCofThisEvent *HCE);

 private:
  C6D6HitCollection *hitsCollection;
  G4int collectionID;
};

#endif
