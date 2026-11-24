
#include "C6D6DetectorConstruction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

C6D6DetectorConstruction::C6D6DetectorConstruction() {
  theInputManager = C6D6InputManager::getInstance();
  flagOverlaps = false;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

C6D6DetectorConstruction::~C6D6DetectorConstruction() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* C6D6DetectorConstruction::Construct() {
  // load materials
  LoadMaterials();

  G4double EAR1ScaleFactor = theInputManager->GetEAR1ScaleFactor();
  // World
  // G4Box* world = new G4Box("World", 4. * m, 4. * m, 11. * m);
  // G4LogicalVolume* logic_world = new G4LogicalVolume(world, air, "World");
  G4Box* world = new G4Box("World", 4. * m * EAR1ScaleFactor,
                           4. * m * EAR1ScaleFactor, 200. * m);
  G4LogicalVolume* logic_world =
      new G4LogicalVolume(world, vacuum_mat, "World");

  G4VPhysicalVolume* phys_world = new G4PVPlacement(
      0, G4ThreeVector(0, 0, 0), logic_world, "World", 0, false, 0);
  logic_world->SetVisAttributes(G4VisAttributes::GetInvisible());

  string theEARName = theInputManager->GetEARName();
  if (theEARName == "1") {
    G4cout << G4endl << "Build EAR1" << G4endl << G4endl;

    // Al columns supports
    G4cout << "Build Two columns" << G4endl;

    ConstructAlColumn(logic_world, -35 * cm, 1);
    ConstructAlColumn(logic_world, 35 * cm, 2);
    // ConstructAlColumnZ0(logic_world, 35 * cm, 3);
    // ConstructsTED5Holder(logic_world);

    // Roof an  d walls
    // G4cout << "Build Roof and walls" << G4endl;
    // ConstructRoofWalls(logic_world);

    // Sample exanger
    // G4cout << "Build SaEx" << G4endl;
    // ConstructSaEx(logic_world);

    // Beam line
    G4cout << "Build Beam line" << G4endl;
    ConstructBeamLineEAR1(logic_world);

    // TAC
    // G4cout << "Build TAC" << G4endl;
    // ConstructTAC(logic_world);
  }
  if (theEARName == "EAR1_2024_SmallSampleHolder") {
    G4cout << G4endl << "Build EAR1" << G4endl << G4endl;

    // Al columns supports
    G4cout << "Build Two columns" << G4endl;

    ConstructAlColumn(logic_world, -37 * cm, 1);
    ConstructAlColumn(logic_world, 37 * cm, 2);
    // ConstructAlColumnZ0(logic_world, 35 * cm, 3);
    // ConstructsTED5Holder(logic_world);

    // Roof an  d walls
    G4cout << "Build Roof and walls" << G4endl;
    ConstructRoofWalls(logic_world);

    // Beam line
    G4cout << "Build Beam line" << G4endl;
    ConstructBeamLineEAR1_2024_SmallSampleHolder(logic_world);

    // TAC
    G4cout << "Build TAC" << G4endl;
    ConstructTAC(logic_world);
  }
  if (theEARName == "EAR1_2023_SmallSampleHolder") {
    G4cout << G4endl << "Build EAR1" << G4endl << G4endl;

    // Al columns supports
    G4cout << "Build Two columns" << G4endl;

    ConstructAlColumn(logic_world, -34 * cm, 1);
    ConstructAlColumnZ0(logic_world, 34 * cm, 2);
    ConstructsTED5Holder(logic_world);

    // Roof an  d walls
    G4cout << "Build Roof and walls" << G4endl;
    ConstructRoofWalls(logic_world);

    // Beam line
    G4cout << "Build Beam line" << G4endl;
    ConstructBeamLineEAR1_2024_SmallSampleHolder(logic_world);

    // TAC
    G4cout << "Build TAC" << G4endl;
    ConstructTAC(logic_world);
  }

  if (theEARName == "EAR1_2024_BigSampleHolder") {
    G4cout << G4endl << "Build EAR1" << G4endl << G4endl;

    // Al columns supports
    G4cout << "Build Two columns" << G4endl;

    ConstructAlColumn(logic_world, -37 * cm, 1);
    ConstructAlColumn(logic_world, 37 * cm, 2);
    // ConstructAlColumnZ0(logic_world, 35 * cm, 3);
    // ConstructsTED5Holder(logic_world);

    // Roof an  d walls
    G4cout << "Build Roof and walls" << G4endl;
    ConstructRoofWalls(logic_world);

    // Beam line
    G4cout << "Build Beam line" << G4endl;
    ConstructBeamLineEAR1_2024_BigSampleHolder(logic_world);

    // TAC
    G4cout << "Build TAC" << G4endl;
    ConstructTAC(logic_world);
  }

  if (theEARName == "EAR1_2024_BigSampleHolder_noWalls") {
    G4cout << G4endl << "Build EAR1" << G4endl << G4endl;

    // Al columns supports
    G4cout << "Build Two columns" << G4endl;

    ConstructAlColumn(logic_world, -37 * cm, 1);
    ConstructAlColumn(logic_world, 37 * cm, 2);

    // Beam line
    G4cout << "Build Beam line" << G4endl;
    ConstructBeamLineEAR1_2024_BigSampleHolder(logic_world);
  }

  if (theEARName == "2") {
    G4cout << G4endl << "Build EAR2" << G4endl << G4endl;

    // Beam line
    G4cout << "Build Beam line and Samplo Holder" << G4endl;
    // ConstructBeamLineEAR2AndSampleHolder_Cm244(logic_world);
    ConstructBeamLineEAR2AndSampleHolder_2021_Commissioning(logic_world);
    // ConstructStru27sTED_2024(logic_world);
    // ConstructLead27sTED_2024(logic_world);
    // ConstructPoly27sTED_2024(logic_world);
    ConstructsTED_LeadRing(logic_world);
  }
  if (theEARName == "3") {
    G4cout << G4endl << "Build Elab" << G4endl << G4endl;

    // Beam line
  }

  G4cout << G4endl;
  // Target
  if (theInputManager->GetTargetName() == "gold") {
    G4cout << "Build 197Au target" << G4endl;
    ConstructTarget_197Au(logic_world);
  } else if (theInputManager->GetTargetName() == "NoTarget") {
    G4cout << "Build Notarget" << G4endl;
    ConstructTarget_NoTarget(logic_world);
  } else if (theInputManager->GetTargetName() == "selenium") {
    G4cout << "Build 80Se target" << G4endl;
    ConstructTarget_80Se(logic_world);
  } else if (theInputManager->GetTargetName() == "er") {
    G4cout << "Build Er target" << G4endl;
    ConstructTarget_Er(logic_world);
  } else if (theInputManager->GetTargetName() == "er166") {
    G4cout << "Build 166Er target" << G4endl;
    ConstructTarget_Er(logic_world, 166);
  } else if (theInputManager->GetTargetName() == "er167") {
    G4cout << "Build 167Er target" << G4endl;
    ConstructTarget_Er(logic_world, 167);
  } else if (theInputManager->GetTargetName() == "u238") {
    G4cout << "Build 238U target" << G4endl;
    ConstructTarget_U(logic_world, 238);
  } else if (theInputManager->GetTargetName() == "lead") {
    G4cout << "Build lead target" << G4endl;
    ConstructTarget_natPb(logic_world);
  } else if (theInputManager->GetTargetName() == "Pb-45-1") {
    G4cout << "Build Pb-45-1 target" << G4endl;
    ConstructTarget_natPb_v02(logic_world, 45. * mm, 1. * mm);
  } else if (theInputManager->GetTargetName() == "Pb-45-2") {
    G4cout << "Build Pb-45-2 target" << G4endl;
    ConstructTarget_natPb_v02(logic_world, 45. * mm, 2. * mm);
  } else if (theInputManager->GetTargetName() == "Bi-20-1") {
    G4cout << "Build Bi-20-1 target" << G4endl;
    ConstructTarget_Bi_v02(logic_world, 20. * mm, 1. * mm);
  } else if (theInputManager->GetTargetName() == "Pb204-45-1") {
    G4cout << "Build Pb204-45-1 target" << G4endl;
    ConstructTarget_monoIso(logic_world, 45. * mm, 1. * mm, 11.34 * g / cm3,
                            82204);
  } else if (theInputManager->GetTargetName() == "Pb206-45-1") {
    G4cout << "Build Pb206-45-1 target" << G4endl;
    ConstructTarget_monoIso(logic_world, 45. * mm, 1. * mm, 11.34 * g / cm3,
                            82206);
  } else if (theInputManager->GetTargetName() == "Pb206-45-5") {
    G4cout << "Build Pb206-45-5 target" << G4endl;
    ConstructTarget_monoIso(logic_world, 45. * mm, 5. * mm, 11.34 * g / cm3,
                            82206);
  } else if (theInputManager->GetTargetName() == "Pb207-45-1") {
    G4cout << "Build Pb207-45-1 target" << G4endl;
    ConstructTarget_monoIso(logic_world, 45. * mm, 1. * mm, 11.34 * g / cm3,
                            82207);
  } else if (theInputManager->GetTargetName() == "Pb208-45-1") {
    G4cout << "Build Pb208-45-1 target" << G4endl;
    ConstructTarget_monoIso(logic_world, 45. * mm, 1. * mm, 11.34 * g / cm3,
                            82208);
  } else if (theInputManager->GetTargetName() == "Graphite-45-1") {
    G4cout << "Build Graphite-45-1 target" << G4endl;
    ConstructTarget_Graphite_v02(logic_world, 45. * mm, 1. * mm);
  } else if (theInputManager->GetTargetName() == "calibration") {
    G4cout << "Build  Calibration" << G4endl;
    ConstructTarget_Calibration(logic_world);
  } else if (theInputManager->GetTargetName() == "test") {
    ConstructTarget_197Au(logic_world);
  } else if (theInputManager->GetTargetName() == "CalibrationELAB") {
    ConstructTarget_CalibrationELAB(logic_world);
  } else if (theInputManager->GetTargetName() == "CalibrationCIEMAT") {
    ConstructTarget_CalibrationCIEMAT(logic_world);

    G4cout << "Build test target" << G4endl;
    G4cout << "WARNING: \"test\" target selected!" << G4endl
           << "        Runing with gold target." << G4endl;
  } else if (theInputManager->GetTargetName() == "EmptyEr") {
    G4cout << "Build EmptyEr target" << G4endl;
    ConstructTarget_EmptyEr(logic_world);
  }

  // #################################Sm Samples
  else if (theInputManager->GetTargetName() == "Sm_25_5") {
    G4cout << "Build Sm_25_5 target" << G4endl;
    ConstructTarget_Sm(logic_world, 0, 25, 0.005);
  } else if (theInputManager->GetTargetName() == "Sm_13_500") {
    G4cout << "Build Sm_13_15 target" << G4endl;
    ConstructTarget_Sm(logic_world, 0, 13, 0.5);
  } else if (theInputManager->GetTargetName() == "Sm_20_15") {
    G4cout << "Build Sm_20_500 target" << G4endl;
    ConstructTarget_Sm(logic_world, 0, 20, 0.0015);
  } else if (theInputManager->GetTargetName() == "Er") {
    G4cout << "Build Er target" << G4endl;
    ConstructTarget_Er(logic_world);
  } else if (theInputManager->GetTargetName() == "Er166") {
    G4cout << "Build 166Er target" << G4endl;
    ConstructTarget_Er(logic_world, 166);
  } else if (theInputManager->GetTargetName() == "Er167") {
    G4cout << "Build 167Er target" << G4endl;
    ConstructTarget_Er(logic_world, 167);
  }
  /////////////
  else if (theInputManager->GetTargetName() == "Ta_2_10") {
    ConstructTarget_Ta(logic_world, 2, 10);
  } else if (theInputManager->GetTargetName() == "Ta_4_10") {
    ConstructTarget_Ta(logic_world, 4, 10);
  } else if (theInputManager->GetTargetName() == "Ta_2_100") {
    ConstructTarget_Ta(logic_world, 2, 100);
  } else if (theInputManager->GetTargetName() == "Ta_4_100") {
    ConstructTarget_Ta(logic_world, 4, 100);
  } else if (theInputManager->GetTargetName() == "Ta_2_500") {
    ConstructTarget_Ta(logic_world, 2, 500);
  } else if (theInputManager->GetTargetName() == "Ta_4_500") {
    ConstructTarget_Ta(logic_world, 4, 500);
  } else if (theInputManager->GetTargetName() == "Er_2_10000") {
    G4cout << "Build Er_2_1000 target" << G4endl;
    ConstructTarget_Er(logic_world, 0, 20, 10.0);
  } else if (theInputManager->GetTargetName() == "Er_2_1000") {
    G4cout << "Build Er_2_1000 target" << G4endl;
    ConstructTarget_Er(logic_world, 0, 20, 1.0);
  } else if (theInputManager->GetTargetName() == "Er_2_500") {
    G4cout << "Build Er_2_1000 target" << G4endl;
    ConstructTarget_Er(logic_world, 0, 20, 0.5);
  } else if (theInputManager->GetTargetName() == "Er_2_100") {
    G4cout << "Build Er_2_1000 target" << G4endl;
    ConstructTarget_Er(logic_world, 0, 20, 0.1);
  } else if (theInputManager->GetTargetName() == "Er_2_25") {
    G4cout << "Build Er_2_25 target" << G4endl;
    ConstructTarget_Er(logic_world, 0, 20, 0.025);
  } else if (theInputManager->GetTargetName() == "Er_2_1") {
    G4cout << "Build Er_2_25 target" << G4endl;
    ConstructTarget_Er(logic_world, 0, 20, 0.001);
  } else if (theInputManager->GetTargetName() == "Au_2_20") {
    ConstructTarget_Au(logic_world, 2, 20);
  } else if (theInputManager->GetTargetName() == "Au_2_207") {
    ConstructTarget_Au(logic_world, 2, 207);
  } else if (theInputManager->GetTargetName() == "Au_2_100") {
    ConstructTarget_Au(logic_world, 2, 100);
  } else if (theInputManager->GetTargetName() == "Au_4_200") {
    ConstructTarget_Au(logic_world, 4, 200);
  } else if (theInputManager->GetTargetName() == "Au_13_200") {
    ConstructTarget_Au(logic_world, 1.3, 200);
  } else if (theInputManager->GetTargetName() == "Au_13_100") {
    ConstructTarget_Au(logic_world, 1.3, 100);
  } else if (theInputManager->GetTargetName() == "Au_2_200") {
    ConstructTarget_Au(logic_world, 2, 200);
  } else if (theInputManager->GetTargetName() == "Au_1_200") {
    ConstructTarget_Au(logic_world, 1, 200);
  } else if (theInputManager->GetTargetName() == "Au_25_100") {
    ConstructTarget_Au(logic_world, 2.5, 100);
  }
  ///////// 2023 samples only with one mylar

  else if (theInputManager->GetTargetName() == "23Ta_2_10") {
    ConstructTarget_23Ta(logic_world, 2, 10);
  } else if (theInputManager->GetTargetName() == "23Ta_4_10") {
    ConstructTarget_23Ta(logic_world, 4, 10);
  } else if (theInputManager->GetTargetName() == "23Ta_2_100") {
    ConstructTarget_23Ta(logic_world, 2, 100);
  } else if (theInputManager->GetTargetName() == "23Ta_4_100") {
    ConstructTarget_23Ta(logic_world, 4, 100);
  } else if (theInputManager->GetTargetName() == "23Ta_2_500") {
    ConstructTarget_23Ta(logic_world, 2, 500);
  } else if (theInputManager->GetTargetName() == "23Ta_4_500") {
    ConstructTarget_23Ta(logic_world, 4, 500);
  } else if (theInputManager->GetTargetName() == "23Er_2_10000") {
    G4cout << "Build 23Er_2_1000 target" << G4endl;
    ConstructTarget_23Er(logic_world, 0, 20, 10.0);
  } else if (theInputManager->GetTargetName() == "23Er_2_1000") {
    G4cout << "Build 23Er_2_1000 target" << G4endl;
    ConstructTarget_23Er(logic_world, 0, 20, 1.0);
  } else if (theInputManager->GetTargetName() == "23Er_2_500") {
    G4cout << "Build 23Er_2_1000 target" << G4endl;
    ConstructTarget_23Er(logic_world, 0, 20, 0.5);
  } else if (theInputManager->GetTargetName() == "23Er_2_100") {
    G4cout << "Build 23Er_2_1000 target" << G4endl;
    ConstructTarget_23Er(logic_world, 0, 20, 0.1);
  } else if (theInputManager->GetTargetName() == "23Er_2_25") {
    G4cout << "Build 23Er_2_25 target" << G4endl;
    ConstructTarget_23Er(logic_world, 0, 20, 0.025);
  } else if (theInputManager->GetTargetName() == "23Er_2_1") {
    G4cout << "Build 23Er_2_25 target" << G4endl;
    ConstructTarget_23Er(logic_world, 0, 20, 0.001);
  } else if (theInputManager->GetTargetName() == "23Au_2_20") {
    ConstructTarget_23Au(logic_world, 2, 20);
  } else if (theInputManager->GetTargetName() == "23Au_2_207") {
    ConstructTarget_23Au(logic_world, 2, 207);
  } else if (theInputManager->GetTargetName() == "23Au_2_100") {
    ConstructTarget_23Au(logic_world, 2, 100);
  } else if (theInputManager->GetTargetName() == "23Au_4_200") {
    ConstructTarget_23Au(logic_world, 4, 200);
  } else if (theInputManager->GetTargetName() == "23Au_13_200") {
    ConstructTarget_23Au(logic_world, 1.3, 200);
  } else if (theInputManager->GetTargetName() == "23Au_2_200") {
    ConstructTarget_23Au(logic_world, 2, 200);
  } else if (theInputManager->GetTargetName() == "23Au_1_200") {
    ConstructTarget_23Au(logic_world, 1, 200);
  }

  else if (theInputManager->GetTargetName() == "23Au_2_3000") {
    ConstructTarget_23Au(logic_world, 2, 3000);
  } else if (theInputManager->GetTargetName() == "23Au_2_20000") {
    ConstructTarget_23Au(logic_world, 2, 20000);
  }
  // #################################

  else {
    G4cout
        << "ERROR: Target not defined or not added to the conditional" << G4endl
        << "       Check target name in the input file ---> "
        << theInputManager->GetTargetName() << G4endl
        << "       Check if target is defined in the DetectorConstruction class"
        << G4endl
        << "       Check conditional in Construct of DetectorConstruction class"
        << G4endl;
    exit(-1);
  }

  int DetectorTypeC6D6[MAXNDET];
  G4double zC6D6[MAXNDET], thetaC6D6[MAXNDET], phiC6D6[MAXNDET];
  theInputManager->GetC6D6Parameters(DetectorTypeC6D6, zC6D6, thetaC6D6,
                                     phiC6D6);

  if (theInputManager->IsB6D6Defined()) {
    ConstructB6D6(logic_world, DetectorTypeC6D6, thetaC6D6, phiC6D6, zC6D6);
  }
  if (theInputManager->IsL6D6Defined()) {
    ConstructL6D6(logic_world, DetectorTypeC6D6, thetaC6D6, phiC6D6, zC6D6);
  }
  if (theInputManager->IsS6D6Defined()) {
    ConstructS6D6(logic_world, DetectorTypeC6D6, thetaC6D6, phiC6D6, zC6D6);
  }
  if (theInputManager->IsESTIDefined()) {
    ConstructESTI(logic_world, DetectorTypeC6D6, thetaC6D6, phiC6D6, zC6D6);
  }
  if (theInputManager->IsECLABR3Defined()) {
    ConstructECLABR3(logic_world, DetectorTypeC6D6, thetaC6D6, phiC6D6, zC6D6);
  }

  // print the table of materials
  // G4cout << *(G4Material::GetMaterialTable()) << G4endl;

  return phys_world;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6DetectorConstruction::LoadMaterials() {
  // BEGIN MATERIALS LIST
  G4NistManager* materials_list =
      G4NistManager::Instance();  // Materials database
  air = materials_list->FindOrBuildMaterial("G4_AIR");
  Al = materials_list->FindOrBuildMaterial("G4_Al");
  Cu = materials_list->FindOrBuildMaterial("G4_Cu");
  H = materials_list->FindOrBuildMaterial("G4_H");
  N = materials_list->FindOrBuildMaterial("G4_N");
  O = materials_list->FindOrBuildMaterial("G4_O");
  C = materials_list->FindOrBuildMaterial("G4_C");
  Ca = materials_list->FindOrBuildMaterial("G4_Ca");
  Br = materials_list->FindOrBuildMaterial("G4_Br");
  Cr = materials_list->FindOrBuildMaterial("G4_Cr");
  Fe = materials_list->FindOrBuildMaterial("G4_Fe");
  Ni = materials_list->FindOrBuildMaterial("G4_Ni");
  Si = materials_list->FindOrBuildMaterial("G4_Si");
  B = materials_list->FindOrBuildMaterial("G4_B");
  K = materials_list->FindOrBuildMaterial("G4_K");
  Ba = materials_list->FindOrBuildMaterial("G4_Ba");
  F = materials_list->FindOrBuildMaterial("G4_F");
  Mn = materials_list->FindOrBuildMaterial("G4_Mn");
  Mg = materials_list->FindOrBuildMaterial("G4_Mg");
  Zn = materials_list->FindOrBuildMaterial("G4_Zn");
  Ti = materials_list->FindOrBuildMaterial("G4_Ti");
  Cd = materials_list->FindOrBuildMaterial("G4_Cd");
  Cl = materials_list->FindOrBuildMaterial("G4_Cl");
  Pb = materials_list->FindOrBuildMaterial("G4_Pb");
  Li = materials_list->FindOrBuildMaterial("G4_Li");
  Na = materials_list->FindOrBuildMaterial("G4_Na");
  Au = materials_list->FindOrBuildMaterial("G4_Au");
  Ta = materials_list->FindOrBuildMaterial("G4_Ta");

  quartz = materials_list->FindOrBuildMaterial("G4_SILICON_DIOXIDE");
  kapton = materials_list->FindOrBuildMaterial("G4_KAPTON");
  MYLAR = materials_list->FindOrBuildMaterial("G4_MYLAR");
  Brass = materials_list->FindOrBuildMaterial("G4_BRASS");

  LaBr3 = new G4Material("LaBr3", 5.06 * g / cm3, 2);
  LaBr3->AddElement(materials_list->FindOrBuildElement("La"), 1);
  LaBr3->AddElement(materials_list->FindOrBuildElement("Br"), 3);

  // Thermal hydrogen:
  G4Element* H_therm =
      new G4Element("TS_H_of_Water", "H", 1., 1.0079 * g / mole);
  H_thermal = new G4Material("H_Thermal", 1.00 * g / cm3, 1);
  H_thermal->AddElement(H_therm, 1.0);

  // Polyethylene doped with Natural Li
  PolDopedLi = new G4Material("PolDopedLi", 1.06 * g / cm3, 3);

  PolDopedLi->AddElement(materials_list->FindOrBuildElement("H"), 0.0859);
  PolDopedLi->AddElement(materials_list->FindOrBuildElement("C"), 0.8385);
  PolDopedLi->AddElement(materials_list->FindOrBuildElement("Li"), 0.0756);

  // material by Alberto
  kovar_mat = new G4Material("Kovar", 8.36 * CLHEP::g / CLHEP::cm3, 6);
  kovar_mat->AddElement(materials_list->FindOrBuildElement("Fe"), 0.5358);
  kovar_mat->AddElement(materials_list->FindOrBuildElement("Ni"), 0.29);
  kovar_mat->AddElement(materials_list->FindOrBuildElement("Co"), 0.17);
  kovar_mat->AddElement(materials_list->FindOrBuildElement("Mn"), 0.003);
  kovar_mat->AddElement(materials_list->FindOrBuildElement("Si"), 0.001);
  kovar_mat->AddElement(materials_list->FindOrBuildElement("C"), 0.0002);
  // material by Alberto

  pyrex_glass_mat = materials_list->FindOrBuildMaterial("G4_Pyrex_Glass");
  // pyrex_glass_mat = materials_list->FindOrBuildMaterial("G4_Galactic");

  // material by Alberto

  vacuum_mat = materials_list->FindOrBuildMaterial("G4_Galactic");

  //  Vacuum
  vacuum = new G4Material("Vacuum", 1., 1.01 * g / mole, 1.e-25 * g / cm3,
                          kStateGas, 273 * kelvin, 3.e-18 * pascal);

  // C6D6
  G4Isotope* IsoH2 = new G4Isotope("my_IsoH2", 1, 2, 2.014 * g / mole);
  G4Element* deuterium = new G4Element("my_Deuterium", "my_D", 1);
  deuterium->AddIsotope(IsoH2, 1.);
  G4Element* carbon =
      new G4Element("my_Carbon", "my_C", 6., 12.0107 * g / mole);
  C6D6 = new G4Material("C6D6", 0.954 * g / cm3, 2);
  C6D6->AddElement(carbon, 1);
  C6D6->AddElement(deuterium, 1);

  // ESTI not deutereted

  // The detector density is not 100% clear
  // https://reader.elsevier.com/reader/sd/pii/S0168900218309653?token=4236DD29F1B37CEAEAB562B75623D237A56F1712A521BC4E9FC0701171A43AB15E714CF8243C8EDA7D8AE130CD54DEE1&originRegion=eu-west-1&originCreation=20221104153518
  G4Element* hidrogen =
      new G4Element("my_Hidrogen", "my_H", 1., 1.00784 * g / mole);

  ESTI = new G4Material("ESTI", 1.16 * g / cm3, 2, kStateSolid);
  ESTI->AddElement(carbon, 14);
  ESTI->AddElement(hidrogen, 12);

  // Mu-metal
  Mumetal = new G4Material("Mumetal", 8.58 * g / cm3, 4);
  Mumetal->AddMaterial(Cr, 0.02);
  Mumetal->AddMaterial(Fe, 0.18);
  Mumetal->AddMaterial(Ni, 0.75);
  Mumetal->AddMaterial(Cu, 0.05);

  // CFK (canning mixture)
  CFK = new G4Material("CFK", 1.5 * g / cm3, 4);
  CFK->AddMaterial(C, 0.8546);
  CFK->AddMaterial(O, 0.1106);
  CFK->AddMaterial(N, 0.0131);
  CFK->AddMaterial(H, 0.0217);

  // Glass with less Boron
  glass_lessB = new G4Material("Glass_lessB", 2.3 * g / cm3, 5);
  glass_lessB->AddMaterial(Si, 0.346232);
  glass_lessB->AddMaterial(O, 0.5702647);
  glass_lessB->AddMaterial(B, 0.0254582);
  glass_lessB->AddMaterial(Al, 0.0173116);
  glass_lessB->AddMaterial(K, 0.040733);

  // Boron-Silicate glass
  glass = new G4Material("Glass", 2.3 * g / cm3, 5);
  glass->AddMaterial(Si, 0.331643);
  glass->AddMaterial(O, 0.556795);
  glass->AddMaterial(B, 0.0537525);
  glass->AddMaterial(Al, 0.0172414);
  glass->AddMaterial(K, 0.04056795);

  // Carbon fiber:
  Cfiber = new G4Material("Carbon_fiber", 1.6 * g / cm3, 5);
  Cfiber->AddMaterial(C, 0.8375);
  Cfiber->AddMaterial(O, 0.084);
  Cfiber->AddMaterial(N, 0.067);
  Cfiber->AddMaterial(Ca, 0.005);
  Cfiber->AddMaterial(Br, 0.0065);

  // Tape material
  tape_material =
      new G4Material("Tape_material", 1.3 * g / cm3, 5);  // density?
  tape_material->AddMaterial(C, 0.823085);
  tape_material->AddMaterial(O, 0.164797);
  tape_material->AddMaterial(Al, 0.004275);
  tape_material->AddMaterial(Si, 0.002226);
  tape_material->AddMaterial(Cl, 0.005617);

  // PM (photomultiplier mixture)
  PM = new G4Material("PM", 8.9 * g / cm3, 2);
  PM->AddMaterial(Ni, 0.8);
  PM->AddMaterial(Fe, 0.2);

  // PVC
  PVC = new G4Material("PVC", 1.3 * g / cm3, 3);
  PVC->AddMaterial(C, 0.333333);
  PVC->AddMaterial(H, 0.5);
  PVC->AddMaterial(Cl, 0.166667);

  // PP
  PP = new G4Material("PP", 0.91 * g / cm3, 2);
  PP->AddMaterial(C, 0.333333);
  PP->AddMaterial(H, 0.666667);

  // Concrete
  if (theInputManager->GetConcreteType() == 1) {  // original definition
    concrete = new G4Material("concrete", 2.3 * g / cm3, 6);
    concrete->AddMaterial(Si, 0.227915);
    concrete->AddMaterial(O, 0.60541);
    concrete->AddMaterial(H_thermal, 0.09972);
    concrete->AddMaterial(Ca, 0.04986);
    concrete->AddMaterial(Al, 0.014245);
    concrete->AddMaterial(Fe, 0.00285);
  } else if (theInputManager->GetConcreteType() == 2) {  // PDG
    //-->
    // https://pdg.lbl.gov/2025/AtomicNuclearProperties/HTML/shielding_concrete.html
    concrete = new G4Material("concrete", 2.3 * g / cm3, 10);
    concrete->AddMaterial(H_thermal, 0.010000);
    concrete->AddMaterial(C, 0.001000);
    concrete->AddMaterial(O, 0.529107);
    concrete->AddMaterial(Na, 0.016000);
    concrete->AddMaterial(Mg, 0.002000);
    concrete->AddMaterial(Al, 0.033872);
    concrete->AddMaterial(Si, 0.337021);
    concrete->AddMaterial(K, 0.013000);
    concrete->AddMaterial(Ca, 0.044000);
    concrete->AddMaterial(Fe, 0.014000);
  } else {
    G4cout << " ########## ERROR in " << __FILE__ << ", line " << __LINE__
           << " ##########" << G4endl;
    exit(1);
  }
  // Al alloy
  Al_alloy = new G4Material("Al_alloy", 2.7 * g / cm3, 9);
  Al_alloy->AddMaterial(Al, 0.9837);
  Al_alloy->AddMaterial(Mn, 0.001);
  Al_alloy->AddMaterial(Fe, 0.002);
  Al_alloy->AddMaterial(Cu, 0.001);
  Al_alloy->AddMaterial(Mg, 0.0048);
  Al_alloy->AddMaterial(Cr, 0.0005);
  Al_alloy->AddMaterial(Zn, 0.0015);
  Al_alloy->AddMaterial(Ti, 0.001);
  Al_alloy->AddMaterial(Si, 0.0045);

  // BaF2
  BaF2 = new G4Material("BaF2", 4.89 * g / cm3, 2);
  BaF2->AddMaterial(Ba, 0.3333);
  BaF2->AddMaterial(F, 0.6667);

  ///////////Materials for BICRON detector
  G4String name;
  G4double temperature = 2.73 * kelvin;
  G4double pressure = 3.e-18 * pascal;
  G4double a, z;  // z=mean number of protons;
  G4int ncomponents, natoms;
  G4double fractionmass;

  Vacuum = new G4Material(name = "Galactic", z = 1., a = 1.01 * g / mole,
                          1.e-25 * g / cm3, kStateGas, temperature, pressure);

  // BGL
  BGL = new G4Material(name = "BGL", 2.3 * g / cm3, ncomponents = 5);
  BGL->AddMaterial(Si, fractionmass = 0.331643);
  BGL->AddMaterial(O, fractionmass = 0.556795);
  BGL->AddMaterial(B, fractionmass = 0.0537525);
  BGL->AddMaterial(Al, fractionmass = 0.0172414);
  BGL->AddMaterial(K, fractionmass = 0.040568);

  // MET
  MET = new G4Material(name = "MET", 8.9 * g / cm3, ncomponents = 2);
  MET->AddMaterial(Ni, fractionmass = 0.80);
  MET->AddMaterial(Fe, fractionmass = 0.20);

  G4Element* CEle = materials_list->FindOrBuildElement("C");
  G4Element* FEle = materials_list->FindOrBuildElement("F");
  G4Element* SiEle = materials_list->FindOrBuildElement("Si");
  G4Element* OEle = materials_list->FindOrBuildElement("O");

  // Teflon
  Teflon = new G4Material(name = "Teflon", 2.2 * g / cm3, ncomponents = 2);
  Teflon->AddElement(CEle, natoms = 2);
  Teflon->AddElement(FEle, natoms = 4);

  // Quartz
  // Quartz = new G4Material(name = "Galactic", z = 1., a = 1.01 * g / mole,
  // 1.e-25 * g / cm3, kStateGas, temperature, pressure);

  Quartz = new G4Material(name = "Quartz", 2.2 * g / cm3, ncomponents = 2);
  Quartz->AddElement(SiEle, natoms = 1);
  Quartz->AddElement(OEle, natoms = 2);

  // ALuminum for Pipes the reference is  AW6082

  G4double aldensityAlAW6082 = 2.700 * g / cm3;
  // Kapton = new G4Material(name="CASAlAW6082",aldensityAlAW6082 ,
  //					ncomponents=9
  //,kStateSolid,temperature,pressure);
  //

  // AlAW6082 = new G4Material(name = "Galactic", z = 1., a = 1.01 * g / mole,
  //         1.e-25 * g / cm3, kStateGas, temperature, pressure);

  // AlAW6082 = materials_list->FindOrBuildMaterial("G4_Al");
  AlAW6082 =
      new G4Material(name = "AlAW6082", aldensityAlAW6082, ncomponents = 9,
                     kStateSolid, temperature, pressure);

  AlAW6082->AddMaterial(Al, fractionmass = 95.35 * perCent);
  AlAW6082->AddMaterial(Cr, fractionmass = 0.25 * perCent);
  AlAW6082->AddMaterial(Cu, fractionmass = 0.1 * perCent);
  AlAW6082->AddMaterial(Fe, fractionmass = 0.5 * perCent);
  AlAW6082->AddMaterial(Mg, fractionmass = 1.2 * perCent);

  AlAW6082->AddMaterial(Mn, fractionmass = 1.0 * perCent);

  AlAW6082->AddMaterial(Si, fractionmass = 1.3 * perCent);
  AlAW6082->AddMaterial(Ti, fractionmass = 0.1 * perCent);
  AlAW6082->AddMaterial(Zn, fractionmass = 0.2 * perCent);

  /// minimum values of contaminants according to
  /// https://www.broncesval.com/aluminio/aluminio-aleacion-magnesio-silicio-en-aw-6082/
  // AlAW6082 =
  //     new G4Material(name = "AlAW6082", aldensityAlAW6082, ncomponents = 4,
  //                    kStateSolid, temperature, pressure);

  // AlAW6082->AddMaterial(Si, fractionmass = 0.7 * perCent);
  // AlAW6082->AddMaterial(Mg, fractionmass = 0.4 * perCent);
  // AlAW6082->AddMaterial(Mn, fractionmass = 0.6 * perCent);
  // AlAW6082->AddMaterial(Al, fractionmass = 98.3 * perCent);

  // Kapton aluminized//
  // DONT TRUST THIS NUMBERS. Ther are  an aproxiamtion made by Victor Alcayne.
  // T
  G4double densityAluminizedKaptonPRELIMINAR = 1.500 * g / cm3;
  AluminizedKaptonPRELIMINAR = new G4Material(
      name = "AluminizedKaptonPRELIMINAR", densityAluminizedKaptonPRELIMINAR,
      ncomponents = 2, kStateSolid, temperature, pressure);

  AluminizedKaptonPRELIMINAR->AddMaterial(kapton, fractionmass = 90 * perCent);
  AluminizedKaptonPRELIMINAR->AddMaterial(Al, fractionmass = 10 * perCent);
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6DetectorConstruction::ConstructTarget_NoTarget(
    G4LogicalVolume* mother) {
  // Solid
  G4double target_diameter = 0.0001 * mm;
  G4double target_thickness = 0.001 * mm;
  G4Tubs* target = new G4Tubs("Target_Calibration", 0, target_diameter / 2,
                              target_thickness / 2, 0. * deg, 360. * deg);
  // Logic
  logic_target = new G4LogicalVolume(target, vacuum, "Target_Calibration");
  // Physic
  /* G4VPhysicalVolume *phys_target=*/new G4PVPlacement(
      0, G4ThreeVector(0, 0, 0), logic_target, "Target_Calibration", mother,
      false, 0, flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Yellow()));
}

void C6D6DetectorConstruction::ConstructTarget_CalibrationCIEMAT(
    G4LogicalVolume* mother) {
  cout << "Build CalibrationCIEMAT" << endl;
  // Solid
  G4double target_diameter = 25.4 * mm;
  G4double target_thickness = 3 * mm;
  G4Tubs* target = new G4Tubs("Target_Calibration", 0, target_diameter / 2,
                              target_thickness / 2, 0. * deg, 360. * deg);
  // Logic
  logic_target = new G4LogicalVolume(target, PVC, "Target_Calibration");
  // Physic
  /* G4VPhysicalVolume *phys_target=*/new G4PVPlacement(
      0, G4ThreeVector(0, 0, 0), logic_target, "Target_Calibration", mother,
      false, 0, flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Yellow()));
}

void C6D6DetectorConstruction::ConstructTarget_CalibrationELAB(
    G4LogicalVolume* mother) {
  // Solid
  G4double target_diameter = 10 * mm;
  G4double target_thickness = 3 * mm;
  G4Tubs* target = new G4Tubs("Target_Calibration", 0, target_diameter / 2,
                              target_thickness / 2, 0. * deg, 360. * deg);
  // Logic
  logic_target = new G4LogicalVolume(target, PVC, "Target_Calibration");
  // Physic
  /* G4VPhysicalVolume *phys_target=*/new G4PVPlacement(
      0, G4ThreeVector(0, 0, -1.5 * cm), logic_target, "Target_Calibration",
      mother, false, 0, flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Yellow()));
}

void C6D6DetectorConstruction::ConstructTarget_Calibration(
    G4LogicalVolume* mother) {
  // Solid
  G4double target_diameter = 10 * mm;
  G4double target_thickness = 2 * mm;
  G4Tubs* target = new G4Tubs("Target_Calibration", 0, target_diameter / 2,
                              target_thickness / 2, 0. * deg, 360. * deg);
  // Logic
  logic_target = new G4LogicalVolume(target, PVC, "Target_Calibration");
  // Physic
  /* G4VPhysicalVolume *phys_target=*/new G4PVPlacement(
      0, G4ThreeVector(0, 0, 0), logic_target, "Target_Calibration", mother,
      false, 0, flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Yellow()));

  // Aluminum Ring
  double ThicknessAlRing = 1.0 * mm;
  double InnerRadiusAlRing = 25 * mm;
  double OuterRadiusAlRing = 30 * mm;

  G4Tubs* solidAlRing =
      new G4Tubs("AlRing", InnerRadiusAlRing, OuterRadiusAlRing,
                 ThicknessAlRing / 2.0, 0, 360 * deg);
  G4LogicalVolume* logicAlRing = new G4LogicalVolume(solidAlRing, Al, "AlRing");
  /* G4VPhysicalVolume* physiAlring =*/new G4PVPlacement(
      0, G4ThreeVector(0., 0., 0), logicAlRing, "AlRing", mother, false, 0,
      flagOverlaps);
  logicAlRing->SetVisAttributes(G4Colour::Gray());

  // CFSampleHolder windows

  const G4int pieces = 2;
  G4double CFSampleHolder_thickness[pieces] = {ThicknessAlRing,
                                               target_thickness + 1 * mm};
  G4double CFSampleHolder_Radius[pieces] = {InnerRadiusAlRing,
                                            target_diameter / 2.0 + 0.1 * mm};

  G4ThreeVector CFSampleHolder_position[pieces];
  G4Tubs* CFSampleHolder[pieces];
  G4Transform3D transformCFSampleHolder =
      G4Transform3D(G4RotationMatrix(0, 0, 0), G4ThreeVector(0., 0., 0));

  CFSampleHolder[0] =
      new G4Tubs("CFSampleHolder0", 0., CFSampleHolder_Radius[0],
                 CFSampleHolder_thickness[0] / 2., -180. * deg, 180 * deg);
  CFSampleHolder[1] =
      new G4Tubs("CFSampleHolder1", 0., CFSampleHolder_Radius[1],
                 CFSampleHolder_thickness[1] / 2., -180. * deg, 180. * deg);

  G4UnionSolid* CFSampleHolder2 =
      new G4UnionSolid("CFSampleHolder2", CFSampleHolder[0], CFSampleHolder[1],
                       transformCFSampleHolder);

  G4SubtractionSolid* CFSampleHolder3 = new G4SubtractionSolid(
      "CFSampleHolder3", CFSampleHolder2, target, transformCFSampleHolder);

  G4LogicalVolume* logic_CFSampleHolder =
      new G4LogicalVolume(CFSampleHolder3, Cfiber, "CFSampleHolder");

  new G4PVPlacement(0, G4ThreeVector(0, 0, 0), logic_CFSampleHolder,
                    "CFSampleHolder", mother, false, flagOverlaps);
  logic_CFSampleHolder->SetVisAttributes(
      new G4VisAttributes(G4Colour::Black()));
}

void C6D6DetectorConstruction::ConstructTarget_197Au(G4LogicalVolume* mother) {
  // Isotope
  G4Isotope* IsoAu197 = new G4Isotope("IsoAu197", 79, 197, 197.0 * g / mole);
  // Element
  G4Element* Au197 = new G4Element("Au197", "AU197", 1);
  Au197->AddIsotope(IsoAu197, 1.);
  // Material
  G4Material* Au197Target =
      new G4Material("Au197_Target", 19.0853 * g / cm3, 1);
  Au197Target->AddElement(Au197, 1.);

  // Solid
  G4double target_diameter = 19.94 * mm;
  G4double target_thickness = 0.1 * mm;
  G4Tubs* target = new G4Tubs("Target_197Au", 0, target_diameter / 2,
                              target_thickness / 2, 0. * deg, 360. * deg);
  // Logic
  logic_target = new G4LogicalVolume(target, Au197Target, "Target_197Au");
  // Physic
  /* G4VPhysicalVolume *phys_target=*/new G4PVPlacement(
      0, G4ThreeVector(0, 0, 0), logic_target, "Target_197Au", mother, false, 0,
      flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Yellow()));

  // Aluminum Ring
  G4Tubs* solidAlRing =
      new G4Tubs("AlRing", 25 * mm, 30 * mm, 0.5 * mm, 0, 360 * deg);
  G4LogicalVolume* logicAlRing = new G4LogicalVolume(solidAlRing, Al, "AlRing");
  /* G4VPhysicalVolume* physiAlring =*/new G4PVPlacement(
      0, G4ThreeVector(0., 0., 0), logicAlRing, "AlRing", mother, false, 0,
      flagOverlaps);
  logicAlRing->SetVisAttributes(G4Colour::Gray());
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6DetectorConstruction::ConstructTarget_natPb(G4LogicalVolume* mother) {
  // Isotopes
  G4Isotope* IsoPb204 = new G4Isotope("IsoPb204", 82, 204, 204.0 * g / mole);
  G4Isotope* IsoPb206 = new G4Isotope("IsoPb206", 82, 206, 206.0 * g / mole);
  G4Isotope* IsoPb207 = new G4Isotope("IsoPb207", 82, 207, 207.0 * g / mole);
  G4Isotope* IsoPb208 = new G4Isotope("IsoPb208", 82, 208, 208.0 * g / mole);
  // Elements
  G4Element* Pb204 = new G4Element("Pb204", "Pb204", 1);
  G4Element* Pb206 = new G4Element("Pb206", "Pb206", 1);
  G4Element* Pb207 = new G4Element("Pb207", "Pb207", 1);
  G4Element* Pb208 = new G4Element("Pb208", "Pb208", 1);
  Pb204->AddIsotope(IsoPb204, 1.);
  Pb206->AddIsotope(IsoPb206, 1.);
  Pb207->AddIsotope(IsoPb207, 1.);
  Pb208->AddIsotope(IsoPb208, 1.);
  // Material
  G4Material* PbTarget = new G4Material("natPb_Target", 10.0754 * g / cm3, 4);
  PbTarget->AddElement(Pb204, 0.014);
  PbTarget->AddElement(Pb206, 0.241);
  PbTarget->AddElement(Pb207, 0.221);
  PbTarget->AddElement(Pb208, 0.524);

  // Solid
  G4double target_diameter = 20. * mm;
  G4double target_thickness = 2.1 * mm;
  G4Tubs* target = new G4Tubs("Target_natPb", 0, target_diameter / 2,
                              target_thickness / 2, 0. * deg, 360. * deg);
  // Logic
  logic_target = new G4LogicalVolume(target, PbTarget, "Target_natPb");
  // Physic
  /*G4VPhysicalVolume *phys_target =*/new G4PVPlacement(
      0, G4ThreeVector(0, 0, 0), logic_target, "Target_natPb", mother, false, 0,
      flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Gray()));

  // Aluminum Ring
  G4Tubs* solidAlRing =
      new G4Tubs("AlRing", 25 * mm, 30 * mm, 0.5 * mm, 0, 360 * deg);
  G4LogicalVolume* logicAlRing = new G4LogicalVolume(solidAlRing, Al, "AlRing");
  /*  G4VPhysicalVolume* physiAlring =*/new G4PVPlacement(
      0, G4ThreeVector(0., 0., 0), logicAlRing, "AlRing", mother, false, 0,
      flagOverlaps);
  logicAlRing->SetVisAttributes(G4Colour::Gray());
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6DetectorConstruction::ConstructTarget_natPb_v02(
    G4LogicalVolume* mother, G4double target_diameter,
    G4double target_thickness) {
  // Solid
  // G4double target_diameter = 20. * mm;
  // G4double target_thickness = 2.1 * mm;
  G4Tubs* target = new G4Tubs("Target_natPb_v02", 0, target_diameter / 2,
                              target_thickness / 2, 0. * deg, 360. * deg);
  // Logic
  logic_target = new G4LogicalVolume(target, Pb, "Target");
  // Physic
  /*G4VPhysicalVolume *phys_target =*/new G4PVPlacement(
      0, G4ThreeVector(0, 0, 0), logic_target, "Target", mother, false, 0,
      flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Gray()));

  // Aluminium rings (4 rings of 1 mm thickness put together)
  G4double al_ring_thickness = 1 * mm;
  G4Tubs* al_rings = new G4Tubs("Al_Rings", 35 * mm, 45 * mm,
                                4 * al_ring_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_al_rings =
      new G4LogicalVolume(al_rings, Al, "Al_Rings");
  new G4PVPlacement(0, G4ThreeVector(0., 0., 0), logic_al_rings, "Al_Rings",
                    mother, false, 0, flagOverlaps);
  logic_al_rings->SetVisAttributes(G4Colour::Gray());
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6DetectorConstruction::ConstructTarget_monoIso(
    G4LogicalVolume* mother, G4double target_diameter,
    G4double target_thickness, G4double target_density, G4int theZA) {
  // Solid
  // G4double target_diameter = 20. * mm;
  // G4double target_thickness = 2.1 * mm;
  G4Tubs* target = new G4Tubs("Target_monoIsoPb", 0, target_diameter / 2,
                              target_thickness / 2, 0. * deg, 360. * deg);

  G4int theZ = theZA / 1000;
  G4int theA = theZA - theZ * 1000;
  G4Isotope* theIso = new G4Isotope("Isotope", theZ, theA);
  G4Element* theElement = new G4Element("TheEle", "TheEle", 1);
  theElement->AddIsotope(theIso, 1.);
  G4Material* theMaterial = new G4Material("TheMaterial", target_density, 1,
                                           kStateUndefined, 293. * kelvin);
  theMaterial->AddElement(theElement, 1);

  // Logic
  logic_target = new G4LogicalVolume(target, theMaterial, "Target");
  // Physic
  /*G4VPhysicalVolume *phys_target =*/new G4PVPlacement(
      0, G4ThreeVector(0, 0, 0), logic_target, "Target", mother, false, 0,
      flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Gray()));

  // Aluminium rings (4 rings of 1 mm thickness put together)
  G4double al_ring_thickness = 1 * mm;
  G4Tubs* al_rings = new G4Tubs("Al_Rings", 35 * mm, 45 * mm,
                                4 * al_ring_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_al_rings =
      new G4LogicalVolume(al_rings, Al, "Al_Rings");
  new G4PVPlacement(0, G4ThreeVector(0., 0., 0), logic_al_rings, "Al_Rings",
                    mother, false, 0, flagOverlaps);
  logic_al_rings->SetVisAttributes(G4Colour::Gray());
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6DetectorConstruction::ConstructTarget_Bi_v02(
    G4LogicalVolume* mother, G4double target_diameter,
    G4double target_thickness) {
  // Solid
  // G4double target_diameter = 20. * mm;
  // G4double target_thickness = 2.1 * mm;
  G4Tubs* target = new G4Tubs("Target_Bi_v02", 0, target_diameter / 2,
                              target_thickness / 2, 0. * deg, 360. * deg);
  // Logic
  G4Material* Bi = G4NistManager::Instance()->FindOrBuildMaterial("G4_Bi");

  logic_target = new G4LogicalVolume(target, Bi, "Target");
  // Physic
  /*G4VPhysicalVolume *phys_target =*/new G4PVPlacement(
      0, G4ThreeVector(0, 0, 0), logic_target, "Target", mother, false, 0,
      flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Gray()));

  // Aluminium rings (4 rings of 1 mm thickness put together)
  G4double al_ring_thickness = 1 * mm;
  G4Tubs* al_rings = new G4Tubs("Al_Rings", 35 * mm, 45 * mm,
                                4 * al_ring_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_al_rings =
      new G4LogicalVolume(al_rings, Al, "Al_Rings");
  new G4PVPlacement(0, G4ThreeVector(0., 0., 0), logic_al_rings, "Al_Rings",
                    mother, false, 0, flagOverlaps);
  logic_al_rings->SetVisAttributes(G4Colour::Gray());
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6DetectorConstruction::ConstructTarget_Graphite_v02(
    G4LogicalVolume* mother, G4double target_diameter,
    G4double target_thickness) {
  // Solid
  G4Tubs* target = new G4Tubs("Target_Graphite_v02", 0, target_diameter / 2,
                              target_thickness / 2, 0. * deg, 360. * deg);
  // Logic
  G4NistManager* materials_list = G4NistManager::Instance();
  G4Material* graphite = materials_list->FindOrBuildMaterial("G4_GRAPHITE");
  logic_target = new G4LogicalVolume(target, graphite, "Target");
  // Physic
  /*G4VPhysicalVolume *phys_target =*/new G4PVPlacement(
      0, G4ThreeVector(0, 0, 0), logic_target, "Target", mother, false, 0,
      flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Gray()));

  // Aluminium rings (4 rings of 1 mm thickness put together)
  G4double al_ring_thickness = 1 * mm;
  G4Tubs* al_rings = new G4Tubs("Al_Rings", 35 * mm, 45 * mm,
                                4 * al_ring_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_al_rings =
      new G4LogicalVolume(al_rings, Al, "Al_Rings");
  new G4PVPlacement(0, G4ThreeVector(0., 0., 0), logic_al_rings, "Al_Rings",
                    mother, false, 0, flagOverlaps);
  logic_al_rings->SetVisAttributes(G4Colour::Gray());
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6DetectorConstruction::ConstructTarget_80Se(G4LogicalVolume* mother) {
  // Isotopes
  G4Isotope* IsoSe74 = new G4Isotope("IsoSe74", 34, 74, 73.9224759 * g / mole);
  G4Isotope* IsoSe76 = new G4Isotope("IsoSe76", 34, 76, 75.9192137 * g / mole);
  G4Isotope* IsoSe78 = new G4Isotope("IsoSe78", 34, 78, 77.9173090 * g / mole);
  G4Isotope* IsoSe80 = new G4Isotope("IsoSe80", 34, 80, 79.9165220 * g / mole);
  G4Isotope* IsoSe82 = new G4Isotope("IsoSe82", 34, 82, 81.9167000 * g / mole);
  // Elements
  G4Element* Se74 = new G4Element("Se74", "SE74", 1);
  G4Element* Se76 = new G4Element("Se76", "SE76", 1);
  G4Element* Se78 = new G4Element("Se78", "SE78", 1);
  G4Element* Se80 = new G4Element("Se80", "SE80", 1);
  G4Element* Se82 = new G4Element("Se82", "SE82", 1);
  Se74->AddIsotope(IsoSe74, 1.);
  Se76->AddIsotope(IsoSe76, 1.);
  Se78->AddIsotope(IsoSe78, 1.);
  Se80->AddIsotope(IsoSe80, 1.);
  Se82->AddIsotope(IsoSe82, 1.);
  // Material
  G4Material* Se80Target = new G4Material("Se80Target", 11.036261 * g / cm3, 5);
  Se80Target->AddElement(Se74, 0.0004);
  Se80Target->AddElement(Se76, 0.0001);
  Se80Target->AddElement(Se78, 0.0001);
  Se80Target->AddElement(Se80, 0.9987);
  Se80Target->AddElement(Se82, 0.0007);

  // Solid
  G4double target_diameter = 20. * mm;
  G4double target_thickness = 3.5 * mm;
  G4Tubs* target = new G4Tubs("Target_80Se", 0, target_diameter / 2,
                              target_thickness / 2, 0. * deg, 360. * deg);
  // Logic
  logic_target = new G4LogicalVolume(target, Se80Target, "Target_80Se");
  // Physic
  /*G4VPhysicalVolume *phys_target =*/new G4PVPlacement(
      0, G4ThreeVector(0, 0, 0), logic_target, "Target_80Se", mother, false, 0,
      flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Red()));

  // Aluminum Ring
  G4Tubs* solidAlRing =
      new G4Tubs("AlRing", 25 * mm, 30 * mm, 0.5 * mm, 0, 360 * deg);
  G4LogicalVolume* logicAlRing = new G4LogicalVolume(solidAlRing, Al, "AlRing");
  /* G4VPhysicalVolume* physiAlring =*/new G4PVPlacement(
      0, G4ThreeVector(0., 0., 0), logicAlRing, "AlRing", mother, false, 0,
      flagOverlaps);
  logicAlRing->SetVisAttributes(G4Colour::Gray());
}

void C6D6DetectorConstruction::ConstructTarget_Er(G4LogicalVolume* mother,
                                                  G4int isotope,
                                                  double target_diameter_mm,
                                                  double target_thickness_mm) {
  G4Isotope* Er162_isotope =
      new G4Isotope("162Er", 68, 162, 161.9287873 * g / mole);
  G4Isotope* Er164_isotope =
      new G4Isotope("164Er", 68, 164, 163.9292077 * g / mole);
  G4Isotope* Er166_isotope =
      new G4Isotope("166Er", 68, 166, 165.9303011 * g / mole);
  G4Isotope* Er167_isotope =
      new G4Isotope("167Er", 68, 167, 166.9320562 * g / mole);
  G4Isotope* Er168_isotope =
      new G4Isotope("168Er", 68, 168, 167.93237828 * g / mole);
  G4Isotope* Er170_isotope =
      new G4Isotope("170Er", 68, 170, 169.9354719 * g / mole);

  G4Element* Er166_element = new G4Element("166Er", "166Er", 1);
  Er166_element->AddIsotope(Er166_isotope, 1);
  G4Element* Er167_element = new G4Element("167Er", "167Er", 1);
  Er167_element->AddIsotope(Er167_isotope, 1);
  G4Element* Er_element = new G4Element("Er", "Er", 6);
  Er_element->AddIsotope(Er162_isotope, 0.139 * perCent);
  Er_element->AddIsotope(Er164_isotope, 1.6 * perCent);
  Er_element->AddIsotope(Er166_isotope, 33.5 * perCent);
  Er_element->AddIsotope(Er167_isotope, 22.9 * perCent);
  Er_element->AddIsotope(Er168_isotope, 27 * perCent);
  Er_element->AddIsotope(Er170_isotope, 14.9 * perCent);

  G4Material* Er166 =
      new G4Material("Er166", 5.6429 * g / cm3,
                     1);  // It is modify because is a powder sample so the mass
                          // for a 300umx13mm sample should be 224.1 therefore
                          // the densitiy is reduced
  Er166->AddElement(Er166_element, 1);
  G4Material* Er167 =
      new G4Material("Er167", 5.577 * g / cm3,
                     1);  // It is modify because is a powder sample so the mass
                          // for a 300umx13mm sample should be 222.1 therefore
                          // the densitiy is reduced
  Er167->AddElement(Er167_element, 1);
  G4Material* Er = new G4Material("Er", 9.065 * g / cm3, 1);
  Er->AddElement(Er_element, 1);

  G4String name;
  G4Material* material;
  if (isotope == 0) {
    name = "Target_Er";
    material = Er;
  } else if (isotope == 166) {
    name = "Target_166Er";
    material = Er166;
  } else if (isotope == 167) {
    name = "Target_167Er";
    material = Er167;
  } else {
    G4cout << "ERROR: Unknown Er sample, not building target!" << G4endl;
    return;
  }

  // Target
  G4float target_diameter = target_diameter_mm * mm;
  G4float target_thickness = target_thickness_mm * mm;
  G4Tubs* target = new G4Tubs(name, 0, target_diameter / 2,
                              target_thickness / 2, 0, 360 * deg);
  logic_target = new G4LogicalVolume(target, material, name);
  new G4PVPlacement(0, G4ThreeVector(0, 0, 0), logic_target, name, mother,
                    false, 0, flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Red()));

  // Mylars
  G4float mylar_thickness = 6 * um;
  G4Tubs* mylar =
      new G4Tubs("Mylar", 0, 25 * mm, mylar_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_mylar = new G4LogicalVolume(mylar, MYLAR, "Mylar");
  new G4PVPlacement(
      0,
      G4ThreeVector(0., 0.,
                    -mylar_thickness / 2 - target_thickness / 2 - 0.001 * mm),
      logic_mylar, "Front_Mylar", mother, false, 0, flagOverlaps);
  new G4PVPlacement(
      0,
      G4ThreeVector(0., 0.,
                    mylar_thickness / 2 + target_thickness / 2 + 0.001 * mm),
      logic_mylar, "Back_Mylar", mother, false, 0, flagOverlaps);
  logic_mylar->SetVisAttributes(new G4VisAttributes(G4Colour(1, 1, 0, 0.25)));

  // Aluminium rings (2 rings of 1 mm thickness put together)
  G4float al_ring_thickness = 1 * mm;
  G4Tubs* al_rings = new G4Tubs("Al_Rings", 25 * mm, 30 * mm,
                                2 * al_ring_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_al_rings =
      new G4LogicalVolume(al_rings, Al, "Al_Rings");
  new G4PVPlacement(0, G4ThreeVector(0., 0., 0), logic_al_rings, "Al_Rings",
                    mother, false, 0, flagOverlaps);
  logic_al_rings->SetVisAttributes(G4Colour::Gray());
}

void C6D6DetectorConstruction::ConstructTarget_EmptyEr(
    G4LogicalVolume* mother) {
  // Solid
  G4double target_diameter = 0.0001 * mm;
  G4double target_thickness = 0.001 * mm;
  G4Tubs* target = new G4Tubs("Target_Calibration", 0, target_diameter / 2,
                              target_thickness / 2, 0. * deg, 360. * deg);
  // Logic
  logic_target = new G4LogicalVolume(target, vacuum, "Target_Calibration");
  // Physic
  /* G4VPhysicalVolume *phys_target=*/new G4PVPlacement(
      0, G4ThreeVector(0, 0, 0), logic_target, "Target_Calibration", mother,
      false, 0, flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Yellow()));

  // Mylars
  G4float mylar_thickness = 6 * um;
  G4Tubs* mylar =
      new G4Tubs("Mylar", 0, 25 * mm, mylar_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_mylar = new G4LogicalVolume(mylar, MYLAR, "Mylar");
  new G4PVPlacement(0, G4ThreeVector(0., 0., -mylar_thickness / 2 - 0.001 * mm),
                    logic_mylar, "Front_Mylar", mother, false, 0, flagOverlaps);
  new G4PVPlacement(0, G4ThreeVector(0., 0., mylar_thickness / 2 + 0.001 * mm),
                    logic_mylar, "Back_Mylar", mother, false, 0, flagOverlaps);
  logic_mylar->SetVisAttributes(new G4VisAttributes(G4Colour(1, 1, 0, 0.25)));

  // Aluminium rings (2 rings of 1 mm thickness put together)
  G4float al_ring_thickness = 1 * mm;
  G4Tubs* al_rings = new G4Tubs("Al_Rings", 25 * mm, 30 * mm,
                                2 * al_ring_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_al_rings =
      new G4LogicalVolume(al_rings, Al, "Al_Rings");
  new G4PVPlacement(0, G4ThreeVector(0., 0., 0), logic_al_rings, "Al_Rings",
                    mother, false, 0, flagOverlaps);
  logic_al_rings->SetVisAttributes(G4Colour::Gray());
}
void C6D6DetectorConstruction::ConstructTarget_Sm(G4LogicalVolume* mother,
                                                  G4int isotope,
                                                  double target_diameter_mm,
                                                  double target_thickness_mm) {
  // ----------------- ISOTOPES -----------------
  G4Isotope* Sm144_isotope =
      new G4Isotope("144Sm", 62, 144, 143.911999 * g / mole);
  G4Isotope* Sm147_isotope =
      new G4Isotope("147Sm", 62, 147, 146.9149044 * g / mole);
  G4Isotope* Sm148_isotope =
      new G4Isotope("148Sm", 62, 148, 147.9148292 * g / mole);
  G4Isotope* Sm149_isotope =
      new G4Isotope("149Sm", 62, 149, 148.9171921 * g / mole);
  G4Isotope* Sm150_isotope =
      new G4Isotope("150Sm", 62, 150, 149.9172829 * g / mole);
  G4Isotope* Sm152_isotope =
      new G4Isotope("152Sm", 62, 152, 151.9197397 * g / mole);
  G4Isotope* Sm154_isotope =
      new G4Isotope("154Sm", 62, 154, 153.9222169 * g / mole);

  // ----------------- PURE ISOTOPIC ELEMENTS -----------------
  G4Element* Sm147_element = new G4Element("147Sm", "147Sm", 1);
  Sm147_element->AddIsotope(Sm147_isotope, 1);

  G4Element* Sm149_element = new G4Element("149Sm", "149Sm", 1);
  Sm149_element->AddIsotope(Sm149_isotope, 1);

  G4Element* Sm150_element = new G4Element("150Sm", "150Sm", 1);
  Sm150_element->AddIsotope(Sm150_isotope, 1);

  // ----------------- NATURAL SAMARIUM -----------------
  G4Element* Sm_element = new G4Element("Sm", "Sm", 7);
  Sm_element->AddIsotope(Sm144_isotope, 3.07 * perCent);
  Sm_element->AddIsotope(Sm147_isotope, 14.99 * perCent);
  Sm_element->AddIsotope(Sm148_isotope, 11.24 * perCent);
  Sm_element->AddIsotope(Sm149_isotope, 13.82 * perCent);
  Sm_element->AddIsotope(Sm150_isotope, 7.38 * perCent);
  Sm_element->AddIsotope(Sm152_isotope, 26.75 * perCent);
  Sm_element->AddIsotope(Sm154_isotope, 22.75 * perCent);

  // ----------------- MATERIALS -----------------
  G4Material* Sm147 = new G4Material("Sm147", 7.52 * g / cm3, 1);
  // Ajusta densidad si es polvo como hiciste con Er
  Sm147->AddElement(Sm147_element, 1);

  G4Material* Sm149 = new G4Material("Sm149", 7.52 * g / cm3, 1);
  Sm149->AddElement(Sm149_element, 1);

  G4Material* Sm150 = new G4Material("Sm150", 7.52 * g / cm3, 1);
  Sm150->AddElement(Sm150_element, 1);

  G4Material* Sm = new G4Material("Sm", 7.52 * g / cm3, 1);
  Sm->AddElement(Sm_element, 1);
  G4String name;
  G4Material* material;
  if (isotope == 0) {
    name = "Target_SmNat";
    material = Sm;
  } else if (isotope == 147) {
    name = "Target_147Sm";
    material = Sm147;
  } else if (isotope == 149) {
    name = "Target_149Sm";
    material = Sm149;
  } else if (isotope == 150) {
    name = "Target_150Sm";
    material = Sm150;
  } else {
    G4cout << "ERROR: Unknown Sm sample, not building target!" << G4endl;
    return;
  }

  // Target
  G4float target_diameter = target_diameter_mm * mm;
  G4float target_thickness = target_thickness_mm * mm;
  G4Tubs* target = new G4Tubs(name, 0, target_diameter / 2,
                              target_thickness / 2, 0, 360 * deg);
  logic_target = new G4LogicalVolume(target, material, name);
  new G4PVPlacement(0, G4ThreeVector(0, 0, 0), logic_target, name, mother,
                    false, 0, flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Red()));

  // Aluminium rings (2 rings of 1 mm thickness put together)
  G4float al_ring_thickness = 1 * mm;
  G4Tubs* al_rings = new G4Tubs("Al_Rings", 25 * mm, 30 * mm,
                                2 * al_ring_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_al_rings =
      new G4LogicalVolume(al_rings, Al, "Al_Rings");
  new G4PVPlacement(0, G4ThreeVector(0., 0., 0), logic_al_rings, "Al_Rings",
                    mother, false, 0, flagOverlaps);
  logic_al_rings->SetVisAttributes(G4Colour::Gray());

  // Mylars
  G4float mylar_thickness = 6 * um;
  G4Tubs* mylar =
      new G4Tubs("Mylar", 0, 25 * mm, mylar_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_mylar = new G4LogicalVolume(mylar, MYLAR, "Mylar");

  // Al
  G4float al_thickness = 25 * um;
  G4Tubs* al = new G4Tubs("al", 0, 25 * mm, al_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_al = new G4LogicalVolume(al, Al, "al");

  if (target_diameter_mm == 13) {
    new G4PVPlacement(
        0,
        G4ThreeVector(0., 0.,
                      -mylar_thickness / 2 - target_thickness / 2 - 0.001 * mm),
        logic_mylar, "Front_Mylar", mother, false, 0, flagOverlaps);
    new G4PVPlacement(
        0,
        G4ThreeVector(0., 0.,
                      mylar_thickness / 2 + target_thickness / 2 + 0.001 * mm),
        logic_mylar, "Back_Mylar", mother, false, 0, flagOverlaps);
    logic_mylar->SetVisAttributes(new G4VisAttributes(G4Colour(1, 1, 0, 0.25)));
  } else if (target_diameter_mm == 20) {
    new G4PVPlacement(
        0,
        G4ThreeVector(0., 0.,
                      al_thickness / 2 + target_thickness / 2 + 0.001 * mm),
        logic_al, "Back_Al", mother, false, 0, flagOverlaps);
    logic_al->SetVisAttributes(G4Colour::Gray());

  } else if (target_diameter_mm == 25) {
    new G4PVPlacement(
        0,
        G4ThreeVector(0., 0.,
                      mylar_thickness / 2 + target_thickness / 2 + 0.001 * mm),
        logic_mylar, "Back_Mylar", mother, false, 0, flagOverlaps);
    logic_mylar->SetVisAttributes(new G4VisAttributes(G4Colour(1, 1, 0, 0.25)));
  } else {
    G4cout << "ERROR: Unknown Sm diametr, not building target!" << G4endl;
    return;
  }
}
void C6D6DetectorConstruction::ConstructTarget_Au(G4LogicalVolume* mother,
                                                  double diameter_cm,
                                                  double Thickness_um) {
  // Ta = materials_list->FindOrBuildMaterial("G4_Ta");
  G4String name;
  name = "Target_Au" + to_string(diameter_cm) + " " + to_string(Thickness_um);

  // Target
  G4float target_diameter = diameter_cm * cm;
  G4float target_thickness = Thickness_um * um;
  G4Tubs* target = new G4Tubs(name, 0, target_diameter / 2,
                              target_thickness / 2, 0, 360 * deg);
  logic_target = new G4LogicalVolume(target, Au, name);
  new G4PVPlacement(0, G4ThreeVector(0, 0, 0), logic_target, name, mother,
                    false, 0, flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Red()));

  // Mylars
  G4float mylar_thickness = 6 * um;
  G4Tubs* mylar =
      new G4Tubs("Mylar", 0, 25 * mm, mylar_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_mylar = new G4LogicalVolume(mylar, MYLAR, "Mylar");
  new G4PVPlacement(
      0,
      G4ThreeVector(0., 0.,
                    -mylar_thickness / 2 - target_thickness / 2 - 0.001 * mm),
      logic_mylar, "Front_Mylar", mother, false, 0, flagOverlaps);
  new G4PVPlacement(
      0,
      G4ThreeVector(0., 0.,
                    mylar_thickness / 2 + target_thickness / 2 + 0.001 * mm),
      logic_mylar, "Back_Mylar", mother, false, 0, flagOverlaps);
  logic_mylar->SetVisAttributes(new G4VisAttributes(G4Colour(1, 1, 0, 0.25)));

  // Aluminium rings (2 rings of 1 mm thickness put together)
  G4float al_ring_thickness = 1 * mm;
  G4Tubs* al_rings = new G4Tubs("Al_Rings", 25 * mm, 30 * mm,
                                2 * al_ring_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_al_rings =
      new G4LogicalVolume(al_rings, Al, "Al_Rings");
  new G4PVPlacement(0, G4ThreeVector(0., 0., 0), logic_al_rings, "Al_Rings",
                    mother, false, 0, flagOverlaps);
  logic_al_rings->SetVisAttributes(G4Colour::Gray());
}
void C6D6DetectorConstruction::ConstructTarget_Ta(G4LogicalVolume* mother,
                                                  double diameter_cm,
                                                  double Thickness_um) {
  // Ta = materials_list->FindOrBuildMaterial("G4_Ta");
  G4String name;
  name = "Target_Ta" + to_string(diameter_cm) + " " + to_string(Thickness_um);

  // Target
  G4float target_diameter = diameter_cm * cm;
  G4float target_thickness = Thickness_um * um;
  G4Tubs* target = new G4Tubs(name, 0, target_diameter / 2,
                              target_thickness / 2, 0, 360 * deg);
  logic_target = new G4LogicalVolume(target, Ta, name);
  new G4PVPlacement(0, G4ThreeVector(0, 0, 0), logic_target, name, mother,
                    false, 0, flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Red()));

  // Mylars
  G4float mylar_thickness = 6 * um;
  G4Tubs* mylar =
      new G4Tubs("Mylar", 0, 25 * mm, mylar_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_mylar = new G4LogicalVolume(mylar, MYLAR, "Mylar");
  new G4PVPlacement(
      0,
      G4ThreeVector(0., 0.,
                    -mylar_thickness / 2 - target_thickness / 2 - 0.001 * mm),
      logic_mylar, "Front_Mylar", mother, false, 0, flagOverlaps);
  new G4PVPlacement(
      0,
      G4ThreeVector(0., 0.,
                    mylar_thickness / 2 + target_thickness / 2 + 0.001 * mm),
      logic_mylar, "Back_Mylar", mother, false, 0, flagOverlaps);
  logic_mylar->SetVisAttributes(new G4VisAttributes(G4Colour(1, 1, 0, 0.25)));

  // Aluminium rings (2 rings of 1 mm thickness put together)
  G4float al_ring_thickness = 1 * mm;
  G4Tubs* al_rings = new G4Tubs("Al_Rings", 25 * mm, 30 * mm,
                                2 * al_ring_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_al_rings =
      new G4LogicalVolume(al_rings, Al, "Al_Rings");
  new G4PVPlacement(0, G4ThreeVector(0., 0., 0), logic_al_rings, "Al_Rings",
                    mother, false, 0, flagOverlaps);
  logic_al_rings->SetVisAttributes(G4Colour::Gray());
}

void C6D6DetectorConstruction::ConstructTarget_23Au(G4LogicalVolume* mother,
                                                    double diameter_cm,
                                                    double Thickness_um) {
  // Ta = materials_list->FindOrBuildMaterial("G4_Ta");
  G4String name;
  name = "Target_Au" + to_string(diameter_cm) + " " + to_string(Thickness_um);

  // Target
  G4float target_diameter = diameter_cm * cm;
  G4float target_thickness = Thickness_um * um;
  G4Tubs* target = new G4Tubs(name, 0, target_diameter / 2,
                              target_thickness / 2, 0, 360 * deg);
  logic_target = new G4LogicalVolume(target, Au, name);

  new G4PVPlacement(0, G4ThreeVector(0, 0, -target_thickness / 2), logic_target,
                    name, mother, false, 0, flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Red()));

  // Mylars
  G4float mylar_thickness = 6 * um;
  G4Tubs* mylar =
      new G4Tubs("Mylar", 0, 25 * mm, mylar_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_mylar = new G4LogicalVolume(mylar, MYLAR, "Mylar");

  new G4PVPlacement(0, G4ThreeVector(0., 0., mylar_thickness / 2 + 0.001 * mm),
                    logic_mylar, "Back_Mylar", mother, false, 0, flagOverlaps);
  logic_mylar->SetVisAttributes(new G4VisAttributes(G4Colour(1, 1, 0, 0.25)));

  // Aluminium rings (2 rings of 1 mm thickness put together)
  G4float al_ring_thickness = 1 * mm;
  G4Tubs* al_rings = new G4Tubs("Al_Rings", 25 * mm, 30 * mm,
                                2 * al_ring_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_al_rings =
      new G4LogicalVolume(al_rings, Al, "Al_Rings");
  new G4PVPlacement(0, G4ThreeVector(0., 0., 0), logic_al_rings, "Al_Rings",
                    mother, false, 0, flagOverlaps);
  logic_al_rings->SetVisAttributes(G4Colour::Gray());
}

void C6D6DetectorConstruction::ConstructTarget_23Ta(G4LogicalVolume* mother,
                                                    double diameter_cm,
                                                    double Thickness_um) {
  // Ta = materials_list->FindOrBuildMaterial("G4_Ta");
  G4String name;
  name = "Target_Ta" + to_string(diameter_cm) + " " + to_string(Thickness_um);

  // Target
  G4float target_diameter = diameter_cm * cm;
  G4float target_thickness = Thickness_um * um;
  G4Tubs* target = new G4Tubs(name, 0, target_diameter / 2,
                              target_thickness / 2, 0, 360 * deg);
  logic_target = new G4LogicalVolume(target, Ta, name);

  new G4PVPlacement(0, G4ThreeVector(0, 0, -target_thickness / 2), logic_target,
                    name, mother, false, 0, flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Red()));

  // Mylars
  G4float mylar_thickness = 6 * um;
  G4Tubs* mylar =
      new G4Tubs("Mylar", 0, 25 * mm, mylar_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_mylar = new G4LogicalVolume(mylar, MYLAR, "Mylar");

  new G4PVPlacement(0, G4ThreeVector(0., 0., mylar_thickness / 2 + 0.001 * mm),
                    logic_mylar, "Back_Mylar", mother, false, 0, flagOverlaps);
  logic_mylar->SetVisAttributes(new G4VisAttributes(G4Colour(1, 1, 0, 0.25)));

  // Aluminium rings (2 rings of 1 mm thickness put together)
  G4float al_ring_thickness = 1 * mm;
  G4Tubs* al_rings = new G4Tubs("Al_Rings", 25 * mm, 30 * mm,
                                2 * al_ring_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_al_rings =
      new G4LogicalVolume(al_rings, Al, "Al_Rings");
  new G4PVPlacement(0, G4ThreeVector(0., 0., 0), logic_al_rings, "Al_Rings",
                    mother, false, 0, flagOverlaps);
  logic_al_rings->SetVisAttributes(G4Colour::Gray());
}

void C6D6DetectorConstruction::ConstructTarget_23Er(
    G4LogicalVolume* mother, G4int isotope, double target_diameter_mm,
    double target_thickness_mm) {
  G4Isotope* Er162_isotope =
      new G4Isotope("162Er", 68, 162, 161.9287873 * g / mole);
  G4Isotope* Er164_isotope =
      new G4Isotope("164Er", 68, 164, 163.9292077 * g / mole);
  G4Isotope* Er166_isotope =
      new G4Isotope("166Er", 68, 166, 165.9303011 * g / mole);
  G4Isotope* Er167_isotope =
      new G4Isotope("167Er", 68, 167, 166.9320562 * g / mole);
  G4Isotope* Er168_isotope =
      new G4Isotope("168Er", 68, 168, 167.93237828 * g / mole);
  G4Isotope* Er170_isotope =
      new G4Isotope("170Er", 68, 170, 169.9354719 * g / mole);

  G4Element* Er166_element = new G4Element("166Er", "166Er", 1);
  Er166_element->AddIsotope(Er166_isotope, 1);
  G4Element* Er167_element = new G4Element("167Er", "167Er", 1);
  Er167_element->AddIsotope(Er167_isotope, 1);
  G4Element* Er_element = new G4Element("Er", "Er", 6);
  Er_element->AddIsotope(Er162_isotope, 0.139 * perCent);
  Er_element->AddIsotope(Er164_isotope, 1.6 * perCent);
  Er_element->AddIsotope(Er166_isotope, 33.5 * perCent);
  Er_element->AddIsotope(Er167_isotope, 22.9 * perCent);
  Er_element->AddIsotope(Er168_isotope, 27 * perCent);
  Er_element->AddIsotope(Er170_isotope, 14.9 * perCent);

  G4Material* Er166 =
      new G4Material("Er166", 5.6429 * g / cm3,
                     1);  // It is modify because is a powder sample so the
                          // mass for a 300umx13mm sample should be 224.1
                          // therefore the densitiy is reduced
  Er166->AddElement(Er166_element, 1);
  G4Material* Er167 =
      new G4Material("Er167", 5.577 * g / cm3,
                     1);  // It is modify because is a powder sample so the
                          // mass for a 300umx13mm sample should be 222.1
                          // therefore the densitiy is reduced
  Er167->AddElement(Er167_element, 1);
  G4Material* Er = new G4Material("Er", 9.065 * g / cm3, 1);
  Er->AddElement(Er_element, 1);

  G4String name;
  G4Material* material;
  if (isotope == 0) {
    name = "Target_Er";
    material = Er;
  } else if (isotope == 166) {
    name = "Target_166Er";
    material = Er166;
  } else if (isotope == 167) {
    name = "Target_167Er";
    material = Er167;
  } else {
    G4cout << "ERROR: Unknown Er sample, not building target!" << G4endl;
    return;
  }

  // Target
  G4float target_diameter = target_diameter_mm * mm;
  G4float target_thickness = target_thickness_mm * mm;
  G4Tubs* target = new G4Tubs(name, 0, target_diameter / 2,
                              target_thickness / 2, 0, 360 * deg);
  logic_target = new G4LogicalVolume(target, material, name);

  new G4PVPlacement(0, G4ThreeVector(0, 0, -target_thickness / 2), logic_target,
                    name, mother, false, 0, flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Red()));

  // Mylars
  G4float mylar_thickness = 6 * um;
  G4Tubs* mylar =
      new G4Tubs("Mylar", 0, 25 * mm, mylar_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_mylar = new G4LogicalVolume(mylar, MYLAR, "Mylar");

  new G4PVPlacement(0, G4ThreeVector(0., 0., mylar_thickness / 2 + 0.001 * mm),
                    logic_mylar, "Back_Mylar", mother, false, 0, flagOverlaps);
  logic_mylar->SetVisAttributes(new G4VisAttributes(G4Colour(1, 1, 0, 0.25)));

  // Aluminium rings (2 rings of 1 mm thickness put together)
  G4float al_ring_thickness = 1 * mm;
  G4Tubs* al_rings = new G4Tubs("Al_Rings", 25 * mm, 30 * mm,
                                2 * al_ring_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_al_rings =
      new G4LogicalVolume(al_rings, Al, "Al_Rings");
  new G4PVPlacement(0, G4ThreeVector(0., 0., 0), logic_al_rings, "Al_Rings",
                    mother, false, 0, flagOverlaps);
  logic_al_rings->SetVisAttributes(G4Colour::Gray());
}

void C6D6DetectorConstruction::ConstructTarget_U(G4LogicalVolume* mother,
                                                 G4int isotope) {
  if (isotope != 238) {
    G4cout << "ERROR: Unknown U isotope, not building target!" << G4endl;
    return;
  }

  G4Isotope* U238_isotope =
      new G4Isotope("238U", 92, 238, 238.050787618 * g / mole);
  G4Element* U238_element = new G4Element("238U", "238U", 1);
  U238_element->AddIsotope(U238_isotope, 1);
  G4Material* U238 = new G4Material("U238", 19.05 * g / cm3, 1);
  U238->AddElement(U238_element, 1);

  // Target
  G4double target_x = 30.2 * mm;  // Rounded average between 30.1972 and 30.2524
  G4double target_y = 53.7 * mm;  // Rounded average between 53.6256 and 53.7607
  G4double target_thickness = 0.20 * mm;  // Not sure
  G4Box* target = new G4Box("Target_238U", target_x / 2, target_y / 2,
                            target_thickness / 2);
  logic_target = new G4LogicalVolume(target, U238, "Target");
  new G4PVPlacement(0, G4ThreeVector(0, 0, 0), logic_target, "Target", mother,
                    false, 0, flagOverlaps);
  logic_target->SetVisAttributes(new G4VisAttributes(G4Colour::Red()));

  // Mylars
  G4double mylar_thickness = 6 * um;
  G4Tubs* mylar =
      new G4Tubs("Mylar", 0, 35 * mm, mylar_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_mylar = new G4LogicalVolume(mylar, MYLAR, "Mylar");
  new G4PVPlacement(
      0, G4ThreeVector(0., 0., -mylar_thickness / 2 - target_thickness / 2),
      logic_mylar, "Front_Mylar", mother, false, 0, flagOverlaps);
  new G4PVPlacement(
      0, G4ThreeVector(0., 0., mylar_thickness / 2 + target_thickness / 2),
      logic_mylar, "Back_Mylar", mother, false, 0, flagOverlaps);
  logic_mylar->SetVisAttributes(new G4VisAttributes(G4Colour(1, 1, 0, 0.25)));

  // Aluminium rings (4 rings of 1 mm thickness put together)
  G4double al_ring_thickness = 1 * mm;
  G4Tubs* al_rings = new G4Tubs("Al_Rings", 35 * mm, 45 * mm,
                                4 * al_ring_thickness / 2, 0, 360 * deg);
  G4LogicalVolume* logic_al_rings =
      new G4LogicalVolume(al_rings, Al, "Al_Rings");
  new G4PVPlacement(0, G4ThreeVector(0., 0., 0), logic_al_rings, "Al_Rings",
                    mother, false, 0, flagOverlaps);
  logic_al_rings->SetVisAttributes(G4Colour::Gray());
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6DetectorConstruction::ConstructL6D6(G4LogicalVolume* mother,
                                             G4int* flagL6D6,
                                             G4double* thetaL6D6,
                                             G4double* phiL6D6,
                                             G4double* zL6D6) {
  cout << endl << "Construct L6D6 detectors" << endl;
  ///////////////////CARBON FIBER SHELL/////////////////
  // Maximum and minimum radii of the carbon fiber shell (big cilinder(1), small
  // cilinder (2)
  G4double R1max = 57.25 * mm;
  G4double R1min = 55.25 * mm;
  G4double R2max = 30.75 * mm;
  G4double R2min = 28.75 * mm;
  G4double detTube_dZ = 46.0 * mm;  // Lenght of the cilinders and cone
  G4double detCone_dZ = 14.0 * mm;
  G4double PMTube_dZ = 102.5 * mm;
  G4double R3max = R2min;  // Radius of the carbonfiber shells to fit to the PM
                           // sield radius .
  G4double R3min = 27.38 * mm;
  G4double R4max = R3min;
  G4double R4min = 26.3 * mm;
  G4double PMAdapt1_dZ = 15.0 * mm;
  G4double PMAdapt2_dZ = 10.0 * mm;
  G4double R_base = 53.0 * mm;
  G4double DetBase1_dZ = 4.3 * mm;
  G4double DetBase2_dZ = 3.0 * mm;

  /////////////C.fiber around Det volume////////////////////
  G4Tubs* DetTube1 =
      new G4Tubs("DetTube1", R1min, R1max, detTube_dZ, 0., CLHEP::twopi);
  // hole for the expansion volume
  G4Tubs* DetTubeHole = new G4Tubs("DetTubeHole", 0, 5.0 * mm,
                                   0.5 * (R1max - R1min), 0., CLHEP::twopi);
  G4RotationMatrix rotmDetTube = G4RotationMatrix(0, -90 * deg, 90 * deg);
  G4ThreeVector transDetTube = G4ThreeVector(0.5 * (R1max + R1min), 0,
                                             180.5 * mm - 134.5 * mm - 60 * mm);
  G4Transform3D transformDetTube = G4Transform3D(rotmDetTube, transDetTube);
  G4SubtractionSolid* DetTube = new G4SubtractionSolid(
      "DetTube", DetTube1, DetTubeHole, transformDetTube);

  // conical reduction of the detection volume
  G4Cons* DetCone = new G4Cons("DetCone", R2min, R2max, R1min, R1max,
                               detCone_dZ, 0, CLHEP::twopi);  // 8
  // Front part of detector
  G4Tubs* DetWindow =
      new G4Tubs("DetWindow", 0, R1min, 0.5 * mm, 0., CLHEP::twopi);
  G4LogicalVolume* fLogicdetTube =
      new G4LogicalVolume(DetTube,          // its solid
                          CFK,              // its material
                          "detTubeShell");  // its name
  G4LogicalVolume* fLogicdetCone =
      new G4LogicalVolume(DetCone,          // its solid
                          CFK,              // its material
                          "detConeShell");  // its name
  G4LogicalVolume* fLogicdetWindow =
      new G4LogicalVolume(DetWindow,     // its solid
                          CFK,           // its material
                          "detWindow");  // its name

  /////////////C. Fiber around and below the PM//////////////////////////
  G4Tubs* PMTube =
      new G4Tubs("PMTube", R2min, R2max, PMTube_dZ, 0., CLHEP::twopi);
  G4Tubs* PMAdapt1 =
      new G4Tubs("PMAdapt1", R3min, R3max, PMAdapt1_dZ, 0., CLHEP::twopi);
  G4Tubs* PMAdapt2 =
      new G4Tubs("PMAdapt2", R4min, R4max, PMAdapt2_dZ, 0., CLHEP::twopi);
  G4Tubs* DetBase1 =
      new G4Tubs("DetBase1", R2min, R_base, DetBase1_dZ, 0., CLHEP::twopi);
  G4Tubs* DetBase2 =
      new G4Tubs("DetBase2", 0., R_base, DetBase2_dZ, 0., CLHEP::twopi);

  G4RotationMatrix rotmDetBase = G4RotationMatrix(0, 0, 0);
  G4ThreeVector transDetBase =
      G4ThreeVector(0, 0, -(DetBase1_dZ + DetBase2_dZ));
  G4Transform3D transformDetBase = G4Transform3D(rotmDetBase, transDetBase);
  G4UnionSolid* DetBase =
      new G4UnionSolid("DetBase", DetBase1, DetBase2, transformDetBase);

  G4LogicalVolume* fLogicPMTube =
      new G4LogicalVolume(PMTube,          // its solid
                          CFK,             // its material
                          "PMTubeShell");  // its name

  G4LogicalVolume* fLogicPMAdapt1 =
      new G4LogicalVolume(PMAdapt1,          // its solid
                          CFK,               // its material
                          "PMAdapt1Shell");  // its name

  G4LogicalVolume* fLogicPMAdapt2 =
      new G4LogicalVolume(PMAdapt2,          // its solid
                          CFK,               // its material
                          "PMAdapt2Shell");  // its name

  G4LogicalVolume* fLogicDetBase = new G4LogicalVolume(DetBase,  // its solid
                                                       CFK,      // its material
                                                       "DetBase");  // its name

  /////////////////////PM///////////////////////////////////////////////
  G4double R_PMS1max =
      R4min;  // dimensions of the insulating sleeve  (PMshield1=PMS1)
  G4double R_PMS1min = 25.75 * mm;
  G4double PMS1_thick = R_PMS1max - R_PMS1min;
  G4double R_PMW = 52.0 * mm;  // Radius of the esphere containing hemispherical
                               // window of the PMT (9829QSB)
  G4double PMW_thick = 0.8 * mm;  // Thickness of the PMwindow
  G4double d_theta = asin(
      R_PMS1min /
      R_PMW);  // starting angle (s) and range (d) of spher. section (PMwindow)
  G4double s_theta = 0;
  G4double PMS1_dZ = 63 * mm - 0.5 * R_PMW * (1 - cos(d_theta));
  G4double R_PMS2max = 25.75 * mm;
  G4double R_PMS2min = 23.60 * mm;
  G4double PMS2_thick = R_PMS2max - R_PMS2min;
  G4double deltaZ = PMW_thick * cos(d_theta);  //=1,736mm
  G4double PMS2_dZ =
      PMS1_dZ - 0.5 * PMS1_thick -
      0.5 * deltaZ;  // length of the second PM Layer (below insulation)
  G4double PMW2_thick =
      2.0 * mm;  // Thickness of the extra window (on the PMWindow)
  G4double R_PMW2 =
      R_PMW + PMW2_thick;  // Radius of sphere containing the extra PM Window
  G4double d_theta2 = asin(R_PMS1max / R_PMW2);
  G4double PMContent_dZ =
      PMS2_dZ - 0.5 * (PMS2_thick) +
      0.00045;  // Dimensions of the volume inside the PM outer layers
  G4double R_PMContent = R_PMS2min;
  G4double PMIntersection_dZ =
      0.5 * (R_PMW * (1 - cos(d_theta)) + deltaZ);  //=3.278*mm
  G4double PMIntersection_pos =
      52.0 * mm - 0.5 * (R_PMW * (1 - cos(d_theta)) + deltaZ);
  G4double PMSupportRing_dZ = 25 * mm;
  G4double VoltageDiv1_dZ = 15 * mm;
  G4double VoltageDiv2_dZ = 10 * mm;

  ////////////PM outter glass, shieldings, Voltage divider , supporting
  /// ring//////////////
  G4Tubs* PMS1Tube =
      new G4Tubs("PMS1Tube", R_PMS1min, R_PMS1max, PMS1_dZ, 0., CLHEP::twopi);
  G4Tubs* PMS1Bottom = new G4Tubs("PMS1Bottom", 0, R_PMS1min, 0.5 * PMS1_thick,
                                  0., CLHEP::twopi);
  G4Tubs* PMS2Tube =
      new G4Tubs("PMS2Tube", R_PMS2min, R_PMS2max, PMS2_dZ, 0., CLHEP::twopi);
  G4Tubs* PMS2Bottom = new G4Tubs("PMS2Bottom", 0, R_PMS2min, 0.5 * PMS2_thick,
                                  0., CLHEP::twopi);
  G4Tubs* PMSupportRing = new G4Tubs("PMSupportRing", R_PMS1max, R2min,
                                     PMSupportRing_dZ, 0., CLHEP::twopi);
  G4Tubs* VoltageDivTube1 =
      new G4Tubs("VoltageDivTube1", 0, R2min, VoltageDiv1_dZ, 0., CLHEP::twopi);
  G4Tubs* VoltageDivTube2 = new G4Tubs("VoltageDivTube2", 0, 12.5 * mm,
                                       VoltageDiv2_dZ, 0., CLHEP::twopi);
  G4Tubs* VoltageDivVol1 =
      new G4Tubs("VoltageDivVol1", 0, R2min - 2 * mm, VoltageDiv1_dZ - 2 * mm,
                 0., CLHEP::twopi);
  G4Tubs* VoltageDivVol2 =
      new G4Tubs("VoltageDivVol2", 0, 10.5 * mm, VoltageDiv2_dZ - 1 * mm, 0.,
                 CLHEP::twopi);

  G4SubtractionSolid* VoltageDiv1 =
      new G4SubtractionSolid("VoltageDiv1", VoltageDivTube1, VoltageDivVol1);
  G4RotationMatrix rotmVD = G4RotationMatrix(0, 0, 0);
  G4ThreeVector transVD = G4ThreeVector(0, 0, 1 * mm);
  G4Transform3D TransformVD = G4Transform3D(rotmVD, transVD);
  G4SubtractionSolid* VoltageDiv2 = new G4SubtractionSolid(
      "VoltageDiv2", VoltageDivTube2, VoltageDivVol2, TransformVD);
  G4RotationMatrix rotmVD2 = G4RotationMatrix(0, 0, 0);
  G4ThreeVector transVD2 = G4ThreeVector(0, 0, -20 * mm);
  G4Transform3D TransformVD2 = G4Transform3D(rotmVD2, transVD2);
  G4UnionSolid* VoltageDiv =
      new G4UnionSolid("VoltageDiv", VoltageDiv1, VoltageDiv2, TransformVD2);

  G4LogicalVolume* fLogicPMS1Tube =
      new G4LogicalVolume(PMS1Tube,     // its solid
                          Mumetal,      // its material
                          "PMS1Tube");  // its name
  G4LogicalVolume* fLogicPMS1Bottom =
      new G4LogicalVolume(PMS1Bottom,     // its solid
                          Mumetal,        // its material
                          "PMS1Bottom");  // its name
  G4LogicalVolume* fLogicPMS2Tube =
      new G4LogicalVolume(PMS2Tube,     // its solid
                          glass_lessB,  // its material
                          "PMS2Tube");  // its name
  G4LogicalVolume* fLogicPMS2Bottom =
      new G4LogicalVolume(PMS2Bottom,     // its solid
                          glass_lessB,    // its material
                          "PMS2Bottom");  // its name

  G4LogicalVolume* fLogicSuppRing =
      new G4LogicalVolume(PMSupportRing,  // its solid
                          PVC,            // its material
                          "SuppRing");    // its name
  G4LogicalVolume* fLogicVoltageDiv =
      new G4LogicalVolume(VoltageDiv,     // its solid
                          PP,             // its material
                          "VoltageDiv");  // its name

  ////////////////////////////PM Content: Empty space within the quarz vessel of
  /// the PM////////
  G4Tubs* PMIntersectionTube = new G4Tubs("PMIntersectionTube", 0, R_PMS1min,
                                          PMIntersection_dZ, 0., CLHEP::twopi);
  G4Tubs* PMContentTube = new G4Tubs("PMContentTube", 0, R_PMContent,
                                     PMContent_dZ, 0., CLHEP::twopi);
  G4Sphere* PMIntersectionSphere = new G4Sphere(
      "PMIntersectionSphere", 0., R_PMW - PMW_thick, 0, CLHEP::twopi,
      s_theta,   // starting theta
      d_theta);  // theta amplitud

  G4RotationMatrix rotmPMContent = G4RotationMatrix(0, 0, 0);
  G4ThreeVector transPMContent = G4ThreeVector(0, 0, PMIntersection_pos);
  G4Transform3D transformPMContent =
      G4Transform3D(rotmPMContent, transPMContent);
  G4IntersectionSolid* PMIntersectionWindow =
      new G4IntersectionSolid("PMIntersectionWindow", PMIntersectionSphere,
                              PMIntersectionTube, transformPMContent);

  G4double PMContent2_pos =
      -PMS2_dZ + 0.5 * PMS2_thick + (R_PMW * cos(d_theta) - deltaZ + 0.00045);
  G4RotationMatrix rotmPMContent2 = G4RotationMatrix(0, 0, 0);
  G4ThreeVector transPMContent2 = G4ThreeVector(0, 0, PMContent2_pos);
  G4Transform3D transformPMContent2 =
      G4Transform3D(rotmPMContent2, transPMContent2);
  G4UnionSolid* PMContent = new G4UnionSolid(
      "PMContent", PMIntersectionWindow, PMContentTube, transformPMContent2);
  G4LogicalVolume* fLogicPMContent =
      new G4LogicalVolume(PMContent,     // its solid
                          vacuum,        // its material
                          "PMContent");  // its name

  //////////PMWindows///////////////////////////////
  // Window coming with the PM
  G4Sphere* PMW = new G4Sphere("PMW", R_PMW - PMW_thick, R_PMW, 0, CLHEP::twopi,
                               s_theta,   // starting theta
                               d_theta);  // theta amplitude
  // Security quartz window (glued to the inner carbon fiber shells)
  G4Sphere* PMW2Sph =
      new G4Sphere("PMW2Sph", R_PMW2 - PMW2_thick, R_PMW2, 0, CLHEP::twopi,
                   s_theta,    // starting theta
                   d_theta2);  // theta amplitude

  G4double PMW2Tube_dZ = detCone_dZ;
  G4double PMW2Tube_pos = (detCone_dZ + R_PMW * cos(d_theta));
  G4Tubs* PMW2Tube =
      new G4Tubs("PMW2Tube", 0, R_PMS1max, PMW2Tube_dZ, 0., CLHEP::twopi);

  G4RotationMatrix rotmPMW2 = G4RotationMatrix(0, 0, 0);
  G4ThreeVector transPMW2 = G4ThreeVector(0, 0, PMW2Tube_pos);
  G4Transform3D TransformPMW2 = G4Transform3D(rotmPMW2, transPMW2);
  G4IntersectionSolid* PMW2 =
      new G4IntersectionSolid("PMW2", PMW2Sph, PMW2Tube, TransformPMW2);

  G4LogicalVolume* fLogicPMWindow = new G4LogicalVolume(PMW,     // its solid
                                                        quartz,  // its material
                                                        "PMW");  // its name

  G4LogicalVolume* fLogicPMWindow2 =
      new G4LogicalVolume(PMW2,     // its solid
                          quartz,   // its material
                          "PMW2");  // its name

  ///////////////////////////////// C6D6 Volume///////////////////////////
  G4double C6D6_dZ = (detTube_dZ - 0.5 * mm) + detCone_dZ;
  G4double CFAdapt_dZ = 0.5 * 20 * mm;
  G4double R_CFAdaptmin = 3.5 * mm;

  G4Tubs* C6D6Tube =
      new G4Tubs("C6D6Tube", 0, R1min, detTube_dZ - 0.5 * mm, 0., CLHEP::twopi);
  G4Cons* C6D6Cone =
      new G4Cons("C6D6Cone", 0, R2min, 0, R1min, detCone_dZ, 0., CLHEP::twopi);

  G4RotationMatrix rotmC6D6 = G4RotationMatrix(0, 0, 0);
  G4ThreeVector transC6D6 = G4ThreeVector(0, 0, -1 * C6D6_dZ);
  G4Transform3D transformC6D6 = G4Transform3D(rotmC6D6, transC6D6);
  G4UnionSolid* C6D6Sol =
      new G4UnionSolid("C6D6Sol", C6D6Tube, C6D6Cone, transformC6D6);  // 6

  // Give the C6D6 detection Volume the hemispherical shape to fit the quarz
  // window (PMW2)
  G4Sphere* C6D6Sphere =
      new G4Sphere("C6D6Sphere", 0., R_PMW2 + 0.0007365 * mm, 0, CLHEP::twopi,
                   s_theta,     // starting theta
                   CLHEP::pi);  // theta amplitude

  //  G4double C6D6Tube_dZ=detCone_dZ;
  G4double C6D6Tube_pos = (detCone_dZ + R_PMW * cos(d_theta));
  // G4Tubs*  C6D6IntTube = new G4Tubs ("C6D6IntTube", 0,R_PMS1max,
  // C6D6Tube_dZ,0.,CLHEP::twopi);

  G4RotationMatrix rotmC6D6_2 = G4RotationMatrix(0, 0, 0);
  G4ThreeVector transC6D6_2 = G4ThreeVector(0, 0, C6D6Tube_pos);
  G4Transform3D TransformC6D6_2 = G4Transform3D(rotmC6D6_2, transC6D6_2);
  //  G4IntersectionSolid* C6D6Sol2 =new G4IntersectionSolid
  //  ("C6D6Sol2",C6D6Sphere,C6D6IntTube, TransformC6D6_2);

  G4double C6D6Sphere_pos =
      -((detTube_dZ - 0.5 * mm) + 2 * detCone_dZ + R_PMW * cos(d_theta));

  G4RotationMatrix rotmC6D6_3 = G4RotationMatrix(0, 0, 0);
  G4ThreeVector transC6D6_3 = G4ThreeVector(0, 0, C6D6Sphere_pos);
  G4Transform3D transformC6D6_3 = G4Transform3D(rotmC6D6_3, transC6D6_3);
  G4SubtractionSolid* C6D6IntSolid = new G4SubtractionSolid(
      "C6D6IntSolid", C6D6Sol, C6D6Sphere, transformC6D6_3);

  G4Tubs* C6D6CFAdapt =
      new G4Tubs("C6D6CFAdapt", 0., R_CFAdaptmin, CFAdapt_dZ, 0., CLHEP::twopi);
  G4RotationMatrix rotmC6D6_4 = G4RotationMatrix(0, -90 * deg, 90 * deg);
  G4ThreeVector transC6D6_4 =
      G4ThreeVector(R1min + CFAdapt_dZ, 0, 180.5 * mm - 134.0 * mm - 60 * mm);
  G4Transform3D transformC6D6_4 = G4Transform3D(rotmC6D6_4, transC6D6_4);
  G4UnionSolid* C6D6Solid =
      new G4UnionSolid("C6D6Solid", C6D6IntSolid, C6D6CFAdapt, transformC6D6_4);

  LfLogicC6D6 = new G4LogicalVolume(C6D6Solid,   // its solid
                                    C6D6,        // its material
                                    "C6D6Vol");  // its name

  G4double VolumeinC6D6 = C6D6Solid->GetCubicVolume();
  // G4cout<<"Volume of C6D6 in one detector"<<0.000001*VolumeinC6D6<<" in
  // Litres"<<G4endl; G4cout<<"Volume of C6D6Expansion in one
  // detector"<<0.000001*VolumeinC6D6ExpasionVol<<" in Litres"<<G4endl;
  G4cout << "Volume of C6D6 " << 0.000001 * VolumeinC6D6 << " Litres" << G4endl;

  G4double expVol_dZ = 0.5 * 76.0 * mm;
  // G4double detVol_dZ=detTube_dZ+detCone_dZ+PMTube_dZ+ expVol_dZ;
  G4double CFHolderShift = 8. * cm;  // s
  G4double detVol_dZ =
      0.5 * (144.5 * mm + 181 * mm) + expVol_dZ + CFHolderShift;

  /////////////////////////////////Individual CF
  /// support///////////////////////////////////////
  G4RotationMatrix rotm1 =
      G4RotationMatrix(0, 0, 0);  // it will be used again later
  G4double halfLengthZCFHolderBar = 19.5 * cm;
  G4double halfLengthXCFHolderBar = 1.0 * cm;
  G4double halfLengthYCFHolderBar = 0.5 * cm;
  G4double halfLengthZCFHolderBottom = 5.0 * cm;
  G4double halfLengthXCFHolderBottom = 5.0 * cm;
  G4double halfLengthYCFHolderBottom = 0.25 * cm;
  //  G4double halfLengthZCFHolderRing= 0.5*cm;
  G4double minRadiusCFHolderRing = 30.75 * mm;
  //  G4double maxRadiusCFHolderRing =minRadiusCFHolderRing+10*mm;
  G4double halfLengthZCFHolderWallPlate = 0.5 * cm;
  G4double halfLengthXCFHolderWallPlate = 5.0 * cm;
  G4double halfLengthYCFHolderWallPlate =
      0.5 * (3.5 * cm + 2 * minRadiusCFHolderRing + 1 * cm);
  G4double halfLengthZHolderRing = 1.0 * cm;
  double distanceHolder2detector = 30.75 * mm + 1 * mm + 3.3 * cm +
                                   2 * halfLengthYCFHolderBottom +
                                   halfLengthYCFHolderBar;

  // Long bar connecting the vertical bars and the support
  G4Box* solidCFHolderBar =
      new G4Box("CFHolderBar", halfLengthXCFHolderBar, halfLengthYCFHolderBar,
                halfLengthZCFHolderBar);
  // Side walls were the detector rest x2
  G4Box* solidCFHolderWallPlate =
      new G4Box("CFHolderWallPlate", halfLengthXCFHolderWallPlate,
                halfLengthYCFHolderWallPlate, halfLengthZCFHolderWallPlate);
  // Bottom of the support on top of the bar
  G4Box* solidCFHolderBottom =
      new G4Box("CFHolderBottom", halfLengthXCFHolderBottom,
                halfLengthYCFHolderBottom, halfLengthZCFHolderBottom);
  // Rings surrounding the detector PMT (L6D6):
  G4Tubs* solidCFFullRing =
      new G4Tubs("CFHolderFullRing", 0, minRadiusCFHolderRing + 1 * mm,
                 halfLengthZHolderRing + 2 * mm, 0. * deg, 360. * deg);
  // Making a hole in the walls to fit the rings
  G4Transform3D transCFHolderWall =
      G4Transform3D(rotm1, G4ThreeVector(0, +0.5 * (3.3 * cm - 1 * cm), 0));

  G4SubtractionSolid* CFHolderRingWall =
      new G4SubtractionSolid("CFHolderRingWall", solidCFHolderWallPlate,
                             solidCFFullRing, transCFHolderWall);

  G4Transform3D transCFHolder1 =
      G4Transform3D(rotm1, G4ThreeVector(0, 0,
                                         -2 * halfLengthZCFHolderBottom +
                                             2 * halfLengthZCFHolderWallPlate));
  G4UnionSolid* CFHolder1 = new G4UnionSolid("CFHolder1", CFHolderRingWall,
                                             CFHolderRingWall, transCFHolder1);

  // Bar + Plate: CFHolder2
  G4Transform3D transCFHolder2 = G4Transform3D(
      rotm1,
      G4ThreeVector(0, halfLengthYCFHolderBottom + halfLengthYCFHolderBar,
                    +halfLengthZCFHolderBar - halfLengthZCFHolderBottom));

  G4UnionSolid* CFHolder2 = new G4UnionSolid(
      "CFHolder2 ", solidCFHolderBar, solidCFHolderBottom, transCFHolder2);

  // Ring Walls + BarPlate --> FullCFHolder
  G4Transform3D transCFFullCFHolder = G4Transform3D(
      rotm1,
      G4ThreeVector(0,
                    2 * halfLengthYCFHolderBottom + halfLengthYCFHolderBar +
                        halfLengthYCFHolderWallPlate,
                    +halfLengthZCFHolderBar - halfLengthZCFHolderWallPlate));

  G4UnionSolid* CFHolder =
      new G4UnionSolid("CFHolder ", CFHolder2, CFHolder1, transCFFullCFHolder);

  G4LogicalVolume* logicCFHolder =
      new G4LogicalVolume(CFHolder, Cfiber, "CFHolder");
  logicCFHolder->SetVisAttributes(new G4VisAttributes(G4Colour::Blue()));

  G4double CFHolder2DetectorWindow =
      halfLengthZCFHolderBar + 9.2 * cm + 2.8 * cm + 5. * cm;
  G4Transform3D TransformCFHolder =
      G4Transform3D(G4RotationMatrix(0, 0, +90 * deg),
                    G4ThreeVector(-distanceHolder2detector, 0,
                                  -CFHolder2DetectorWindow + detVol_dZ));

  ////////////////////////////////DETECTOR VACUUM MOTHER
  /// LOGIC/////////////////////////////////
  G4Box* solidDetVol =
      new G4Box("detVol", 152.5 * mm, R1max + 0.001 * mm, detVol_dZ);

  G4Box* subtractionBox =
      new G4Box("SubtractionBox", 160 * mm, R1max + 1 * mm, detVol_dZ + 1 * mm);

  G4ThreeVector subtractionPosition0(-24 * cm, 0 * cm, 0);
  G4RotationMatrix* rotation = nullptr;

  G4SubtractionSolid* solidDetVolSubtracted0 =
      new G4SubtractionSolid("ModifiedBox0", solidDetVol, subtractionBox,
                             rotation, subtractionPosition0);

  G4Box* subtractionBox1 =
      new G4Box("SubtractionBox1", 160 * mm, R1max + 1 * mm, detVol_dZ);
  G4ThreeVector subtractionPosition(24 * cm, 0 * cm, 51 * cm);

  G4SubtractionSolid* solidDetVolSubtracted1 =
      new G4SubtractionSolid("ModifiedBox", solidDetVolSubtracted0,
                             subtractionBox1, rotation, subtractionPosition);

  G4Box* subtractionBox2 = new G4Box("SubtractionBox2", 160 * mm,
                                     R1max + 1 * mm, (detVol_dZ / 2) + 5 * cm);
  G4ThreeVector subtractionPosition2(28.5 * cm, 0 * cm, 20 * cm);
  G4SubtractionSolid* solidDetVolSubtracted2 =
      new G4SubtractionSolid("ModifiedBox", solidDetVolSubtracted1,
                             subtractionBox2, rotation, subtractionPosition2);

  G4Tubs* subtractionBox3 =
      new G4Tubs("SubtractionBox3", R1max + 0.1 * mm, R1max + 50 * cm, 5 * cm,
                 0., CLHEP::twopi);
  G4ThreeVector subtractionPosition3(0, 0 * cm, 28 * cm);
  G4SubtractionSolid* solidDetVolSubtracted3 =
      new G4SubtractionSolid("ModifiedBox", solidDetVolSubtracted2,
                             subtractionBox3, rotation, subtractionPosition3);

  G4Box* subtractionBox4 = new G4Box("SubtractionBox4", 160 * mm,
                                     R1max + 1 * mm, detVol_dZ - 15 * cm);
  G4ThreeVector subtractionPosition4(22 * cm, 7.5 * cm, +15 * cm);
  G4SubtractionSolid* solidDetVolSubtracted4 =
      new G4SubtractionSolid("ModifiedBox", solidDetVolSubtracted3,
                             subtractionBox4, rotation, subtractionPosition4);

  G4ThreeVector subtractionPosition5(22 * cm, -7.5 * cm, +15 * cm);
  G4SubtractionSolid* solidDetVolSubtracted5 =
      new G4SubtractionSolid("ModifiedBox", solidDetVolSubtracted4,
                             subtractionBox4, rotation, subtractionPosition5);
  ////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////
  G4Box* subtractionBox6 =
      new G4Box("SubtractionBox6", 160 * mm, R1max + 1 * mm, detVol_dZ);
  G4ThreeVector subtractionPosition6(-15 * cm, -7.5 * cm, -40 * cm);
  G4SubtractionSolid* solidDetVolSubtracted6 =
      new G4SubtractionSolid("ModifiedBox", solidDetVolSubtracted5,
                             subtractionBox6, rotation, subtractionPosition6);

  G4ThreeVector subtractionPosition7(-15 * cm, +7.5 * cm, -40 * cm);
  G4SubtractionSolid* solidDetVolSubtracted =
      new G4SubtractionSolid("ModifiedBox", solidDetVolSubtracted6,
                             subtractionBox6, rotation, subtractionPosition7);

  G4LogicalVolume* logicDetVol =
      new G4LogicalVolume(solidDetVolSubtracted,  // its solid
                          vacuum,                 // its material
                          "detVol");              // its name
  logicDetVol->SetVisAttributes(G4VisAttributes::GetInvisible());
  // logicDetVol->SetVisAttributes(G4Color::Green());

  /////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////PLACEMENT
  /// DETECTORS///////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////
  ////////////

  G4RotationMatrix rotL6D6[50];
  G4double rL6D6[50];
  G4ThreeVector posL6D6[50];
  // G4VPhysicalVolume* physiCFHolderL6D6[50];
  // G4VPhysicalVolume *physiL6D6[50];

  char name[1000];

  for (int i = 1; i < (theInputManager->GetTotalNC6D6Detectors() + 1); i++) {
    if (flagL6D6[i] == 2) {
      G4cout << "Build L6D6_" << i << " thetaL6D6= " << thetaL6D6[i]
             << " phiL6D6z= " << phiL6D6[i] << " z= " << zL6D6[i] << G4endl;
      rotL6D6[i] = G4RotationMatrix();
      rotL6D6[i].rotateY(thetaL6D6[i] * deg);
      rotL6D6[i].rotateZ(phiL6D6[i] * deg);
      rL6D6[i] = detVol_dZ + zL6D6[i] * cm;
      posL6D6[i] = G4ThreeVector(
          -rL6D6[i] * sin(thetaL6D6[i] * deg) * cos(phiL6D6[i] * deg),
          -rL6D6[i] * sin(thetaL6D6[i] * deg) * sin(phiL6D6[i] * deg),
          -rL6D6[i] * cos(thetaL6D6[i] * deg));
      sprintf(name, "L6D6_%d", i);
      //      physiL6D6[i] =
      new G4PVPlacement(G4Transform3D(rotL6D6[i], posL6D6[i]),
                        logicDetVol,  // its logical volume
                        name,
                        mother,  // its
                        false,   // no boolean operation
                        i,       // copy number
                        flagOverlaps);
      // sprintf(name, "CFHolderL6D6_%d", i);

      // //      physiCFHolderL6D6[i] =
      // new G4PVPlacement(TransformCFHolder, logicCFHolder, name, logicDetVol,
      //                   false, i, flagOverlaps);
    }
  }
  // Modify by Valcayne to not have overlaps in the volumes.
  sprintf(name, "CFHolderL6D6");
  //      physiCFHolderL6D6[i] =
  new G4PVPlacement(TransformCFHolder, logicCFHolder, name, logicDetVol, false,
                    0, flagOverlaps);
  /////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////PLACEMENT
  /// COMPONENTS///////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////
  G4double R_tubeAdaptmax = 7 * mm;
  G4double R_tubeAdaptmin = 5 * mm;
  G4double tubeAdapt_dZ = 0.5 * 12.75 * mm;
  G4double R_CFAdaptmax = R_tubeAdaptmin;
  G4double R_tubemax = 4 * mm;
  G4double R_tubemin = 3 * mm;
  G4double tube1_dZ = 0.5 * 16 * mm;
  G4double coneAdapt_dZ = 0.5 * 8 * mm;
  // thorus for the curve of the Al tube
  G4double s_theta_torus = 0.;
  G4double d_theta_torus = 0.5 * CLHEP::pi;
  G4double R_torusmin = R_tubemin;
  G4double R_torusmax = R_tubemax;
  G4double R_torusCenter = 16 * mm;
  G4double tube2_dZ =
      0.5 * (2 * R_tubemax + 28 * mm - (R_torusCenter + R_torusmax) +
             2 * detCone_dZ + 2 * PMTube_dZ);
  // dimensions of the expansion Volume cilindert
  G4double R_expVolmax = 32.5 * mm;
  G4double R_expVolmin = 30.5 * mm;
  G4double expVol_thick = R_expVolmax - R_expVolmin;

  G4double support_dX = 0.5 * 88.75 * mm;
  G4double support_dY = 32.5 * mm;
  G4double support_dZ = 1 * mm;

  /////////CARBON FIBER PIPE ADAPTOR & Exp Vol
  /// SUPPORT//////////////////////////
  // Carbon fiber Support of the expansion Volume
  G4Box* supportBox =
      new G4Box("supportBox", support_dX, support_dY, support_dZ);
  G4Tubs* supportTube = new G4Tubs("supportTube", 0., support_dY, support_dZ,
                                   1.5 * CLHEP::pi, CLHEP::pi);
  G4Tubs* Hole =
      new G4Tubs("Hole", 0., R_tubemax, support_dZ, 0., CLHEP::twopi);
  G4RotationMatrix rotmSupp = G4RotationMatrix(0, 0, 0);
  G4ThreeVector transSupp = G4ThreeVector(-support_dX + 0.5 * mm, 0, 0);
  G4Transform3D transformSupp = G4Transform3D(rotmSupp, transSupp);
  G4UnionSolid* support =
      new G4UnionSolid("support", supportTube, supportBox, transformSupp);
  // ensambled and w/ a hole for the Al Tube
  G4SubtractionSolid* supportHoled =
      new G4SubtractionSolid("supportHoled", support, Hole);
  G4LogicalVolume* fLogicSupportHoled =
      new G4LogicalVolume(supportHoled,  // its solid
                          CFK,           // its material
                          "supportHoled");
  // carbon fiber adaptor from the detection volume to the Al expansion tube
  G4Tubs* CFAdapt = new G4Tubs("CFAdapt", R_CFAdaptmin, R_CFAdaptmax,
                               CFAdapt_dZ, 0., CLHEP::twopi);
  G4LogicalVolume* fLogicCFAdapt = new G4LogicalVolume(CFAdapt,  // its solid
                                                       CFK,      // its material
                                                       "CFAdapt");

  ////////////////ALUMINUM TUBE///////////////////////////
  // Conical part of the tube
  G4Tubs* tubeAdapt = new G4Tubs("tubeAdapt", R_tubeAdaptmin, R_tubeAdaptmax,
                                 tubeAdapt_dZ, 0., CLHEP::twopi);
  G4Cons* coneAdapt =
      new G4Cons("coneAdapt", R_tubeAdaptmin, R_tubeAdaptmax, R_tubemin,
                 R_tubemax, coneAdapt_dZ, 0., CLHEP::twopi);
  G4RotationMatrix rotmAdapt = G4RotationMatrix(0, 0, 0);
  G4ThreeVector transAdapt = G4ThreeVector(0, 0, coneAdapt_dZ + tubeAdapt_dZ);
  G4Transform3D transformAdapt = G4Transform3D(rotmAdapt, transAdapt);
  G4UnionSolid* Adapt =
      new G4UnionSolid("Adapt", tubeAdapt, coneAdapt, transformAdapt);
  // tube1: short, perpendicular to detector longitudinal(z) axis, tube 2:long
  // parallel to z axis
  G4Tubs* tube1 =
      new G4Tubs("tube1", R_tubemin, R_tubemax, tube1_dZ, 0., CLHEP::twopi);
  G4Tubs* tube2 =
      new G4Tubs("tube2", R_tubemin, R_tubemax, tube2_dZ, 0., CLHEP::twopi);
  G4Torus* torus = new G4Torus("torus ", R_torusmin, R_torusmax, R_torusCenter,
                               s_theta_torus, d_theta_torus);
  G4RotationMatrix rotmTube1 = G4RotationMatrix(0, -90 * deg, 90 * deg);
  G4ThreeVector transTube1 =
      G4ThreeVector(-(R_torusCenter + tube1_dZ), 0, R_torusCenter + tube2_dZ);
  G4Transform3D transformTube1 = G4Transform3D(rotmTube1, transTube1);
  G4UnionSolid* tube1tube2 =
      new G4UnionSolid("tube1tube2", tube2, tube1, transformTube1);
  G4RotationMatrix rotmTube2 = G4RotationMatrix(0 * deg, -90 * deg, 0 * deg);
  G4ThreeVector transTube2 = G4ThreeVector(-R_torusCenter, 0, tube2_dZ);
  G4Transform3D transformTube2 = G4Transform3D(rotmTube2, transTube2);
  G4UnionSolid* AlTube =
      new G4UnionSolid("AlTube", tube1tube2, torus, transformTube2);
  G4RotationMatrix rotmTube3 = G4RotationMatrix(0, +90 * deg, 90 * deg);
  G4ThreeVector transTube3 = G4ThreeVector(
      -(R_torusCenter + 2 * tube1_dZ + 2 * coneAdapt_dZ + tubeAdapt_dZ), 0,
      tube2_dZ + R_torusCenter);
  G4Transform3D transformTube3 = G4Transform3D(rotmTube3, transTube3);
  // ensambled Al tube
  G4UnionSolid* AluminiumTube =
      new G4UnionSolid("AluminiumTube", AlTube, Adapt, transformTube3);
  G4LogicalVolume* fLogicAluminiumTube =
      new G4LogicalVolume(AluminiumTube,     // its solid
                          Al,                // its material
                          "AluminiumTube");  // its name

  ////////////////////EXPANSION CILINDER
  /// VOLUME///////////////////////////////////
  G4Tubs* expVolShell = new G4Tubs("expVolShell", R_expVolmin, R_expVolmax,
                                   expVol_dZ, 0., CLHEP::twopi);
  G4Tubs* expVolTop = new G4Tubs("expVolTop", 0., R_expVolmin,
                                 0.5 * expVol_thick, 0., CLHEP::twopi);
  G4RotationMatrix rotmexpVol2 = G4RotationMatrix(0, 0, 0);
  G4ThreeVector transexpVol2 = G4ThreeVector(0, 0, -expVol_dZ + 1 * mm);
  G4Transform3D transformexpVol2 = G4Transform3D(rotmexpVol2, transexpVol2);
  // Ensambled cilinder
  G4UnionSolid* expVol =
      new G4UnionSolid("expVol", expVolShell, expVolTop, transformexpVol2);
  G4LogicalVolume* fLogicExpVol = new G4LogicalVolume(expVol,  // its solid
                                                      CFK,     // its material
                                                      "expVol");  // its name
  //// C6D6 Expansion Volume: Filling the expansion
  /// tube//////////////////////////////////
  G4double C6D6Adapt_dZ = 0.5 * (12.75 * mm - 8 * mm);
  //  G4double C6D6CFAdapt_dZ=0.5*20*mm;
  G4Tubs* C6D6tubeAdapt = new G4Tubs("C6D6tubeAdapt", 0, R_tubeAdaptmin,
                                     C6D6Adapt_dZ, 0., CLHEP::twopi);
  G4Cons* C6D6coneAdapt = new G4Cons("C6D6coneAdapt", 0, R_tubeAdaptmin, 0,
                                     R_tubemin, coneAdapt_dZ, 0., CLHEP::twopi);
  G4RotationMatrix rotmC6D6Adapt = G4RotationMatrix(0, 0, 0);
  G4ThreeVector transC6D6Adapt =
      G4ThreeVector(0, 0, coneAdapt_dZ + C6D6Adapt_dZ);
  G4Transform3D transformC6D6Adapt =
      G4Transform3D(rotmC6D6Adapt, transC6D6Adapt);
  G4UnionSolid* AdaptC6D6 = new G4UnionSolid("AdapC6D6t", C6D6tubeAdapt,
                                             C6D6coneAdapt, transformC6D6Adapt);
  G4Tubs* tubeC6D61 =
      new G4Tubs("tubeC6D61", 0, R_tubemin, tube1_dZ, 0., CLHEP::twopi);
  G4Tubs* tubeC6D62 =
      new G4Tubs("tubeC6D62", 0, R_tubemin, tube2_dZ, 0., CLHEP::twopi);
  G4Torus* torusC6D6 = new G4Torus("torusC6D6 ", 0, R_torusmin, R_torusCenter,
                                   s_theta_torus, d_theta_torus);
  G4RotationMatrix rotmTubeC6D61 = G4RotationMatrix(0, -90 * deg, 90 * deg);
  G4ThreeVector transTubeC6D61 =
      G4ThreeVector(-(R_torusCenter + tube1_dZ), 0, R_torusCenter + tube2_dZ);
  G4Transform3D transformTubeC6D61 = G4Transform3D(rotmTube1, transTube1);
  G4UnionSolid* tube1tube2C6D6 = new G4UnionSolid(
      "tube1tube2C6D6", tubeC6D62, tubeC6D61, transformTubeC6D61);
  G4RotationMatrix rotmTubeC6D62 =
      G4RotationMatrix(0 * deg, -90 * deg, 0 * deg);
  G4ThreeVector transTubeC6D62 = G4ThreeVector(-R_torusCenter, 0, tube2_dZ);
  G4Transform3D transformTubeC6D62 =
      G4Transform3D(rotmTubeC6D62, transTubeC6D62);
  G4UnionSolid* TubeC6D61 = new G4UnionSolid("TubeC6D61", tube1tube2C6D6,
                                             torusC6D6, transformTubeC6D62);
  G4RotationMatrix rotmTubeC6D63 = G4RotationMatrix(0, +90 * deg, 90 * deg);
  G4ThreeVector transTubeC6D63 = G4ThreeVector(
      -(R_torusCenter + 2 * tube1_dZ + 2 * coneAdapt_dZ + C6D6Adapt_dZ), 0,
      tube2_dZ + R_torusCenter);
  G4Transform3D transformTubeC6D63 =
      G4Transform3D(rotmTubeC6D63, transTubeC6D63);
  G4UnionSolid* C6D6ExpTube =
      new G4UnionSolid("C6D6ExpTube", TubeC6D61, AdaptC6D6, transformTubeC6D63);
  G4LogicalVolume* fLogicC6D6ExpTube =
      new G4LogicalVolume(C6D6ExpTube,     // its solid
                          C6D6,            // its material
                          "C6D6ExpTube");  // its name
  G4Tubs* expVolC6D6 = new G4Tubs("expVolC6D6", 0, R_expVolmin,
                                  expVol_dZ - expVol_thick, 0., CLHEP::twopi);
  G4LogicalVolume* fLogicExpVolC6D6 =
      new G4LogicalVolume(expVolC6D6,     // its solid
                          C6D6,           // its material
                          "expVolC6D6");  // its name

  //////////////////////////////////////////////////////////////////////////////////////////////
  /////////////// place detector logic part-->> empty mother
  /// volume/////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////

  /////////CARBON FIBER SHELL////////////////////////////////
  //////detTubeShell:1///////////////////////////////////////
  G4ThreeVector position1 =
      G4ThreeVector(0, 0, 134.5 * mm + 20 * mm + CFHolderShift);
  G4Transform3D transform1 = G4Transform3D(rotm1, position1);
  new G4PVPlacement(transform1,      // rotation,position
                    fLogicdetTube,   // its logical volume
                    "detTubeShell",  // its name
                    logicDetVol,     // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps
  ////////////detConeShell:2///////////////////////////////////
  G4ThreeVector position2 =
      G4ThreeVector(0, 0, 74.5 * mm + 20 * mm + CFHolderShift);
  G4Transform3D transform2 = G4Transform3D(rotm1, position2);
  new G4PVPlacement(transform2,      // rotation,position
                    fLogicdetCone,   // its logical volume
                    "detConeShell",  // its name
                    logicDetVol,     // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps
  ////////////////////PMTubeShell:3//////////////////////////////
  G4ThreeVector position3 =
      G4ThreeVector(0, 0, -42 * mm + 20 * mm + CFHolderShift);
  G4Transform3D transform3 = G4Transform3D(rotm1, position3);
  new G4PVPlacement(transform3,     // rotation,position
                    fLogicPMTube,   // its logical volume
                    "PMTubeShell",  // its name
                    logicDetVol,    // its mother  volume
                    false,          // no boolean operation
                    0,              // copy number
                    flagOverlaps);  // checking overlaps
  ////////////detWindow:4 (Front part of the CFiber shell)////////
  G4ThreeVector position4 =
      G4ThreeVector(0, 0, 180.0 * mm + 20 * mm + CFHolderShift);
  G4Transform3D transform4 = G4Transform3D(rotm1, position4);
  new G4PVPlacement(transform4,       // rotation,position
                    fLogicdetWindow,  // its logical volume
                    "detWindow",      // its name
                    logicDetVol,      // its mother  volume
                    false,            // no boolean operation
                    0,                // copy number
                    flagOverlaps);    // checking overlaps
  /////////////////// Detector Base :20 ////////////////////////////
  //  G4double DetBase_pos=-144.5*mm-DetBase1_dZ;
  G4ThreeVector position20 =
      G4ThreeVector(0, 0, -144.5 * mm - DetBase1_dZ + 20 * mm + CFHolderShift);
  G4Transform3D transform20 = G4Transform3D(rotm1, position20);
  new G4PVPlacement(transform20,    // rotation,position
                    fLogicDetBase,  // its logical volume
                    "DetBase",      // its name
                    logicDetVol,    // its mother  volume
                    false,          // no boolean operation
                    0,              // copy number
                    flagOverlaps);  // checking overlaps
  //////////////22:CF support for Expansion Volume////////////////////
  // vbs->overlap with AluminumTube
  //  G4ThreeVector position22 = G4ThreeVector(120*mm,0.,
  //  tube2_dZ+0.5*expVol_thick+CFHolderShift); G4Transform3D transform22 =
  //  G4Transform3D(rotm1,position22); new G4PVPlacement (transform22,
  //  		     fLogicSupportHoled,            //its logical volume
  //  		     "supportHoled",               //its name
  //  		     logicDetVol,                     //its mother  volume
  //  		     false,                 //no boolean operation
  //  		     0,                     //copy number
  //  		     flagOverlaps);       // checking overlaps
  /////////////////////////CF Adaptor before aluminium tube:23///////////
  G4RotationMatrix rotm23 = G4RotationMatrix(0, -90 * deg, 90 * deg);
  G4ThreeVector position23 = G4ThreeVector(
      CFAdapt_dZ + R1min, 0, tube2_dZ + R_torusCenter + CFHolderShift);
  G4Transform3D transform23 = G4Transform3D(rotm23, position23);
  new G4PVPlacement(transform23,    //
                    fLogicCFAdapt,  // its logical volume
                    "CFAdapt",      // its name
                    logicDetVol,    // its mother  volume
                    false,          // no boolean opera
                    0,              // copy number
                    flagOverlaps);  // checking overlaps
  ////////////////////////// Aluminium Tube for expansion Volume:24/////////
  new G4PVPlacement(0,
                    G4ThreeVector(120 * mm, 0, CFHolderShift),  // Translation
                    fLogicAluminiumTube,  // its logical volume
                    "AluminiumTube",      // its name
                    logicDetVol,          // its mother  volume
                    false,                // no boolean operation
                    0,                    // copy number
                    flagOverlaps);        // checking overlaps
  /////////////////////////Expansion Volume Cilinder
  ///:25///////////////////////////////
  new G4PVPlacement(
      0, G4ThreeVector(120 * mm, 0, -tube2_dZ - expVol_dZ + CFHolderShift),
      fLogicExpVol,   // its logical volume
      "ExpVol",       // its name
      logicDetVol,    // its mother  volume
      false,          // no boolean operation
      0,              // copy number
      flagOverlaps);  // checking overlaps
  ///////////////////////PMWindow:5////////////////////////////////////////////////////////
  G4ThreeVector position5 =
      G4ThreeVector(0, 0, 15.324 * mm + 20 * mm + CFHolderShift);
  G4Transform3D transform5 = G4Transform3D(rotm1, position5);
  new G4PVPlacement(transform5,      // rotation,position
                    fLogicPMWindow,  // its logical volume
                    "PMW",           // its name
                    logicDetVol,     // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps
  ///////////////////////Extra
  /// Window:10////////////////////////////////////////////////
  G4ThreeVector position10 =
      G4ThreeVector(0, 0, 15.324 * mm + 20 * mm + CFHolderShift);
  G4Transform3D transform10 = G4Transform3D(rotm1, position10);
  new G4PVPlacement(transform10,      // rotation,position
                    fLogicPMWindow2,  // its logical volume
                    "PMW2",           // its name
                    logicDetVol,      // its mother  volume
                    false,            // no boolean operation
                    0,                // copy number
                    flagOverlaps);    // checking overlaps
  ///////////////////////C6D6 liquid
  /// volume///6//////////////////////////////////////
  G4ThreeVector position6 =
      G4ThreeVector(0, 0, 134.0 * mm + 20 * mm + CFHolderShift);
  G4Transform3D transform6 = G4Transform3D(rotm1, position6);
  new G4PVPlacement(transform6,     // rotation,position
                    LfLogicC6D6,    // its logical volume
                    "L6D6",         // its name
                    logicDetVol,    // its mother  volume
                    false,          // no boolean operation
                    0,              // copy number
                    flagOverlaps);  // checking overlaps
  ///////////////////////// C6D6 Expansion/Filling Tube
  ///:26///////////////////////////////
  new G4PVPlacement(0,                                          // no rotation
                    G4ThreeVector(120 * mm, 0, CFHolderShift),  // Translation
                    fLogicC6D6ExpTube,  // its logical volume
                    "C6D6ExpTube",      // its name
                    logicDetVol,        // its mother  volume
                    false,              // no boolean operation
                    0,                  // copy number
                    flagOverlaps);      // checking overlaps
  /////////////////////////Expansion Volume C6D6
  ///:27///////////////////////////////
  new G4PVPlacement(
      0,  // no rotation
      G4ThreeVector(120 * mm, 0,
                    -tube2_dZ - expVol_dZ + 0.5 * expVol_thick + CFHolderShift),
      fLogicExpVolC6D6,  // its logical volume
      "ExpVolC6D6",      // its name
      logicDetVol,       // its mother  volume
      false,             // no boolean operation
      0,                 // copy number
      flagOverlaps);     // checking overlaps
  ////////////////////PMShield1Tube:11/////////////////////////////////////////
  G4double PMS1Tube_pos = -1 * PMS1_dZ + 60.5 * mm;  //=0.912*mm;
  G4ThreeVector position11 =
      G4ThreeVector(0, 0, PMS1Tube_pos + 20 * mm + CFHolderShift);
  G4Transform3D transform11 = G4Transform3D(rotm1, position11);
  new G4PVPlacement(transform11,     // rotation,position
                    fLogicPMS1Tube,  // its logical volume
                    "PMS1Tube",      // its name
                    logicDetVol,     // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps
  ////////////////////PMShield1Bottom:12/////////////////////////////////////////
  G4double PMS1Bottom_pos =
      -2 * PMS1_dZ + 60.5 * mm + 0.5 * PMS1_thick;  //= -58.405mm;
  G4ThreeVector position12 =
      G4ThreeVector(0, 0, PMS1Bottom_pos + 20 * mm + CFHolderShift);
  G4Transform3D transform12 = G4Transform3D(rotm1, position12);
  new G4PVPlacement(transform12,       // rotation,position
                    fLogicPMS1Bottom,  // its logical volume
                    "PMS1Bottom",      // its name
                    logicDetVol,       // its mother  volume
                    false,             // no boolean operation
                    0,                 // copy number
                    flagOverlaps);     // checking overlaps
  ////////////////////PMShield2Tube:13/////////////////////////////////////////
  G4double PMS2Tube_pos = PMS1Bottom_pos + 0.5 * PMS1_thick + PMS2_dZ;  //
  G4ThreeVector position13 =
      G4ThreeVector(0, 0, PMS2Tube_pos + 20 * mm + CFHolderShift);
  G4Transform3D transform13 = G4Transform3D(rotm1, position13);
  new G4PVPlacement(transform13,     // rotation,position
                    fLogicPMS2Tube,  // its logical volume
                    "PMS2Tube",      // its name
                    logicDetVol,     // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps
  ////////////////////PMShield2Bottom:14/////////////////////////////////////////
  G4double PMS2Bottom_pos =
      PMS1Bottom_pos + 0.5 * PMS1_thick + 0.5 * PMS2_thick;
  G4ThreeVector position14 =
      G4ThreeVector(0, 0, PMS2Bottom_pos + 20 * mm + CFHolderShift);
  G4Transform3D transform14 = G4Transform3D(rotm1, position14);
  new G4PVPlacement(transform14,       // rotation,position
                    fLogicPMS2Bottom,  // its logical volume
                    "PMS2Bottom",      // its name
                    logicDetVol,       // its mother  volume
                    false,             // no boolean operation
                    0,                 // copy number
                    flagOverlaps);     // checking overlaps
  ///////////////////////////////////PMContentVolume:15///////////////////////////////////
  G4double PMContent_pos = 15.324 * mm;
  G4ThreeVector position15 =
      G4ThreeVector(0, 0, PMContent_pos + 20 * mm + CFHolderShift);
  G4Transform3D transform15 = G4Transform3D(rotm1, position15);
  new G4PVPlacement(transform15,      // rotation,position
                    fLogicPMContent,  // its logical volume
                    "PMContent",      // its name
                    logicDetVol,      // its mother  volume
                    false,            // no boolean operation
                    0,                // copy number
                    flagOverlaps);    // checking overlaps
  /////////////PMAdapt1: 16///////////////////////////////
  G4double PMAdapt1_pos = 45.5 * mm;
  G4ThreeVector position16 =
      G4ThreeVector(0, 0, PMAdapt1_pos + 20 * mm + CFHolderShift);
  G4Transform3D transform16 = G4Transform3D(rotm1, position16);
  new G4PVPlacement(transform16,      // rotation,position
                    fLogicPMAdapt1,   // its logical volume
                    "PMAdapt1Shell",  // its name
                    logicDetVol,      // its mother  volume
                    false,            // no boolean operation
                    0,                // copy number
                    flagOverlaps);    // checking overlaps
  /////////////PMAdapt2:17//////////////////////////////
  G4double PMAdapt2_pos = 50.5 * mm;
  G4ThreeVector position17 =
      G4ThreeVector(0, 0, PMAdapt2_pos + 20 * mm + CFHolderShift);
  G4Transform3D transform17 = G4Transform3D(rotm1, position17);
  new G4PVPlacement(transform17,      // rotation,position
                    fLogicPMAdapt2,   // its logical volume
                    "PMAdapt2Shell",  // its name
                    logicDetVol,      // its mother  volume
                    false,            // no boolean operation
                    0,                // copy number
                    flagOverlaps);    // checking overlaps
  /////////////Voltage divider:18///////////////////////////////
  G4double VoltageDiv_pos =
      PMS1Bottom_pos - VoltageDiv1_dZ - 0.5 * PMS1_thick;  //=-71.18*mm;
  G4ThreeVector position18 =
      G4ThreeVector(0, 0, VoltageDiv_pos + 20 * mm + CFHolderShift);
  G4Transform3D transform18 = G4Transform3D(rotm1, position18);
  new G4PVPlacement(transform18,       // rotation,position
                    fLogicVoltageDiv,  // its logical volume
                    "VoltageDiv",      // its name
                    logicDetVol,       // its mother  volume
                    false,             // no boolean operation
                    0,                 // copy number
                    flagOverlaps);     // checking overlaps
  /////////////SupportRing:19///////////////////////////////
  G4double SuppRing_pos =
      VoltageDiv_pos - PMSupportRing_dZ - VoltageDiv1_dZ;  //=-98.68*mm
  G4ThreeVector position19 =
      G4ThreeVector(0, 0, SuppRing_pos + 20 * mm + CFHolderShift);
  G4Transform3D transform19 = G4Transform3D(rotm1, position19);
  new G4PVPlacement(transform19,     // rotation,position
                    fLogicSuppRing,  // its logical volume
                    "SuppRing",      // its name
                    logicDetVol,     // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps

  /////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////     ATRIBUTES
  //////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////
  G4VisAttributes* CarbonFiberVisAtt = new G4VisAttributes(G4Color::Gray());
  G4VisAttributes* PMS1VisAtt = new G4VisAttributes(G4Color::Yellow());
  G4VisAttributes* PMS2VisAtt = new G4VisAttributes(G4Color::Blue());
  G4VisAttributes* VoltageDivVisAtt = new G4VisAttributes(G4Color::Green());
  G4VisAttributes* PMW2VisAtt = new G4VisAttributes(G4Color::White());
  G4VisAttributes* PMWVisAtt = new G4VisAttributes(G4Color::Yellow());
  G4VisAttributes* SuppRingVisAtt = new G4VisAttributes(G4Color::Cyan());
  G4VisAttributes* PMContentVisAtt = new G4VisAttributes(G4Color::Green());
  G4VisAttributes* C6D6VisAtt = new G4VisAttributes(G4Color::Green());
  fLogicdetCone->SetVisAttributes(CarbonFiberVisAtt);
  fLogicdetTube->SetVisAttributes(CarbonFiberVisAtt);
  fLogicPMTube->SetVisAttributes(CarbonFiberVisAtt);
  fLogicDetBase->SetVisAttributes(CarbonFiberVisAtt);
  fLogicdetWindow->SetVisAttributes(CarbonFiberVisAtt);
  fLogicPMAdapt1->SetVisAttributes(CarbonFiberVisAtt);
  fLogicPMAdapt2->SetVisAttributes(CarbonFiberVisAtt);
  fLogicExpVol->SetVisAttributes(CarbonFiberVisAtt);
  fLogicCFAdapt->SetVisAttributes(CarbonFiberVisAtt);
  PMW2VisAtt->SetForceWireframe(true);
  fLogicAluminiumTube->SetVisAttributes(PMW2VisAtt);
  fLogicSupportHoled->SetVisAttributes(CarbonFiberVisAtt);
  fLogicPMS1Tube->SetVisAttributes(PMS1VisAtt);
  fLogicPMS1Bottom->SetVisAttributes(PMS1VisAtt);
  fLogicPMS2Tube->SetVisAttributes(PMS2VisAtt);
  fLogicPMS2Bottom->SetVisAttributes(PMS2VisAtt);
  fLogicPMWindow->SetVisAttributes(PMWVisAtt);
  fLogicPMWindow2->SetVisAttributes(PMW2VisAtt);
  LfLogicC6D6->SetVisAttributes(C6D6VisAtt);
  fLogicExpVolC6D6->SetVisAttributes(C6D6VisAtt);
  fLogicC6D6ExpTube->SetVisAttributes(C6D6VisAtt);
  fLogicVoltageDiv->SetVisAttributes(VoltageDivVisAtt);
  fLogicSuppRing->SetVisAttributes(SuppRingVisAtt);
  fLogicPMContent->SetVisAttributes(PMContentVisAtt);
}

void C6D6DetectorConstruction::ConstructECLABR3(G4LogicalVolume* mother,

                                                G4int* flagLABR,

                                                G4double* thetaLABR,

                                                G4double* phiLABR,
                                                G4double* zLABR) {
  //////////////////////////////////

  //=================================================================================================

  //=================================================================================================

  /////////////////////////////////////

  /// Epic Crystal LaBr3 detectors: ///

  /// as the ones used in NEL for   ///

  /// the Pb bkgd tests in May 2026 ///

  /////////////////////////////////////

  cout << endl << "Construct Epic Crystal's LaBr3 detectors" << endl;

  G4double LengthLABR = 50.8 * mm;

  G4double RadiusLABR = 38.1 / 2.0 * mm;  // 1.5 inch diameter

  G4double TotalLengthLABRDevice = 249.0 * mm;  // according to drawing

  // Teflon (PTFE) reflector around crystal (covering front but not back)

  G4double ThicknessTeflonLABR = 1.0 * mm;  // 1 mm thick

  G4double RadiusTeflonLABR = RadiusLABR + ThicknessTeflonLABR;

  G4double halfLengthTeflonLABR =
      (LengthLABR + ThicknessTeflonLABR - 0.01) * mm /
      2.0;  // 1 mm longer than the crystal to cover the front face

  // Quartz window after the LaBr3 crystal

  G4double RadiusQuartzLABR = RadiusLABR;  // same radius as the LaBr3 crystal

  G4double halfLengthQuartzLABR =
      5.0 / 2.0 * mm;  // 5 mm thick according to Luxium

  // PMT:

  G4double RadiusPMTLABR = RadiusLABR;  // same radius as the LaBr3 crystal

  G4double halfLengthPMTLABR =
      96.0 / 2.0 * mm;  // 76 mm thick, PMT 9215B (ET Enterprises)

  // PMT magnetic shield (Mu-metal):

  G4double RadiusMuMetalLABR =
      56.0 / 2.0 * mm;  // 56 mm diameter, according to ET Enterprises

  G4double halfLengthMuMetalLABR = halfLengthPMTLABR;  // same length as the PMT

  // Al case thickness:

  G4double ThicknessAlcase = 0.5 * mm;  // 0.5 mm thick acc. to drawing

  // Al case for LaBr3 crystal:

  G4double RadiusAlCaseLABR =
      57.0 / 2.0 * mm;  // 57 mm diameter, according to drawing

  G4double halfLengthAlCaseLABR = 52.0 / 2.0 * mm;  // 52 mm length

  // Aluminum disk in front

  G4double RadiusAlCaseFrontDisk =
      RadiusAlCaseLABR -
      0.1 * mm;  // slightly smaller than the Al case to avoid overlaps

  G4double halfLengthAlCaseFrontDisk = ThicknessAlcase / 2.0;

  // Al case for PMT:

  G4double RadiusAlCasePMTLABR = 59.0 / 2.0 * mm;  // 59 mm diameter

  G4double halfLengthAlCasePMTLABR = 77.0 / 2.0 * mm;  // 77 mm length

  // Al case cylinder for voltage divider:

  G4double RadiusAlCaseVDLABR =
      74.0 / 2.0 * mm;  // 74 mm diameter, according to drawing

  G4double halfLengthAlCaseVDLABR = 90.0 / 2.0 * mm;

  // Al case rear disk:

  G4double RadiusAlCaseRearDiskLABR =
      RadiusAlCaseVDLABR -
      0.1 * mm;  // slightly smaller than the Al case to avoid overlaps

  G4double halfLengthAlCaseRearDiskLABR = ThicknessAlcase / 2.0;

  // Brass rings:

  G4double RadiusBrassRing1LABR =
      68.0 / 2.0 * mm;  // 68 mm diameter, according to drawing

  G4double RadiusBrassRing2LABR = 82.0 / 2.0 * mm;  // 82 mm diameter

  G4double halfLengthBrassRingLABR = 15.0 / 2.0 * mm;  // 15 mm length

  // Calculate total length of LaBr3 device (without voltage divider):

  G4double LengthDetector = LengthLABR;

  LengthDetector += 2.0 * halfLengthAlCaseFrontDisk;

  LengthDetector += 2.0 * halfLengthQuartzLABR;

  LengthDetector += 2.0 * halfLengthPMTLABR;

  LengthDetector += ThicknessTeflonLABR;  // teflon thickness in one side

  // Voltage divider, no info. I deduce its diameter and length from Al case:

  G4double RadiusVoltageDividerLABR =
      RadiusAlCaseVDLABR - ThicknessAlcase;  // just inside the Al case

  G4double halfLengthVoltageDividerLABR = TotalLengthLABRDevice / 2.0 -
                                          LengthDetector / 2.0 -
                                          ThicknessAlcase / 2.0;

  // Update LengthDetector:

  LengthDetector += 2.0 * halfLengthVoltageDividerLABR;

  //========================================================================

  //========================================================================

  //========================================================================

  //========================================================================

  //========================================================================

  //========================================================================

  //========================================================================

  //========================================================================

  //========================================================================

  //========================================================================

  //========================================================================

  G4ThreeVector positionLABR =

      G4ThreeVector(0 * cm, 0. * cm,
                    LengthDetector / 2.0 - LengthLABR / 2.0

                        - ThicknessAlcase

                        - ThicknessTeflonLABR);

  // Teflon reflector:

  G4ThreeVector positionTeflonLABR =

      G4ThreeVector(0 * cm, 0. * cm,
                    LengthDetector / 2.0 - halfLengthTeflonLABR

                        - ThicknessAlcase);

  // AlCase LaBr3 crystal front cylinder:

  G4ThreeVector positionAlCaseFrontLABR =

      G4ThreeVector(0 * cm, 0. * cm,

                    LengthDetector / 2.0 - halfLengthAlCaseLABR);

  // Brass Ring 1 between crystal and PMT:

  G4ThreeVector positionBrassRing1LABR =
      G4ThreeVector(0. * cm, 0. * cm,

                    LengthDetector / 2.0 - 2.0 * halfLengthAlCaseLABR -
                        halfLengthBrassRingLABR);

  // Quartz window after the LaBr3 crystal:

  G4ThreeVector positionQuartzLABR = G4ThreeVector(
      0. * cm, 0. * cm,

      LengthDetector / 2.0 - ThicknessAlcase - ThicknessTeflonLABR -
          LengthLABR - halfLengthQuartzLABR);

  // PMT and Mu-metal shield:

  G4ThreeVector positionPMTLABR =
      G4ThreeVector(0. * cm, 0. * cm,

                    -1.0 * LengthDetector / 2.0 +
                        2.0 * halfLengthVoltageDividerLABR + halfLengthPMTLABR);

  G4ThreeVector positionMuMetalLABR = positionPMTLABR;  // same position as PMT

  // Al case for PMT:

  G4ThreeVector positionAlCasePMTLABR = G4ThreeVector(
      0. * cm, 0. * cm,

      LengthDetector / 2.0 - 2.0 * halfLengthAlCaseLABR -
          2.0 * halfLengthBrassRingLABR - halfLengthAlCasePMTLABR);

  // Voltage divider:

  G4ThreeVector positionVoltageDividerLABR =
      G4ThreeVector(0. * cm, 0. * cm,

                    -1.0 * LengthDetector / 2.0 + ThicknessAlcase +
                        halfLengthVoltageDividerLABR);

  // Al case for voltage divider:

  G4ThreeVector positionAlCaseVDLABR =
      G4ThreeVector(0. * cm, 0. * cm,

                    -1.0 * LengthDetector / 2.0 + halfLengthAlCaseVDLABR);

  // Brass Ring 2 between PMT and voltage divider:

  G4ThreeVector positionBrassRing2LABR =
      G4ThreeVector(0. * cm, 0. * cm,

                    -1.0 * LengthDetector / 2.0 + 2.0 * halfLengthAlCaseVDLABR +
                        halfLengthBrassRingLABR);

  //=======================

  /// PLACEMENT OF THE COMPONENTS OF THE LABR DETECTOR IN THE VAC0 VOLUME

  // G4Box* ssolidDetVol=  new G4Box("sdetVol",RadiusLABR+0.01*mm,

  // RadiusLABR+0.01*mm,LengthDetector/2.0+0.01*mm);

  G4Tubs* ssolidDetVol =

      new G4Tubs("sdetVol", 0, RadiusBrassRing2LABR + 0.01 * mm,

                 LengthDetector / 2.0 + 0.01 * mm, 0. * deg, 360. * deg);

  G4LogicalVolume* slogicDetVol =

      new G4LogicalVolume(ssolidDetVol,  // its solid

                          vacuum,  // its material

                          "sdetVol");  // its name

  slogicDetVol->SetVisAttributes(G4VisAttributes::GetInvisible());

  // slogicDetVol->SetVisAttributes(G4Color::Gray());

  // G4bool PSURFCHK=true;

  G4double detVol_dZ = LengthDetector / 2.0;

  for (int i = 1; i < (theInputManager->GetTotalNC6D6Detectors() + 1); i++) {
    G4RotationMatrix rotLABR[50];

    G4double rLABR[50];

    G4ThreeVector posLABR[50];

    // G4VPhysicalVolume *physiLABR[50];

    char name[1000];

    if (flagLABR[i] == 7) {
      G4cout << "Build LABR_" << i << " thetaLABR= " << thetaLABR[i]

             << " phiLABRz= " << phiLABR[i] << " z= " << zLABR[i] << G4endl;

      //   rotLABR[i] = G4RotationMatrix();

      //   rotLABR[i].rotateY(thetaLABR[i] * deg);

      //   rotLABR[i].rotateZ(phiLABR[i] * deg);

      rLABR[i] = detVol_dZ + zLABR[i] * cm;

      posLABR[i] = G4ThreeVector(

          rLABR[i] * sin(thetaLABR[i] * deg) * cos(phiLABR[i] * deg),

          rLABR[i] * sin(thetaLABR[i] * deg) * sin(phiLABR[i] * deg),

          rLABR[i] * cos(thetaLABR[i] * deg));

      sprintf(name, "LABR_%d", i);

      G4cout << posLABR[i].x() / cm << ", "

             << posLABR[i].y() / cm << ", " << posLABR[i].z() / cm << G4endl;

      // Orientate detector to point towards origin (target):

      G4ThreeVector zAxis =
          -1.0 * posLABR[i].unit();  // direction from detector to origin

      G4ThreeVector xAxis = G4ThreeVector(0, 0, 1).cross(zAxis);

      if (xAxis.mag() < 1e-6) {
        xAxis = G4ThreeVector(1, 0, 0);
      }  // degenerated case

      xAxis = xAxis.unit();

      G4ThreeVector yAxis = zAxis.cross(xAxis);

      rotLABR[i] = G4RotationMatrix(xAxis, yAxis, zAxis);

      new G4PVPlacement(G4Transform3D(rotLABR[i], posLABR[i]),

                        slogicDetVol,  // its logical volume

                        name,

                        mother,  // its

                        false,  // no boolean operation

                        i,  // copy number

                        flagOverlaps);
    }
  }

  //-------------------------------------------------------------------------------------------------------

  // Al case for LaBr3 crystal placement:

  // Details: union of the front disk and the cylinder

  G4Tubs* solidAlCaseFrontLABR =
      new G4Tubs("AlFrontLABR", 0, RadiusAlCaseFrontDisk,

                 halfLengthAlCaseFrontDisk, 0. * deg, 360. * deg);

  G4Tubs* solidPrimAlCaseLABR = new G4Tubs(
      "PrimAlCaseLABR", RadiusAlCaseLABR - ThicknessAlcase, RadiusAlCaseLABR,

      halfLengthAlCaseLABR, 0. * deg, 360. * deg);

  G4UnionSolid* solidAlCaseCrystalLABR =

      new G4UnionSolid(
          "AlCaseCrystalLABR",

          solidPrimAlCaseLABR,  // reference solid A

          solidAlCaseFrontLABR,  // solid B to be added

          0,
          G4ThreeVector(
              0, 0,
              halfLengthAlCaseLABR -
                  halfLengthAlCaseFrontDisk));  // position of B relative to A

  G4LogicalVolume* logicAlCaseFrontLABR =
      new G4LogicalVolume(solidAlCaseCrystalLABR, Al, "AlCaseCrystalLABR");

  G4RotationMatrix rotm_AlCaseFrontLABR = G4RotationMatrix(0, 0, 0);

  G4Transform3D transform_AlCaseFrontLABR =
      G4Transform3D(rotm_AlCaseFrontLABR, positionAlCaseFrontLABR);

  new G4PVPlacement(transform_AlCaseFrontLABR,  // rotation,position

                    logicAlCaseFrontLABR,  // its logical volume

                    "AlCaseCrystalLABR",  // its name

                    slogicDetVol,  // its mother  volume

                    false,  // no boolean operation

                    0,  // copy number

                    flagOverlaps);  // checking overlaps

  G4VisAttributes* AlCaseFrontLABRVisAtt =

      new G4VisAttributes(G4Colour(0.6, 0.6, 0.6));  // GREY

  logicAlCaseFrontLABR->SetVisAttributes(AlCaseFrontLABRVisAtt);

  //-------------------------------------------------------------------------------------------------------

  // Al case for PMT placement:

  G4Tubs* solidAlCasePMTLABR =
      new G4Tubs("AlCasePMTLABR", RadiusAlCasePMTLABR - ThicknessAlcase,
                 RadiusAlCasePMTLABR,

                 halfLengthAlCasePMTLABR, 0. * deg, 360. * deg);

  G4LogicalVolume* logicAlCasePMTLABR =
      new G4LogicalVolume(solidAlCasePMTLABR, Al, "AlCasePMTLABR");

  G4RotationMatrix rotm_AlCasePMTLABR = G4RotationMatrix(0, 0, 0);

  G4Transform3D transform_AlCasePMTLABR =
      G4Transform3D(rotm_AlCasePMTLABR, positionAlCasePMTLABR);

  new G4PVPlacement(transform_AlCasePMTLABR,  // rotation,position

                    logicAlCasePMTLABR,  // its logical volume

                    "AlCasePMTLABR",  // its name

                    slogicDetVol,  // its mother  volume

                    false,  // no boolean operation

                    0,  // copy number

                    flagOverlaps);  // checking overlaps

  G4VisAttributes* AlCasePMTLABRVisAtt =

      new G4VisAttributes(G4Colour(0.6, 0.6, 0.6));  // GREY

  logicAlCasePMTLABR->SetVisAttributes(AlCasePMTLABRVisAtt);

  //-------------------------------------------------------------------------------------------------------

  // Brass ring 1 placement:

  G4Tubs* solidPrimRing1LABR =
      new G4Tubs("BrassRing1LABR", RadiusAlCaseLABR, RadiusBrassRing1LABR,

                 halfLengthBrassRingLABR, 0. * deg, 360. * deg);

  // Subtract Al case for PMT:

  auto innerAlCasePMT =
      new G4Tubs("InnerAlCasePMTLABR", 0, RadiusAlCasePMTLABR - ThicknessAlcase,

                 halfLengthBrassRingLABR, 0. * deg, 360. * deg);

  G4SubtractionSolid* solidBrassRing1LABR =

      new G4SubtractionSolid(
          "BrassRing1LABR",

          solidPrimRing1LABR,  // reference solid A

          innerAlCasePMT,  // solid B to be subtracted

          0,
          G4ThreeVector(
              0, 0,
              -1.0 * halfLengthBrassRingLABR));  // position of B relative to A

  G4LogicalVolume* logicBrassRing1LABR =
      new G4LogicalVolume(solidBrassRing1LABR, Brass, "BrassRing1LABR");

  G4RotationMatrix rotm_BrassRing1LABR = G4RotationMatrix(0, 0, 0);

  G4Transform3D transform_BrassRing1LABR =
      G4Transform3D(rotm_BrassRing1LABR, positionBrassRing1LABR);

  new G4PVPlacement(transform_BrassRing1LABR,  // rotation,position

                    logicBrassRing1LABR,  // its logical volume

                    "BrassRing1LABR",  // its name

                    slogicDetVol,  // its mother  volume

                    false,  // no boolean operation

                    0,  // copy number

                    flagOverlaps);  // checking overlaps

  G4VisAttributes* BrassRing1LABRVisAtt =

      new G4VisAttributes(G4Colour(181.0 / 255.0, 166.0 / 255.0,
                                   66.0 / 255.0));  // Brass-like color

  logicBrassRing1LABR->SetVisAttributes(BrassRing1LABRVisAtt);

  //-------------------------------------------------------------------------------------------------------

  // Al case for voltage divider placement:

  // Details: union of the rear disk and the cylinder

  G4Tubs* solidAlCaseRearDiskLABR =
      new G4Tubs("AlRearDiskLABR", 0, RadiusAlCaseRearDiskLABR,

                 halfLengthAlCaseRearDiskLABR, 0. * deg, 360. * deg);

  G4Tubs* solidPrimAlCaseVDLABR = new G4Tubs(
      "AlCaseVDLABR", RadiusAlCaseVDLABR - ThicknessAlcase, RadiusAlCaseVDLABR,

      halfLengthAlCaseVDLABR, 0. * deg, 360. * deg);

  G4UnionSolid* solidAlCaseVDLABR =

      new G4UnionSolid(
          "AlCaseVDLABR",

          solidPrimAlCaseVDLABR,  // reference solid A

          solidAlCaseRearDiskLABR,  // solid B to be added

          0,
          G4ThreeVector(0, 0,
                        -1.0 * halfLengthAlCaseVDLABR +
                            halfLengthAlCaseRearDiskLABR));  // position of B
                                                             // relative to A

  G4LogicalVolume* logicAlCaseVDLABR =
      new G4LogicalVolume(solidAlCaseVDLABR, Al, "AlCaseVDLABR");

  G4RotationMatrix rotm_AlCaseVDLABR = G4RotationMatrix(0, 0, 0);

  G4Transform3D transform_AlCaseVDLABR =
      G4Transform3D(rotm_AlCaseVDLABR, positionAlCaseVDLABR);

  new G4PVPlacement(transform_AlCaseVDLABR,  // rotation,position

                    logicAlCaseVDLABR,  // its logical volume

                    "AlCaseVDLABR",  // its name

                    slogicDetVol,  // its mother  volume

                    false,  // no boolean operation

                    0,  // copy number

                    flagOverlaps);  // checking overlaps

  G4VisAttributes* AlCaseVDLABRVisAtt =

      new G4VisAttributes(G4Colour(0.6, 0.6, 0.6));  // GREY

  logicAlCaseVDLABR->SetVisAttributes(AlCaseVDLABRVisAtt);

  //-------------------------------------------------------------------------------------------------------

  // Brass ring 2 placement:

  G4Tubs* solidPrimRing2LABR =
      new G4Tubs("BrassRing2LABR", RadiusAlCasePMTLABR, RadiusBrassRing2LABR,

                 halfLengthBrassRingLABR, 0. * deg, 360. * deg);

  // Subtract Al case for voltage divider:

  auto innerAlCaseVD =
      new G4Tubs("InnerAlCaseVDLABR", 0, RadiusAlCaseVDLABR - ThicknessAlcase,

                 halfLengthBrassRingLABR, 0. * deg, 360. * deg);

  G4SubtractionSolid* solidBrassRing2LABR =

      new G4SubtractionSolid(
          "BrassRing2LABR",

          solidPrimRing2LABR,  // reference solid A

          innerAlCaseVD,  // solid B to be subtracted

          0,
          G4ThreeVector(
              0, 0,
              -1.0 * halfLengthBrassRingLABR));  // position of B relative to A

  G4LogicalVolume* logicBrassRing2LABR =
      new G4LogicalVolume(solidBrassRing2LABR, Brass, "BrassRing2LABR");

  G4RotationMatrix rotm_BrassRing2LABR = G4RotationMatrix(0, 0, 0);

  G4Transform3D transform_BrassRing2LABR =
      G4Transform3D(rotm_BrassRing2LABR, positionBrassRing2LABR);

  new G4PVPlacement(transform_BrassRing2LABR,  // rotation,position

                    logicBrassRing2LABR,  // its logical volume

                    "BrassRing2LABR",  // its name

                    slogicDetVol,  // its mother  volume

                    false,  // no boolean operation

                    0,  // copy number

                    flagOverlaps);  // checking overlaps

  G4VisAttributes* BrassRing2LABRVisAtt =

      new G4VisAttributes(G4Colour(181.0 / 255.0, 166.0 / 255.0,
                                   66.0 / 255.0));  // Brass-like color

  logicBrassRing2LABR->SetVisAttributes(BrassRing2LABRVisAtt);

  //-------------------------------------------------------------------------------------------------------

  // Quartz window placement:

  G4Tubs* solidQuartzLABR =
      new G4Tubs("QuartzLABR", 0, RadiusQuartzLABR, halfLengthQuartzLABR,

                 0. * deg, 360. * deg);

  G4LogicalVolume* logicQuartzLABR =
      new G4LogicalVolume(solidQuartzLABR, Quartz, "QuartzLABR");

  G4RotationMatrix rotm_QuartzLABR = G4RotationMatrix(0, 0, 0);

  G4Transform3D transform_QuartzLABR =
      G4Transform3D(rotm_QuartzLABR, positionQuartzLABR);

  new G4PVPlacement(transform_QuartzLABR,  // rotation,position

                    logicQuartzLABR,  // its logical volume

                    "QuartzLABR",  // its name

                    slogicDetVol,  // its mother  volume

                    false,  // no boolean operation

                    0,  // copy number

                    flagOverlaps);  // checking overlaps

  G4VisAttributes* QuartzLABRVisAtt =

      new G4VisAttributes(G4Colour(0.7, 0.2, 0.0, 0.8));  // Orange, opacity 80%

  logicQuartzLABR->SetVisAttributes(QuartzLABRVisAtt);

  //-------------------------------------------------------------------------------------------------------

  // PMT placement:

  G4Tubs* solidPMTLABR =
      new G4Tubs("PMTLABR", 0, RadiusPMTLABR, halfLengthPMTLABR,

                 0. * deg, 360. * deg);

  G4LogicalVolume* logicPMTLABR =
      new G4LogicalVolume(solidPMTLABR, kovar_mat, "PMTLABR");

  G4RotationMatrix rotm_PMTLABR = G4RotationMatrix(0, 0, 0);

  G4Transform3D transform_PMTLABR =
      G4Transform3D(rotm_PMTLABR, positionPMTLABR);

  new G4PVPlacement(transform_PMTLABR,  // rotation,position

                    logicPMTLABR,  // its logical volume

                    "PMTLABR",  // its name

                    slogicDetVol,  // its mother  volume

                    false,  // no boolean operation

                    0,  // copy number

                    flagOverlaps);  // checking overlaps

  G4VisAttributes* PMTLABRVisAtt =

      new G4VisAttributes(
          G4Colour(243.0 / 255.0, 199.0 / 255.0, 54.0 / 255.0));  // Yellow-ish

  logicPMTLABR->SetVisAttributes(PMTLABRVisAtt);

  //-------------------------------------------------------------------------------------------------------

  // Mu-metal shield placement:

  G4Tubs* solidMuMetalLABR = new G4Tubs(
      "MuMetalLABR", RadiusPMTLABR, RadiusMuMetalLABR, halfLengthMuMetalLABR,

      0. * deg, 360. * deg);

  G4LogicalVolume* logicMuMetalLABR =
      new G4LogicalVolume(solidMuMetalLABR, Mumetal, "MuMetalLABR");

  G4RotationMatrix rotm_MuMetalLABR = G4RotationMatrix(0, 0, 0);

  G4Transform3D transform_MuMetalLABR =
      G4Transform3D(rotm_MuMetalLABR, positionMuMetalLABR);

  new G4PVPlacement(transform_MuMetalLABR,  // rotation,position

                    logicMuMetalLABR,  // its logical volume

                    "MuMetalLABR",  // its name

                    slogicDetVol,  // its mother  volume

                    false,  // no boolean operation

                    0,  // copy number

                    flagOverlaps);  // checking overlaps

  G4VisAttributes* MuMetalLABRVisAtt =

      new G4VisAttributes(G4Colour(0.4, 0.4, 0.4));  // DARK GREY

  logicMuMetalLABR->SetVisAttributes(MuMetalLABRVisAtt);

  //-------------------------------------------------------------------------------------------------------

  // Voltage divider placement:

  G4Tubs* solidVoltageDividerLABR =
      new G4Tubs("VoltageDividerLABR", 0, RadiusVoltageDividerLABR,
                 halfLengthVoltageDividerLABR,

                 0. * deg, 360. * deg);

  G4LogicalVolume* logicVoltageDividerLABR =
      new G4LogicalVolume(solidVoltageDividerLABR, PP, "VoltageDividerLABR");

  G4RotationMatrix rotm_VoltageDividerLABR = G4RotationMatrix(0, 0, 0);

  G4Transform3D transform_VoltageDividerLABR =
      G4Transform3D(rotm_VoltageDividerLABR, positionVoltageDividerLABR);

  new G4PVPlacement(transform_VoltageDividerLABR,  // rotation,position

                    logicVoltageDividerLABR,  // its logical volume

                    "VoltageDividerLABR",  // its name

                    slogicDetVol,  // its mother  volume

                    false,  // no boolean operation

                    0,  // copy number

                    flagOverlaps);  // checking overlaps

  G4VisAttributes* VoltageDividerLABRVisAtt =

      new G4VisAttributes(
          G4Colour(11.0 / 255.0, 228.0 / 255.0, 55.0 / 255.0));  // Green

  logicVoltageDividerLABR->SetVisAttributes(VoltageDividerLABRVisAtt);

  //-------------------------------------------------------------------------------------------------------

  /////////////////////////////////////////////////////

  /////LABR Liquid////////

  /////////////////////////////////////////////////////

  G4Tubs* solidLABR = new G4Tubs("solidLABR", 0, RadiusLABR, LengthLABR / 2,

                                 0. * deg, 360. * deg);

  ECLaBrflogicC6D6 = new G4LogicalVolume(solidLABR, LaBr3, "LABR");

  G4RotationMatrix rotm_LABR = G4RotationMatrix(0, 0, 0);

  G4Transform3D transform_LABR = G4Transform3D(rotm_LABR, positionLABR);

  //     thesTED->AddPlacedVolume(logicLABR,transform_LABR);

  new G4PVPlacement(transform_LABR,  // rotation,position

                    ECLaBrflogicC6D6,  // its logical volume

                    "LABR",  // its name

                    slogicDetVol,  // its mother  volume

                    false,  // no boolean operation

                    0,  // copy number

                    flagOverlaps);  // checking overlaps

  G4VisAttributes* LABRVisAtt = new G4VisAttributes(G4Colour(0., 1.0, 1.0));  //

  ECLaBrflogicC6D6->SetVisAttributes(LABRVisAtt);

  G4double VolumeinLABR = solidLABR->GetCubicVolume();

  // G4cout<<"Volume of LABR in one detector"<<0.000001*VolumeinLABR<<" in

  // Litres"<<G4endl; G4cout<<"Volume of LABRExpansion in one

  // detector"<<0.000001*VolumeinLABRExpasionVol<<" in Litres"<<G4endl;

  G4cout << "Volume of LABR " << 0.000001 * VolumeinLABR << " Litres" << G4endl;

  //-------------------------------------------------------------------------------------------------------

  // Teflon reflector placement:

  G4Tubs* solidPrimTeflonLABR =
      new G4Tubs("PrimaryTeflonLABR", 0, RadiusTeflonLABR,

                 halfLengthTeflonLABR, 0. * deg, 360. * deg);

  // Subtract LaBr3 solid:

  G4SubtractionSolid* solidTeflonLABR =

      new G4SubtractionSolid(
          "TeflonLABR", solidPrimTeflonLABR, solidLABR, 0,

          G4ThreeVector(
              0, 0,
              halfLengthTeflonLABR - LengthLABR / 2.0 - ThicknessTeflonLABR));

  G4LogicalVolume* logicTeflonLABR =
      new G4LogicalVolume(solidTeflonLABR, Teflon, "TeflonLABR");

  G4RotationMatrix rotm_TeflonLABR = G4RotationMatrix(0, 0, 0);

  G4Transform3D transform_TeflonLABR =
      G4Transform3D(rotm_TeflonLABR, positionTeflonLABR);

  new G4PVPlacement(transform_TeflonLABR,  // rotation,position

                    logicTeflonLABR,  // its logical volume

                    "TeflonLABR",  // its name

                    slogicDetVol,  // its mother  volume

                    false,  // no boolean operation

                    0,  // copy number

                    flagOverlaps);  // checking overlaps

  G4VisAttributes* TeflonLABRVisAtt =

      new G4VisAttributes(G4Colour(0.0, 0.0, 0.0));  // Black

  logicTeflonLABR->SetVisAttributes(TeflonLABRVisAtt);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6DetectorConstruction::ConstructsTED5Holder(G4LogicalVolume* mother) {
  G4double halfLengthAlHolderSupport = 2.0 * mm;
  G4double minRadiusAlHolderSupport = 220 * mm;
  G4double maxRadiusAlHolderSupport = 280 * mm;
  G4RotationMatrix rot90 = G4RotationMatrix(0, 90 * deg, 0);
  G4ThreeVector posXYZ = G4ThreeVector(0., -2. * cm, 0.);
  char columnName[50];
  sprintf(columnName, "AlHolderSupport%d", 1);

  G4Tubs* solidAlHolderSupport =
      new G4Tubs("solidAlHolderSupport", minRadiusAlHolderSupport,
                 maxRadiusAlHolderSupport, halfLengthAlHolderSupport,
                 135.0 * deg, 95.0 * deg);

  G4LogicalVolume* logicAlHolderSupport =
      new G4LogicalVolume(solidAlHolderSupport, Al_alloy, columnName);

  /*  G4VPhysicalVolume* physiAlHolderSupport =*/new G4PVPlacement(
      G4Transform3D(rot90, posXYZ), logicAlHolderSupport, columnName, mother,
      false, 1, flagOverlaps);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6DetectorConstruction::ConstructAlColumn(G4LogicalVolume* mother,
                                                 G4double posX,
                                                 G4int columnID) {
  G4double halfLengthAlHolderSupport = 1.3 * m;
  G4double minRadiusAlHolderSupport = 0 * mm;
  G4double maxRadiusAlHolderSupport = 12.5 * mm;
  G4RotationMatrix rot90 = G4RotationMatrix(0, 90 * deg, 0);
  G4double posZ = -30. * cm;
  G4ThreeVector posXYZ = G4ThreeVector(posX, 0., posZ);
  char columnName[50];
  sprintf(columnName, "AlHolderSupport%d", columnID);

  G4Tubs* solidAlHolderSupport =
      new G4Tubs("solidAlHolderSupport", minRadiusAlHolderSupport,
                 maxRadiusAlHolderSupport, halfLengthAlHolderSupport, 0. * deg,
                 360. * deg);

  G4LogicalVolume* logicAlHolderSupport =
      new G4LogicalVolume(solidAlHolderSupport, Al_alloy, columnName);

  /*  G4VPhysicalVolume* physiAlHolderSupport =*/new G4PVPlacement(
      G4Transform3D(rot90, posXYZ), logicAlHolderSupport, columnName, mother,
      false, columnID, flagOverlaps);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6DetectorConstruction::ConstructAlColumnZ0(G4LogicalVolume* mother,
                                                   G4double posX,
                                                   G4int columnID) {
  G4double halfLengthAlHolderSupport = 1.3 * m;
  G4double minRadiusAlHolderSupport = 0 * mm;
  G4double maxRadiusAlHolderSupport = 12.5 * mm;
  G4RotationMatrix rot90 = G4RotationMatrix(0, 90 * deg, 0);
  G4double posZ = -11. * cm;
  G4ThreeVector posXYZ = G4ThreeVector(posX, 0., posZ);
  char columnName[50];
  sprintf(columnName, "AlHolderSupport%d", columnID);

  G4Tubs* solidAlHolderSupport =
      new G4Tubs("solidAlHolderSupport", minRadiusAlHolderSupport,
                 maxRadiusAlHolderSupport, halfLengthAlHolderSupport, 0. * deg,
                 360. * deg);

  G4LogicalVolume* logicAlHolderSupport =
      new G4LogicalVolume(solidAlHolderSupport, Al_alloy, columnName);

  /*  G4VPhysicalVolume* physiAlHolderSupport =*/new G4PVPlacement(
      G4Transform3D(rot90, posXYZ), logicAlHolderSupport, columnName, mother,
      false, columnID, flagOverlaps);
}

void C6D6DetectorConstruction::ConstructRoofWalls(G4LogicalVolume* mother) {
  G4double EAR1ScaleFactor = theInputManager->GetEAR1ScaleFactor();

  // Distances
  G4double lateral_width = 4. * m * EAR1ScaleFactor;
  G4double longitudinal_length = 7.7 * m * EAR1ScaleFactor;
  G4double ceiling_height =
      3.7 * m * EAR1ScaleFactor;  // from floor to highest point
  G4double vertical_shift = 0.815 * m * EAR1ScaleFactor;
  G4double lateral_shift = 0.821 * m * EAR1ScaleFactor;
  G4double floor_thickness = 1.5 * m;
  G4double ceiling_thickness = 1.5 * m;
  G4double front_wall_thickness = 1.5 * m;
  G4double rear_wall_thickness = 1.5 * m;
  G4double side_wall_thickness = 1.5 * m;
  G4double side_wall_height = 2.5 * m * EAR1ScaleFactor;
  G4double sample_longitudinal_distance =
      2.224 * m * EAR1ScaleFactor;  // from beamline-entry wall ("front" wall)
  G4double sample_lateral_projection =
      1.546 * m * EAR1ScaleFactor;  // from side-wall 1 ("right" wall)
  G4double sample_height_projection =
      2.144 * m *
      EAR1ScaleFactor;  // projection on a beamline-entry wall ("front" wall)
  G4double directional_length =
      sqrt(pow(lateral_shift, 2) + pow(vertical_shift, 2) +
           pow(longitudinal_length, 2));
  G4double alpha = 0. * radian;
  G4double theta = -acos(longitudinal_length / directional_length) * radian;
  G4double phi = -atan(vertical_shift / lateral_shift) * radian;

  // Floor
  G4double x_floor = lateral_width + 2. * side_wall_thickness;
  G4double y_floor = floor_thickness;
  G4double z_floor = longitudinal_length;
  G4double beamline_diameter[2];
  beamline_diameter[0] = 16. * cm;  // thick beamline before sample
  beamline_diameter[1] = 16. * cm;  // thick beamline after sample

  G4double dx =
      (lateral_width - lateral_shift) / 2. - sample_lateral_projection;
  G4double dy =
      -sample_height_projection + (vertical_shift - floor_thickness) / 2.;
  G4double dz = longitudinal_length / 2. - sample_longitudinal_distance;
  G4ThreeVector floor_position =
      G4ThreeVector(dx, dy, dz);  // relative to the sample

  G4Para* floor = new G4Para("Floor", x_floor / 2., y_floor / 2., z_floor / 2.,
                             alpha, theta, phi);
  G4LogicalVolume* logic_floor = new G4LogicalVolume(floor, concrete, "Floor");
  // G4VPhysicalVolume* phys_floor=new G4PVPlacement(0,
  // 						  floor_position,
  // 						  logic_floor,
  // 						  "Floor",
  // 						  mother,
  // 						  false,
  // 						  0,
  // 						  flagOverlaps);

  new G4PVPlacement(0, floor_position, logic_floor, "Floor", mother, false, 0,
                    flagOverlaps);
  logic_floor->SetVisAttributes(new G4VisAttributes(G4Colour::Gray()));
  logic_floor->SetVisAttributes(new G4VisAttributes(G4Colour::Gray()));
  // Aluminum floor
  G4double x_plate = lateral_width;
  G4double y_plate = 5. * mm;
  G4double z_plate = longitudinal_length;
  G4double theta0 = -atan(lateral_shift / longitudinal_length) * radian;
  G4ThreeVector plate_position =
      floor_position +
      G4ThreeVector(0., (vertical_shift + y_floor + y_plate) / 2., 0.);

  G4Para* plate = new G4Para("Al_floor", x_plate / 2., y_plate / 2.,
                             z_plate / 2., 0. * deg, theta0, 0. * deg);
  G4LogicalVolume* logic_plate =
      new G4LogicalVolume(plate, Al_alloy, "Al_floor");
  /*  G4VPhysicalVolume* phys_plate=*/new G4PVPlacement(
      0, plate_position, logic_plate, "Al_floor", mother, false, flagOverlaps);

  // Ceiling
  G4double cosine = sin(theta) * sin(phi);
  G4double arc_depth = ceiling_height - side_wall_height;
  G4double arc_radius =
      (4. * pow(arc_depth, 2) + pow(lateral_width, 2)) / (8. * arc_depth);
  G4double arc_length =
      (directional_length +
       2. * arc_radius * sqrt(pow(cosine, 2) / (1 - pow(cosine, 2)))) *
      1.2;
  G4double y_ceiling = ceiling_thickness + arc_depth;
  G4ThreeVector ceiling_position =
      floor_position +
      G4ThreeVector(0. * m,
                    side_wall_height + (y_ceiling + floor_thickness) / 2.,
                    0. * m);
  G4RotationMatrix rm;
  rm.rotateY(theta);
  rm.rotateZ(phi);
  G4Para* ceiling_base =
      new G4Para("Ceiling_base", x_floor / 2., y_ceiling / 2., z_floor / 2.,
                 alpha, theta, phi);
  G4Tubs* arc = new G4Tubs("Ceiling_arc", 0., arc_radius, arc_length / 2.,
                           0. * deg, 360. * deg);
  G4SubtractionSolid* ceiling = new G4SubtractionSolid(
      "Ceiling", ceiling_base, arc,
      G4Transform3D(
          rm, G4ThreeVector(0. * m, -arc_radius - y_ceiling / 2. + arc_depth,
                            0. * m)));
  G4LogicalVolume* logic_ceiling =
      new G4LogicalVolume(ceiling, concrete, "Ceiling");
  /*G4VPhysicalVolume* phys_ceiling=*/new G4PVPlacement(
      0, ceiling_position, logic_ceiling, "Ceiling", mother, false,
      flagOverlaps);
  logic_ceiling->SetVisAttributes(new G4VisAttributes(G4Colour::Gray()));

  // Front and rear wall
  G4double frw_height = floor_thickness + ceiling_height + ceiling_thickness;
  G4ThreeVector front_position =
      floor_position +
      G4ThreeVector(
          lateral_shift / 2.,
          (frw_height - vertical_shift - floor_thickness) / 2.,
          -(z_floor + front_wall_thickness) / 2.);  // relative to the world
  G4ThreeVector front_hole_position = G4ThreeVector(
      -x_floor / 2. + sample_lateral_projection + side_wall_thickness,
      -frw_height / 2. + floor_thickness + sample_height_projection,
      0. * m);  // relative to the front wall
  // Front
  G4Box* front_base = new G4Box("Front_wall_base", x_floor / 2.,
                                frw_height / 2., front_wall_thickness / 2.);
  G4Tubs* front_hole =
      new G4Tubs("Front_wall_hole", 0., beamline_diameter[0] / 2.,
                 0.6 * front_wall_thickness, 0. * deg, 360. * deg);
  G4SubtractionSolid* front_wall = new G4SubtractionSolid(
      "Front_wall", front_base, front_hole, 0, front_hole_position);
  G4LogicalVolume* logic_front =
      new G4LogicalVolume(front_wall, concrete, "Front_wall");
  /*G4VPhysicalVolume* phys_front=*/new G4PVPlacement(
      0, front_position, logic_front, "Front_wall", mother, false,
      flagOverlaps);
  logic_front->SetVisAttributes(new G4VisAttributes(G4Colour::Gray()));
  // Rear
  G4ThreeVector rear_position =
      floor_position +
      G4ThreeVector(
          -lateral_shift / 2.,
          (frw_height + vertical_shift - floor_thickness) / 2.,
          (z_floor + rear_wall_thickness) / 2.);  // relative to the world
  G4ThreeVector rear_hole_position =
      front_hole_position + G4ThreeVector(lateral_shift, -vertical_shift,
                                          0. * m);  // relative to the rear wall
  G4Box* rear_base = new G4Box("Rear_wall_base", x_floor / 2., frw_height / 2.,
                               rear_wall_thickness / 2.);
  G4Tubs* rear_hole =
      new G4Tubs("Rear_wall_hole", 0., beamline_diameter[1] / 2.,
                 0.6 * rear_wall_thickness, 0. * deg, 360. * deg);
  G4SubtractionSolid* rear_wall = new G4SubtractionSolid(
      "Rear_wall", rear_base, rear_hole, 0, rear_hole_position);
  G4LogicalVolume* logic_rear =
      new G4LogicalVolume(rear_wall, concrete, "Rear_wall");
  /* G4VPhysicalVolume* phys_rear=*/new G4PVPlacement(
      0, rear_position, logic_rear, "Rear_wall", mother, false, flagOverlaps);
  logic_rear->SetVisAttributes(new G4VisAttributes(G4Colour::Gray()));

  // Side walls
  // Right
  G4ThreeVector right_position =
      floor_position + G4ThreeVector(-(x_floor - side_wall_thickness) / 2.,
                                     (floor_thickness + side_wall_height) / 2.,
                                     0. * m);
  G4Para* right_wall =
      new G4Para("Right_wall", side_wall_thickness / 2., side_wall_height / 2.,
                 z_floor / 2., alpha, theta, phi);
  G4LogicalVolume* logic_right =
      new G4LogicalVolume(right_wall, concrete, "Right_wall");
  /*G4VPhysicalVolume* phys_right=*/new G4PVPlacement(
      0, right_position, logic_right, "Right_wall", mother, false,
      flagOverlaps);
  logic_right->SetVisAttributes(new G4VisAttributes(G4Colour::Gray()));
  // Left
  G4ThreeVector left_position =
      floor_position + G4ThreeVector((x_floor - side_wall_thickness) / 2.,
                                     (floor_thickness + side_wall_height) / 2.,
                                     0. * m);
  G4Para* left_wall =
      new G4Para("Left_wall", side_wall_thickness / 2., side_wall_height / 2.,
                 z_floor / 2., alpha, theta, phi);
  G4LogicalVolume* logic_left =
      new G4LogicalVolume(left_wall, concrete, "Left_wall");
  /*  G4VPhysicalVolume* phys_left=*/new G4PVPlacement(
      0, left_position, logic_left, "Left_wall", mother, false, flagOverlaps);
  logic_left->SetVisAttributes(new G4VisAttributes(G4Colour::Gray()));
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6DetectorConstruction::ConstructSaEx(G4LogicalVolume* mother) {
  // Distances
  G4double AlFloorDistance = 1.32 * m;  //
  //  G4double halfWidthEAR1 = 150*cm;//vbs
  // G4double halfWidthConcrete = 30*cm;//vbs
  // Color
  G4VisAttributes* SaEXAlPlateVisAtt =
      new G4VisAttributes(G4Colour(0.9, 0.9, 0.9));

  // Solids
  // G4Box *solidSaEX = new G4Box("SaEX",25.*cm,AlFloorDistance,12.5*cm);
  G4Box* solidSaEXAlPlate =
      new G4Box("SaEXAlPlate", 20. * cm, 0.5 * cm, 10 * cm);
  G4Box* solidSaEXAlTube = new G4Box("SaEXAlTube", 1 * cm, 60 * cm, 1 * cm);
  G4Tubs* solidSaEXAlLeg =
      new G4Tubs("SaEXAlLeg", 9 * cm, 10 * cm, (AlFloorDistance - 70 * cm) / 2,
                 0., 360 * deg);
  G4Tubs* solidSaEXAlCilinder =
      new G4Tubs("SaEXAlCilinder", 1 * cm, 1.2 * cm, 10 * cm, 0., 360 * deg);
  // Logics
  G4LogicalVolume* logicSaEXAlPlate =
      new G4LogicalVolume(solidSaEXAlPlate, Al_alloy, "SaEXAlPlate");
  logicSaEXAlPlate->SetVisAttributes(SaEXAlPlateVisAtt);
  G4LogicalVolume* logicSaEXAlPlate_top =
      new G4LogicalVolume(solidSaEXAlPlate, Al_alloy, "SaEXAlPlate_top");
  logicSaEXAlPlate_top->SetVisAttributes(SaEXAlPlateVisAtt);
  G4LogicalVolume* logicSaEXAlPlate_down =
      new G4LogicalVolume(solidSaEXAlPlate, Al_alloy, "SaEXAlPlate_down");
  logicSaEXAlPlate_down->SetVisAttributes(SaEXAlPlateVisAtt);
  G4LogicalVolume* logicSaEXAlPlate_bottom =
      new G4LogicalVolume(solidSaEXAlPlate, Al_alloy, "SaEXAlPlate_bottom");
  logicSaEXAlPlate_bottom->SetVisAttributes(SaEXAlPlateVisAtt);
  G4LogicalVolume* logicSaEXAlTube1 =
      new G4LogicalVolume(solidSaEXAlTube, Al_alloy, "SaEXAlTube1");
  logicSaEXAlTube1->SetVisAttributes(SaEXAlPlateVisAtt);
  G4LogicalVolume* logicSaEXAlTube2 =
      new G4LogicalVolume(solidSaEXAlTube, Al_alloy, "SaEXAlTube2");
  logicSaEXAlTube2->SetVisAttributes(SaEXAlPlateVisAtt);
  G4LogicalVolume* logicSaEXAlLeg =
      new G4LogicalVolume(solidSaEXAlLeg, Al_alloy, "SaEXAlLeg");
  logicSaEXAlLeg->SetVisAttributes(SaEXAlPlateVisAtt);
  G4LogicalVolume* logicSaEXAlCilinder_l =
      new G4LogicalVolume(solidSaEXAlCilinder, Al_alloy, "SaEXAlCilinder_l");
  logicSaEXAlCilinder_l->SetVisAttributes(SaEXAlPlateVisAtt);
  G4LogicalVolume* logicSaEXAlCilinder_r =
      new G4LogicalVolume(solidSaEXAlCilinder, Al_alloy, "SaEXAlCilinder_r");
  logicSaEXAlCilinder_r->SetVisAttributes(SaEXAlPlateVisAtt);
  // Placements
  /*G4VPhysicalVolume *physiSaEXAlPlate = */ new G4PVPlacement(
      0, G4ThreeVector(0, -50 * cm, 0), logicSaEXAlPlate, "SaEXAlPlate", mother,
      false, flagOverlaps);
  /* G4VPhysicalVolume *physiSaEXAlPlate_top = */ new G4PVPlacement(
      0, G4ThreeVector(0, 50 * cm, 0), logicSaEXAlPlate_top, "SaEXAlPlate_top",
      mother, false, flagOverlaps);
  /* G4VPhysicalVolume *physiSaEXAlPlate_down =*/new G4PVPlacement(
      0, G4ThreeVector(0, -70 * cm, 0), logicSaEXAlPlate_down,
      "SaEXAlPlate_down", mother, false, flagOverlaps);
  /* G4VPhysicalVolume *physiSaEXAlPlate_bottom =*/new G4PVPlacement(
      0, G4ThreeVector(0, -(AlFloorDistance), 0), logicSaEXAlPlate_bottom,
      "SaEXAlPlate_bottom", mother, false, flagOverlaps);
  /* G4VPhysicalVolume *physiSaEXAlTube1 =*/new G4PVPlacement(
      0, G4ThreeVector(15 * cm, -10 * cm, 9 * cm), logicSaEXAlTube1,
      "SaEXAlTube1", mother, false, flagOverlaps);
  /* G4VPhysicalVolume *physiSaEXAlTube2 =*/new G4PVPlacement(
      0, G4ThreeVector(-15 * cm, -10 * cm, 9 * cm), logicSaEXAlTube2,
      "SaEXAlTube2", mother, false, flagOverlaps);
  G4RotationMatrix* rotSaEXAlLeg = new G4RotationMatrix(0, 90 * deg, 0);
  /*G4VPhysicalVolume *physiSaEXAlLeg=*/new G4PVPlacement(
      rotSaEXAlLeg,
      G4ThreeVector(0, -(AlFloorDistance - 70 * cm) / 2 - 70 * cm, 0),
      logicSaEXAlLeg, "SaEXAlLeg", mother, false, flagOverlaps);
  G4RotationMatrix* rotSaEXAlCilinder_l = new G4RotationMatrix(0, 90 * deg, 0);
  /* G4VPhysicalVolume *physiSaEXAlCilinder_l=*/new G4PVPlacement(
      rotSaEXAlCilinder_l, G4ThreeVector(10 * cm, -60 * cm, -7 * cm),
      logicSaEXAlCilinder_l, "SaEXAlCilinder_l", mother, false, flagOverlaps);
  G4RotationMatrix* rotSaEXAlCilinder_r = new G4RotationMatrix(0, 90 * deg, 0);
  /*G4VPhysicalVolume *physiSaEXAlCilinder_r=*/new G4PVPlacement(
      rotSaEXAlCilinder_r, G4ThreeVector(-10 * cm, -60 * cm, -7 * cm),
      logicSaEXAlCilinder_r, "SaEXAlCilinder_r", mother, false, flagOverlaps);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6DetectorConstruction::ConstructBeamLineEAR1(G4LogicalVolume* mother) {
  // Safety margin for solids union / subtraction
  //   G4double safety_margin=0.01*mm;
  // Beamline diameter
  G4double inner_beamline_diameter =
      5. * cm;  // for thin beamlines just before and after the sample
  G4double outer_beamline_diameter =
      5.3 * cm;  // for thin beamlines just before and after the sample
  const G4int pipes = 8;
  G4double beamline_diameter[2], pipe_length[pipes], inner_diameter[pipes],
      outer_diameter[pipes], distance_from_sample[pipes];
  beamline_diameter[0] = 16. * cm;  // thick beamline before sample
  beamline_diameter[1] = 16. * cm;  // thick beamline after sample
  // Pipes
  // First pipe before sample
  pipe_length[3] = 82.5 * cm;
  inner_diameter[3] = inner_beamline_diameter;
  outer_diameter[3] = outer_beamline_diameter;
  distance_from_sample[3] = -19.0 * cm;
  // Far pipe before sample
  pipe_length[2] = 1.3 * m;
  inner_diameter[2] = inner_diameter[3];
  outer_diameter[2] = outer_diameter[3];
  distance_from_sample[2] = distance_from_sample[3] - pipe_length[3];
  // Thick-thin pipe connector before sample
  pipe_length[1] = 1 * cm;
  inner_diameter[1] = inner_diameter[2];
  outer_diameter[1] = beamline_diameter[0];
  distance_from_sample[1] = distance_from_sample[2] - pipe_length[2];
  // Thick pipe before sample
  pipe_length[0] = 2. * m;
  inner_diameter[0] = beamline_diameter[0] - 1. * cm;
  outer_diameter[0] = beamline_diameter[0];
  distance_from_sample[0] = distance_from_sample[1] - pipe_length[1];
  // First pipe after sample
  pipe_length[4] = 40. * cm;
  inner_diameter[4] = inner_beamline_diameter;
  outer_diameter[4] = outer_beamline_diameter;
  distance_from_sample[4] = 2 * cm;  // 7.4*cm;
  // Far pipe after sample
  pipe_length[5] = 4.5 * m;
  inner_diameter[5] = inner_diameter[4];
  outer_diameter[5] = outer_diameter[4];
  distance_from_sample[5] = distance_from_sample[4] + pipe_length[4];
  // Thick-thin pipe connector after sample
  pipe_length[6] = 1 * cm;
  inner_diameter[6] = inner_diameter[4];
  outer_diameter[6] = beamline_diameter[1];
  distance_from_sample[6] = distance_from_sample[5] + pipe_length[5];
  // Thick pipe after sample
  pipe_length[7] = 10.3 * m;
  inner_diameter[7] = beamline_diameter[1] - 1. * cm;
  outer_diameter[7] = beamline_diameter[1];
  distance_from_sample[7] = distance_from_sample[6] + pipe_length[6];
  // Vacuum
  const G4int vacuums = 4;
  G4double vacuum_length[vacuums], vacuum_diameter[vacuums];
  G4ThreeVector vacuum_position[vacuums];
  // Far before sample
  vacuum_length[0] =
      (distance_from_sample[1] - distance_from_sample[0]) + pipe_length[0];
  vacuum_diameter[0] = outer_diameter[0];
  vacuum_position[0] = G4ThreeVector(
      0. * cm, 0. * cm, distance_from_sample[1] - vacuum_length[0] / 2.);
  // Near before sample
  vacuum_length[1] =
      (distance_from_sample[3] - distance_from_sample[2]) + pipe_length[2];
  vacuum_diameter[1] = outer_diameter[3];
  vacuum_position[1] = G4ThreeVector(
      0. * cm, 0. * cm, distance_from_sample[3] - vacuum_length[1] / 2.);
  // Near after sample
  vacuum_length[2] =
      (distance_from_sample[5] - distance_from_sample[4]) + pipe_length[5];
  vacuum_diameter[2] = outer_diameter[4];
  vacuum_position[2] = G4ThreeVector(
      0. * cm, 0. * cm, distance_from_sample[4] + vacuum_length[2] / 2.);
  // Far after sample
  vacuum_length[3] =
      (distance_from_sample[7] - distance_from_sample[6]) + pipe_length[7];
  vacuum_diameter[3] = outer_diameter[1];
  vacuum_position[3] = G4ThreeVector(
      0. * cm, 0. * cm, distance_from_sample[6] + vacuum_length[3] / 2.);
  G4Tubs* vacuum_pipe[vacuums];
  G4LogicalVolume* logic_vacuum[vacuums];
  // G4VPhysicalVolume* phys_vacuum[vacuums];
  G4String name;
  for (G4int i = 0; i < vacuums; i++) {
    name = GetName("Vacuum", i + 1);
    vacuum_pipe[i] = new G4Tubs(name.c_str(), 0., vacuum_diameter[i] / 2.,
                                vacuum_length[i] / 2., 0. * deg, 360. * deg);
    logic_vacuum[i] = new G4LogicalVolume(vacuum_pipe[i], vacuum, name.c_str());
    //    phys_vacuum[i]=
    new G4PVPlacement(0, vacuum_position[i], logic_vacuum[i], name.c_str(),
                      mother, false, flagOverlaps);
    logic_vacuum[i]->SetVisAttributes(G4VisAttributes::GetInvisible());
  }
  // Beamline tubes
  G4ThreeVector pipe_position[pipes];  // Relative to the vacuum pipes
  for (G4int i = 0; i < pipes; i++)
    pipe_position[i] = G4ThreeVector(
        0. * cm, 0. * cm,
        pow(-1, i) * (-vacuum_length[i / 2] + pipe_length[i]) / 2.);
  G4Tubs* beam_pipe[pipes];
  G4LogicalVolume* logic_pipe[pipes];
  // G4VPhysicalVolume* phys_pipe[pipes];
  for (G4int i = 0; i < pipes; i++) {
    if (i == 3 || i == 4) {
      name = GetName("Beam_pipe", i + 1);
      beam_pipe[i] = new G4Tubs(name.c_str(), inner_diameter[i] / 2.,
                                outer_diameter[i] / 2., pipe_length[i] / 2.,
                                0. * deg, 360. * deg);
      logic_pipe[i] = new G4LogicalVolume(beam_pipe[i], Al_alloy, name.c_str());
      //    phys_pipe[i]=
      new G4PVPlacement(0, pipe_position[i], logic_pipe[i], name.c_str(),
                        logic_vacuum[i / 2], false, flagOverlaps);
    }
  }
  // Pipe rings
  const G4int rings = 4;
  G4double ring_length[rings] = {20. * cm, 2.8 * cm, 2.8 * cm, 20. * cm};
  G4double inner_ring_diameter[rings] = {outer_diameter[3], outer_diameter[3],
                                         outer_diameter[4], outer_diameter[4]};
  G4double outer_ring_diameter[rings] = {6.0 * cm, 5.7 * cm, 5.8 * cm,
                                         6.1 * cm};
  G4ThreeVector ring_position[rings];
  ring_position[0] =
      G4ThreeVector(0. * cm, 0. * cm, distance_from_sample[3] - pipe_length[3]);
  ring_position[1] =
      G4ThreeVector(0. * cm, 0. * cm, distance_from_sample[3] - 2.1 * cm);
  ring_position[2] =
      G4ThreeVector(0. * cm, 0. * cm, distance_from_sample[4] + 2.55 * cm);
  ring_position[3] =
      G4ThreeVector(0. * cm, 0. * cm, distance_from_sample[4] + pipe_length[4]);
  G4Tubs* pipe_ring[rings];
  G4LogicalVolume* logic_ring[rings];
  //  G4VPhysicalVolume* phys_ring[rings];
  for (G4int i = 0; i < rings; i++) {
    // if(i==3||i==4){

    name = GetName("Pipe_ring", i + 1);
    pipe_ring[i] = new G4Tubs(name.c_str(), inner_ring_diameter[i] / 2.,
                              outer_ring_diameter[i] / 2., ring_length[i] / 2.,
                              0. * deg, 360. * deg);
    logic_ring[i] = new G4LogicalVolume(pipe_ring[i], Al_alloy, name.c_str());
    //    phys_ring[i] =
    new G4PVPlacement(0, ring_position[i], logic_ring[i], name.c_str(), mother,
                      false, flagOverlaps);
    logic_ring[i]->SetVisAttributes(new G4VisAttributes(G4Colour::Cyan()));
    //	    }
  }
  // Kapton windows
  const G4int windows = 4;
  G4double kapton_thickness[windows] = {0.075 * mm, 0.075 * mm, 0.075 * mm,
                                        0.075 * mm};
  G4double kapton_diameter[windows] = {inner_diameter[3], outer_diameter[3],
                                       outer_diameter[4], inner_diameter[4]};
  G4LogicalVolume* mother_volume[windows] = {logic_vacuum[1], mother, mother,
                                             logic_vacuum[2]};
  G4ThreeVector kapton_position[windows];
  kapton_position[0] = G4ThreeVector(
      0. * cm,  // relative to the logic_vacuum[1]
      0. * cm, (vacuum_length[1] - kapton_thickness[0]) / 2. - pipe_length[3]);
  kapton_position[1] = G4ThreeVector(
      0. * cm,  // relative to the world
      0. * cm, distance_from_sample[3] + kapton_thickness[1] / 2.);
  kapton_position[2] = G4ThreeVector(
      0. * cm,  // relative to the world
      0. * cm, distance_from_sample[4] - kapton_thickness[2] / 2.);
  kapton_position[3] = G4ThreeVector(
      0. * cm,  // relative to the logic_vacuum[2]
      0. * cm, (-vacuum_length[2] + kapton_thickness[3]) / 2. + pipe_length[4]);
  G4Tubs* kapton_window[windows];
  G4LogicalVolume* logic_kapton[windows];
  //  G4VPhysicalVolume* phys_kapton[windows];
  for (G4int i = 0; i < windows; i++) {
    name = GetName("Kapton_window", i + 1);
    kapton_window[i] =
        new G4Tubs(name.c_str(), 0., kapton_diameter[i] / 2.,
                   kapton_thickness[i] / 2., 0. * deg, 360. * deg);
    logic_kapton[i] =
        new G4LogicalVolume(kapton_window[i], kapton, name.c_str());
    //    phys_kapton[i]=
    new G4PVPlacement(0, kapton_position[i], logic_kapton[i], name.c_str(),
                      mother_volume[i], false, flagOverlaps);
    logic_kapton[i]->SetVisAttributes(new G4VisAttributes(G4Colour::Yellow()));
  }
}

void C6D6DetectorConstruction::ConstructBeamLineEAR1_2024_BigSampleHolder(
    G4LogicalVolume* mother) {
  G4double inner_beamline_diameter =
      5. * cm;  // for thin beamlines just before and after the sample
  G4double outer_beamline_diameter =
      5.3 * cm;  // for thin beamlines just before and after the sample

  G4double outer_beamline_diameter2 =
      6 * cm;  // Diameter of the extra rings of the pipes

  G4double outer_beamline_diameter3 = 8 * cm;  // Diameter of the clamps

  const G4int pipes = 8;
  G4double beamline_diameter[2], pipe_length[pipes], inner_diameter[pipes],
      outer_diameter[pipes], distance_from_sample[pipes];
  // Pipes the order is from the target to the beam dump

  // It is defined before because it is used in the loop
  pipe_length[2] = 40 * cm;

  // Distance fromo sample to firsts pipes
  double DistanceFrontPipesToSample = -19.0 * cm;

  // Distance fromosample to back pipes
  double DistanceBackPipesToSample = 2 * cm;

  // It is defined before because it is used in the loop
  pipe_length[2] = 40 * cm;

  // First Al Pipe
  pipe_length[0] = 40 * cm;
  inner_diameter[0] = inner_beamline_diameter;
  outer_diameter[0] = outer_beamline_diameter;
  distance_from_sample[0] =
      DistanceFrontPipesToSample - pipe_length[2] - pipe_length[0] / 2.0;

  // First clamp Pipe
  pipe_length[1] = 3 * cm;
  inner_diameter[1] = outer_beamline_diameter;
  outer_diameter[1] = outer_beamline_diameter2;
  distance_from_sample[1] = DistanceFrontPipesToSample - pipe_length[2];

  // second Pipe  the one of CF
  inner_diameter[2] = inner_beamline_diameter;
  outer_diameter[2] = outer_beamline_diameter;
  distance_from_sample[2] = DistanceFrontPipesToSample - (pipe_length[2] / 2.0);

  // Ring of Al of the CF
  pipe_length[3] = 2 * cm;
  inner_diameter[3] = outer_beamline_diameter;
  outer_diameter[3] = outer_beamline_diameter2;
  distance_from_sample[3] = DistanceFrontPipesToSample - pipe_length[3] / 2.0;

  // Pipe Of Al after the sample ( there are two but I define them as one)
  pipe_length[4] = 217 * cm;
  pipe_length[4] = 80 * cm;

  inner_diameter[4] = inner_beamline_diameter;
  outer_diameter[4] = outer_beamline_diameter;
  distance_from_sample[4] = DistanceBackPipesToSample + pipe_length[4] / 2.0;

  // first ring of Al of the first pipe  after the sample
  pipe_length[5] = 3 * cm;
  inner_diameter[5] = outer_beamline_diameter;
  outer_diameter[5] = outer_beamline_diameter2;
  distance_from_sample[5] =
      DistanceBackPipesToSample + 1 * cm + pipe_length[5] / 2;

  // Second ring of Al of the first pipe  after the sample
  pipe_length[6] = 3 * cm;
  inner_diameter[6] = outer_beamline_diameter;
  outer_diameter[6] = outer_beamline_diameter2;
  distance_from_sample[6] =
      DistanceBackPipesToSample + 25 * cm + pipe_length[6] / 2;

  // Second Clamp
  pipe_length[7] = 3 * cm;
  inner_diameter[7] = outer_beamline_diameter;
  outer_diameter[7] = outer_beamline_diameter2;
  distance_from_sample[7] =
      DistanceBackPipesToSample + 40 * cm + pipe_length[7] / 2;

  // Beamline tubes
  G4ThreeVector pipe_position[pipes];  // Relative to the vacuum pipes
  for (G4int i = 0; i < pipes; i++)
    pipe_position[i] = G4ThreeVector(0. * cm, 0. * cm, distance_from_sample[i]);
  G4Tubs* beam_pipe[pipes];
  G4LogicalVolume* logic_pipe[pipes];
  G4String name;
  G4VisAttributes* PipeVisAtt[pipes];
  // G4VPhysicalVolume* phys_pipe[pipes];

  for (G4int i = 0; i < pipes; i++) {
    name = GetName("Beam_pipe", i + 1);
    beam_pipe[i] =
        new G4Tubs(name.c_str(), inner_diameter[i] / 2., outer_diameter[i] / 2.,
                   pipe_length[i] / 2., 0. * deg, 360. * deg);
    logic_pipe[i] = new G4LogicalVolume(beam_pipe[i], Al_alloy, name.c_str());
    //    phys_pipe[i]=
    new G4PVPlacement(0, pipe_position[i], logic_pipe[i], name.c_str(), mother,
                      false, flagOverlaps);

    PipeVisAtt[i] = new G4VisAttributes(G4Color::Grey());
    if (i == 2) {
      PipeVisAtt[i] = new G4VisAttributes(G4Color::Black());
    }
    logic_pipe[i]->SetVisAttributes(PipeVisAtt[i]);
  }

  // Kapton windows
  const G4int windows = 2;
  G4double kapton_thickness[windows] = {0.075 * mm, 0.075 * mm};
  G4double kapton_diameter[windows] = {outer_beamline_diameter,
                                       outer_beamline_diameter};

  G4ThreeVector kapton_position[windows];
  G4Tubs* kapton_window[windows];

  kapton_position[0] = G4ThreeVector(
      0. * cm,  // relative to the logic_vacuum[1]
      0. * cm, DistanceFrontPipesToSample + kapton_thickness[0] / 2.0);

  kapton_position[1] = G4ThreeVector(
      0. * cm,  // relative to the world
      0. * cm, DistanceBackPipesToSample - kapton_thickness[1] / 2.0);

  G4LogicalVolume* logic_kapton[windows];
  //  G4VPhysicalVolume* phys_kapton[windows];
  for (G4int i = 0; i < windows; i++) {
    name = GetName("Kapton_window", i + 1);
    kapton_window[i] =
        new G4Tubs(name.c_str(), 0., kapton_diameter[i] / 2.,
                   kapton_thickness[i] / 2., 0. * deg, 360. * deg);
    logic_kapton[i] =
        new G4LogicalVolume(kapton_window[i], kapton, name.c_str());
    //    phys_kapton[i]=
    new G4PVPlacement(0, kapton_position[i], logic_kapton[i], name.c_str(),
                      mother, false, flagOverlaps);
    logic_kapton[i]->SetVisAttributes(new G4VisAttributes(G4Colour::Yellow()));
  }

  // Vacuum
  const G4int vacuums = 2;
  G4double vacuum_length[vacuums], vacuum_diameter[vacuums];
  G4ThreeVector vacuum_position[vacuums];
  // Far before sample
  vacuum_length[0] = pipe_length[0] + pipe_length[2];
  vacuum_diameter[0] = inner_beamline_diameter;
  vacuum_position[0] = G4ThreeVector(
      0. * cm, 0. * cm, DistanceFrontPipesToSample - vacuum_length[0] / 2.0);
  // after sample
  vacuum_length[1] = pipe_length[4];
  vacuum_diameter[1] = inner_beamline_diameter;
  vacuum_position[1] = G4ThreeVector(
      0. * cm, 0. * cm, DistanceBackPipesToSample + vacuum_length[1] / 2.0);
  G4Tubs* vacuum_pipe[vacuums];

  G4LogicalVolume* logic_vacuum[vacuums];
  // G4VPhysicalVolume* phys_vacuum[vacuums];
  for (G4int i = 0; i < vacuums; i++) {
    name = GetName("Vacuum", i + 1);
    vacuum_pipe[i] = new G4Tubs(name.c_str(), 0., vacuum_diameter[i] / 2.,
                                vacuum_length[i] / 2., 0. * deg, 360. * deg);
    logic_vacuum[i] = new G4LogicalVolume(vacuum_pipe[i], vacuum, name.c_str());
    //    phys_vacuum[i]=
    new G4PVPlacement(0, vacuum_position[i], logic_vacuum[i], name.c_str(),
                      mother, false, flagOverlaps);
    logic_vacuum[i]->SetVisAttributes(G4VisAttributes::GetInvisible());
    logic_vacuum[i]->SetVisAttributes(new G4VisAttributes(G4Colour::Green()));
  }

  // Sample holder
  G4double SampleHolderDesviationInZaxis = 0.0 * cm;

  G4double SHolderAngleStart = 0.0 * deg;
  G4double SHolderAngleEnd = 180.0 * deg;

  G4double SHolder1Lhalf = 0.2 / 2.0 * cm;
  G4double SHolder1R = 9.0 / 2.0 * cm;
  G4double SHolder1r = 8.50 / 2.0 * cm;

  G4double SHolder2Lhalf = 0.9 / 2.0 * cm;
  G4double SHolder2R = 9.50 / 2.0 * cm;
  G4double SHolder2r = SHolder1R;

  G4double SHolder3Lhalf = 0.2 / 2.0 * cm;
  G4double SHolder3R = SHolder1R;
  G4double SHolder3r = 6.2 / 2.0 * cm;

  G4double SHolder4Lhalf = 6.0 / 2.0 * cm;
  G4double SHolder4R = 6.5 / 2.0 * cm;
  G4double SHolder4r = SHolder3r;

  G4Tubs* SOLIDSHolder1 =
      new G4Tubs("SOLIDSHolder1", SHolder1r, SHolder1R, SHolder1Lhalf,
                 SHolderAngleStart, SHolderAngleEnd);
  G4Tubs* SOLIDSHolder2 =
      new G4Tubs("SOLIDSHolder2", SHolder2r, SHolder2R, SHolder2Lhalf,
                 SHolderAngleStart, SHolderAngleEnd);
  G4Tubs* SOLIDSHolder3 =
      new G4Tubs("SOLIDSHolder3", SHolder3r, SHolder3R, SHolder3Lhalf,
                 SHolderAngleStart, SHolderAngleEnd);
  G4Tubs* SOLIDSHolder4 = new G4Tubs("SOLIDSHolder4", SHolder4r, SHolder4R,
                                     SHolder4Lhalf, 0. * deg, 360. * deg);

  G4UnionSolid* SOLIDSHolderinter1 = new G4UnionSolid(
      "SOLIDSHolderinter1", SOLIDSHolder1, SOLIDSHolder2, 0,
      G4ThreeVector(0. * mm, 0. * mm, -SHolder1Lhalf + SHolder2Lhalf));
  G4UnionSolid* SOLIDSHolderinter2 = new G4UnionSolid(
      "SOLIDSHolderinter2", SOLIDSHolderinter1, SOLIDSHolder3, 0,
      G4ThreeVector(0. * mm, 0. * mm,
                    -SHolder1Lhalf + 2 * SHolder2Lhalf - SHolder3Lhalf));
  G4UnionSolid* SOLIDSHolderinter3 = new G4UnionSolid(
      "SOLIDSHolderinter3", SOLIDSHolderinter2, SOLIDSHolder4, 0,
      G4ThreeVector(0. * mm, 0. * mm,
                    -SHolder1Lhalf + 2 * SHolder2Lhalf + SHolder4Lhalf));

  G4LogicalVolume* LOGSHolderinter =
      new G4LogicalVolume(SOLIDSHolderinter3, Al, "SHolder");
  G4ThreeVector positionSHolder = G4ThreeVector(
      0 * cm, 0. * cm,
      SampleHolderDesviationInZaxis + SHolder1Lhalf - SHolder2Lhalf);
  // Placing the sample in the 0,0,0, position with the variable
  // SampleHolderDesviationInZaxis this can be moved in the Z axis
  G4RotationMatrix* rm = new G4RotationMatrix(180 * deg, 0, 0);
  new G4PVPlacement(rm, positionSHolder, LOGSHolderinter, "SHolder", mother,
                    false, 0, flagOverlaps);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void C6D6DetectorConstruction::ConstructBeamLineEAR1_2024_SmallSampleHolder(
    G4LogicalVolume* mother) {
  G4double inner_beamline_diameter =
      5. * cm;  // for thin beamlines just before and after the sample
  G4double outer_beamline_diameter =
      5.3 * cm;  // for thin beamlines just before and after the sample

  G4double outer_beamline_diameter2 =
      6 * cm;  // Diameter of the extra rings of the pipes

  G4double outer_beamline_diameter3 = 8 * cm;  // Diameter of the clamps

  const G4int pipes = 8;
  G4double beamline_diameter[2], pipe_length[pipes], inner_diameter[pipes],
      outer_diameter[pipes], distance_from_sample[pipes];
  // Pipes the order is from the target to the beam dump

  // It is defined before because it is used in the loop
  pipe_length[2] = 40 * cm;

  // Distance fromo sample to firsts pipes
  double DistanceFrontPipesToSample = -19.0 * cm;

  // Distance fromosample to back pipes
  double DistanceBackPipesToSample = 2 * cm;

  // It is defined before because it is used in the loop
  pipe_length[2] = 40 * cm;

  // First Al Pipe
  pipe_length[0] = 40 * cm;
  inner_diameter[0] = inner_beamline_diameter;
  outer_diameter[0] = outer_beamline_diameter;
  distance_from_sample[0] =
      DistanceFrontPipesToSample - pipe_length[2] - pipe_length[0] / 2.0;

  // First clamp Pipe
  pipe_length[1] = 3 * cm;
  inner_diameter[1] = outer_beamline_diameter;
  outer_diameter[1] = outer_beamline_diameter2;
  distance_from_sample[1] = DistanceFrontPipesToSample - pipe_length[2];

  // second Pipe  the one of CF
  inner_diameter[2] = inner_beamline_diameter;
  outer_diameter[2] = outer_beamline_diameter;
  distance_from_sample[2] = DistanceFrontPipesToSample - (pipe_length[2] / 2.0);

  // Ring of Al of the CF
  pipe_length[3] = 2 * cm;
  inner_diameter[3] = outer_beamline_diameter;
  outer_diameter[3] = outer_beamline_diameter2;
  distance_from_sample[3] = DistanceFrontPipesToSample - pipe_length[3] / 2.0;

  // Pipe Of Al after the sample ( there are two but I define them as one)
  pipe_length[4] = 217 * cm;
  // pipe_length[4] = 80 * cm;

  inner_diameter[4] = inner_beamline_diameter;
  outer_diameter[4] = outer_beamline_diameter;
  distance_from_sample[4] = DistanceBackPipesToSample + pipe_length[4] / 2.0;

  // first ring of Al of the first pipe  after the sample
  pipe_length[5] = 3 * cm;
  inner_diameter[5] = outer_beamline_diameter;
  outer_diameter[5] = outer_beamline_diameter2;
  distance_from_sample[5] =
      DistanceBackPipesToSample + 1 * cm + pipe_length[5] / 2;

  // Second ring of Al of the first pipe  after the sample
  pipe_length[6] = 3 * cm;
  inner_diameter[6] = outer_beamline_diameter;
  outer_diameter[6] = outer_beamline_diameter2;
  distance_from_sample[6] =
      DistanceBackPipesToSample + 25 * cm + pipe_length[6] / 2;

  // Second Clamp
  pipe_length[7] = 3 * cm;
  inner_diameter[7] = outer_beamline_diameter;
  outer_diameter[7] = outer_beamline_diameter2;
  distance_from_sample[7] =
      DistanceBackPipesToSample + 40 * cm + pipe_length[7] / 2;

  // Beamline tubes
  G4ThreeVector pipe_position[pipes];  // Relative to the vacuum pipes
  for (G4int i = 0; i < pipes; i++)
    pipe_position[i] = G4ThreeVector(0. * cm, 0. * cm, distance_from_sample[i]);
  G4Tubs* beam_pipe[pipes];
  G4LogicalVolume* logic_pipe[pipes];
  G4String name;
  G4VisAttributes* PipeVisAtt[pipes];
  // G4VPhysicalVolume* phys_pipe[pipes];

  for (G4int i = 0; i < pipes; i++) {
    name = GetName("Beam_pipe", i + 1);
    beam_pipe[i] =
        new G4Tubs(name.c_str(), inner_diameter[i] / 2., outer_diameter[i] / 2.,
                   pipe_length[i] / 2., 0. * deg, 360. * deg);
    logic_pipe[i] = new G4LogicalVolume(beam_pipe[i], Al_alloy, name.c_str());
    //    phys_pipe[i]=
    new G4PVPlacement(0, pipe_position[i], logic_pipe[i], name.c_str(), mother,
                      false, flagOverlaps);

    PipeVisAtt[i] = new G4VisAttributes(G4Color::Grey());
    if (i == 2) {
      PipeVisAtt[i] = new G4VisAttributes(G4Color::Black());
    }
    logic_pipe[i]->SetVisAttributes(PipeVisAtt[i]);
  }

  // Kapton windows
  const G4int windows = 2;
  G4double kapton_thickness[windows] = {0.075 * mm, 0.075 * mm};
  G4double kapton_diameter[windows] = {outer_beamline_diameter,
                                       outer_beamline_diameter};

  G4ThreeVector kapton_position[windows];
  G4Tubs* kapton_window[windows];

  kapton_position[0] = G4ThreeVector(
      0. * cm,  // relative to the logic_vacuum[1]
      0. * cm, DistanceFrontPipesToSample + kapton_thickness[0] / 2.0);

  kapton_position[1] = G4ThreeVector(
      0. * cm,  // relative to the world
      0. * cm, DistanceBackPipesToSample - kapton_thickness[1] / 2.0);

  G4LogicalVolume* logic_kapton[windows];
  //  G4VPhysicalVolume* phys_kapton[windows];
  for (G4int i = 0; i < windows; i++) {
    name = GetName("Kapton_window", i + 1);
    kapton_window[i] =
        new G4Tubs(name.c_str(), 0., kapton_diameter[i] / 2.,
                   kapton_thickness[i] / 2., 0. * deg, 360. * deg);
    logic_kapton[i] =
        new G4LogicalVolume(kapton_window[i], kapton, name.c_str());
    //    phys_kapton[i]=
    new G4PVPlacement(0, kapton_position[i], logic_kapton[i], name.c_str(),
                      mother, false, flagOverlaps);
    logic_kapton[i]->SetVisAttributes(new G4VisAttributes(G4Colour::Yellow()));
  }

  // Vacuum
  const G4int vacuums = 2;
  G4double vacuum_length[vacuums], vacuum_diameter[vacuums];
  G4ThreeVector vacuum_position[vacuums];
  // Far before sample
  vacuum_length[0] = pipe_length[0] + pipe_length[2];
  vacuum_diameter[0] = inner_beamline_diameter;
  vacuum_position[0] = G4ThreeVector(
      0. * cm, 0. * cm, DistanceFrontPipesToSample - vacuum_length[0] / 2.0);
  // after sample
  vacuum_length[1] = pipe_length[4];
  vacuum_diameter[1] = inner_beamline_diameter;
  vacuum_position[1] = G4ThreeVector(
      0. * cm, 0. * cm, DistanceBackPipesToSample + vacuum_length[1] / 2.0);
  G4Tubs* vacuum_pipe[vacuums];

  G4LogicalVolume* logic_vacuum[vacuums];
  // G4VPhysicalVolume* phys_vacuum[vacuums];
  for (G4int i = 0; i < vacuums; i++) {
    name = GetName("Vacuum", i + 1);
    vacuum_pipe[i] = new G4Tubs(name.c_str(), 0., vacuum_diameter[i] / 2.,
                                vacuum_length[i] / 2., 0. * deg, 360. * deg);
    logic_vacuum[i] = new G4LogicalVolume(vacuum_pipe[i], vacuum, name.c_str());
    //    phys_vacuum[i]=
    new G4PVPlacement(0, vacuum_position[i], logic_vacuum[i], name.c_str(),
                      mother, false, flagOverlaps);
    logic_vacuum[i]->SetVisAttributes(G4VisAttributes::GetInvisible());
    logic_vacuum[i]->SetVisAttributes(new G4VisAttributes(G4Colour::Green()));
  }

  // Sample holder
  G4double SampleHolderDesviationInZaxis = -0.2 * cm;

  G4double SHolderAngleStart = 0.0 * deg;
  G4double SHolderAngleEnd = 180.0 * deg;

  G4double SHolder1Lhalf = 1.5 / 2.0 * mm;
  G4double SHolder1R = 6.5 / 2.0 * cm;
  G4double SHolder1r = 5.5 / 2.0 * cm;

  G4double SHolder2Lhalf = 2.8 / 2.0 * mm;
  G4double SHolder2R = SHolder1R;
  G4double SHolder2r = 6 / 2.0 * cm;

  G4double SHolder3Lhalf = 2 / 2.0 * mm;
  G4double SHolder3R = SHolder1R;
  G4double SHolder3r = SHolder1r;

  G4double SHolder4Lhalf = 2.67 / 2.0 * cm;
  G4double SHolder4R = SHolder1R;
  G4double SHolder4r = SHolder2r;

  G4Tubs* SOLIDSHolder1 =
      new G4Tubs("SOLIDSHolder1", SHolder1r, SHolder1R, SHolder1Lhalf,
                 SHolderAngleStart, SHolderAngleEnd);
  G4Tubs* SOLIDSHolder2 =
      new G4Tubs("SOLIDSHolder2", SHolder2r, SHolder2R, SHolder2Lhalf,
                 SHolderAngleStart, SHolderAngleEnd);
  G4Tubs* SOLIDSHolder3 =
      new G4Tubs("SOLIDSHolder3", SHolder3r, SHolder3R, SHolder3Lhalf,
                 SHolderAngleStart, SHolderAngleEnd);
  G4Tubs* SOLIDSHolder4 = new G4Tubs("SOLIDSHolder4", SHolder4r, SHolder4R,
                                     SHolder4Lhalf, 0. * deg, 360. * deg);

  G4UnionSolid* SOLIDSHolderinter1 = new G4UnionSolid(
      "SOLIDSHolderinter1", SOLIDSHolder1, SOLIDSHolder2, 0,
      G4ThreeVector(0. * mm, 0. * mm, SHolder1Lhalf + SHolder2Lhalf));
  G4UnionSolid* SOLIDSHolderinter2 = new G4UnionSolid(
      "SOLIDSHolderinter2", SOLIDSHolderinter1, SOLIDSHolder3, 0,
      G4ThreeVector(0. * mm, 0. * mm,
                    SHolder1Lhalf + 2 * SHolder2Lhalf + SHolder3Lhalf));
  G4UnionSolid* SOLIDSHolderinter3 = new G4UnionSolid(
      "SOLIDSHolderinter3", SOLIDSHolderinter2, SOLIDSHolder4, 0,
      G4ThreeVector(0. * mm, 0. * mm,
                    SHolder1Lhalf + 2 * SHolder2Lhalf + 2 * SHolder3Lhalf +
                        SHolder4Lhalf));

  G4LogicalVolume* LOGSHolderinter =
      new G4LogicalVolume(SOLIDSHolderinter3, Al, "SHolder");
  G4ThreeVector positionSHolder = G4ThreeVector(
      0 * cm, 0. * cm,
      SampleHolderDesviationInZaxis /*+ SHolder1Lhalf + SHolder2Lhalf*/);
  // Placing the sample in the 0,0,0, position with the variable
  // SampleHolderDesviationInZaxis this can be moved in the Z axis
  G4RotationMatrix* rm = new G4RotationMatrix(180 * deg, 0, 0);
  new G4PVPlacement(rm, positionSHolder, LOGSHolderinter, "SHolder", mother,
                    false, 0, flagOverlaps);

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6DetectorConstruction::ConstructTAC(G4LogicalVolume* mother) {
  // BaF2 ball
  G4double inner_diameter = 20. * cm;
  G4double outer_diameter = 50. * cm;
  G4double outer_shell_diameter = 56. * cm;
  G4double hole_diameter = 7. * cm;
  G4double hemispheres_distance = 10. * cm;
  G4double distance_from_sample = 1.5 * m;
  G4Sphere* hemisphere_base[4];
  //  G4SubtractionSolid *hemisphere[4];
  G4LogicalVolume* logic_hemisphere[4];
  //  G4VPhysicalVolume *phys_hemisphere[4];
  G4String name;
  G4Tubs* hole = new G4Tubs("BaF2_hole", 0., hole_diameter / 2.,
                            outer_shell_diameter / 2., 0. * deg, 360. * deg);
  for (G4int i = 0; i < 2; i++) {
    // Solids
    name = GetName("BaF2_base", i + 1);
    hemisphere_base[i] =
        new G4Sphere(name.c_str(), inner_diameter / 2., outer_diameter / 2,
                     (270. - 180. * i) * deg, 180. * deg, 0. * deg, 180. * deg);
    name = GetName("BaF2_hemisphere", i + 1);
    //    hemisphere[i] =
    new G4SubtractionSolid(name.c_str(), hemisphere_base[i], hole, 0,
                           G4ThreeVector());
    // Logics
    logic_hemisphere[i] =
        new G4LogicalVolume(hemisphere_base[i], BaF2, name.c_str());
    // Physics
    //     phys_hemisphere[i]=
    new G4PVPlacement(0,
                      G4ThreeVector(pow(-1, i) * hemispheres_distance / 2.,
                                    0. * m, distance_from_sample),
                      logic_hemisphere[i], name.c_str(), mother, false,
                      flagOverlaps);
    logic_hemisphere[i]->SetVisAttributes(
        new G4VisAttributes(G4Colour::Grey()));
  }
  for (G4int i = 2; i < 4; i++) {
    // Solids
    name = GetName("Shell_base", i - 1);
    hemisphere_base[i] = new G4Sphere(
        name.c_str(), outer_diameter / 2., outer_shell_diameter / 2,
        (270. - 180. * i) * deg, 180. * deg, 0. * deg, 180. * deg);
    name = GetName("Al_shell", i - 1);
    //    hemisphere[i] =
    new G4SubtractionSolid(name.c_str(), hemisphere_base[i], hole, 0,
                           G4ThreeVector());
    // Logics
    logic_hemisphere[i] =
        new G4LogicalVolume(hemisphere_base[i], Al_alloy, name.c_str());
    // Physics
    //     phys_hemisphere[i] =
    new G4PVPlacement(0,
                      G4ThreeVector(pow(-1, i) * hemispheres_distance / 2.,
                                    0. * m, distance_from_sample),
                      logic_hemisphere[i], name.c_str(), mother, false,
                      flagOverlaps);
  }

  // Aluminum bars
  const G4int bars = 20;
  G4CSGSolid* bar_base[bars];
  G4SubtractionSolid* hollow_bar[bars];
  G4LogicalVolume* logic_bar[bars];
  // G4VPhysicalVolume *phys_bar[bars];
  G4Transform3D bar_placement[bars];
  G4int bar_width = 5 * cm;
  G4int hole_width = 4.4 * cm;
  G4int lower_base_length = 1.8 * m;
  G4int upper_base_length = 1. * m;
  G4int displacement = 20. * cm;
  G4int height = 1.6 * m;
  G4int vertical_shift = 0. * m;
  G4RotationMatrix rm0, rm1, rm2;
  rm1.rotateY(90. * deg);
  rm2.rotateX(90. * deg);
  G4double alpha = atan((lower_base_length - upper_base_length) /
                        (2. * (height - 2. * bar_width))) *
                   radian;
  G4double x_bar0 = hole_width / (cos(alpha));
  G4double y_bar0 = height;
  G4double z_bar0 = hole_width;
  G4Box* straight_hole =
      new G4Box("Straight_hole", hole_width / 2., hole_width / 2.,
                1.2 * lower_base_length / 2.);
  G4Para* skewed_hole[2];
  for (G4int i = 0; i < 2; i++) {
    name = GetName("Skewed_hole", i + 1);
    skewed_hole[i] =
        new G4Para(name.c_str(), x_bar0 / 2., y_bar0 / 2., z_bar0 / 2.,
                   pow(-1, i) * alpha, 0. * deg, 0. * deg);
  }
  G4ThreeVector reference_point =
      G4ThreeVector(0. * m, vertical_shift, distance_from_sample);

  // Lower bars
  bar_placement[0] = G4Transform3D(
      rm1,
      reference_point + G4ThreeVector(0. * m, -(height - bar_width) / 2.,
                                      -(lower_base_length - bar_width) / 2.));
  bar_placement[1] = G4Transform3D(
      rm1,
      reference_point + G4ThreeVector(0. * m, -(height - bar_width) / 2.,
                                      (lower_base_length - bar_width) / 2.));
  bar_placement[2] = G4Transform3D(
      rm0,
      reference_point + G4ThreeVector(-(lower_base_length - bar_width) / 2.,
                                      -(height - bar_width) / 2., 0. * m));
  bar_placement[3] = G4Transform3D(
      rm0, reference_point + G4ThreeVector((lower_base_length - bar_width) / 2.,
                                           -(height - bar_width) / 2., 0. * m));
  bar_placement[4] = G4Transform3D(
      rm0,
      reference_point +
          G4ThreeVector(-(upper_base_length + bar_width) / 2. + displacement,
                        -(height - bar_width) / 2., 0. * m));
  bar_placement[5] = G4Transform3D(
      rm0,
      reference_point +
          G4ThreeVector((upper_base_length + bar_width) / 2. - displacement,
                        -(height - bar_width) / 2., 0. * m));
  // Solids
  for (G4int i = 0; i < 2; i++) {
    name = GetName("Bar_base", i + 1);
    bar_base[i] = new G4Box(name.c_str(), bar_width / 2., bar_width / 2.,
                            lower_base_length / 2.);
  }
  for (G4int i = 2; i < 6; i++) {
    name = GetName("Bar_base", i + 1);
    bar_base[i] = new G4Box(name.c_str(), bar_width / 2., bar_width / 2.,
                            lower_base_length / 2. - bar_width);
  }

  // Upper bars
  bar_placement[6] = G4Transform3D(
      rm1,
      reference_point + G4ThreeVector(-(upper_base_length - displacement) / 2.,
                                      (height - bar_width) / 2.,
                                      -(lower_base_length - bar_width) / 2.));
  bar_placement[7] = G4Transform3D(
      rm1,
      reference_point + G4ThreeVector((upper_base_length - displacement) / 2.,
                                      (height - bar_width) / 2.,
                                      -(lower_base_length - bar_width) / 2.));
  bar_placement[8] = G4Transform3D(
      rm1,
      reference_point + G4ThreeVector(-(upper_base_length - displacement) / 2.,
                                      (height - bar_width) / 2.,
                                      (lower_base_length - bar_width) / 2.));
  bar_placement[9] = G4Transform3D(
      rm1,
      reference_point + G4ThreeVector((upper_base_length - displacement) / 2.,
                                      (height - bar_width) / 2.,
                                      (lower_base_length - bar_width) / 2.));
  bar_placement[10] = G4Transform3D(
      rm0,
      reference_point +
          G4ThreeVector(-(upper_base_length + bar_width) / 2. + displacement,
                        (height - bar_width) / 2., 0. * m));
  bar_placement[11] = G4Transform3D(
      rm0,
      reference_point +
          G4ThreeVector((upper_base_length + bar_width) / 2. - displacement,
                        (height - bar_width) / 2., 0. * m));
  // Solids
  for (G4int i = 6; i < 10; i++) {
    name = GetName("Bar_base", i + 1);
    bar_base[i] = new G4Box(name.c_str(), bar_width / 2., bar_width / 2.,
                            displacement / 2.);
  }
  for (G4int i = 10; i < 12; i++) {
    name = GetName("Bar_base", i + 1);
    bar_base[i] = new G4Box(name.c_str(), bar_width / 2., bar_width / 2.,
                            lower_base_length / 2. - bar_width);
  }

  // Vertical bars
  bar_placement[12] = G4Transform3D(
      rm2,
      reference_point +
          G4ThreeVector(-(upper_base_length + bar_width) / 2. + displacement,
                        0. * m, -(lower_base_length - bar_width) / 2.));
  bar_placement[13] = G4Transform3D(
      rm2,
      reference_point +
          G4ThreeVector((upper_base_length + bar_width) / 2. - displacement,
                        0. * m, -(lower_base_length - bar_width) / 2.));
  bar_placement[14] = G4Transform3D(
      rm2,
      reference_point +
          G4ThreeVector(-(upper_base_length + bar_width) / 2. + displacement,
                        0. * m, (lower_base_length - bar_width) / 2.));
  bar_placement[15] = G4Transform3D(
      rm2,
      reference_point +
          G4ThreeVector((upper_base_length + bar_width) / 2. - displacement,
                        0. * m, (lower_base_length - bar_width) / 2.));
  // Solids
  for (G4int i = 12; i < 16; i++) {
    name = GetName("Bar_base", i + 1);
    bar_base[i] = new G4Box(name.c_str(), bar_width / 2., bar_width / 2.,
                            height / 2. - bar_width);
  }

  // Diagonal bars
  G4double x_bar = bar_width / (cos(alpha));
  G4double y_bar = height - 2. * bar_width;
  G4double z_bar = bar_width;
  bar_placement[16] = G4Transform3D(
      rm0, reference_point +
               G4ThreeVector(
                   -(upper_base_length + lower_base_length) / 4. + x_bar / 2.,
                   0., -(lower_base_length - bar_width) / 2.));
  bar_placement[17] = G4Transform3D(
      rm0, reference_point +
               G4ThreeVector(
                   (upper_base_length + lower_base_length) / 4. - x_bar / 2.,
                   0., -(lower_base_length - bar_width) / 2.));
  bar_placement[18] = G4Transform3D(
      rm0, reference_point +
               G4ThreeVector(
                   -(upper_base_length + lower_base_length) / 4. + x_bar / 2.,
                   0., (lower_base_length - bar_width) / 2.));
  bar_placement[19] = G4Transform3D(
      rm0, reference_point +
               G4ThreeVector(
                   (upper_base_length + lower_base_length) / 4. - x_bar / 2.,
                   0., (lower_base_length - bar_width) / 2.));
  // Solids
  for (G4int i = 16; i < 20; i++) {
    name = GetName("Bar_base", i + 1);
    bar_base[i] = new G4Para(name.c_str(), x_bar / 2., y_bar / 2., z_bar / 2.,
                             pow(-1, i) * alpha, 0. * deg, 0. * deg);
  }

  for (G4int i = 0; i < 16; i++) {
    name = GetName("Al_bar", i + 1);
    hollow_bar[i] = new G4SubtractionSolid(name.c_str(), bar_base[i],
                                           straight_hole, 0, G4ThreeVector());
  }
  for (G4int i = 16; i < 20; i++) {
    name = GetName("Al_bar", i + 1);
    hollow_bar[i] = new G4SubtractionSolid(
        name.c_str(), bar_base[i], skewed_hole[i % 2], 0, G4ThreeVector());
  }

  // Placement all bars
  for (G4int i = 0; i < bars; i++) {
    name = GetName("Al_bar", i + 1);
    logic_bar[i] = new G4LogicalVolume(hollow_bar[i], Al_alloy, name.c_str());
    //    phys_bar[i] =
    new G4PVPlacement(bar_placement[i], logic_bar[i], name.c_str(), mother,
                      false, flagOverlaps);
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4String C6D6DetectorConstruction::GetName(G4String name, G4int number) {
  ostringstream* buffer = new ostringstream;
  *buffer << number;
  name += (*buffer).str();
  delete buffer;
  return name;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6DetectorConstruction::ConstructSDandField() {
  G4SDManager* sdManager = G4SDManager::GetSDMpointer();

  C6D6SensitiveDetector* theC6D6SensitiveDetector =
      new C6D6SensitiveDetector("C6D6SensitiveDetector");
  sdManager->AddNewDetector(theC6D6SensitiveDetector);
  if (theInputManager->IsB6D6Defined()) {
    BfLogicC6D6->SetSensitiveDetector(theC6D6SensitiveDetector);
  }
  if (theInputManager->IsL6D6Defined()) {
    LfLogicC6D6->SetSensitiveDetector(theC6D6SensitiveDetector);
  }
  if (theInputManager->IsS6D6Defined()) {
    SfLogicC6D6->SetSensitiveDetector(theC6D6SensitiveDetector);
  }
  if (theInputManager->IsESTIDefined()) {
    EfLogicC6D6->SetSensitiveDetector(theC6D6SensitiveDetector);
  }

  C6D6SensitiveTarget* theC6D6SensitiveTarget =
      new C6D6SensitiveTarget("C6D6SensitiveTarget");
  sdManager->AddNewDetector(theC6D6SensitiveTarget);
  logic_target->SetSensitiveDetector(theC6D6SensitiveTarget);
}

void C6D6DetectorConstruction::ConstructBeamLineEAR2AndSampleHolder_Cm244(
    G4LogicalVolume* mother) {
  ///////////////////////////
  //////SAMPLE HOLDER SHolder////////
  ///////////////////////////

  G4double SHolder1Lhalf = 8.0 / 2.0 * cm;
  G4double SHolder1R = 8.60 / 2.0 * cm;
  G4double SHolder1r = 8.20 / 2.0 * cm;

  G4double SHolder2Lhalf = 0.25 / 2.0 * cm;
  G4double SHolder2R = 9.50 / 2.0 * cm;
  G4double SHolder2r = 8.20 / 2.0 * cm;

  G4double SHolder3Lhalf = 0.5 / 2.0 * cm;
  G4double SHolder3R = 9.50 / 2.0 * cm;
  G4double SHolder3r = 9.00 / 2.0 * cm;

  G4double SHolder4Lhalf = 0.25 / 2.0 * cm;
  G4double SHolder4RUp = 9.50 / 2.0 * cm;
  G4double SHolder4rUp = 9.50 / 2.0 * cm;
  G4double SHolder4RDown = 9.50 / 2.0 * cm;
  G4double SHolder4rDown = 9.00 / 2.0 * cm;

  G4double SHolder5x = 7.0 / 2.0 * cm;
  G4double SHolder5y = 3 / 2.0 * cm;
  G4double SHolder5z = 2 / 2.0 * cm;
  ///////////////////////////
  //////DownPipe  DownPipe////////
  ///////////////////////////

  G4double DownPipe1Lhalf = 0.75 / 2.0 * cm;
  G4double DownPipe1R = 16.6 / 2.0 * cm;
  G4double DownPipe1r = 7.0 / 2.0 * cm;

  G4double DownPipe2Lhalf = 0.5 / 2.0 * cm;
  G4double DownPipe2R = 16.6 / 2.0 * cm;
  G4double DownPipe2r = 7 / 2.0 * cm;

  G4double DownPipe3Lhalf = 37.8 / 2.0 * cm;
  G4double DownPipe3R = 7.5 / 2.0 * cm;
  G4double DownPipe3r = 7 / 2.0 * cm;

  G4double DownPipe4Lhalf = 1.24 / 2.0 * cm;
  G4double DownPipe4R = 8.2 / 2.0 * cm;
  G4double DownPipe4r = 7.5 / 2.0 * cm;

  G4double DownPipeDistanceInsideSampleHolder = 4.1 * cm;

  ///////////////////////////
  //////UpPipe  UpPipe////////
  ///////////////////////////

  G4double UpPipe1Lhalf = 1.0 / 2.0 * cm;
  G4double UpPipe1R = 16.7 / 2.0 * cm;
  G4double UpPipe1r = 8.7 / 2.0 * cm;

  G4double UpPipe2Lhalf = 52.0 / 2.0 * cm;
  G4double UpPipe2R = 9.0 / 2.0 * cm;
  G4double UpPipe2r = 8.7 / 2.0 * cm;

  G4double UpPipe3Lhalf = 0.9 / 2.0 * cm;
  G4double UpPipe3R = 9.2 / 2.0 * cm;
  G4double UpPipe3r = 9 / 2.0 * cm;
  G4double UpPipe3DistanceBorder = 0.6 * cm;

  G4double UpPipeDistanceToSampleHolder = 15 * cm;

  //-------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------

  ///////////////////////////////
  //////SAMPLE HOLDER SHolder////////
  ///////////////////////////////
  G4Tubs* SOLIDSHolder1 = new G4Tubs("SOLIDSHolder1", SHolder1r, SHolder1R,
                                     SHolder1Lhalf, 0. * deg, 360. * deg);

  G4Tubs* SOLIDSHolder2 = new G4Tubs("SOLIDSHolder2", SHolder2r, SHolder2R,
                                     SHolder2Lhalf, 0. * deg, 360. * deg);

  G4Tubs* SOLIDSHolder3 = new G4Tubs("SOLIDSHolder3", SHolder3r, SHolder3R,
                                     SHolder3Lhalf, 0. * deg, 360. * deg);

  G4Cons* SOLIDSHolder4 =
      new G4Cons("SOLIDSHolder4", SHolder4rDown, SHolder4RDown, SHolder4rUp,
                 SHolder4RUp, SHolder4Lhalf, 0. * deg, 360. * deg);
  G4Box* SOLIDSHolder5 =
      new G4Box("SOLIDSHolder5", SHolder5x, SHolder5y, SHolder5z);

  ////////////////////////////////////////////
  //////////////////////////////////////////

  G4UnionSolid* SOLIDSHolderinter1 = new G4UnionSolid(
      "SOLIDSHolderinter1", SOLIDSHolder1, SOLIDSHolder2, 0,
      G4ThreeVector(0. * mm, 0. * mm, SHolder1Lhalf + SHolder2Lhalf));
  G4UnionSolid* SOLIDSHolderinter2 = new G4UnionSolid(
      "SOLIDSHolderinter2", SOLIDSHolderinter1, SOLIDSHolder3, 0,
      G4ThreeVector(0. * mm, 0. * mm,
                    SHolder1Lhalf + 2 * SHolder2Lhalf + SHolder3Lhalf));
  G4UnionSolid* SOLIDSHolderinter3 = new G4UnionSolid(
      "SOLIDSHolderinter3", SOLIDSHolderinter2, SOLIDSHolder4, 0,
      G4ThreeVector(0. * mm, 0. * mm,
                    SHolder1Lhalf + 2 * SHolder2Lhalf + 2 * SHolder3Lhalf +
                        SHolder4Lhalf));
  G4SubtractionSolid* SOLIDSHolderinter4 = new G4SubtractionSolid(
      "SOLIDSHolderinter4", SOLIDSHolderinter3, SOLIDSHolder5, 0,
      G4ThreeVector(0. * mm, SHolder3R - SHolder5y,
                    SHolder1Lhalf + 2 * SHolder2Lhalf + 2 * SHolder3Lhalf +
                        2 * SHolder4Lhalf - SHolder5z));
  G4LogicalVolume* LOGSHolderinter =
      new G4LogicalVolume(SOLIDSHolderinter4, AlAW6082, "SHolder");
  G4ThreeVector positionSHolder = G4ThreeVector(
      0 * cm, 0. * cm, -SHolder1Lhalf - 2 * SHolder2Lhalf);  // CHANGED

  // G4ThreeVector positionSHolder = G4ThreeVector(0*cm,0.*cm,0.*cm);    //
  // CHANGED
  G4RotationMatrix rotm_SHolder = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_SHolder =
      G4Transform3D(rotm_SHolder, positionSHolder);

  // theBeamPipe->AddPlacedVolume(LOGSHolderinter,transform_SHolder);
  new G4PVPlacement(transform_SHolder,  // rotation,position
                    LOGSHolderinter,    // its logical volume
                    "SHolderinter",     // its name
                    mother,             // its mother  volume
                    false,              // no boolean operation
                    0,                  // copy number
                    flagOverlaps);      // checking overlaps

  LOGSHolderinter->SetVisAttributes(new G4VisAttributes(G4Colour::Green()));

  ///////////////////////////
  //////DownPipe  DownPipe////////
  ///////////////////////////

  G4Tubs* SOLIDDownPipe1 = new G4Tubs("SOLIDDownPipe1", DownPipe1r, DownPipe1R,
                                      DownPipe1Lhalf, 0. * deg, 360. * deg);

  G4Tubs* SOLIDDownPipe2 = new G4Tubs("SOLIDDownPipe2", DownPipe2r, DownPipe2R,
                                      DownPipe2Lhalf, 0. * deg, 360. * deg);

  G4Tubs* SOLIDDownPipe3 = new G4Tubs("SOLIDDownPipe3", DownPipe3r, DownPipe3R,
                                      DownPipe3Lhalf, 0. * deg, 360. * deg);
  G4Tubs* SOLIDDownPipe4 = new G4Tubs("SOLIDDownPipe4", DownPipe4r, DownPipe4R,
                                      DownPipe4Lhalf, 0. * deg, 360. * deg);

  ////////////////////////////////////////////
  //////////////////////////////////////////

  G4UnionSolid* SOLIDDownPipeinter1 = new G4UnionSolid(
      "SOLIDDownPipeinter1", SOLIDDownPipe1, SOLIDDownPipe2, 0,
      G4ThreeVector(0. * mm, 0. * mm, DownPipe1Lhalf + DownPipe2Lhalf));
  G4UnionSolid* SOLIDDownPipeinter2 = new G4UnionSolid(
      "SOLIDDownPipeinter2", SOLIDDownPipeinter1, SOLIDDownPipe3, 0,
      G4ThreeVector(0. * mm, 0. * mm,
                    DownPipe1Lhalf + 2 * DownPipe2Lhalf + DownPipe3Lhalf));
  G4UnionSolid* SOLIDDownPipeinter3 = new G4UnionSolid(
      "SOLIDDownPipeinter3", SOLIDDownPipeinter2, SOLIDDownPipe4, 0,
      G4ThreeVector(0. * mm, 0. * mm,
                    DownPipe1Lhalf + 2 * DownPipe2Lhalf + 2 * DownPipe3Lhalf -
                        DownPipe4Lhalf));

  ////////////////////////////////////////////
  //////////////////////////////////////////

  G4LogicalVolume* LOGDownPipeinter =
      new G4LogicalVolume(SOLIDDownPipeinter3, AlAW6082, "DownPipe");
  G4ThreeVector positionDownPipe =
      G4ThreeVector(0 * cm, 0. * cm,
                    -DownPipe1Lhalf - 2 * DownPipe2Lhalf - 2 * DownPipe3Lhalf -
                        2 * SHolder1Lhalf + DownPipeDistanceInsideSampleHolder -
                        2 * SHolder2Lhalf);
  G4RotationMatrix rotm_DownPipe = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_DownPipe =
      G4Transform3D(rotm_DownPipe, positionDownPipe);
  // theBeamPipe->AddPlacedVolume(LOGDownPipeinter,transform_DownPipe);

  new G4PVPlacement(transform_DownPipe,  // rotation,position
                    LOGDownPipeinter,    // its logical volume
                    "DownPipe",          // its name
                    mother,              // its mother  volume
                    false,               // no boolean operation
                    0,                   // copy number
                    flagOverlaps);       // checking overlaps

  LOGDownPipeinter->SetVisAttributes(new G4VisAttributes(G4Colour::Yellow()));

  /// Cascate to Simulate the KaptonAluminizade Window;

  G4double thick = 100 * um;  // thick of the Kapton
  G4double pSTheta = 0 * deg;
  G4double RSphere =
      15 / 2.0 *
      cm;  // Radius Real Sphere, It is a Way of seeing how deep is the hole,
           // for a infinitive big sphere it gives a flat surface.
  G4double obertura = DownPipe3r;  /// radius of the Kapton Window

  G4double LCascate = sqrt(RSphere * RSphere - obertura * obertura);
  G4double pDTheta = acos(LCascate / RSphere);
  //  G4cout<<"LCascate/RSphere"<<LCascate/RSphere<<"Acos(0.88440.5=
  //  "<<acos(0.8844)<<"obertura"<<obertura<<"LCascate "<<LCascate<<"pDTheta
  //  "<<pDTheta<<G4endl;

  G4Sphere* SOLIDDownPipeWindow =
      new G4Sphere("TubeWindow", RSphere - thick, RSphere, 0. * deg, 360. * deg,
                   pSTheta, pDTheta);
  G4LogicalVolume* LOGDownPipeWindow = new G4LogicalVolume(
      SOLIDDownPipeWindow, AluminizedKaptonPRELIMINAR, "DownPipeWindow");

  G4ThreeVector positionDownPipeWindow =
      G4ThreeVector(0 * cm, 0. * cm,
                    -2 * SHolder1Lhalf + DownPipeDistanceInsideSampleHolder +
                        LCascate - 2 * SHolder2Lhalf);

  G4RotationMatrix rotm_DownPipeWindow = G4RotationMatrix(0, 180 * deg, 0);
  G4Transform3D transform_DownPipeWindow =
      G4Transform3D(rotm_DownPipeWindow, positionDownPipeWindow);
  //  theBeamPipe->AddPlacedVolume(LOGDownPipeWindow,transform_DownPipeWindow);

  new G4PVPlacement(transform_DownPipeWindow,  // rotation,position
                    LOGDownPipeWindow,         // its logical volume
                    "DownPipeWindow",          // its name
                    mother,                    // its mother  volume
                    false,                     // no boolean operation
                    0,                         // copy number
                    flagOverlaps);             // checking overlaps

  LOGDownPipeWindow->SetVisAttributes(new G4VisAttributes(G4Colour::Magenta()));

  ///////////////////////////
  //////UpPipe  UpPipe////////
  ///////////////////////////

  G4Tubs* SOLIDUpPipe1 = new G4Tubs("SOLIDUpPipe1", UpPipe1r, UpPipe1R,
                                    UpPipe1Lhalf, 0. * deg, 360. * deg);

  G4Tubs* SOLIDUpPipe2 = new G4Tubs("SOLIDUpPipe2", UpPipe2r, UpPipe2R,
                                    UpPipe2Lhalf, 0. * deg, 360. * deg);

  G4Tubs* SOLIDUpPipe3 = new G4Tubs("SOLIDUpPipe3", UpPipe3r, UpPipe3R,
                                    UpPipe3Lhalf, 0. * deg, 360. * deg);

  ////////////////////////////////////////////
  //////////////////////////////////////////

  G4UnionSolid* SOLIDUpPipeinter1 = new G4UnionSolid(
      "SOLIDUpPipeinter1", SOLIDUpPipe1, SOLIDUpPipe2, 0,
      G4ThreeVector(0. * mm, 0. * mm, -UpPipe1Lhalf - UpPipe2Lhalf));
  G4UnionSolid* SOLIDUpPipeinter2 =
      new G4UnionSolid("SOLIDUpPipeinter2", SOLIDUpPipeinter1, SOLIDUpPipe3, 0,
                       G4ThreeVector(0. * mm, 0. * mm,
                                     -UpPipe1Lhalf - 2 * UpPipe2Lhalf +
                                         UpPipe3Lhalf + UpPipe3DistanceBorder));

  ////////////////////////////////////////////
  //////////////////////////////////////////

  G4LogicalVolume* LOGUpPipeinter =
      new G4LogicalVolume(SOLIDUpPipeinter2, AlAW6082, "UpPipe");
  G4ThreeVector positionUpPipe = G4ThreeVector(
      0 * cm, 0. * cm,
      +UpPipe1Lhalf + 2 * UpPipe2Lhalf + UpPipeDistanceToSampleHolder);
  G4RotationMatrix rotm_UpPipe = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_UpPipe = G4Transform3D(rotm_UpPipe, positionUpPipe);
  // theBeamPipe->AddPlacedVolume(LOGUpPipeinter,transform_UpPipe);
  new G4PVPlacement(transform_UpPipe,  // rotation,position
                    LOGUpPipeinter,    // its logical volume
                    "UpPipe",          // its name
                    mother,            // its mother  volume
                    false,             // no boolean operation
                    0,                 // copy number
                    flagOverlaps);     // checking overlaps

  LOGUpPipeinter->SetVisAttributes(new G4VisAttributes(G4Colour::Yellow()));

  /// Cascate to Simulate the KaptonAluminizade Window;

  G4double Upthick = 50 * um;  // thick of the Kapton
  G4double UppSTheta = 0 * deg;
  G4double UpRSphere =
      15 / 2.0 *
      cm;  // Radius Real Sphere, It is a Way of seeing how deep is the hole,
           // for a infinitive big sphere it gives a flat surface.
  G4double Upobertura = UpPipe2r;  /// radius of the Kapton Window

  G4double UpLCascate = sqrt(UpRSphere * UpRSphere - Upobertura * Upobertura);
  G4double UppDTheta = acos(UpLCascate / UpRSphere);
  //  G4cout<<"LCascate/RSphere"<<LCascate/RSphere<<"Acos(0.88440.5=
  //  "<<acos(0.8844)<<"obertura"<<obertura<<"LCascate "<<LCascate<<"pDTheta
  //  "<<pDTheta<<G4endl;

  G4Sphere* SOLIDUpPipeWindow =
      new G4Sphere("TubeWindow", UpRSphere - Upthick, UpRSphere, 0. * deg,
                   360. * deg, UppSTheta, UppDTheta);
  G4LogicalVolume* LOGUpPipeWindow =
      new G4LogicalVolume(SOLIDUpPipeWindow, kapton, "UpPipeWindow");

  G4ThreeVector positionUpPipeWindow =
      G4ThreeVector(0 * cm, 0. * cm, UpPipeDistanceToSampleHolder - UpLCascate);

  G4RotationMatrix rotm_UpPipeWindow = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_UpPipeWindow =
      G4Transform3D(rotm_UpPipeWindow, positionUpPipeWindow);
  // theBeamPipe->AddPlacedVolume(LOGUpPipeWindow,transform_UpPipeWindow);

  new G4PVPlacement(transform_UpPipeWindow,  // rotation,position
                    LOGUpPipeWindow,         // its logical volume
                    "UpPipeWindow",          // its name
                    mother,                  // its mother  volume
                    false,                   // no boolean operation
                    0,                       // copy number
                    flagOverlaps);           // checking overlaps

  LOGUpPipeWindow->SetVisAttributes(new G4VisAttributes(G4Colour::Magenta()));
}

void C6D6DetectorConstruction::ConstructStru27sTED_2024(
    G4LogicalVolume* mother) {
  G4double RingLhalf = 1 / 2.0 * cm;
  G4double RingR = 31 * cm;
  G4double Ringr = 26.5 * cm;
  G4double RingHeight = 5.1 * cm + RingLhalf;

  G4double SmallRingLhalf = 0.4 / 2.0 * cm;
  G4double SmallRingR = 5.75 * cm;
  G4double SmallRingr = 3.75 * cm;
  G4double SmallRingHeight = RingHeight + 0.4 * cm;

  G4double ArmL = 0.4 * cm;
  G4double ArmLength = 3 * cm;
  G4double ArmThick = 9.5 * cm;

  G4double ArmHeight = RingHeight;
  G4double ArmDistanceToCenter = 16.5 * cm;

  G4double SmallArmL = 0.4 * cm;
  G4double SmallArmLength = 2 * cm;
  G4double SmallArmThick = 14.5 * cm;

  G4double SmallArmHeight = SmallRingHeight;
  G4double SmallArmDistanceToCenter = SmallRingR;

  ////////////////////////////////////////////
  //////////////////////////////////////////
  ///////////////////////////////////////////////
  //////////////////////////////////////////

  G4Tubs* SOLIDSRing =
      new G4Tubs("SOLIDSRing", Ringr, RingR, RingLhalf, 0. * deg, 360. * deg);

  G4LogicalVolume* LOGSRinginter =
      new G4LogicalVolume(SOLIDSRing, AlAW6082, "SRing");
  G4ThreeVector positionSRing =
      G4ThreeVector(0 * cm, 0. * cm, -RingHeight - RingLhalf);  // CHANGED

  G4RotationMatrix rotm_SRing = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_SRing = G4Transform3D(rotm_SRing, positionSRing);
  new G4PVPlacement(transform_SRing,  // rotation,position
                    LOGSRinginter,    // its logical volume
                    "SRinginter",     // its name
                    mother,           // its mother  volume
                    false,            // no boolean operation
                    0,                // copy number
                    flagOverlaps);    // checking overlaps

  LOGSRinginter->SetVisAttributes(new G4VisAttributes(G4Colour::Green()));

  ////////////////////////////////////////////
  //////////////////////////////////////////
  ///////////////////////////////////////////////
  //////////////////////////////////////////

  G4Tubs* SOLIDSSmallRing =
      new G4Tubs("SOLIDSSmallRing", SmallRingr, SmallRingR, SmallRingLhalf,
                 0. * deg, 360. * deg);

  G4LogicalVolume* LOGSSmallRinginter =
      new G4LogicalVolume(SOLIDSSmallRing, AlAW6082, "SSmallRing");
  G4ThreeVector positionSSmallRing = G4ThreeVector(
      0 * cm, 0. * cm, -SmallRingHeight - SmallRingLhalf);  // CHANGED

  G4RotationMatrix rotm_SSmallRing = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_SSmallRing =
      G4Transform3D(rotm_SSmallRing, positionSSmallRing);
  new G4PVPlacement(transform_SSmallRing,  // rotation,position
                    LOGSSmallRinginter,    // its logical volume
                    "SSmallRinginter",     // its name
                    mother,                // its mother  volume
                    false,                 // no boolean operation
                    0,                     // copy number
                    flagOverlaps);         // checking overlaps

  LOGSSmallRinginter->SetVisAttributes(new G4VisAttributes(G4Colour::Red()));

  ////////////////////////////////////////////
  //////////////////////////////////////////
  ///////////////////////////////////////////////
  //////////////////////////////////////////

  G4Box* ssolidArm = new G4Box("sArm", ArmLength / 2, ArmThick / 2, ArmL / 2);

  G4LogicalVolume* slogicArm = new G4LogicalVolume(ssolidArm,  // its solid
                                                   AlAW6082,   // its material
                                                   "sArm");    // its name

  int const NumberPieces = 9;
  double AnglesPieces[NumberPieces] = {0, 40, 80, 120, 160, 200, 240, 280, 320};
  double rArm1 = ArmDistanceToCenter + ArmThick / 2;

  G4double rArm[NumberPieces] = {rArm1, rArm1, rArm1, rArm1, rArm1,
                                 rArm1, rArm1, rArm1, rArm1};

  for (int i = 0; i < (NumberPieces); i++) {
    G4RotationMatrix rotArm[50];
    G4ThreeVector posArm[50];
    char name[1000];

    G4cout << "Build Arm_" << i << " thetaArm= " << AnglesPieces[i] << G4endl;
    rotArm[i] = G4RotationMatrix();
    rotArm[i].rotateZ((AnglesPieces[i] + 90) * deg);
    // rArm[i] = ArmDistanceToCenter + ArmThick / 2;
    posArm[i] = G4ThreeVector(-rArm[i] * cos(AnglesPieces[i] * deg),
                              -rArm[i] * sin(AnglesPieces[i] * deg),
                              -ArmHeight - ArmL / 2);
    sprintf(name, "Arm_%d", i);
    //      physiArm[i] =
    new G4PVPlacement(G4Transform3D(rotArm[i], posArm[i]),
                      slogicArm,  // its logical volume
                      name,
                      mother,  // its
                      false,   // no boolean operation
                      i,       // copy number
                      flagOverlaps);
  }
  slogicArm->SetVisAttributes(new G4VisAttributes(G4Colour::Green()));

  ////////////////////////////////////////////
  //////////////////////////////////////////
  ///////////////////////////////////////////////
  //////////////////////////////////////////

  G4Box* ssolidSmallArm = new G4Box("sSmallArm", SmallArmLength / 2,
                                    SmallArmThick / 2, SmallArmL / 2);

  G4LogicalVolume* slogicSmallArm =
      new G4LogicalVolume(ssolidSmallArm,  // its solid
                          AlAW6082,        // its material
                          "sSmallArm");    // its name

  int const SmallNumberPieces = 3;
  double SmallAnglesPieces[SmallNumberPieces] = {0, 120, 240};
  double rSmallArm1 = SmallArmDistanceToCenter + SmallArmThick / 2;

  G4double rSmallArm[SmallNumberPieces] = {rSmallArm1, rSmallArm1, rSmallArm1};

  for (int i = 0; i < (SmallNumberPieces); i++) {
    G4RotationMatrix rotSmallArm[50];
    G4ThreeVector posSmallArm[50];
    char name[1000];

    G4cout << "Build SmallArm_" << i << " thetaSmallArm= " << AnglesPieces[i]
           << G4endl;
    rotSmallArm[i] = G4RotationMatrix();
    rotSmallArm[i].rotateZ((SmallAnglesPieces[i] + 90) * deg);
    // rSmallArm[i] = SmallArmDistanceToCenter + SmallArmThick / 2;
    posSmallArm[i] =
        G4ThreeVector(-rSmallArm[i] * cos(SmallAnglesPieces[i] * deg),
                      -rSmallArm[i] * sin(SmallAnglesPieces[i] * deg),
                      -SmallArmHeight - SmallArmL / 2);
    sprintf(name, "SmallArm_%d", i);
    //      physiSmallArm[i] =
    new G4PVPlacement(G4Transform3D(rotSmallArm[i], posSmallArm[i]),
                      slogicSmallArm,  // its logical volume
                      name,
                      mother,  // its
                      false,   // no boolean operation
                      i,       // copy number
                      flagOverlaps);
  }
  slogicSmallArm->SetVisAttributes(new G4VisAttributes(G4Colour::Red()));
}

void C6D6DetectorConstruction::ConstructsTED_LeadRing(G4LogicalVolume* mother) {
  G4double RingLhalf = 4 / 2.0 * cm;
  G4double RingR = 4.5 * cm;
  G4double Ringr = 4.0 * cm;

  // G4double RingR = 5.0 * cm;
  // G4double Ringr = 4.5 * cm;
  ////////////////////////////////////////////
  //////////////////////////////////////////
  ///////////////////////////////////////////////
  //////////////////////////////////////////

  G4Tubs* SOLIDSRing =
      new G4Tubs("SOLIDSRing", Ringr, RingR, RingLhalf, 0. * deg, 360. * deg);

  G4LogicalVolume* LOGSRinginter = new G4LogicalVolume(SOLIDSRing, Pb, "SRing");
  G4ThreeVector positionSRing =
      G4ThreeVector(0 * cm, 0. * cm, 0 * cm);  // CHANGED

  G4RotationMatrix rotm_SRing = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_SRing = G4Transform3D(rotm_SRing, positionSRing);
  new G4PVPlacement(transform_SRing,  // rotation,position
                    LOGSRinginter,    // its logical volume
                    "SRinginter",     // its name
                    mother,           // its mother  volume
                    false,            // no boolean operation
                    0,                // copy number
                    flagOverlaps);    // checking overlaps

  LOGSRinginter->SetVisAttributes(new G4VisAttributes(G4Colour::Black()));

  ////////////////////////////////////////////
  //////////////////////////////////////////
  ///////////////////////////////////////////////
  //////////////////////////////////////////
}

void C6D6DetectorConstruction::ConstructPoly27sTED_2024(
    G4LogicalVolume* mother) {
  G4double ArmL = 20 * cm;
  G4double ArmLength = 0.5 * cm;
  G4double ArmThick = 10 * cm;

  G4double ArmHeight = 0 * cm;
  G4double ArmDistanceToCenter = 5.5 * cm;

  ////////////////////////////////////////////
  //////////////////////////////////////////
  ///////////////////////////////////////////////P
  //////////////////////////////////////////

  ////////////////////////////////////////////
  //////////////////////////////////////////
  ///////////////////////////////////////////////
  //////////////////////////////////////////

  // G4Box* ssolidArm = new G4Box("sArm", ArmLength / 2, ArmThick / 2, ArmL /
  // 2);

  G4Tubs* ssolidArm =
      new G4Tubs("sArm", 0, ArmL, ArmThick / 2.0, -20 * deg, 40 * deg);

  G4LogicalVolume* slogicArm = new G4LogicalVolume(ssolidArm,   // its solid
                                                   PolDopedLi,  // its material
                                                   "sArm");     // its name

  int const NumberPieces = 9;
  double AnglesPieces[NumberPieces] = {20,  60,  100, 140, 180,
                                       220, 260, 300, 340};
  double rArm1 = ArmDistanceToCenter;

  G4double rArm[NumberPieces] = {rArm1, rArm1, rArm1, rArm1, rArm1,
                                 rArm1, rArm1, rArm1, rArm1};

  for (int i = 0; i < (NumberPieces); i++) {
    G4RotationMatrix rotArm[50];
    G4ThreeVector posArm[50];
    char name[1000];

    G4cout << "Build Arm_" << i << " thetaArm= " << AnglesPieces[i] << G4endl;
    rotArm[i] = G4RotationMatrix();
    rotArm[i].rotateZ((AnglesPieces[i] + 180) * deg);
    // rArm[i] = ArmDistanceToCenter + ArmThick / 2;
    posArm[i] =
        G4ThreeVector(-rArm[i] * cos(AnglesPieces[i] * deg),
                      -rArm[i] * sin(AnglesPieces[i] * deg), -ArmHeight);
    sprintf(name, "Arm_%d", i);
    //      physiArm[i] =
    new G4PVPlacement(G4Transform3D(rotArm[i], posArm[i]),
                      slogicArm,  // its logical volume
                      name,
                      mother,  // its
                      false,   // no boolean operation
                      i,       // copy number
                      flagOverlaps);
  }
  slogicArm->SetVisAttributes(new G4VisAttributes(G4Colour::Green()));

  ////////////////////////////////////////////
  //////////////////////////////////////////
  ///////////////////////////////////////////////
  //////////////////////////////////////////
}

void C6D6DetectorConstruction::ConstructLead27sTED_2024(
    G4LogicalVolume* mother) {
  G4double ArmL = 10.5 * cm;
  G4double ArmLength = 0.5 * cm;
  G4double ArmThick = 22 * cm;

  G4double ArmHeight = 0 * cm;
  G4double ArmDistanceToCenter = 5.7 * cm;

  ////////////////////////////////////////////
  //////////////////////////////////////////
  ///////////////////////////////////////////////
  //////////////////////////////////////////

  ////////////////////////////////////////////
  //////////////////////////////////////////
  ///////////////////////////////////////////////
  //////////////////////////////////////////

  G4Box* ssolidArm = new G4Box("sArm", ArmLength / 2, ArmThick / 2, ArmL / 2);

  G4LogicalVolume* slogicArm = new G4LogicalVolume(ssolidArm,  // its solid
                                                   Pb,         // its material
                                                   "sArm");    // its name

  int const NumberPieces = 9;
  double AnglesPieces[NumberPieces] = {20,  60,  100, 140, 180,
                                       220, 260, 300, 340};
  double rArm1 = ArmDistanceToCenter + ArmThick / 2;

  G4double rArm[NumberPieces] = {rArm1, rArm1, rArm1, rArm1, rArm1,
                                 rArm1, rArm1, rArm1, rArm1};

  for (int i = 0; i < (NumberPieces); i++) {
    G4RotationMatrix rotArm[50];
    G4ThreeVector posArm[50];
    char name[1000];

    G4cout << "Build Arm_" << i << " thetaArm= " << AnglesPieces[i] << G4endl;
    rotArm[i] = G4RotationMatrix();
    rotArm[i].rotateZ((AnglesPieces[i] + 90) * deg);
    // rArm[i] = ArmDistanceToCenter + ArmThick / 2;
    posArm[i] =
        G4ThreeVector(-rArm[i] * cos(AnglesPieces[i] * deg),
                      -rArm[i] * sin(AnglesPieces[i] * deg), -ArmHeight);
    sprintf(name, "Arm_%d", i);
    //      physiArm[i] =
    new G4PVPlacement(G4Transform3D(rotArm[i], posArm[i]),
                      slogicArm,  // its logical volume
                      name,
                      mother,  // its
                      false,   // no boolean operation
                      i,       // copy number
                      flagOverlaps);
  }
  slogicArm->SetVisAttributes(new G4VisAttributes(G4Colour::Green()));

  ////////////////////////////////////////////
  //////////////////////////////////////////
  ///////////////////////////////////////////////
  //////////////////////////////////////////
}

void C6D6DetectorConstruction::
    ConstructBeamLineEAR2AndSampleHolder_2021_Commissioning(
        G4LogicalVolume* mother) {
  // There are three pilars to hold the sample holder  that are not simulated
  // maybe it can be done in the future

  ///////////////////////////
  //////SAMPLE HOLDER SHolder////////
  ///////////////////////////

  G4double SHolderLhalf = 0.10 / 2.0 * cm;
  G4double SHolderR = 9.0 / 2.0 * cm;
  G4double SHolderr = 6.0 / 2.0 * cm;

  G4double DistanceDownpipe = 8.25 / 2.0 * cm;

  ///////////////////////////
  //////DownPipe  DownPipe////////
  ///////////////////////////

  G4double DownPipe1Lhalf = 0.75 / 2.0 * cm;
  G4double DownPipe1R = 16.6 / 2.0 * cm;
  G4double DownPipe1r = 7.0 / 2.0 * cm;

  G4double DownPipe2Lhalf = 0.5 / 2.0 * cm;
  G4double DownPipe2R = 16.6 / 2.0 * cm;
  G4double DownPipe2r = 7 / 2.0 * cm;

  G4double DownPipe3Lhalf = 37.8 / 2.0 * cm;
  G4double DownPipe3R = 7.5 / 2.0 * cm;
  G4double DownPipe3r = 7 / 2.0 * cm;

  G4double DownPipe4Lhalf = 1.24 / 2.0 * cm;
  G4double DownPipe4R = 8.2 / 2.0 * cm;
  G4double DownPipe4r = 7.5 / 2.0 * cm;

  /// G4double DownPipeDistanceInsideSampleHolder = 4.1 * cm;
  // modify 2024 for 27 sTED
  G4double DownPipeDistanceInsideSampleHolder = 0 * cm;

  ///////////////////////////
  //////UpPipe  UpPipe////////
  ///////////////////////////

  G4double UpPipe1Lhalf = 1.0 / 2.0 * cm;
  G4double UpPipe1R = 16.7 / 2.0 * cm;
  G4double UpPipe1r = 8.7 / 2.0 * cm;

  G4double UpPipe2Lhalf = 52.0 / 2.0 * cm;
  G4double UpPipe2R = 9.0 / 2.0 * cm;
  G4double UpPipe2r = 8.7 / 2.0 * cm;

  G4double UpPipe3Lhalf = 0.9 / 2.0 * cm;
  G4double UpPipe3R = 9.2 / 2.0 * cm;
  G4double UpPipe3r = 9 / 2.0 * cm;
  G4double UpPipe3DistanceBorder = 0.6 * cm;

  G4double UpPipeDistanceToSampleHolder = 15 * cm;

  //-------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------

  ///////////////////////////////
  //////SAMPLE HOLDER SHolder////////
  ///////////////////////////////
  G4Tubs* SOLIDSHolder = new G4Tubs("SOLIDSHolder", SHolderr, SHolderR,
                                    SHolderLhalf, 0. * deg, 360. * deg);

  ////////////////////////////////////////////
  //////////////////////////////////////////

  G4LogicalVolume* LOGSHolderinter =
      new G4LogicalVolume(SOLIDSHolder, AlAW6082, "SHolder");
  G4ThreeVector positionSHolder =
      G4ThreeVector(0 * cm, 0. * cm, -SHolderLhalf);  // CHANGED

  // G4ThreeVector positionSHolder = G4ThreeVector(0*cm,0.*cm,0.*cm);    //
  // CHANGED
  G4RotationMatrix rotm_SHolder = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_SHolder =
      G4Transform3D(rotm_SHolder, positionSHolder);

  // theBeamPipe->AddPlacedVolume(LOGSHolderinter,transform_SHolder);
  // new G4PVPlacement(transform_SHolder,  // rotation,position
  //                   LOGSHolderinter,    // its logical volume
  //                   "SHolderinter",     // its name
  //                   mother,             // its mother  volume
  //                   false,              // no boolean operation
  //                   0,                  // copy number
  //                   flagOverlaps);      // checking overlaps

  LOGSHolderinter->SetVisAttributes(new G4VisAttributes(G4Colour::Green()));

  ///////////////////////////
  //////DownPipe  DownPipe////////
  ///////////////////////////

  G4Tubs* SOLIDDownPipe1 = new G4Tubs("SOLIDDownPipe1", DownPipe1r, DownPipe1R,
                                      DownPipe1Lhalf, 0. * deg, 360. * deg);

  G4Tubs* SOLIDDownPipe2 = new G4Tubs("SOLIDDownPipe2", DownPipe2r, DownPipe2R,
                                      DownPipe2Lhalf, 0. * deg, 360. * deg);

  G4Tubs* SOLIDDownPipe3 = new G4Tubs("SOLIDDownPipe3", DownPipe3r, DownPipe3R,
                                      DownPipe3Lhalf, 0. * deg, 360. * deg);
  G4Tubs* SOLIDDownPipe4 = new G4Tubs("SOLIDDownPipe4", DownPipe4r, DownPipe4R,
                                      DownPipe4Lhalf, 0. * deg, 360. * deg);

  ////////////////////////////////////////////
  //////////////////////////////////////////

  G4UnionSolid* SOLIDDownPipeinter1 = new G4UnionSolid(
      "SOLIDDownPipeinter1", SOLIDDownPipe1, SOLIDDownPipe2, 0,
      G4ThreeVector(0. * mm, 0. * mm, DownPipe1Lhalf + DownPipe2Lhalf));
  G4UnionSolid* SOLIDDownPipeinter2 = new G4UnionSolid(
      "SOLIDDownPipeinter2", SOLIDDownPipeinter1, SOLIDDownPipe3, 0,
      G4ThreeVector(0. * mm, 0. * mm,
                    DownPipe1Lhalf + 2 * DownPipe2Lhalf + DownPipe3Lhalf));
  G4UnionSolid* SOLIDDownPipeinter3 = new G4UnionSolid(
      "SOLIDDownPipeinter3", SOLIDDownPipeinter2, SOLIDDownPipe4, 0,
      G4ThreeVector(0. * mm, 0. * mm,
                    DownPipe1Lhalf + 2 * DownPipe2Lhalf + 2 * DownPipe3Lhalf -
                        DownPipe4Lhalf));

  ////////////////////////////////////////////
  //////////////////////////////////////////

  G4LogicalVolume* LOGDownPipeinter =
      new G4LogicalVolume(SOLIDDownPipeinter3, AlAW6082, "DownPipe");
  G4ThreeVector positionDownPipe = G4ThreeVector(
      0 * cm, 0. * cm,
      -DownPipe1Lhalf - 2 * DownPipe2Lhalf - 2 * DownPipe3Lhalf -
          2 * DistanceDownpipe + DownPipeDistanceInsideSampleHolder);
  G4RotationMatrix rotm_DownPipe = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_DownPipe =
      G4Transform3D(rotm_DownPipe, positionDownPipe);
  // theBeamPipe->AddPlacedVolume(LOGDownPipeinter,transform_DownPipe);

  new G4PVPlacement(transform_DownPipe,  // rotation,position
                    LOGDownPipeinter,    // its logical volume
                    "DownPipe",          // its name
                    mother,              // its mother  volume
                    false,               // no boolean operation
                    0,                   // copy number
                    flagOverlaps);       // checking overlaps

  LOGDownPipeinter->SetVisAttributes(new G4VisAttributes(G4Colour::Yellow()));

  /// Cascate to Simulate the KaptonAluminizade Window;

  G4double thick = 100 * um;  // thick of the Kapton
  G4double pSTheta = 0 * deg;
  G4double RSphere =
      15 / 2.0 *
      cm;  // Radius Real Sphere, It is a Way of seeing how deep is the hole,
           // for a infinitive big sphere it gives a flat surface.
  G4double obertura = DownPipe3r;  /// radius of the Kapton Window

  G4double LCascate = sqrt(RSphere * RSphere - obertura * obertura);
  G4double pDTheta = acos(LCascate / RSphere);
  //  G4cout<<"LCascate/RSphere"<<LCascate/RSphere<<"Acos(0.88440.5=
  //  "<<acos(0.8844)<<"obertura"<<obertura<<"LCascate "<<LCascate<<"pDTheta
  //  "<<pDTheta<<G4endl;

  G4Sphere* SOLIDDownPipeWindow =
      new G4Sphere("TubeWindow", RSphere - thick, RSphere, 0. * deg, 360. * deg,
                   pSTheta, pDTheta);
  G4LogicalVolume* LOGDownPipeWindow = new G4LogicalVolume(
      SOLIDDownPipeWindow, AluminizedKaptonPRELIMINAR, "DownPipeWindow");

  G4ThreeVector positionDownPipeWindow = G4ThreeVector(
      0 * cm, 0. * cm,
      +DownPipeDistanceInsideSampleHolder + LCascate - 2 * DistanceDownpipe);

  G4RotationMatrix rotm_DownPipeWindow = G4RotationMatrix(0, 180 * deg, 0);
  G4Transform3D transform_DownPipeWindow =
      G4Transform3D(rotm_DownPipeWindow, positionDownPipeWindow);
  //  theBeamPipe->AddPlacedVolume(LOGDownPipeWindow,transform_DownPipeWindow);

  new G4PVPlacement(transform_DownPipeWindow,  // rotation,position
                    LOGDownPipeWindow,         // its logical volume
                    "DownPipeWindow",          // its name
                    mother,                    // its mother  volume
                    false,                     // no boolean operation
                    0,                         // copy number
                    flagOverlaps);             // checking overlaps

  LOGDownPipeWindow->SetVisAttributes(new G4VisAttributes(G4Colour::Magenta()));

  ///////////////////////////
  //////UpPipe  UpPipe////////
  ///////////////////////////

  G4Tubs* SOLIDUpPipe1 = new G4Tubs("SOLIDUpPipe1", UpPipe1r, UpPipe1R,
                                    UpPipe1Lhalf, 0. * deg, 360. * deg);

  G4Tubs* SOLIDUpPipe2 = new G4Tubs("SOLIDUpPipe2", UpPipe2r, UpPipe2R,
                                    UpPipe2Lhalf, 0. * deg, 360. * deg);

  G4Tubs* SOLIDUpPipe3 = new G4Tubs("SOLIDUpPipe3", UpPipe3r, UpPipe3R,
                                    UpPipe3Lhalf, 0. * deg, 360. * deg);

  ////////////////////////////////////////////
  //////////////////////////////////////////

  G4UnionSolid* SOLIDUpPipeinter1 = new G4UnionSolid(
      "SOLIDUpPipeinter1", SOLIDUpPipe1, SOLIDUpPipe2, 0,
      G4ThreeVector(0. * mm, 0. * mm, -UpPipe1Lhalf - UpPipe2Lhalf));
  G4UnionSolid* SOLIDUpPipeinter2 =
      new G4UnionSolid("SOLIDUpPipeinter2", SOLIDUpPipeinter1, SOLIDUpPipe3, 0,
                       G4ThreeVector(0. * mm, 0. * mm,
                                     -UpPipe1Lhalf - 2 * UpPipe2Lhalf +
                                         UpPipe3Lhalf + UpPipe3DistanceBorder));

  ////////////////////////////////////////////
  //////////////////////////////////////////

  G4LogicalVolume* LOGUpPipeinter =
      new G4LogicalVolume(SOLIDUpPipeinter2, AlAW6082, "UpPipe");
  G4ThreeVector positionUpPipe = G4ThreeVector(
      0 * cm, 0. * cm,
      +UpPipe1Lhalf + 2 * UpPipe2Lhalf + UpPipeDistanceToSampleHolder);
  G4RotationMatrix rotm_UpPipe = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_UpPipe = G4Transform3D(rotm_UpPipe, positionUpPipe);
  // theBeamPipe->AddPlacedVolume(LOGUpPipeinter,transform_UpPipe);
  new G4PVPlacement(transform_UpPipe,  // rotation,position
                    LOGUpPipeinter,    // its logical volume
                    "UpPipe",          // its name
                    mother,            // its mother  volume
                    false,             // no boolean operation
                    0,                 // copy number
                    flagOverlaps);     // checking overlaps

  LOGUpPipeinter->SetVisAttributes(new G4VisAttributes(G4Colour::Yellow()));

  /// Cascate to Simulate the KaptonAluminizade Window;

  G4double Upthick = 50 * um;  // thick of the Kapton
  G4double UppSTheta = 0 * deg;
  G4double UpRSphere =
      15 / 2.0 *
      cm;  // Radius Real Sphere, It is a Way of seeing how deep is the hole,
           // for a infinitive big sphere it gives a flat surface.
  G4double Upobertura = UpPipe2r;  /// radius of the Kapton Window

  G4double UpLCascate = sqrt(UpRSphere * UpRSphere - Upobertura * Upobertura);
  G4double UppDTheta = acos(UpLCascate / UpRSphere);
  //  G4cout<<"LCascate/RSphere"<<LCascate/RSphere<<"Acos(0.88440.5=
  //  "<<acos(0.8844)<<"obertura"<<obertura<<"LCascate "<<LCascate<<"pDTheta
  //  "<<pDTheta<<G4endl;

  G4Sphere* SOLIDUpPipeWindow =
      new G4Sphere("TubeWindow", UpRSphere - Upthick, UpRSphere, 0. * deg,
                   360. * deg, UppSTheta, UppDTheta);
  G4LogicalVolume* LOGUpPipeWindow =
      new G4LogicalVolume(SOLIDUpPipeWindow, kapton, "UpPipeWindow");

  G4ThreeVector positionUpPipeWindow =
      G4ThreeVector(0 * cm, 0. * cm, UpPipeDistanceToSampleHolder - UpLCascate);

  G4RotationMatrix rotm_UpPipeWindow = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_UpPipeWindow =
      G4Transform3D(rotm_UpPipeWindow, positionUpPipeWindow);
  // theBeamPipe->AddPlacedVolume(LOGUpPipeWindow,transform_UpPipeWindow);

  new G4PVPlacement(transform_UpPipeWindow,  // rotation,position
                    LOGUpPipeWindow,         // its logical volume
                    "UpPipeWindow",          // its name
                    mother,                  // its mother  volume
                    false,                   // no boolean operation
                    0,                       // copy number
                    flagOverlaps);           // checking overlaps

  LOGUpPipeWindow->SetVisAttributes(new G4VisAttributes(G4Colour::Magenta()));
}

void C6D6DetectorConstruction::ConstructB6D6(G4LogicalVolume* mother,
                                             G4int* flagB6D6,
                                             G4double* thetaB6D6,
                                             G4double* phiB6D6,
                                             G4double* zB6D6) {
  cout << endl << "Construct B6D6 detectors" << endl;

  G4double minRadius = 0;
  G4double startPhi = 0;
  G4double deltaPhi = 360. * deg;
  // G4double DistanceCut=0.000*cm;

  ///////////////////////////////////////////////
  /////C6D6 and Covers////////////////////////////
  ///////////////////////////////////////////////
  // This includes the C6D6 volume, the Teflon tubing, and the Al Case.

  // C6D6+Boundary:
  G4double maxRadiusC6D6 = 5.08 * cm;
  G4double halfLengthC6D6 = 3.81 * cm;
  G4double ThicknessBottom = 0.1 * cm;
  G4double ThicknessWallOutdside = 0.05 * cm;

  // ALU1=Global Al cylinder
  G4double maxRadiusALU1 =
      6.5151 * cm;  // (Diameter of the Bicron Drawing: 6.750inch)/2
  G4double halfLengthALU1 =
      8.67 * cm /
      2;  // Victor extract measuring Drawing(Al Cylinder + firstRing is 8.617.
          // Final used value 8.67 to have space for the C6D6, QUA1 and
          // ThicknessBottom  ) Before 4.36*cm; // (Deep of the C6D6 cavity +
          // Quarz window thikness + Aluminum housing (bottom))/2

  // ALURING1= ring to attach the two parts of the detector
  G4double minRadiusALURING1 = maxRadiusALU1;    // Info Drawing
  G4double maxRadiusALURING1 = 17.145 * cm / 2;  // Info Drawing
  G4double halfLengthALURING1 =
      0.957 / 2 * cm;  // Victor 0.51*cm;  // (2*halfLengthALU1-1.0cm)/2

  // VAC2= to place the TEFLON
  G4double maxRadiusVAC2 =
      6.3451 * cm;  //(5.130inch-2*1.70*mm?)/2 // measuring Drawing
  G4double minRadiusVAC2 =
      maxRadiusC6D6 +
      ThicknessWallOutdside;  // C6D6 cell width + Al wall (0.5mm)
  G4double halfLengthVAC2 = halfLengthALU1 - ThicknessBottom / 2;  // (

  // TEFL= to simulate the Teflon of the detector
  G4double minRadiusTEFL = minRadiusVAC2;  // Teflon tubing (look notebook)
  G4double maxRadiusTEFL = maxRadiusVAC2;
  G4double halfLengthTEFL = 3.08 * cm;  // Distance measuring  Drawing
  G4double maxRadiusQUA1 =
      maxRadiusC6D6;  // Quartz window between C6D6 and (optical grease+) PM

  // QUA1= to simulate the Window
  G4double halfLengthQUA1 = 0.95 * cm / 2;  // info Drawing
  // The optial Grease is not simulated

  /////////////////////////////////////////////////////
  /////Mu metal shielding////////
  /////////////////////////////////////////////////////
  // Outside Shielding of the PMT

  G4double maxRadiusMU1 = 7.09 * cm;  // Bottom part of the Mu-Metal PM housing
  G4double minRadiusMU1 = 7.0 * cm;
  G4double halfLengthMU1 = 4.11 * cm;  //

  G4double maxRadiusMU3 = 4.35 * cm;  // Top part of the Mu-metal PM housing
  G4double minRadiusMU3 = 4.26 * cm;
  G4double halfLengthMU3 = 7.05 * cm;

  G4double minRadius1MU2 = minRadiusMU3;  // Cone section for the Mu-PM housing
  G4double maxRadius1MU2 = maxRadiusMU3;
  G4double minRadius2MU2 = minRadiusMU1;
  G4double maxRadius2MU2 = maxRadiusMU1;
  G4double halfLengthMU2 = 1.44 * cm;

  /////////////////////////////////////////////////////////////
  /////Second AL ring///////
  /////////////////////////////////////////////////////////////
  // Second Al  Ring from the PMT

  G4double minRadiusALU2 = maxRadiusMU1;
  G4double maxRadiusALU2 = maxRadiusALURING1;
  G4double halfLengthALU2 = 0.63 * cm / 2;  // Distance measuring Drawing

  /////////////////////////////////////////////////////////////
  /////Aluminium VD CASES///////
  /////////////////////////////////////////////////////////////
  // Al Case of the VD

  G4double maxRadiusALUPM1 = minRadiusMU3;  // extra alumimum inside the case
  G4double minRadiusALUPM1 = 4.11 * cm;
  G4double halfLengthALUPM1 = 0.95 * cm;
  G4double maxRadiusALUPM2 = maxRadiusMU3;  // outside of Al
  G4double minRadiusALUPM2 = maxRadiusALUPM1;
  G4double halfLengthALUPM2 = 3.6 * cm;        // Changed FromEmilio to 2.6
  G4double maxRadiusALUPM3 = minRadiusALUPM1;  // Top VD
  G4double halfLengthALUPM3 = 0.15 * cm;

  /////////////////////////////////////////////////////////////
  ///// PM Window///////
  ////////////////////////////////////////////////////////////
  // Window of the PMT, PMW inside of a vaccum disk

  G4double halfLengthPMWC =
      1.27 * cm / 2 +
      0.17 * cm / 2;  // 0.970835*cm//main volume for PM Window (Quartz-Cone)
  G4double minRadius1PMWC = 0. * cm;
  G4double maxRadius1PMWC = 5.5 * cm;  // 6.5
  G4double minRadius2PMWC = 0. * cm;
  G4double maxRadius2PMWC = 5.5 * cm;  // 6.5

  G4double minRadiusPMWS = 0. * cm;      // PM-Window (Vacuum-Sphere)
  G4double maxRadiusPMWS = 12.544 * cm;  // 13.0*cm;
  G4double minThetaPMWS = 0.0 * deg;
  G4double maxThetaPMWS = 360.0 * deg;  // 180.0*deg;
  G4double minPhiPMWS = 0. * deg;
  G4double maxPhiPMWS = 360. * deg;
  G4double LengthExtraWindowPMW = 0.17 * cm;

  /////////////////////////////////////////////////////////////
  ///// DYNODES ///////
  /////////////////////////////////////////////////////////////
  // To simulate dynodes

  G4double minRadiusELC1 = 5.60 * cm;
  G4double maxRadiusELC1 = 5.66 * cm;
  G4double halfLengthELC1 = 2.25 * cm;

  G4double minRadiusELC2 = 2.62 * cm;
  G4double maxRadiusELC2 = maxRadiusELC1;  // 5.66*cm;
  G4double halfLengthELC2 = 0.03 * cm;

  G4double minRadiusELC3 = 2.5 * cm;
  G4double maxRadiusELC3 = minRadiusELC2;
  G4double halfLengthELC3 = 5.0 * cm;

  /////////////////////////////////////////////////////////////
  /////GLASS CASE///////
  /////////////////////////////////////////////////////////////
  // To simulate Glass Case of the PMT

  G4double minRadiusGLA1 = 6.5 * cm;
  G4double maxRadiusGLA1 = 6.65 * cm;
  G4double halfLengthGLA1 = 3.76 * cm;  // Changed FromEmilio to 3.61

  G4double minRadiusGLA3 = 4.1 * cm;
  G4double maxRadiusGLA3 = 4.25 * cm;
  G4double halfLengthGLA3 = 5.65 * cm;

  G4double halfLengthGLA2 = 1.7 * cm;  // Changed FromEmilio to 1.67
  G4double minRadius1GLA2 = minRadiusGLA3;
  G4double maxRadius1GLA2 = maxRadiusGLA3;
  G4double minRadius2GLA2 = minRadiusGLA1;
  G4double maxRadius2GLA2 = maxRadiusGLA1;

  G4double maxRadiusGLA4 = maxRadiusGLA3;
  G4double halfLengthGLA4 = 0.075 * cm;
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================

  double TotalLength = 2 * halfLengthALU1 + 2 * halfLengthMU1 +
                       2 * halfLengthMU2 + 2 * halfLengthMU3 +
                       2 * halfLengthALUPM2;

  G4double detVol_dZ = TotalLength / 2.0;

  /////////////////////////////////////////////////////
  /////C6D6 and Covers////////
  /////////////////////////////////////////////////////

  G4ThreeVector positionALU1 = G4ThreeVector(
      0 * cm, 0. * cm, 2 * detVol_dZ + 0.00 * cm - halfLengthALU1);
  G4ThreeVector positionALUFront = G4ThreeVector(
      0 * cm, 0. * cm, 2 * detVol_dZ + 0.00 * cm - ThicknessBottom / 2.0);
  G4ThreeVector positionALURING1 = G4ThreeVector(
      0 * cm, 0. * cm, 2 * detVol_dZ - 2 * halfLengthALU1 + halfLengthALURING1);
  G4ThreeVector positionVAC2 = G4ThreeVector(
      0 * cm, 0. * cm, +halfLengthALU1 - halfLengthVAC2 - ThicknessBottom);
  G4ThreeVector positionTEFL =
      G4ThreeVector(0 * cm, 0. * cm, +halfLengthVAC2 - halfLengthTEFL);

  G4ThreeVector positionC6D6 = G4ThreeVector(
      0 * cm, 0. * cm, 2 * detVol_dZ - halfLengthC6D6 - ThicknessBottom);

  G4ThreeVector positionQUA1 = G4ThreeVector(
      0 * cm, 0. * cm,
      2 * detVol_dZ - 2 * halfLengthC6D6 - ThicknessBottom - halfLengthQUA1);

  /////////////////////////////////////////////////////////////
  /////Second AL ring///////
  /////////////////////////////////////////////////////////////

  G4ThreeVector positionALU2 = G4ThreeVector(
      0 * cm, 0 * cm, 2 * detVol_dZ - 2 * halfLengthALU1 - halfLengthALU2);

  /////////////////////////////////////////////////////r
  /////Mu metal shielding////////
  /////////////////////////////////////////////////////

  G4ThreeVector positionMU1 = G4ThreeVector(
      0 * cm, 0. * cm, 2 * detVol_dZ - 2 * halfLengthALU1 - halfLengthMU1);
  G4ThreeVector positionMU2 = G4ThreeVector(
      0 * cm, 0. * cm,
      2 * detVol_dZ - 2 * halfLengthALU1 - 2 * halfLengthMU1 - halfLengthMU2);
  G4ThreeVector positionMU3 =
      G4ThreeVector(0 * cm, 0. * cm,
                    2 * detVol_dZ - 2 * halfLengthALU1 - 2 * halfLengthMU1 -
                        2 * halfLengthMU2 - halfLengthMU3);
  G4double TotalMUlength =
      2 * halfLengthMU1 + 2 * halfLengthMU2 + 2 * halfLengthMU3;

  /////////////////////////////////////////////////////////////
  /////Aluminium VD  CASE////////
  /////////////////////////////////////////////////////////////

  G4ThreeVector positionALUPM1 = G4ThreeVector(
      0 * cm, 0. * cm,
      2 * detVol_dZ - 2 * halfLengthALU1 - TotalMUlength - halfLengthALUPM1);
  G4ThreeVector positionALUPM2 = G4ThreeVector(
      0 * cm, 0. * cm,
      2 * detVol_dZ - 2 * halfLengthALU1 - TotalMUlength - halfLengthALUPM2);
  G4ThreeVector positionALUPM3 =
      G4ThreeVector(0 * cm, 0. * cm,
                    2 * detVol_dZ - 2 * halfLengthALU1 - TotalMUlength -
                        2 * halfLengthALUPM2 + halfLengthALUPM3);

  /////////////////////////////////////////////////////////////
  ///// PM Window///////
  /////////////////////////////////////////////////////////////
  // For the new PM-WINDOW

  G4ThreeVector positionPMWC = G4ThreeVector(
      0 * cm, 0. * cm, 2 * detVol_dZ - 2 * halfLengthALU1 - halfLengthPMWC);
  //  G4ThreeVector positionPMWS =
  //  G4ThreeVector(0*cm,0.*cm,2*detVol_dZ-maxRadiusPMWS+halfLengthPMWC-LengthExtraWindowPMW);
  G4ThreeVector positionPMWS = G4ThreeVector(
      0 * cm, 0. * cm, -maxRadiusPMWS + halfLengthPMWC - LengthExtraWindowPMW);

  G4ThreeVector positionPMWCIntersPMWS =
      G4ThreeVector(0. * cm, 0. * cm, 0. * cm);

  /////////////////////////////////////////////////////////////
  /////GLASS CASE///////
  /////////////////////////////////////////////////////////////

  G4ThreeVector positionGLA1 = G4ThreeVector(
      0 * cm, 0 * cm, 2 * detVol_dZ - 2 * halfLengthALU1 - halfLengthGLA1);
  G4ThreeVector positionGLA2 = G4ThreeVector(
      0 * cm, 0 * cm,
      2 * detVol_dZ - 2 * halfLengthALU1 - 2 * halfLengthGLA1 - halfLengthGLA2);
  G4ThreeVector positionGLA3 =
      G4ThreeVector(0 * cm, 0 * cm,
                    2 * detVol_dZ - 2 * halfLengthALU1 - 2 * halfLengthGLA1 -
                        2 * halfLengthGLA2 - halfLengthGLA3);
  G4ThreeVector positionGLA4 = G4ThreeVector(
      0 * cm, 0 * cm,
      2 * detVol_dZ - 2 * halfLengthALU1 - 2 * halfLengthGLA1 -
          2 * halfLengthGLA2 - 2 * halfLengthGLA3 - halfLengthGLA4);

  /////////////////////////////////////////////////////////////
  ///// DYNODES ///////
  ////////////////////////////////////////////////////////////

  G4ThreeVector positionELC1 = G4ThreeVector(
      0 * cm, 0 * cm,
      2 * detVol_dZ - 2 * halfLengthALU1 - 2 * halfLengthPMWC - halfLengthELC1);
  G4ThreeVector positionELC2 =
      G4ThreeVector(0 * cm, 0 * cm,
                    2 * detVol_dZ - 2 * halfLengthALU1 - 2 * halfLengthPMWC -
                        2 * halfLengthELC1 - halfLengthELC2);
  G4ThreeVector positionELC3 = G4ThreeVector(
      0 * cm, 0 * cm,
      2 * detVol_dZ - 2 * halfLengthALU1 - 2 * halfLengthPMWC -
          2 * halfLengthELC1 - 2 * halfLengthELC2 - halfLengthELC3);

  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================

  /////////////////////////////////////////////////////
  /////C6D6 and Covers////////
  /////////////////////////////////////////////////////
  //-------------------------------------------------------------------------------------------------------------
  /// PLAcEMENT OF THE COMPONENTS OF THE C6D6 DETECTOR IN THE VAC0 VOLUME

  // G4Tubs* bsolidDetVol = new
  // G4Tubs("bdetVol",minRadius,maxRadiusALURING1+0.01*mm,detVol_dZ+0.01*mm,
  // startPhi,deltaPhi);

  int const numZPlanes = 12;
  G4double rInner[numZPlanes] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  G4double rOuter[numZPlanes] = {2 * maxRadiusMU1 - 9.5 * cm,
                                 2 * maxRadiusMU1 - 9.5 * cm,
                                 2 * maxRadiusMU1 - 4.5 * cm,
                                 2 * maxRadiusMU1 - 4.5 * cm,
                                 2 * maxRadiusMU1,
                                 2 * maxRadiusMU1,
                                 maxRadiusMU1,
                                 maxRadiusMU1,
                                 maxRadiusALURING1,
                                 maxRadiusALURING1,
                                 maxRadiusALU1,
                                 maxRadiusALU1};

  G4double zPlane[numZPlanes] = {
      0,
      9 * cm,
      9 * cm,
      14 * cm,
      14 * cm,
      2 * halfLengthMU3 + 2 * halfLengthALUPM2,
      2 * halfLengthMU3 + 2 * halfLengthALUPM2,
      2 * halfLengthMU3 + 2 * halfLengthALUPM2 + 2 * halfLengthMU1 +
          2 * halfLengthMU2 - 2 * halfLengthALU2,
      2 * halfLengthMU3 + 2 * halfLengthALUPM2 + 2 * halfLengthMU1 +
          2 * halfLengthMU2 - 2 * halfLengthALU2,
      2 * halfLengthMU3 + 2 * halfLengthALUPM2 + 2 * halfLengthMU1 +
          2 * halfLengthMU2 + 2 * halfLengthALURING1,
      2 * halfLengthMU3 + 2 * halfLengthALUPM2 + 2 * halfLengthMU1 +
          2 * halfLengthMU2 + 2 * halfLengthALURING1,

      TotalLength};
  // for (int i = 0; i < numZPlanes; i++) {
  //   G4cout << " rInner " << rInner[i] << " rOuter " << rOuter[i] << " zPlane
  //   "
  //          << zPlane[i] << G4endl;
  // }
  G4Polycone* bsolidDetVol = new G4Polycone("bdetVol", startPhi, deltaPhi,
                                            numZPlanes, zPlane, rInner, rOuter);

  // G4Box* bsolidDetVol=  new G4Box("bdetVol", 10*cm, 10*cm,detVol_dZ);
  G4LogicalVolume* blogicDetVol =
      new G4LogicalVolume(bsolidDetVol,  // its solid
                          vacuum,        // its material
                          "bdetVol");    // its name
  blogicDetVol->SetVisAttributes(G4VisAttributes::GetInvisible());
  // blogicDetVol->SetVisAttributes(G4Color::Red());

  G4RotationMatrix rotB6D6[50];
  G4double rB6D6[50];
  G4ThreeVector posB6D6[50];
  // G4VPhysicalVolume *physiB6D6[50];
  char name[1000];

  for (int i = 1; i < (theInputManager->GetTotalNC6D6Detectors() + 1); i++) {
    if (flagB6D6[i] == 1) {
      G4cout << "Build B6D6_" << i << " thetaB6D6= " << thetaB6D6[i]
             << " phiB6D6z= " << phiB6D6[i] << " z= " << zB6D6[i] << G4endl;
      rotB6D6[i] = G4RotationMatrix();
      rotB6D6[i].rotateY(-thetaB6D6[i] * deg + 180 * deg);
      rotB6D6[i].rotateX(180 * deg);
      rotB6D6[i].rotateZ(phiB6D6[i] * deg);
      rB6D6[i] = 2 * detVol_dZ + zB6D6[i] * cm;
      posB6D6[i] = G4ThreeVector(
          -rB6D6[i] * sin(thetaB6D6[i] * deg) * cos(phiB6D6[i] * deg),
          -rB6D6[i] * sin(thetaB6D6[i] * deg) * sin(phiB6D6[i] * deg),
          -rB6D6[i] * cos(thetaB6D6[i] * deg));
      sprintf(name, "B6D6_%d", i);
      //      physiB6D6[i] =
      new G4PVPlacement(G4Transform3D(rotB6D6[i], posB6D6[i]),
                        blogicDetVol,  // its logical volume
                        name,
                        mother,  // its
                        false,   // no boolean operation
                        i,       // copy number
                        flagOverlaps);
    }
  }

  // ALUFront Tap of Al to close de volume solidALU1 )// Case of Aluminium
  G4Tubs* solidALUFront = new G4Tubs("ALUFront", minRadius, maxRadiusC6D6,
                                     ThicknessBottom / 2.0, startPhi, deltaPhi);
  G4LogicalVolume* logicALUFront =
      new G4LogicalVolume(solidALUFront, Al, "ALUFront");
  G4RotationMatrix rotm_ALUFront = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_ALUFront =
      G4Transform3D(rotm_ALUFront, positionALUFront);
  //  theBICRON->AddPlacedVolume(logicALU1,transform_ALU1);

  new G4PVPlacement(transform_ALUFront,  // rotation,position
                    logicALUFront,       // its logical volume
                    "ALUFront",          // its name
                    blogicDetVol,        // its mother  volume
                    false,               // no boolean operation
                    0,                   // copy number
                    flagOverlaps);       // checking overlaps

  G4VisAttributes* ALUFrontVisAtt =
      new G4VisAttributes(G4Colour(0., 0., 1.0));  // BLUE
  logicALUFront->SetVisAttributes(ALUFrontVisAtt);

  // ALU1 (Aluminum cap containing teflon tub., C6D6, etc)// Case of Aluminium
  G4Tubs* solidALU1 = new G4Tubs("ALU1", maxRadiusC6D6, maxRadiusALU1,
                                 halfLengthALU1, startPhi, deltaPhi);
  G4LogicalVolume* logicALU1 = new G4LogicalVolume(solidALU1, Al, "ALU1");
  G4RotationMatrix rotm_ALU1 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_ALU1 = G4Transform3D(rotm_ALU1, positionALU1);
  //  theBICRON->AddPlacedVolume(logicALU1,transform_ALU1);

  new G4PVPlacement(transform_ALU1,  // rotation,position
                    logicALU1,       // its logical volume
                    "ALU1",          // its name
                    blogicDetVol,    // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps

  G4VisAttributes* ALU1VisAtt =
      new G4VisAttributes(G4Colour(0., 0., 1.0));  // BLUE
  logicALU1->SetVisAttributes(ALU1VisAtt);
  //-------------------------------------------------------------------------------------------------------------
  // ALURING1 (Aluminum Ring surrounding previous Alu cell)

  G4Tubs* solidALURING1 =
      new G4Tubs("ALURING1", minRadiusALURING1, maxRadiusALURING1,
                 halfLengthALURING1, startPhi, deltaPhi);
  G4LogicalVolume* logicALURING1 =
      new G4LogicalVolume(solidALURING1, Al, "ALURING1");

  G4RotationMatrix rotm_ALURING1 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_ALURING1 =
      G4Transform3D(rotm_ALURING1, positionALURING1);
  //  theBICRON->AddPlacedVolume(logicALURING1,transform_ALURING1);
  new G4PVPlacement(transform_ALURING1,  // rotation,position
                    logicALURING1,       // its logical volume
                    "ALURING1",          // its name
                    blogicDetVol,        // its mother  volume
                    false,               // no boolean operation
                    0,                   // copy number
                    flagOverlaps);       // checking overlaps

  G4VisAttributes* ALURING1VisAtt =
      new G4VisAttributes(G4Colour(0., 0., 1.0));  // BLUE
  logicALURING1->SetVisAttributes(ALURING1VisAtt);
  //   //-------------------------------------------------------------------------------------------------------------
  // C6D6// It is placed inside logicALU1

  /// To be activated to remove part par of the volume
  //  G4Tubs* solidC6D6Pre = new
  //  G4Tubs("C6D6Pre",minRadius,maxRadiusC6D6,halfLengthC6D6,
  //  startPhi,deltaPhi); G4Box *solidCuttingVolume = new
  //  G4Box("CuttingVolume",DistanceCut/2,maxRadiusC6D6,halfLengthC6D6+ThicknessBottom);
  // G4SubtractionSolid *solidC6D6=new G4SubtractionSolid("C6D6",solidC6D6Pre
  // ,solidCuttingVolume,0,G4ThreeVector(maxRadiusC6D6-DistanceCut/2,0.*mm,0.*mm)
  // );

  G4Tubs* solidC6D6 = new G4Tubs("C6D6", minRadius, maxRadiusC6D6,
                                 halfLengthC6D6, startPhi, deltaPhi);
  BfLogicC6D6 = new G4LogicalVolume(solidC6D6, C6D6, "C6D6");

  G4double VolumeinC6D6 = solidC6D6->GetCubicVolume();
  G4cout << " Volume of C6D6 " << 0.000001 * VolumeinC6D6 << " Litres"
         << G4endl;

  // G4cout<<G4endl<<G4endl<<G4endl<<G4endl<<G4endl<<G4endl<<" Distance cut
  // "<<DistanceCut<<" Volume of C6D6 "<<0.000001*VolumeinC6D6<<" in
  // Litres"<<G4endl;
  // G4cout<<"Percent of C6D6 remove "<<100*(617778-VolumeinC6D6)/617778<<"
  // %"<<G4endl;

  // G4VPhysicalVolume* physiC6D6 = new
  // G4PVPlacement(0,positionC6D6,BfLogicC6D6,"C6D6", logicALU1,false,0);

  // G4VPhysicalVolume* physiC6D6 = new
  // G4PVPlacement(0,positionC6D6,BfLogicC6D6,"C6D6", logicALU1,false,0);
  G4RotationMatrix rotm_C6D6 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_C6D6 = G4Transform3D(rotm_C6D6, positionC6D6);

  new G4PVPlacement(transform_C6D6,  // rotation,position
                    BfLogicC6D6,     // its logical volume
                    "C6D6",          // its name
                    blogicDetVol,    // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps

  G4VisAttributes* C6D6VisAtt =
      new G4VisAttributes(G4Colour(0., 1.0, 0.));  // CYAN
  BfLogicC6D6->SetVisAttributes(C6D6VisAtt);

  //-------------------------------------------------------------------------------------------------------------
  // VAC2 (Vacuum for the Teflon placement)

  G4Tubs* solidVAC2 = new G4Tubs("VAC2", minRadiusVAC2, maxRadiusVAC2,
                                 halfLengthVAC2, startPhi, deltaPhi);
  G4LogicalVolume* logicVAC2 = new G4LogicalVolume(solidVAC2, Vacuum, "VAC2");

  /*  G4VPhysicalVolume* physiVAC2 =*/new G4PVPlacement(
      0, positionVAC2, logicVAC2, "VAC2", logicALU1, false, 0, flagOverlaps);

  G4VisAttributes* VAC2VisAtt =
      new G4VisAttributes(G4Colour(1., 0., 0.));  // RED 100
  logicVAC2->SetVisAttributes(VAC2VisAtt);

  //-------------------------------------------------------------------------------------------------------------
  // The teflon we placed inside the VAC2
  // G4cout<<G4endl<<G4endl<<G4endl<<" Warning, The material used to simulate
  // the tubing is just TEFLON"<<G4endl<<G4endl<<G4endl;
  G4Tubs* solidTEFL = new G4Tubs("TEFL", minRadiusTEFL, maxRadiusTEFL,
                                 halfLengthTEFL, startPhi, deltaPhi);
  G4LogicalVolume* logicTEFL = new G4LogicalVolume(solidTEFL, Teflon, "TEFL");

  /*  G4VPhysicalVolume* physiTEFL =*/new G4PVPlacement(
      0, positionTEFL, logicTEFL, "TEFL", logicVAC2, false, 0, flagOverlaps);

  G4VisAttributes* TEFLVisAtt =
      new G4VisAttributes(G4Colour(1., 1., 1.0));  // WHITE
  logicTEFL->SetVisAttributes(TEFLVisAtt);
  //------//
  //-------------------------------------------------------------------------------------------------------

  // QUA1

  G4Tubs* solidQUA1 = new G4Tubs("QUA1", minRadius, maxRadiusQUA1,
                                 halfLengthQUA1, startPhi, deltaPhi);

  G4LogicalVolume* logicQUA1 = new G4LogicalVolume(solidQUA1, Quartz, "QUA1");

  // G4VPhysicalVolume* physiQUA1 = new
  // G4PVPlacement(0,positionQUA1,logicQUA1,"QUA1",logicALU1,false,0,true);

  G4RotationMatrix rotm_QUA1 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_QUA1 = G4Transform3D(rotm_QUA1, positionQUA1);

  new G4PVPlacement(transform_QUA1,  // rotation,position
                    logicQUA1,       // its logical volume
                    "QUA1",          // its name
                    blogicDetVol,    // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps

  G4VisAttributes* QUA1VisAtt =
      new G4VisAttributes(G4Colour(0.7, 0.2, 0.0));  // ORANGE
  logicQUA1->SetVisAttributes(QUA1VisAtt);
  //-------------------------------------------------------------------------------------------------------------

  /////////////////////////////////////////////////////////////
  /////Second AL ring///////
  /////////////////////////////////////////////////////////////
  // ALU2
  G4Tubs* solidALU2 = new G4Tubs("ALU2", minRadiusALU2, maxRadiusALU2,
                                 halfLengthALU2, startPhi, deltaPhi);

  G4LogicalVolume* logicALU2 = new G4LogicalVolume(solidALU2, Al, "ALU2");

  G4RotationMatrix rotm_ALU2 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_ALU2 = G4Transform3D(rotm_ALU2, positionALU2);
  //  theBICRON->AddPlacedVolume(logicALU2,transform_ALU2);

  new G4PVPlacement(transform_ALU2,  // rotation,position
                    logicALU2,       // its logical volume
                    "ALU2",          // its name
                    blogicDetVol,    // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps

  //-------------------------------------------------------------------------------------------------------------

  /////////////////////////////////////////////////////
  /////Mu metal shielding////////
  /////////////////////////////////////////////////////

  // MU1
  G4Tubs* solidMU1 = new G4Tubs("MU1", minRadiusMU1, maxRadiusMU1,
                                halfLengthMU1, startPhi, deltaPhi);
  G4LogicalVolume* logicMU1 = new G4LogicalVolume(solidMU1, Mumetal, "MU1");

  G4RotationMatrix rotm_MU1 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_MU1 = G4Transform3D(rotm_MU1, positionMU1);
  // theBICRON->AddPlacedVolume(logicMU1,transform_MU1);
  new G4PVPlacement(transform_MU1,  // rotation,position
                    logicMU1,       // its logical volume
                    "MU1",          // its name
                    blogicDetVol,   // its mother  volume
                    false,          // no boolean operation
                    0,              // copy number
                    flagOverlaps);  // checking overlaps

  G4VisAttributes* MU1VisAtt =
      new G4VisAttributes(G4Colour(0.6, 0.6, 0.6));  // GREY
  logicMU1->SetVisAttributes(MU1VisAtt);

  //-------------------------------------------------------------------------------------------------------------
  // MU2

  G4Cons* solidMU2 =
      new G4Cons("MU2", minRadius1MU2, maxRadius1MU2, minRadius2MU2,
                 maxRadius2MU2, halfLengthMU2, startPhi, deltaPhi);

  G4LogicalVolume* logicMU2 = new G4LogicalVolume(solidMU2, Mumetal, "MU2");

  G4RotationMatrix rotm_MU2 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_MU2 = G4Transform3D(rotm_MU2, positionMU2);
  //  theBICRON->AddPlacedVolume(logicMU2,transform_MU2);
  new G4PVPlacement(transform_MU2,  // rotation,position
                    logicMU2,       // its logical volume
                    "MU2",          // its name
                    blogicDetVol,   // its mother  volume
                    false,          // no boolean operation
                    0,              // copy number
                    flagOverlaps);  // checking overlaps

  G4VisAttributes* MU2VisAtt =
      new G4VisAttributes(G4Colour(0.6, 0.6, 0.6));  // GREY
  logicMU2->SetVisAttributes(MU2VisAtt);

  //-------------------------------------------------------------------------------------------------------------
  // MU3

  G4Tubs* solidMU3 = new G4Tubs("MU3", minRadiusMU3, maxRadiusMU3,
                                halfLengthMU3, startPhi, deltaPhi);

  G4LogicalVolume* logicMU3 = new G4LogicalVolume(solidMU3, Mumetal, "MU3");

  G4RotationMatrix rotm_MU3 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_MU3 = G4Transform3D(rotm_MU3, positionMU3);
  // theBICRON->AddPlacedVolume(logicMU3,transform_MU3);

  new G4PVPlacement(transform_MU3,  // rotation,position
                    logicMU3,       // its logical volume
                    "MU3",          // its name
                    blogicDetVol,   // its mother  volume
                    false,          // no boolean operation
                    0,              // copy number
                    flagOverlaps);  // checking overlaps

  G4VisAttributes* MU3VisAtt =
      new G4VisAttributes(G4Colour(0.6, 0.6, 0.6));  // GREY
  logicMU3->SetVisAttributes(MU3VisAtt);
  //-------------------------------------------------------------------------------------------------------------

  /////////////////////////////////////////////////////////////
  /////Aluminium VD CASES///////
  /////////////////////////////////////////////////////////////

  //-------------------------------------------------------------------------------------------------------------
  // ALUPM1

  G4Tubs* solidALUPM1 = new G4Tubs("ALUPM1", minRadiusALUPM1, maxRadiusALUPM1,
                                   halfLengthALUPM1, startPhi, deltaPhi);

  G4LogicalVolume* logicALUPM1 = new G4LogicalVolume(solidALUPM1, Al, "ALUPM1");

  G4RotationMatrix rotm_ALUPM1 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_ALUPM1 = G4Transform3D(rotm_ALUPM1, positionALUPM1);
  // theBICRON->AddPlacedVolume(logicALUPM1,transform_ALUPM1);

  new G4PVPlacement(transform_ALUPM1,  // rotation,position
                    logicALUPM1,       // its logical volume
                    "ALUPM1",          // its name
                    blogicDetVol,      // its mother  volume
                    false,             // no boolean operation
                    0,                 // copy number
                    flagOverlaps);     // checking overlaps

  G4VisAttributes* ALUPM1VisAtt =
      new G4VisAttributes(G4Colour(0.6, 0.6, 0.6));  // GREY
  logicALUPM1->SetVisAttributes(ALUPM1VisAtt);
  //-------------------------------------------------------------------------------------------------------------
  // ALUPM2

  G4Tubs* solidALUPM2 = new G4Tubs("ALUPM2", minRadiusALUPM2, maxRadiusALUPM2,
                                   halfLengthALUPM2, startPhi, deltaPhi);

  G4LogicalVolume* logicALUPM2 = new G4LogicalVolume(solidALUPM2, Al, "ALUPM2");

  G4RotationMatrix rotm_ALUPM2 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_ALUPM2 = G4Transform3D(rotm_ALUPM2, positionALUPM2);
  // theBICRON->AddPlacedVolume(logicALUPM2,transform_ALUPM2);

  new G4PVPlacement(transform_ALUPM2,  // rotation,position
                    logicALUPM2,       // its logical volume
                    "ALUPM2",          // its name
                    blogicDetVol,      // its mother  volume
                    false,             // no boolean operation
                    0,                 // copy number
                    flagOverlaps);     // checking overlaps
  G4VisAttributes* ALUPM2VisAtt =
      new G4VisAttributes(G4Colour(0.6, 0.6, 0.6));  // GREY
  logicALUPM2->SetVisAttributes(ALUPM2VisAtt);
  //-------------------------------------------------------------------------------------------------------------
  // ALUPM3

  G4Tubs* solidALUPM3 = new G4Tubs("ALUPM3", minRadius, maxRadiusALUPM3,
                                   halfLengthALUPM3, startPhi, deltaPhi);

  G4LogicalVolume* logicALUPM3 = new G4LogicalVolume(solidALUPM3, Al, "ALUPM3");

  G4RotationMatrix rotm_ALUPM3 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_ALUPM3 = G4Transform3D(rotm_ALUPM3, positionALUPM3);
  //  theBICRON->AddPlacedVolume(logicALUPM3,transform_ALUPM3);

  new G4PVPlacement(transform_ALUPM3,  // rotation,position
                    logicALUPM3,       // its logical volume
                    "ALUPM3",          // its name
                    blogicDetVol,      // its mother  volume
                    false,             // no boolean operation
                    0,                 // copy number
                    flagOverlaps);     // checking overlaps

  G4VisAttributes* ALUPM3VisAtt =
      new G4VisAttributes(G4Colour(0.6, 0.6, 0.6));  // GREY
  logicALUPM3->SetVisAttributes(ALUPM3VisAtt);
  //-------------------------------------------------------------------------------------------------------------

  //-------------------------------------------------------------------------------------------------------------
  /////////////////////////////////////////////////////////////
  ///// PM Window///////
  /////////////////////////////////////////////////////////////

  // New Quartz-Window for the PM (A vacuum intersection between a cylinder and
  // a sphere is placed inside of the cylinder)

  // G4cout<<G4endl<<G4endl<<G4endl<<" Warning, The way this window is created
  // is prelimnar"<<G4endl<<G4endl<<G4endl;
  G4Cons* solidPMWC =
      new G4Cons("PMWC", minRadius1PMWC, maxRadius1PMWC, minRadius2PMWC,
                 maxRadius2PMWC, halfLengthPMWC, startPhi, deltaPhi);
  G4Sphere* solidPMWS =
      new G4Sphere("PMWS", minRadiusPMWS, maxRadiusPMWS, minThetaPMWS,
                   maxThetaPMWS, minPhiPMWS, maxPhiPMWS);
  G4IntersectionSolid* solidPMWCIntersPMWS = new G4IntersectionSolid(
      "PMWCintersPMWS", solidPMWC, solidPMWS, 0, positionPMWS);

  G4LogicalVolume* logicPMWC = new G4LogicalVolume(solidPMWC, Quartz, "PMWC");
  G4RotationMatrix rotm_PMWC = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_PMWC = G4Transform3D(rotm_PMWC, positionPMWC);
  // theBICRON->AddPlacedVolume(logicPMWC,transform_PMWC);

  new G4PVPlacement(transform_PMWC,  // rotation,position
                    logicPMWC,       // its logical volume
                    "PMWC",          // its name
                    blogicDetVol,    // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps

  G4VisAttributes* PMWC =
      new G4VisAttributes(G4Colour(0.7, 0.2, 0.0));  // Orange
  logicPMWC->SetVisAttributes(PMWC);
  G4LogicalVolume* logicPMWCIntersPMWS =
      new G4LogicalVolume(solidPMWCIntersPMWS, Vacuum, "PMWCIntersPMWS");

  /*G4VPhysicalVolume* physiPMWCIntersPMWS =*/new G4PVPlacement(
      0, positionPMWCIntersPMWS, logicPMWCIntersPMWS, "PMWCIntersPMWS",
      logicPMWC, false, 0, flagOverlaps);

  G4VisAttributes* PMWCIntersPMWSVisAtt =
      new G4VisAttributes(G4Colour(1.0, 0.0, 0.0));  // Red
  logicPMWCIntersPMWS->SetVisAttributes(PMWCIntersPMWSVisAtt);

  //-------------------------------------------------------------------------------------------------------------

  //-------------------------------------------------------------------------------------------------------------
  /////////////////////////////////////////////////////////////
  /////GLASS CASE///////
  /////////////////////////////////////////////////////////////
  // GLA1
  G4Tubs* solidGLA1 = new G4Tubs("GLA1", minRadiusGLA1, maxRadiusGLA1,
                                 halfLengthGLA1, startPhi, deltaPhi);
  G4LogicalVolume* logicGLA1 = new G4LogicalVolume(solidGLA1, BGL, "GLA1");

  G4RotationMatrix rotm_GLA1 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_GLA1 = G4Transform3D(rotm_GLA1, positionGLA1);
  // theBICRON->AddPlacedVolume(logicGLA1,transform_GLA1);

  new G4PVPlacement(transform_GLA1,  // rotation,position
                    logicGLA1,       // its logical volume
                    "GLA1",          // its name
                    blogicDetVol,    // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps

  G4VisAttributes* GLA1VisAtt =
      new G4VisAttributes(G4Colour(0.0, 1.0, 1.0));  // CYAN
  logicGLA1->SetVisAttributes(GLA1VisAtt);

  //-------------------------------------------------------------------------------------------------------------
  // GLA2

  G4Cons* solidGLA2 =
      new G4Cons("GLA2", minRadius1GLA2, maxRadius1GLA2, minRadius2GLA2,
                 maxRadius2GLA2, halfLengthGLA2, startPhi, deltaPhi);

  G4LogicalVolume* logicGLA2 = new G4LogicalVolume(solidGLA2, BGL, "GLA2");

  G4RotationMatrix rotm_GLA2 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_GLA2 = G4Transform3D(rotm_GLA2, positionGLA2);
  //  theBICRON->AddPlacedVolume(logicGLA2,transform_GLA2);

  new G4PVPlacement(transform_GLA2,  // rotation,position
                    logicGLA2,       // its logical volume
                    "GLA2",          // its name
                    blogicDetVol,    // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps

  G4VisAttributes* GLA2VisAtt =
      new G4VisAttributes(G4Colour(0.0, 1.0, 1.0));  // CYAN
  logicGLA2->SetVisAttributes(GLA2VisAtt);

  //------------------------------------------------------------------------------------------
  // GLA3
  G4Tubs* solidGLA3 = new G4Tubs("GLA3", minRadiusGLA3, maxRadiusGLA3,
                                 halfLengthGLA3, startPhi, deltaPhi);

  G4LogicalVolume* logicGLA3 = new G4LogicalVolume(solidGLA3, BGL, "GLA3");

  G4RotationMatrix rotm_GLA3 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_GLA3 = G4Transform3D(rotm_GLA3, positionGLA3);
  // theBICRON->AddPlacedVolume(logicGLA3,transform_GLA3);

  new G4PVPlacement(transform_GLA3,  // rotation,position
                    logicGLA3,       // its logical volume
                    "GLA3",          // its name
                    blogicDetVol,    // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps

  G4VisAttributes* GLA3VisAtt =
      new G4VisAttributes(G4Colour(0.0, 1.0, 1.0));  // CYAN
  logicGLA3->SetVisAttributes(GLA3VisAtt);

  //-------------------------------------------------------------------------------------------------------------
  // GLA4

  G4Tubs* solidGLA4 = new G4Tubs("GLA4", minRadius, maxRadiusGLA4,
                                 halfLengthGLA4, startPhi, deltaPhi);

  G4LogicalVolume* logicGLA4 = new G4LogicalVolume(solidGLA4, BGL, "GLA4");

  G4RotationMatrix rotm_GLA4 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_GLA4 = G4Transform3D(rotm_GLA4, positionGLA4);
  // theBICRON->AddPlacedVolume(logicGLA4,transform_GLA4);

  new G4PVPlacement(transform_GLA4,  // rotation,position
                    logicGLA4,       // its logical volume
                    "GLA4",          // its name
                    blogicDetVol,    // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps

  G4VisAttributes* GLA4VisAtt =
      new G4VisAttributes(G4Colour(0.0, 1.0, 1.0));  // Cyan
  logicGLA4->SetVisAttributes(GLA4VisAtt);

  //-------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------
  //-------------------------------------------------------------------------------------------------------------

  /////////////////////////////////////////////////////////////
  ///// DYNODES ///////
  /////////////////////////////////////////////////////////////

  // ELC1
  G4Tubs* solidELC1 = new G4Tubs("ELC1", minRadiusELC1, maxRadiusELC1,
                                 halfLengthELC1, startPhi, deltaPhi);

  G4LogicalVolume* logicELC1 = new G4LogicalVolume(solidELC1, MET, "ELC1");

  G4RotationMatrix rotm_ELC1 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_ELC1 = G4Transform3D(rotm_ELC1, positionELC1);
  // theBICRON->AddPlacedVolume(logicELC1,transform_ELC1);

  new G4PVPlacement(transform_ELC1,  // rotation,position
                    logicELC1,       // its logical volume
                    "ELC1",          // its name
                    blogicDetVol,    // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps

  G4VisAttributes* ELC1VisAtt =
      new G4VisAttributes(G4Colour(0.0, 0.0, 0.0));  // BLACK
  logicELC1->SetVisAttributes(ELC1VisAtt);

  //-------------------------------------------------------------------------------------------------------------
  // ELC2
  G4Tubs* solidELC2 = new G4Tubs("ELC2", minRadiusELC2, maxRadiusELC2,
                                 halfLengthELC2, startPhi, deltaPhi);

  G4LogicalVolume* logicELC2 = new G4LogicalVolume(solidELC2, MET, "ELC2");

  G4RotationMatrix rotm_ELC2 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_ELC2 = G4Transform3D(rotm_ELC2, positionELC2);
  // theBICRON->AddPlacedVolume(logicELC2,transform_ELC2);

  new G4PVPlacement(transform_ELC2,  // rotation,position
                    logicELC2,       // its logical volume
                    "ELC2",          // its name
                    blogicDetVol,    // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps

  G4VisAttributes* ELC2VisAtt =
      new G4VisAttributes(G4Colour(0.0, 0.0, 0.0));  // AºBLACK
  logicELC2->SetVisAttributes(ELC2VisAtt);

  //-------------------------------------------------------------------------------------------------------------
  // ELC3
  G4Tubs* solidELC3 = new G4Tubs("ELC3", minRadiusELC3, maxRadiusELC3,
                                 halfLengthELC3, startPhi, deltaPhi);

  G4LogicalVolume* logicELC3 = new G4LogicalVolume(solidELC3, MET, "ELC3");

  G4RotationMatrix rotm_ELC3 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_ELC3 = G4Transform3D(rotm_ELC3, positionELC3);
  // theBICRON->AddPlacedVolume(logicELC3,transform_ELC3);

  new G4PVPlacement(transform_ELC3,  // rotation,position
                    logicELC3,       // its logical volume
                    "ELC3",          // its name
                    blogicDetVol,    // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps

  G4VisAttributes* ELC3VisAtt =
      new G4VisAttributes(G4Colour(0.0, 0.0, 0.0));  // BLACK
  logicELC3->SetVisAttributes(ELC3VisAtt);
  //-------------------------------------------------------------------------------------------------------------

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7

  // DEFINE DETECTOR HOLDER//

  G4double XPostionDetHolder =
      6.823 * cm;  // distance to place the Detector Holder in the X axis;

  // G4double DistanceToCenter= (13.9+9.25)*cm;
  ///////////////////////////////////////////////
  /////Heptagonal Shape////////////////////////////
  ///////////////////////////////////////////////
  // This is the shape to hold the sample Holder, thera are two of this

  G4double HalfLengthHepta = 0.8 / 2 * cm;

  G4double Heptax1 = 0, Heptay1 = 0;
  G4double Heptax2 = 0, Heptay2 = 13.4 * cm;
  G4double Heptax3 = -4.8 * cm, Heptay3 = 13.4 * cm;
  G4double Heptax4 = -4.8 * cm, Heptay4 = 11.9 * cm;
  G4double Heptax5 = -1.8 * cm, Heptay5 = 6.7 * cm;
  G4double Heptax6 = -4.8 * cm, Heptay6 = 1.5 * cm;
  G4double Heptax7 = -4.8 * cm, Heptay7 = 0 * cm;

  ///////////////////////////////////////////////
  //////Top Detector Holder///////////////////////////
  ///////////////////////////////////////////////

  G4double HalfLengthTop = 10 * cm / 2 - HalfLengthHepta;
  G4double XHalfLengthTop = 0.6 * cm / 2;
  G4double YHalfLengthTop = Heptay3 / 2;
  ///////////////////////////////////////////////
  //////Holder Detector UForm///////////////////////////
  ///////////////////////////////////////////////
  // This is where the carbon fiber bar is inserted

  G4double HalfLengthUForm = 1.9 / 2 * cm;

  G4double UFormx1 = 0.0 * cm, UFormy1 = 0.0 * cm;
  G4double UFormx2 = 0.0 * cm, UFormy2 = 0.9 * cm;
  G4double UFormx3 = -5.3 * cm, UFormy3 = 0.9 * cm;
  G4double UFormx4 = -5.3 * cm, UFormy4 = 2.1 * cm;
  G4double UFormx5 = 0.0 * cm, UFormy5 = 2.1 * cm;
  G4double UFormx6 = 0.0 * cm, UFormy6 = 3.0 * cm;
  G4double UFormx7 = -6.5 * cm, UFormy7 = 3.0 * cm;
  G4double UFormx8 = -6.5 * cm, UFormy8 = 0.0 * cm;

  // //////////////////////////////////////////////
  // //////Circle Carbon fiber ///////////////////////////
  // ///////////////////////////////////////////////
  // //This is the Carbon fiber piece taht goes inside the UForm
  // G4double XPostionCarbonCircle=4.3*cm;
  // G4double HalfLengthCarbonCircle=1.2/2*cm;
  // G4double RmaxCarbonCircle=5/2*cm;

  // //////////////////////////////////////////////
  // //////BAR Carbon fiber///////////////////////////
  // ///////////////////////////////////////////////
  // G4double HalfLengthCarbonBar=122.5/2*cm;
  // G4double RmaxCarbonBar=3/2*cm;

  //////////////////////////////////////////////
  //////Detector Strips///////////////////////////
  ///////////////////////////////////////////////
  /// Strips of Al to hold the Detector; simplify geoemtry
  G4double HalfLengthStrip = 2 / 2 * cm;
  G4double RmaxStrip = 4.4 * cm;
  G4double RminStrip = 4.35 * cm;
  G4double startPhiStrip = 57. * deg;
  G4double LengthPhiStrip = 246. * deg;

  //////////////////////////////////////////////
  //////Detector Bars for the Cm244 measurement///////////////////////////
  ///////////////////////////////////////////////

  // G4double
  // DistanceCenterToBarConnectionPoint=pow((DistanceToCenter+HalfLengthHepta)*(DistanceToCenter+HalfLengthHepta)+(Heptay3/2-Heptay6/2)*(Heptay3/2-Heptay6/2),0.5);
  //   G4double
  //   AngleDetector=acos((DistanceToCenter+HalfLengthHepta)/DistanceCenterToBarConnectionPoint);
  // G4double AngleBar=60*deg-AngleDetector;
  // G4double
  // DistanceCenterToBar=cos(AngleBar)*DistanceCenterToBarConnectionPoint;//19.31cm
  // // This is all done to get the distance that you have to place the center
  // of the bar. Yoou can change all of this with DistanceCenterToBar=19.31*cm
  //   //////////////////////////////////////////////

  // G4double HalfLengthAlBar=43/2*cm;
  // G4double RotateBar=30*deg;//60*deg

  // G4double AlBarx1=0.0*cm,AlBary1=0.0*cm;
  // G4double AlBarx2=0.0*cm,AlBary2=1*cm;
  // G4double AlBarx3=-0.7*cm,AlBary3=1*cm;
  // G4double AlBarx4=-0.7*cm,AlBary4=0.75*cm;
  // G4double AlBarx5=-0.25*cm,AlBary5=0.75*cm;
  // G4double AlBarx6=-0.25*cm,AlBary6=-0.75*cm;
  // G4double AlBarx7=-0.7*cm,AlBary7=-0.75*cm;
  // G4double AlBarx8=-0.7*cm,AlBary8=-1*cm;
  // G4double AlBarx9=0.0*cm,AlBary9=-1*cm;

  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================

  ///////////////////////////////////////////////
  ////Distances////////////////////////////
  ///////////////////////////////////////////////

  G4ThreeVector positionHeptaFront = G4ThreeVector(
      XPostionDetHolder, 0 - Heptay2 / 2, detVol_dZ - HalfLengthHepta);

  G4ThreeVector positionHeptaBack = G4ThreeVector(
      XPostionDetHolder, 0 - Heptay2 / 2,
      detVol_dZ - 2 * HalfLengthHepta - 2 * HalfLengthTop - HalfLengthHepta);

  G4ThreeVector positionTop =
      G4ThreeVector(XPostionDetHolder - XHalfLengthTop, 0 * cm,
                    detVol_dZ - 2 * HalfLengthHepta - HalfLengthTop);

  G4ThreeVector positionUForm =
      G4ThreeVector(XPostionDetHolder - UFormx7, -UFormy7 / 2,
                    detVol_dZ - 2 * HalfLengthHepta - HalfLengthTop);

  //  G4ThreeVector positionCarbonCircle =
  //  G4ThreeVector(XPostionDetHolder+XPostionCarbonCircle,0.0,-2*HalfLengthHepta-HalfLengthTop);

  // G4ThreeVector positionCarbonBar =
  // G4ThreeVector(XPostionDetHolder-UFormx7+HalfLengthCarbonBar,0.0,-2*HalfLengthHepta-HalfLengthTop);

  G4ThreeVector positionStripFront =
      G4ThreeVector(0, 0.0, detVol_dZ - HalfLengthHepta);

  G4ThreeVector positionStripBack = G4ThreeVector(
      0, 0.0,
      detVol_dZ - 2 * HalfLengthHepta - 2 * HalfLengthTop - HalfLengthHepta);

  // G4ThreeVector positionAlBar =
  // G4ThreeVector(XPostionDetHolder+Heptax6,DistanceCenterToBar*sin(RotateBar+30*deg),-DistanceCenterToBar*cos(RotateBar+30*deg)+DistanceToCenter);

  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================

  ///////////////////////////////////////////////
  /////Heptagonal Shape////////////////////////////
  ///////////////////////////////////////////////

  std::vector<G4TwoVector> points;

  points.push_back(G4TwoVector(Heptax1, Heptay1));  // (x, z)
  points.push_back(G4TwoVector(Heptax2, Heptay2));  // (x, z)
  points.push_back(G4TwoVector(Heptax3, Heptay3));  // (x, z)
  points.push_back(G4TwoVector(Heptax4, Heptay4));  // (x, z)
  points.push_back(G4TwoVector(Heptax5, Heptay5));  // (x, z)
  points.push_back(G4TwoVector(Heptax6, Heptay6));  // (x, z)
  points.push_back(G4TwoVector(Heptax7, Heptay7));  // (x, z)

  G4VSolid* solidHeptaFront = new G4ExtrudedSolid("solidHeptaFront", points,
                                                  HalfLengthHepta, 0, 1, 0, 1);

  G4LogicalVolume* logicHeptaFront =
      new G4LogicalVolume(solidHeptaFront, Al, "HeptaFront");

  G4RotationMatrix rotm_HeptaFront = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_HeptaFront =
      G4Transform3D(rotm_HeptaFront, positionHeptaFront);
  // theDetectorHolder->AddPlacedVolume(logicHeptaFront,transform_HeptaFront);

  new G4PVPlacement(transform_HeptaFront,  // rotation,position
                    logicHeptaFront,       // its logical volume
                    "HeptaFront",          // its name
                    blogicDetVol,          // its mother  volume
                    false,                 // no boolean operation
                    0,                     // copy number
                    flagOverlaps);         // checking overlaps

  G4VisAttributes* HeptaFrontVisAtt =
      new G4VisAttributes(G4Colour(0., 0., 1.0));  // BLUE
  logicHeptaFront->SetVisAttributes(HeptaFrontVisAtt);

  //  //-------------------------------------------------------------------------------------------------------------

  G4VSolid* solidHeptaBack = new G4ExtrudedSolid("solidHeptaBack", points,
                                                 HalfLengthHepta, 0, 1, 0, 1);

  G4LogicalVolume* logicHeptaBack =
      new G4LogicalVolume(solidHeptaBack, Al, "HeptaBack");

  G4RotationMatrix rotm_HeptaBack = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_HeptaBack =
      G4Transform3D(rotm_HeptaBack, positionHeptaBack);
  //  theDetectorHolder->AddPlacedVolume(logicHeptaBack,transform_HeptaBack);

  new G4PVPlacement(transform_HeptaBack,  // rotation,position
                    logicHeptaBack,       // its logical volume
                    "HeptaBack",          // its name
                    blogicDetVol,         // its mother  volume
                    false,                // no boolean operation
                    0,                    // copy number
                    flagOverlaps);        // checking overlaps

  G4VisAttributes* HeptaBackVisAtt =
      new G4VisAttributes(G4Colour(0., 0., 1.0));  // BLUE
  logicHeptaBack->SetVisAttributes(HeptaBackVisAtt);

  ///////////////////////////////////////////////
  //////Top Detector Holder///////////////////////////
  ///////////////////////////////////////////////
  G4Box* solidTop =
      new G4Box("solidTop", XHalfLengthTop, YHalfLengthTop, HalfLengthTop);

  G4LogicalVolume* logicTop = new G4LogicalVolume(solidTop, Al, "Top");

  G4RotationMatrix rotm_Top = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_Top = G4Transform3D(rotm_Top, positionTop);
  // theDetectorHolder->AddPlacedVolume(logicTop,transform_Top);

  new G4PVPlacement(transform_Top,  // rotation,position
                    logicTop,       // its logical volume
                    "Top",          // its name
                    blogicDetVol,   // its mother  volume
                    false,          // no boolean operation
                    0,              // copy number
                    flagOverlaps);  // checking overlaps

  G4VisAttributes* TopVisAtt =
      new G4VisAttributes(G4Colour(0, 0, 1.0));  // BLUE
  logicTop->SetVisAttributes(TopVisAtt);

  ///////////////////////////////////////////////
  //////Uform///////////////////////////
  ///////////////////////////////////////////////
  std::vector<G4TwoVector> PUForm;
  PUForm.push_back(G4TwoVector(UFormx1, UFormy1));  // (x, z)
  PUForm.push_back(G4TwoVector(UFormx2, UFormy2));  // (x, z)
  PUForm.push_back(G4TwoVector(UFormx3, UFormy3));  // (x, z)
  PUForm.push_back(G4TwoVector(UFormx4, UFormy4));  // (x, z)
  PUForm.push_back(G4TwoVector(UFormx5, UFormy5));  // (x, z)
  PUForm.push_back(G4TwoVector(UFormx6, UFormy6));  // (x, z)
  PUForm.push_back(G4TwoVector(UFormx7, UFormy7));  // (x, z)
  PUForm.push_back(G4TwoVector(UFormx8, UFormy8));  // (x, z)
  //-------------------------------------------------------------------------------------------------------------
  G4VSolid* solidUForm =
      new G4ExtrudedSolid("solidUForm", PUForm, HalfLengthUForm, 0, 1, 0, 1);

  G4LogicalVolume* logicUForm = new G4LogicalVolume(solidUForm, Al, "UForm");

  G4RotationMatrix rotm_UForm = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_UForm = G4Transform3D(rotm_UForm, positionUForm);
  //  theDetectorHolder->AddPlacedVolume(logicUForm,transform_UForm);

  new G4PVPlacement(transform_UForm,  // rotation,position
                    logicUForm,       // its logical volume
                    "UForm",          // its name
                    blogicDetVol,     // its mother  volume
                    false,            // no boolean operation
                    0,                // copy number
                    flagOverlaps);    // checking overlaps

  G4VisAttributes* UFormVisAtt =
      new G4VisAttributes(G4Colour(0., 0., 1.0));  // BLUE
  logicUForm->SetVisAttributes(UFormVisAtt);

  // //////////////////////////////////////////////
  //   //////Circle Carbon fiber ///////////////////////////
  //   ///////////////////////////////////////////////
  //   G4Tubs* solidCarbonCircle = new
  //   G4Tubs("CarbonCircle",0.0,RmaxCarbonCircle,HalfLengthCarbonCircle,startPhi,deltaPhi);

  //   G4LogicalVolume* logicCarbonCircle = new
  //   G4LogicalVolume(solidCarbonCircle,Cfiber,"CarbonCircle");

  //   G4RotationMatrix rotm_CarbonCircle  =  G4RotationMatrix(0,90*deg,0);
  //   G4Transform3D transform_CarbonCircle =
  //   G4Transform3D(rotm_CarbonCircle,positionCarbonCircle);
  //   //  theDetectorHolder
  //   ->AddPlacedVolume(logicCarbonCircle,transform_CarbonCircle);

  // new G4PVPlacement(transform_CarbonCircle,             //rotation,position
  //   		    logicCarbonCircle,           //its logical volume
  //   		    "CarbonCircle",             //its name
  //   		    blogicDetVol,             //its mother  volume
  //   		    false,                 //no boolean operation
  //   		    0,                 //copy number
  //   		    flagOverlaps);       // checking overlaps

  //   G4VisAttributes* CarbonCircleVisAtt= new
  //   G4VisAttributes(G4Colour(0.,0.,0.0));  //Black
  //   logicCarbonCircle->SetVisAttributes(CarbonCircleVisAtt);

  //   //////////////////////////////////////////////
  //   //////BAR Carbon fiber///////////////////////////
  //   ///////////////////////////////////////////////
  //   G4Tubs* solidCarbonBar = new
  //   G4Tubs("CarbonBar",0.0,RmaxCarbonBar,HalfLengthCarbonBar,startPhi,deltaPhi);

  //   G4LogicalVolume* logicCarbonBar = new
  //   G4LogicalVolume(solidCarbonBar,Cfiber,"CarbonBar");

  //   G4RotationMatrix rotm_CarbonBar  =
  //   G4RotationMatrix(0.0*deg,90.0*deg,90.0*deg); G4Transform3D
  //   transform_CarbonBar = G4Transform3D(rotm_CarbonBar,positionCarbonBar);
  //   //  theDetectorHolder
  //   ->AddPlacedVolume(logicCarbonBar,transform_CarbonBar);

  // new G4PVPlacement(transform_CarbonBar,             //rotation,position
  //   		    logicCarbonBar,           //its logical volume
  //   		    "CarbonBar",             //its name
  //   		    blogicDetVol,             //its mother  volume
  //   		    false,                 //no boolean operation
  //   		    0,                 //copy number
  //   		    flagOverlaps);       // checking overlaps

  //   G4VisAttributes* CarbonBarVisAtt= new
  //   G4VisAttributes(G4Colour(0.,0.,0.0));  //Black
  //   logicCarbonBar->SetVisAttributes(CarbonBarVisAtt);

  //   //
  //   //------------------------------------------------------------------------------------------------------------

  G4Tubs* solidStripFront =
      new G4Tubs("StripFront", RminStrip, RmaxStrip, HalfLengthStrip,
                 startPhiStrip, LengthPhiStrip);

  G4LogicalVolume* logicStripFront =
      new G4LogicalVolume(solidStripFront, Cfiber, "StripFront");

  G4RotationMatrix rotm_StripFront = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_StripFront =
      G4Transform3D(rotm_StripFront, positionStripFront);
  //  theDetectorHolder ->AddPlacedVolume(logicStripFront,transform_StripFront);

  new G4PVPlacement(transform_StripFront,  // rotation,position
                    logicStripFront,       // its logical volume
                    "StripFront",          // its name
                    blogicDetVol,          // its mother  volume
                    false,                 // no boolean operation
                    0,                     // copy number
                    flagOverlaps);         // checking overlaps

  G4VisAttributes* StripFrontVisAtt =
      new G4VisAttributes(G4Colour(0., 0., 1));  // Blue
  logicStripFront->SetVisAttributes(StripFrontVisAtt);
  //  //-------------------------------------------------------------------------------------------------------------

  G4Tubs* solidStripBack =
      new G4Tubs("StripBack", RminStrip, RmaxStrip, HalfLengthStrip,
                 startPhiStrip, LengthPhiStrip);

  G4LogicalVolume* logicStripBack =
      new G4LogicalVolume(solidStripBack, Cfiber, "StripBack");

  G4RotationMatrix rotm_StripBack = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_StripBack =
      G4Transform3D(rotm_StripBack, positionStripBack);
  // theDetectorHolder ->AddPlacedVolume(logicStripBack,transform_StripBack);

  new G4PVPlacement(transform_StripBack,  // rotation,position
                    logicStripBack,       // its logical volume
                    "StripBack",          // its name
                    blogicDetVol,         // its mother  volume
                    false,                // no boolean operation
                    0,                    // copy number
                    flagOverlaps);        // checking overlaps

  G4VisAttributes* StripBackVisAtt =
      new G4VisAttributes(G4Colour(0., 0., 1));  // Blue
  logicStripBack->SetVisAttributes(StripBackVisAtt);
  //////////////////////////////////////////////
  //   //////Detector Bars///////////////////////////
  //   ///////////////////////////////////////////////
  //   std::vector<G4TwoVector> PAlBar;

  //   PAlBar.push_back(G4TwoVector(AlBarx1,AlBary1)); // (x, z)
  //   PAlBar.push_back(G4TwoVector(AlBarx2,AlBary2)); // (x, z)
  //   PAlBar.push_back(G4TwoVector(AlBarx3,AlBary3)); // (x, z)
  //   PAlBar.push_back(G4TwoVector(AlBarx4,AlBary4)); // (x, z)
  //   PAlBar.push_back(G4TwoVector(AlBarx5,AlBary5)); // (x, z)
  //   PAlBar.push_back(G4TwoVector(AlBarx6,AlBary6)); // (x, z)
  //   PAlBar.push_back(G4TwoVector(AlBarx7,AlBary7)); // (x, z)
  //   PAlBar.push_back(G4TwoVector(AlBarx8,AlBary8)); // (x, z)
  //   PAlBar.push_back(G4TwoVector(AlBarx9,AlBary9)); // (x, z)

  //   //-------------------------------------------------------------------------------------------------------------

  //   G4VSolid* solidAlBar = new G4ExtrudedSolid("solidAlBar",
  //   PAlBar,HalfLengthAlBar , 0,1,0,1);

  //   G4LogicalVolume* logicAlBar = new G4LogicalVolume(solidAlBar,Al,"AlBar");

  //   G4RotationMatrix rotm_AlBar  = G4RotationMatrix(0,RotateBar,0);
  //   G4Transform3D transform_AlBar = G4Transform3D(rotm_AlBar,positionAlBar);
  //   //theDetectorHolder ->AddPlacedVolume(logicAlBar,transform_AlBar);

  // new G4PVPlacement(transform_AlBar,             //rotation,position
  //   		    logicAlBar,           //its logical volume
  //   		    "AlBar",             //its name
  //   		    blogicDetVol,             //its mother  volume
  //   		    false,                 //no boolean operation
  //   		    0,                 //copy number
  //   		    flagOverlaps);       // checking overlaps

  //   G4VisAttributes* AlBarVisAtt= new G4VisAttributes(G4Colour(0.,0.,1.0));
  //   //BLUE logicAlBar->SetVisAttributes(AlBarVisAtt);

  //  //-------------------------------------------------------------------------------------------------------------
}

void C6D6DetectorConstruction::ConstructS6D6(G4LogicalVolume* mother,
                                             G4int* flagS6D6,
                                             G4double* thetaS6D6,
                                             G4double* phiS6D6,
                                             G4double* zS6D6) {
  //////////////////////////////////

  //=================================================================================================
  //=================================================================================================
  ////////////////////////////////////
  /////////////sTEd detectors://////////
  ///////////////////////////////////

  cout << endl << "Construct S6D6 detectors" << endl;

  G4double LengthC6D6 = 6.93 * cm;
  G4double RadiusC6D6 = 1.27 * cm;

  G4double LengthC6D6ExpasionVol = 0.68 * cm;
  G4double RadiusC6D6ExpasionVol = 1.8 / 2.0 * cm;

  G4double LengthQuartz = 1.1 * cm;
  G4double RadiusQuartz = 1.3 / 2.0 * cm;

  G4double LengthQuartz2 = 0.7 * cm;
  G4double RadiusQuartz2 = 1.9 / 2.0 * cm;

  const auto AlCase_pmt_x = 3.5 * CLHEP::cm;
  const auto AlCase_pmt_y = AlCase_pmt_x;
  const auto AlCase_pmt_z = 12.0 * CLHEP::cm;
  const auto AlCase_pmt_Thickness = .16 * CLHEP::cm;

  const auto pmt_x = 2.54 * CLHEP::cm;
  const auto pmt_y = pmt_x;
  const auto pmt_z = 2. * CLHEP::cm;

  const auto pmt_thickness = 2 * CLHEP::mm;
  const auto pmt_window_x = pmt_x - 2 * pmt_thickness;
  const auto pmt_window_y = pmt_window_x;
  const auto pmt_window_z = 0.8 * CLHEP::mm;

  const auto pmt_vacuum_x = pmt_window_x;
  const auto pmt_vacuum_y = pmt_vacuum_x;
  const auto pmt_vacuum_z = pmt_z - pmt_window_z - pmt_thickness;

  G4double LengthAlCaseFrontPart = 0.32 * cm;
  G4double LengthAlCase =
      LengthC6D6 + LengthC6D6ExpasionVol + LengthQuartz + LengthQuartz2;
  G4double RadiusAlCase = RadiusC6D6 + 0.32 * cm;
  G4double LenghtDetector = LengthAlCase + LengthAlCaseFrontPart;

  // if( DetID>NDetectors){
  //   G4cout<<" ****** Error in "<<__FILE__<<", line "<<__LINE__<<"
  //   ******"<<G4endl; G4cout<<"  DetID = "<<DetID<<" NDetectors=
  //   "<<NDetectors<<G4endl; exit(1);
  // }

  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================

  /////////////////////////////////////////////////////
  /////////////////////////////////////////////////////
  G4ThreeVector positionAlCaseFront = G4ThreeVector(
      0 * cm, 0. * cm, LenghtDetector / 2.0 - LengthAlCaseFrontPart / 2.0);
  G4ThreeVector positionAlCase = G4ThreeVector(
      0 * cm, 0. * cm,
      LenghtDetector / 2.0 - LengthAlCaseFrontPart - LengthAlCase / 2.0);
  G4ThreeVector positionC6D6 = G4ThreeVector(
      0 * cm, 0. * cm,
      LenghtDetector / 2.0 - LengthC6D6 / 2.0 - LengthAlCaseFrontPart);
  //    G4ThreeVector positionC6D6 =
  //    G4ThreeVector(0*cm,0.*cm,LengthAlCase/2.0-LengthC6D6/2.0);

  G4ThreeVector positionC6D6ExpasionVol = G4ThreeVector(
      0 * cm, 0. * cm, -LengthC6D6 / 2.0 - LengthC6D6ExpasionVol / 2.0);
  G4ThreeVector positionQuartz =
      G4ThreeVector(0 * cm, 0. * cm,
                    LenghtDetector / 2.0 - LengthC6D6 - LengthAlCaseFrontPart -
                        LengthC6D6ExpasionVol - LengthQuartz / 2.0);
  G4ThreeVector positionQuartz2 = G4ThreeVector(
      0 * cm, 0. * cm,
      LenghtDetector / 2.0 - LengthC6D6 - LengthAlCaseFrontPart -
          LengthC6D6ExpasionVol - LengthQuartz - LengthQuartz2 / 2.0);

  G4ThreeVector positionC6D6Subtraction =
      G4ThreeVector(0 * cm, 0. * cm, +LengthAlCase / 2.0 - LengthC6D6 / 2.0);
  G4ThreeVector positionQuartzSubtraction =
      G4ThreeVector(0 * cm, 0. * cm,
                    +LengthAlCase / 2.0 - LengthC6D6 - LengthC6D6ExpasionVol -
                        LengthQuartz / 2.0);
  G4ThreeVector positionQuartz2Subtraction =
      G4ThreeVector(0 * cm, 0. * cm,
                    +LengthAlCase / 2.0 - LengthC6D6 - LengthC6D6ExpasionVol -
                        LengthQuartz - LengthQuartz2 / 2.0);

  G4ThreeVector positionAlCase_pmt =
      G4ThreeVector(0 * cm, 0. * cm, -LenghtDetector / 2 - AlCase_pmt_z / 2);

  G4ThreeVector positionAlCase_pmt_Vacuum = G4ThreeVector(
      0 * cm, 0. * cm,
      +AlCase_pmt_z / 2 - (AlCase_pmt_z - AlCase_pmt_Thickness) / 2);

  G4ThreeVector positionpmt =
      G4ThreeVector(0 * cm, 0. * cm,
                    +((AlCase_pmt_z - AlCase_pmt_Thickness) / 2) - pmt_z / 2);

  const auto pmt_window_z_position = +pmt_z / 2.0 - pmt_window_z / 2.0;
  const auto pmt_vacuum_z_position =
      pmt_window_z_position + -pmt_window_z / 2.0 + -pmt_vacuum_z / 2.0;

  //=======================

  /// PLAcEMENT OF THE COMPONENTS OF THE C6D6 DETECTOR IN THE VAC0 VOLUME

  G4Box* ssolidDetVol =
      new G4Box("sdetVol", RadiusAlCase + 0.01 * mm, RadiusAlCase + 0.01 * mm,
                LenghtDetector / 2.0);

  G4Box* ssolidDetVolPMT =
      new G4Box("sdetVolPMT", AlCase_pmt_x / 2 + 0.01 * mm,
                AlCase_pmt_x / 2 + 0.01 * mm, AlCase_pmt_z / 2.0 + 0.01 * mm);

  G4UnionSolid* ssolidDetVolUnion = new G4UnionSolid(
      "ssolidDetVolUnion", ssolidDetVol, ssolidDetVolPMT, 0,
      G4ThreeVector(0. * mm, 0. * mm,
                    -LenghtDetector / 2 + -AlCase_pmt_z / 2.0));

  G4LogicalVolume* slogicDetVol =
      new G4LogicalVolume(ssolidDetVolUnion,  // its solid
                          vacuum,             // its material
                          "sdetVol");         // its name
  slogicDetVol->SetVisAttributes(G4VisAttributes::GetInvisible());
  // slogicDetVol->SetVisAttributes(G4Color::Gray());

  // slogicDetVol->SetVisAttributes(G4Color::Gray());

  // G4bool PSURFCHK=true;
  G4double detVol_dZ = LenghtDetector / 2.0;
  G4double detVolPMT_dZ = LenghtDetector + AlCase_pmt_x / 2.0;

  for (int i = 1; i < (theInputManager->GetTotalNC6D6Detectors() + 1); i++) {
    G4RotationMatrix rotS6D6[50];
    G4double rS6D6[50];

    G4ThreeVector posS6D6[50];

    // G4VPhysicalVolume *physiS6D6[50];
    char name[1000];
    if (flagS6D6[i] == 3) {
      G4cout << "Build S6D6_" << i << " thetaS6D6= " << thetaS6D6[i]
             << " phiS6D6z= " << phiS6D6[i] << " z= " << zS6D6[i] << G4endl;
      rotS6D6[i] = G4RotationMatrix();

      if (zS6D6[i] <= 0) {
        G4cout << "### Det=" << i
               << " Modify to have an horizontal detector  Distance R="
               << zS6D6[i] << " ###" << G4endl;

        rotS6D6[i].rotateY(90 * deg);
        zS6D6[i] = -zS6D6[i];
      } else {
        rotS6D6[i].rotateY(thetaS6D6[i] * deg);
      }
      rotS6D6[i].rotateZ(phiS6D6[i] * deg);
      rS6D6[i] = detVol_dZ + zS6D6[i] * cm;

      posS6D6[i] = G4ThreeVector(
          -rS6D6[i] * sin(thetaS6D6[i] * deg) * cos(phiS6D6[i] * deg),
          -rS6D6[i] * sin(thetaS6D6[i] * deg) * sin(phiS6D6[i] * deg),
          -rS6D6[i] * cos(thetaS6D6[i] * deg));

      sprintf(name, "S6D6_%d", i);
      //      physiS6D6[i] =
      new G4PVPlacement(G4Transform3D(rotS6D6[i], posS6D6[i]),
                        slogicDetVol,  // its logical volume
                        name,
                        mother,  // its
                        false,   // no boolean operation
                        i,       // copy number
                        flagOverlaps);
    }
  }

  /////////////////////////////////////////////////////
  /////C6D6 Liquid////////
  /////////////////////////////////////////////////////

  G4Box* solidC6D6Prev =
      new G4Box("solidC6D6Prev", RadiusC6D6, RadiusC6D6, LengthC6D6 / 2.0);

  // G4double VolumeinC6D6Prev=solidC6D6Prev->GetCubicVolume();

  G4Box* soliC6D6ExpasionVol =
      new G4Box("soliC6D6ExpasionVol", RadiusC6D6ExpasionVol,
                RadiusC6D6ExpasionVol, LengthC6D6ExpasionVol / 2.0);

  // G4double VolumeinC6D6ExpasionVol=soliC6D6ExpasionVol->GetCubicVolume();

  G4UnionSolid* solidC6D6 =
      new G4UnionSolid("solidC6D6", solidC6D6Prev, soliC6D6ExpasionVol, 0,
                       positionC6D6ExpasionVol);

  SfLogicC6D6 = new G4LogicalVolume(solidC6D6, C6D6, "C6D6");
  G4RotationMatrix rotm_C6D6 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_C6D6 = G4Transform3D(rotm_C6D6, positionC6D6);
  //     thesTED->AddPlacedVolume(logicC6D6,transform_C6D6);
  new G4PVPlacement(transform_C6D6,  // rotation,position
                    SfLogicC6D6,     // its logical volume
                    "C6D6",          // its name
                    slogicDetVol,    // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps

  G4VisAttributes* C6D6VisAtt =
      new G4VisAttributes(G4Colour(0., 0., 1.0));  // BLUE

  SfLogicC6D6->SetVisAttributes(C6D6VisAtt);

  G4double VolumeinC6D6 = solidC6D6->GetCubicVolume();
  // G4cout<<"Volume of C6D6 in one detector"<<0.000001*VolumeinC6D6<<" in
  // Litres"<<G4endl; G4cout<<"Volume of C6D6Expansion in one
  // detector"<<0.000001*VolumeinC6D6ExpasionVol<<" in Litres"<<G4endl;
  G4cout << "Volume of C6D6 " << 0.000001 * VolumeinC6D6 << " Litres" << G4endl;

  /////////////////////////////////////////////////////
  ////Quartz////////
  /////////////////////////////////////////////////////

  G4Box* solidQuartz =
      new G4Box("Quartz", RadiusQuartz, RadiusQuartz, LengthQuartz / 2.0);
  G4LogicalVolume* logicQuartz =
      new G4LogicalVolume(solidQuartz, Quartz, "Quartz");
  G4RotationMatrix rotm_Quartz = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_Quartz = G4Transform3D(rotm_Quartz, positionQuartz);
  // thesTED->AddPlacedVolume(logicQuartz,transform_Quartz);

  new G4PVPlacement(transform_Quartz,  // rotation,position
                    logicQuartz,       // its logical volume
                    "Quartz",          // its name
                    slogicDetVol,      // its mother  volume
                    false,             // no boolean operation
                    0,                 // copy number
                    flagOverlaps);     // checking overlaps

  G4VisAttributes* QuartzVisAtt =
      new G4VisAttributes(G4Colour(1., 0., 0.));  // RED 100
  logicQuartz->SetVisAttributes(QuartzVisAtt);

  /////////////////////////////////////////////////////
  /////Quartz2 ////////
  /////////////////////////////////////////////////////

  G4Box* solidQuartz2 =
      new G4Box("Quartz2", RadiusQuartz2, RadiusQuartz2, LengthQuartz2 / 2.0);
  G4LogicalVolume* logicQuartz2 =
      new G4LogicalVolume(solidQuartz2, Quartz, "Quartz2");
  G4RotationMatrix rotm_Quartz2 = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_Quartz2 =
      G4Transform3D(rotm_Quartz2, positionQuartz2);
  // thesTED->AddPlacedVolume(logicQuartz2,transform_Quartz2);
  new G4PVPlacement(transform_Quartz2,  // rotation,position
                    logicQuartz2,       // its logical volume
                    "Quartz2",          // its name
                    slogicDetVol,       // its mother  volume
                    false,              // no boolean operation
                    0,                  // copy number
                    flagOverlaps);      // checking overlaps

  G4VisAttributes* Quartz2VisAtt =
      new G4VisAttributes(G4Colour(0.7, 0.2, 0.0));  // ORANGE
  logicQuartz2->SetVisAttributes(Quartz2VisAtt);

  /////////////////////////////////////////////////////
  /////Al Front CaseFront////////
  /////////////////////////////////////////////////////

  G4Box* solidAlCaseFront = new G4Box("AlCaseFront", RadiusAlCase, RadiusAlCase,
                                      LengthAlCaseFrontPart / 2.0);
  G4LogicalVolume* logicAlCaseFront =
      new G4LogicalVolume(solidAlCaseFront, AlAW6082, "AlCaseFront");
  G4RotationMatrix rotm_AlCaseFront = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_AlCaseFront =
      G4Transform3D(rotm_AlCaseFront, positionAlCaseFront);
  //  thesTED->AddPlacedVolume(logicAlCaseFront,transform_AlCaseFront);
  new G4PVPlacement(transform_AlCaseFront,  // rotation,position
                    logicAlCaseFront,       // its logical volume
                    "AlCaseFront",          // its name
                    slogicDetVol,           // its mother  volume
                    false,                  // no boolean operation
                    0,                      // copy number
                    flagOverlaps);          // checking overlaps

  G4VisAttributes* AlCaseFrontVisAtt =
      new G4VisAttributes(G4Colour(0.6, 0.6, 0.6));  // GREY
  logicAlCaseFront->SetVisAttributes(AlCaseFrontVisAtt);

  /////////////////////////////////////////////////////
  /////Al Case////////
  /////////////////////////////////////////////////////

  G4Box* solidAlCasePrev1 = new G4Box("solidAlCasePrev1", RadiusAlCase,
                                      RadiusAlCase, LengthAlCase / 2.0);

  G4SubtractionSolid* solidAlCasePrev2 =
      new G4SubtractionSolid("solidAlCasePrev2", solidAlCasePrev1, solidC6D6, 0,
                             positionC6D6Subtraction);
  G4SubtractionSolid* solidAlCasePrev3 =
      new G4SubtractionSolid("solidAlCasePrev3", solidAlCasePrev2, solidQuartz,
                             0, positionQuartzSubtraction);
  G4SubtractionSolid* solidAlCase =
      new G4SubtractionSolid("solidAlCase", solidAlCasePrev3, solidQuartz2, 0,
                             positionQuartz2Subtraction);

  G4LogicalVolume* logicAlCase =
      new G4LogicalVolume(solidAlCase, AlAW6082, "AlCase");
  G4RotationMatrix rotm_AlCase = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_AlCase = G4Transform3D(rotm_AlCase, positionAlCase);
  // thesTED->AddPlacedVolume(logicAlCase,transform_AlCase);
  new G4PVPlacement(transform_AlCase,  // rotation,position
                    logicAlCase,       // its logical volume
                    "AlCase",          // its name
                    slogicDetVol,      // its mother  volume
                    false,             // no boolean operation
                    0,                 // copy number
                    flagOverlaps);     // checking overlaps

  G4VisAttributes* AlCaseVisAtt =
      new G4VisAttributes(G4Colour(0.6, 0.6, 0.6));  // GREY
  logicAlCase->SetVisAttributes(AlCaseVisAtt);

  /////////////////////////////////////////////////////
  /////Al Case PMT////////
  /////////////////////////////////////////////////////

  const auto AlCase_pmt = new G4Box("AlCase_PMT", AlCase_pmt_x / 2,
                                    AlCase_pmt_y / 2, AlCase_pmt_z / 2);
  const auto log_AlCase_pmt = new G4LogicalVolume(AlCase_pmt, AlAW6082, "PMT");

  G4RotationMatrix rotm_pmt = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_pmt = G4Transform3D(rotm_pmt, positionAlCase_pmt);
  // thesTED->AddPlacedVolume(logicAlCase,transform_AlCase);
  new G4PVPlacement(transform_pmt,   // rotation,position
                    log_AlCase_pmt,  // its logical volume
                    "AlCase_PMT",    // its name
                    slogicDetVol,    // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps

  G4VisAttributes* PMTVisAtt = new G4VisAttributes(G4Color::Grey());  // grey
  log_AlCase_pmt->SetVisAttributes(PMTVisAtt);

  /////////////////////////////////////////////////////
  /////Al Case PMT Vacuum////////
  /////////////////////////////////////////////////////

  const auto AlCase_pmt_vacuum =
      new G4Box("AlCase_vacuum", (AlCase_pmt_y - 2 * AlCase_pmt_Thickness) / 2,
                (AlCase_pmt_y - 2 * AlCase_pmt_Thickness) / 2,
                (AlCase_pmt_z - AlCase_pmt_Thickness) / 2);
  const auto log_AlCase_pmt_vacuum =
      new G4LogicalVolume(AlCase_pmt_vacuum, vacuum_mat, "AlCase_pmt_vacuum");

  new G4PVPlacement(nullptr, positionAlCase_pmt_Vacuum, log_AlCase_pmt_vacuum,
                    "AlCase_pmt_vacuum", log_AlCase_pmt, false, 0, true);

  G4VisAttributes* AlCase_pmt_vacuumVisAtt =
      new G4VisAttributes(G4Colour::White());  // White
  log_AlCase_pmt_vacuum->SetVisAttributes(AlCase_pmt_vacuumVisAtt);
  /////////////////////////////////////////////////////
  /////PMT ////////
  /////////////////////////////////////////////////////

  const auto pmt = new G4Box("PMT", pmt_x / 2, pmt_y / 2, pmt_z / 2);
  const auto log_pmt = new G4LogicalVolume(pmt, kovar_mat, "PMT");
  new G4PVPlacement(nullptr, positionpmt, log_pmt, "PMT", log_AlCase_pmt_vacuum,
                    false, 0, true);
  G4VisAttributes* PMT_VisAtt =
      new G4VisAttributes(G4Colour::Yellow());  // Yellow
  log_pmt->SetVisAttributes(PMT_VisAtt);
  /////////////////////////////////////////////////////
  /////PMT Window ////////
  /////////////////////////////////////////////////////

  const auto pmt_window = new G4Box("PMT_Window", pmt_window_x / 2,
                                    pmt_window_y / 2, pmt_window_z / 2);
  const auto log_pmt_window =
      new G4LogicalVolume(pmt_window, pyrex_glass_mat, "PMT_Window");

  new G4PVPlacement(nullptr, G4ThreeVector(0, 0, pmt_window_z_position),
                    log_pmt_window, "PMT_Window", log_pmt, false, 0, true);

  G4VisAttributes* PMT_windowVisAtt =
      new G4VisAttributes(G4Colour::Magenta());  // ORANGE
  log_pmt_window->SetVisAttributes(PMT_windowVisAtt);
  /////////////////////////////////////////////////////
  /////PMT Vacuum inside ////////
  /////////////////////////////////////////////////////

  const auto pmt_vacuum = new G4Box("PMT_Vacuum", pmt_vacuum_x / 2,
                                    pmt_vacuum_y / 2, pmt_vacuum_z / 2);

  const auto log_pmt_vacuum =
      new G4LogicalVolume(pmt_vacuum, vacuum_mat, "PMT_Vacuum");

  new G4PVPlacement(nullptr, G4ThreeVector(0, 0, pmt_vacuum_z_position),
                    log_pmt_vacuum, "PMT_Vacuum", log_pmt, false, 0, true);
  G4VisAttributes* log_pmt_vacuumVisAtt =
      new G4VisAttributes(G4Colour::White());  // White
  log_pmt_vacuum->SetVisAttributes(log_pmt_vacuumVisAtt);
}

void C6D6DetectorConstruction::ConstructESTI(G4LogicalVolume* mother,
                                             G4int* flagESTI,
                                             G4double* thetaESTI,
                                             G4double* phiESTI,
                                             G4double* zESTI) {
  //////////////////////////////////

  //=================================================================================================
  //=================================================================================================
  ////////////////////////////////////
  /////////////ESTI detectors://////////
  ///////////////////////////////////

  cout << endl << "Construct ESTI detectors" << endl;

  G4double LengthESTI = 1 * cm;
  G4double RadiusESTI = 1.5875 * cm;

  G4double LenghtDetector = LengthESTI;

  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================
  //========================================================================

  G4ThreeVector positionESTI =
      G4ThreeVector(0 * cm, 0. * cm, LenghtDetector / 2.0 - LengthESTI / 2.0);
  //    G4ThreeVector positionESTI =
  //    G4ThreeVector(0*cm,0.*cm,LengthAlCase/2.0-LengthESTI/2.0);

  //=======================

  /// PLAcEMENT OF THE COMPONENTS OF THE ESTI DETECTOR IN THE VAC0 VOLUME

  // G4Box* ssolidDetVol=  new G4Box("sdetVol",RadiusESTI+0.01*mm,
  // RadiusESTI+0.01*mm,LenghtDetector/2.0+0.01*mm);
  G4Tubs* ssolidDetVol =
      new G4Tubs("sdetVol", 0, RadiusESTI + 0.01 * mm,
                 LengthESTI / 2 + 0.01 * mm, 0. * deg, 360. * deg);

  G4LogicalVolume* slogicDetVol =
      new G4LogicalVolume(ssolidDetVol,  // its solid
                          vacuum,        // its material
                          "sdetVol");    // its name
  slogicDetVol->SetVisAttributes(G4VisAttributes::GetInvisible());
  // slogicDetVol->SetVisAttributes(G4Color::Gray());

  // G4bool PSURFCHK=true;
  G4double detVol_dZ = LenghtDetector / 2.0;

  for (int i = 1; i < (theInputManager->GetTotalNC6D6Detectors() + 1); i++) {
    G4RotationMatrix rotESTI[50];
    G4double rESTI[50];
    G4ThreeVector posESTI[50];
    // G4VPhysicalVolume *physiESTI[50];
    char name[1000];
    if (flagESTI[i] == 4) {
      G4cout << "Build ESTI_" << i << " thetaESTI= " << thetaESTI[i]
             << " phiESTIz= " << phiESTI[i] << " z= " << zESTI[i] << G4endl;
      rotESTI[i] = G4RotationMatrix();
      rotESTI[i].rotateY(thetaESTI[i] * deg);
      rotESTI[i].rotateZ(phiESTI[i] * deg);
      rESTI[i] = detVol_dZ + zESTI[i] * cm;
      posESTI[i] = G4ThreeVector(
          -rESTI[i] * sin(thetaESTI[i] * deg) * cos(phiESTI[i] * deg),
          -rESTI[i] * sin(thetaESTI[i] * deg) * sin(phiESTI[i] * deg),
          -rESTI[i] * cos(thetaESTI[i] * deg));
      sprintf(name, "ESTI_%d", i);
      //      physiESTI[i] =
      new G4PVPlacement(G4Transform3D(rotESTI[i], posESTI[i]),
                        slogicDetVol,  // its logical volume
                        name,
                        mother,  // its
                        false,   // no boolean operation
                        i,       // copy number
                        flagOverlaps);
    }
  }

  /////////////////////////////////////////////////////
  /////ESTI Liquid////////
  /////////////////////////////////////////////////////

  G4Tubs* solidESTI = new G4Tubs("solidESTI", 0, RadiusESTI, LengthESTI / 2,
                                 0. * deg, 360. * deg);

  EfLogicC6D6 = new G4LogicalVolume(solidESTI, ESTI, "ESTI");
  G4RotationMatrix rotm_ESTI = G4RotationMatrix(0, 0, 0);
  G4Transform3D transform_ESTI = G4Transform3D(rotm_ESTI, positionESTI);
  //     thesTED->AddPlacedVolume(logicESTI,transform_ESTI);
  new G4PVPlacement(transform_ESTI,  // rotation,position
                    EfLogicC6D6,     // its logical volume
                    "ESTI",          // its name
                    slogicDetVol,    // its mother  volume
                    false,           // no boolean operation
                    0,               // copy number
                    flagOverlaps);   // checking overlaps

  G4VisAttributes* ESTIVisAtt =
      new G4VisAttributes(G4Colour(0., 0., 1.0));  // BLUE

  EfLogicC6D6->SetVisAttributes(ESTIVisAtt);

  G4double VolumeinESTI = solidESTI->GetCubicVolume();
  // G4cout<<"Volume of ESTI in one detector"<<0.000001*VolumeinESTI<<" in
  // Litres"<<G4endl; G4cout<<"Volume of ESTIExpansion in one
  // detector"<<0.000001*VolumeinESTIExpasionVol<<" in Litres"<<G4endl;
  G4cout << "Volume of ESTI " << 0.000001 * VolumeinESTI << " Litres" << G4endl;
}
