#ifndef C6D6EventAction_h
#define C6D6EventAction_h

#include <fstream>
#include <iostream>
#include <ctime>

#include "C6D6Hit.hh"
#include "C6D6PrimaryGeneratorAction.hh"
#include "C6D6SensitiveDetector.hh"
#include "C6D6SensitiveTarget.hh"
#include "C6D6InputManager.hh"
#include "C6D6TrackingAction.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4Trajectory.hh"
#include "G4TrajectoryContainer.hh"
#include "G4UImanager.hh"
#include "G4UnitsTable.hh"
#include "G4UserEventAction.hh"
#include "G4VVisManager.hh"
#include "G4ios.hh"
#include "globals.hh"

#define MAXNSIG 10000

class C6D6EventAction : public G4UserEventAction {
 public:
  C6D6EventAction(C6D6PrimaryGeneratorAction *primaryGenerator);
  ~C6D6EventAction();

 public:
  void BeginOfEventAction(const G4Event *anEvent);
  void EndOfEventAction(const G4Event *evt);
  G4int GetNEvents(){return NEvents;}

  void AddNeutronHistory(const NeutronHistory& history) {
    fNeutronList.push_back(history);
  }

  
 private:
  void FromHitsToSignals(const G4Event* evt);
  void PrintProgress();

  C6D6PrimaryGeneratorAction *myPrimaryGenerator;

  G4int NEvents,NEventsToRun,NDump;
  G4int indexC6D6, indexTarget;
  G4String simulatedParticle;
  G4int NDet;

  //------------------------------
  G4int SigNSignals[MAXNDET];
  G4double* SigEdep[MAXNDET];
  G4double* SigTimeMin[MAXNDET];
  G4double* SigTimeMax[MAXNDET];
  G4double SignalTimeWidth;
  std::ofstream det_out;
  //------------------------------
  G4int TotalNSignals;
  G4int TotalNCaptures;
  G4double TOFCaptures[10000];
  G4int TotalNActProd;
  G4int ActProd[10000];

  C6D6InputManager *theInputManager;
  G4String InputFname;
  //Energy resolution:
  G4double Eres_a1[MAXNDET],Eres_a2[MAXNDET];
  G4double NextPrint_minutes;
  time_t starttime;

  std::vector<NeutronHistory> fNeutronList;
  G4bool PrintNeutronList=false;
};

#endif
