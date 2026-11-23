#ifndef C6D6DetectorConstruction_h
#define C6D6DetectorConstruction_h

#include <stdio.h>

#include <iostream>
#include <sstream>

#include "C6D6SensitiveDetector.hh"
#include "C6D6SensitiveTarget.hh"
#include "C6D6UserInput.hh"
#include "G4Box.hh"
#include "G4Colour.hh"
#include "G4Cons.hh"
#include "G4Element.hh"
#include "G4ElementTable.hh"
#include "G4ExtrudedSolid.hh"
#include "G4Gamma.hh"
#include "G4IntersectionSolid.hh"
#include "G4Isotope.hh"
#include "G4LogicalVolume.hh"
#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4NistManager.hh"
#include "G4Orb.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4Para.hh"
#include "G4Polycone.hh"
#include "G4RotationMatrix.hh"
#include "G4SDManager.hh"
#include "G4Sphere.hh"
#include "G4SubtractionSolid.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "G4Torus.hh"
#include "G4Transform3D.hh"
#include "G4Tubs.hh"
#include "G4UnionSolid.hh"
#include "G4UserLimits.hh"
#include "G4VSensitiveDetector.hh"
#include "G4VSolid.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VisAttributes.hh"
#include "G4ios.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

class G4VPhysicalVolume;
class RecorderBase;
class G4Box;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4SDManager;
class G4NistManager;
class G4Material;
class BICRONConstructor;

class C6D6DetectorConstruction : public G4VUserDetectorConstruction {
 public:
  C6D6DetectorConstruction(C6D6UserInput* u);
  virtual ~C6D6DetectorConstruction();

  virtual G4VPhysicalVolume* Construct();
  virtual void ConstructSDandField();

 private:
  void ConstructTarget_CalibrationEAR2(G4LogicalVolume* mother);

  void ConstructTarget_197Au(G4LogicalVolume* mother);
  void ConstructTarget_natPb(G4LogicalVolume* mother);
  void ConstructTarget_80Se(G4LogicalVolume* mother);
  void ConstructTarget_Er(G4LogicalVolume* mother, G4int isotope = 0,
                          double target_diameter_mm = 13,
                          double targer_thickness_mm = 0.3);
  void ConstructTarget_Sm(G4LogicalVolume* mother, G4int isotope = 0,
                          double target_diameter_mm = 13,
                          double targer_thickness_mm = 0.3);
  void ConstructTarget_U(G4LogicalVolume* mother, G4int isotope = 0);
  void ConstructTarget_Calibration(G4LogicalVolume* mother);
  void ConstructTarget_NoTarget(G4LogicalVolume* mother);
  void ConstructTarget_CalibrationELAB(G4LogicalVolume* mother);
  void ConstructTarget_CalibrationCIEMAT(G4LogicalVolume* mother);
  void ConstructTarget_Ta(G4LogicalVolume* mother, double diameter_cm,
                          double Thickness_um);
  void ConstructTarget_Au(G4LogicalVolume* mother, double diameter_cm,
                          double Thickness_um);

  void ConstructTarget_23Ta(G4LogicalVolume* mother, double diameter_cm,
                            double Thickness_um);
  void ConstructTarget_23Au(G4LogicalVolume* mother, double diameter_cm,
                            double Thickness_um);
  void ConstructTarget_23Er(G4LogicalVolume* mother, G4int isotope = 0,
                            double target_diameter_mm = 13,
                            double targer_thickness_mm = 0.3);

  void ConstructL6D6(G4LogicalVolume* mother, G4int* flagL6D6,
                     G4float* thetaL6D6, G4float* phiL6D6, G4float* zL6D6);

  void ConstructB6D6(G4LogicalVolume* mother, G4int* flagB6D6,
                     G4float* thetaB6D6, G4float* phiB6D6, G4float* zB6D6);

  void ConstructS6D6(G4LogicalVolume* mother, G4int* flagS6D6,
                     G4float* thetaS6D6, G4float* phiS6D6, G4float* zS6D6);
  void ConstructS6D6Short(G4LogicalVolume* mother, G4int* flagS6D6,
                          G4float* thetaS6D6, G4float* phiS6D6, G4float* zS6D6);
  void ConstructESTI(G4LogicalVolume* mother, G4int* flagS6D6,
                     G4float* thetaS6D6, G4float* phiS6D6, G4float* zS6D6);
  void ConstructLABR(G4LogicalVolume* mother, G4int* flagS6D6,
                     G4float* thetaS6D6, G4float* phiS6D6, G4float* zS6D6);
  void ConstructAlColumnZ0(G4LogicalVolume* mother, G4float posX,
                           G4int columnID);
  void ConstructsTED5Holder(G4LogicalVolume* mother);

  void ConstructAlColumn(G4LogicalVolume* mother, G4float posX, G4int columnID);
  void ConstructRoofWalls(G4LogicalVolume* mother);
  void ConstructSaEx(G4LogicalVolume* mother);
  void ConstructBeamLineEAR1(G4LogicalVolume* mother);
  void ConstructBeamLineEAR1_2024_BigSampleHolder(G4LogicalVolume* mother);
  void ConstructBeamLineEAR1_2024_SmallSampleHolder(G4LogicalVolume* mother);
  void ConstructBeamLineEAR1_2026_PlasticSampleHolder(G4LogicalVolume* mother);

  void ConstructBeamLineEAR2_2025(G4LogicalVolume* mother);
  void ConstructBeamLineEAR2AndSampleHolder_Cm244(G4LogicalVolume* mother);
  void ConstructBeamLineEAR2AndSampleHolder_2021_Commissioning(
      G4LogicalVolume* mother);
  void ConstructStru27sTED_2025(G4LogicalVolume* mother);
  void ConstructStru9sTED_2025(G4LogicalVolume* mother);

  void ConstructLead27sTED_2024(G4LogicalVolume* mother);
  void ConstructPoly27sTED_2024(G4LogicalVolume* mother);
  void ConstructsTED_LeadRing(G4LogicalVolume* mother);
  void ConstructTAC(G4LogicalVolume* mother);
  void LoadMaterials();
  G4String GetName(G4String name, G4int number);

  C6D6UserInput* userInp;
  G4LogicalVolume* LfLogicC6D6;
  G4LogicalVolume* BfLogicC6D6;
  G4LogicalVolume* SfLogicC6D6;
  G4LogicalVolume* SShortfLogicC6D6;
  G4LogicalVolume* LaBrfLogicC6D6;
  G4LogicalVolume* EfLogicC6D6;

  G4LogicalVolume* logic_target;

  G4Material *Li, *Pb, *Al, *Cu, *H, *N, *O, *C, *Ca, *Br, *Cr, *Fe, *Ni, *Si,
      *B, *K, *Ba, *F, *Mn, *Mg, *Zn, *Ti, *Cd, *Cl, *air, *quartz, *kapton,
      *ESTI, *MYLAR, *kovar_mat, *pyrex_glass_mat, *vacuum_mat, *Ta, *Au, *La;
  G4Material *vacuum, *C6D6, *Mumetal, *CFK, *glass, *glass_lessB, *PM, *Cfiber,
      *tape_material, *PVC, *PP, *concrete, *Al_alloy, *BaF2, *LaBr;
  G4Material *Vacuum, *BGL, *MET, *Teflon, *Quartz, *PolDopedLi;
  G4Material *AlAW6082, *AluminizedKaptonPRELIMINAR;

  G4bool flagOverlaps;
};

#endif
