#ifndef PRIMARYGENERATORACTION_HH
#define PRIMARYGENERATORACTION_HH 1

#include <stdio.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>

#include "C6D6InputManager.hh"
#include "CLHEP/Random/RandGeneral.h"
#include "G4Event.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4IonTable.hh"
#include "G4ThreeVector.hh"
#include "G4UnitsTable.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "Randomize.hh"
#include "globals.hh"

using namespace std;

class G4ParticleGun;
class G4SPSPosDistribution;
class G4Event;
class G4ParticleTable;
class G4ParticleDefinition;

class C6D6PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
 public:
  C6D6PrimaryGeneratorAction();
  ~C6D6PrimaryGeneratorAction();

 public:
  void GeneratePrimaries(G4Event *anEvent);

  void SamplePosition();
  void SampleDirection();
  void SampleEnergy();

 private:
  G4ParticleGun *particleGun;
  C6D6InputManager *theInputManager;

  G4ThreeVector SourcePos;
  G4ThreeVector SourceDir;
  G4double SourceEne;

  //variables from the input manager:
  G4int SourceType;
  G4double sourcepos_x,sourcepos_y,sourcepos_z;
  G4double sourcepos_zlength,sourcepos_xs; //macroscopic XS
  G4double sourcepos_rad;
  G4double source_angle; //apertura
  G4String BIFFname;
  G4double source_Emin,source_Emax,source_Esample;
  G4String source_par;
  G4int theZA;
  G4int NSourceFnames;
  G4String SourceFname[100];

  std::vector<std::pair<G4double, G4double>> bif;
  std::vector<G4int> theFP_ZA; //fission products
  std::vector<G4int> theFP_M; //fission products
  std::vector<G4double> theFP_Y_CumulProb; //fission products

  ifstream in1;
};


#endif


