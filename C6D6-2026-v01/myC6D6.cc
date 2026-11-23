
#include "C6D6ActionInitialization.hh"
#include "C6D6DetectorConstruction.hh"
#include "C6D6InputManager.hh"
#include "FTFP_BERT_HP.hh"
#include "FTFP_INCLXX_HP.hh"
#include "G4HadronicParameters.hh"
#include "G4HadronicProcessStore.hh"
#include "G4ParticleHPManager.hh"
#include "G4PhysListFactory.hh"
#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VModularPhysicsList.hh"
#include "G4VisExecutive.hh"
#include "QGSP_BERT.hh"
#include "QGSP_BERT_HP.hh"
#include "QGSP_BIC_HP.hh"
#include "QGSP_INCLXX_HP.hh"
#include "Randomize.hh"
#include "Shielding.hh"

int main(int argc, char** argv) {
  if (argc < 2) {
    G4cout << " ###############################################################"
              "#########"
           << G4endl;
    G4cout << " Input has to be like --->  ./myC6D6 InputFname [replacement "
              "commands]  "
           << G4endl;
    G4cout << " ###############################################################"
              "#########"
           << G4endl;
    return 1;
  }

  //-----------------------------------------------------------------------
  char inputfile[500];
  if (argc == 2) {
    sprintf(inputfile, "%s", argv[1]);
  } else {
    char command[1000];
    G4String tmpinput = G4String(argv[1]);
    for (int i = 0; i < argc / 2 - 1; i++) {
      G4String parval = G4String(argv[2 * (i + 1) + 1]);
      std::replace(parval.begin(), parval.end(), '/', '-');
      tmpinput += "_" + parval;
    }
    sprintf(command, "cp %s %s", argv[1], tmpinput.c_str());
    int check = system(command);
    if (check != 0) {
      G4cout << " ########### Error executing command: " << command
             << "  ###########" << G4endl;
      exit(1);
    }
    for (int i = 0; i < argc / 2 - 1; i++) {
      G4String parname = G4String(argv[2 * (i + 1)]);
      G4String parval = G4String(argv[2 * (i + 1) + 1]);
      size_t pos = parval.find("/");
      while (pos != std::string::npos) {
        parval.replace(pos, 1, "\\/");
        pos = parval.find("/", pos + 2);
      }
      sprintf(command, "sed -i 's/%s/%s/g' %s", parname.c_str(), parval.c_str(),
              tmpinput.c_str());
      check = system(command);
      if (check != 0) {
        G4cout << " ########### Error executing command: " << command
               << "  ###########" << G4endl;
        exit(1);
      }
    }
    sprintf(inputfile, "%s", tmpinput.c_str());
  }
  //-----------------------------------------------------------------------

  // User input
  C6D6InputManager* theInputManager = C6D6InputManager::getInstance();
  theInputManager->Read(inputfile);
  theInputManager->Print();

  // Random engine
  G4long myseed = theInputManager->GetSeed();
  CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
  G4Random::setTheSeed(myseed);

  G4bool Interactive = theInputManager->IsInteractive();
  // G4bool Interactive=true;
  G4UIExecutive* ui = nullptr;
  if (Interactive) {
    ui = new G4UIExecutive(argc, argv);
  }

  G4RunManager* runManager = new G4RunManager();

  // Detector construction
  C6D6DetectorConstruction* theDetectorConstruction =
      new C6D6DetectorConstruction();
  runManager->SetUserInitialization(theDetectorConstruction);

  // Physics list
  // Needed for Geant4 v11 To simulate also the decaysources with a half life
  // longer than 1 year
  G4HadronicParameters::Instance()->SetTimeThresholdForRadioactiveDecay(
      1.0e+4 * CLHEP::year);
  G4int VerboseLevel = 0;
  G4PhysListFactory factory(VerboseLevel);
  G4VModularPhysicsList* physicsList = nullptr;
  G4String physListName = theInputManager->GetPhysicsListName();
  if ("" == physListName || !factory.IsReferencePhysList(physListName)) {
    G4cout << " ########## ERROR in " << __FILE__ << ", line " << __LINE__
           << " ##########" << G4endl;
    exit(1);
  }
  physicsList = factory.GetReferencePhysList(physListName);
  physicsList->SetVerboseLevel(VerboseLevel);
  if (physListName == "QGSP_BIC" || physListName == "QGSP_INCLXX") {
    physicsList->RegisterPhysics(new G4RadioactiveDecayPhysics(VerboseLevel));
    physicsList->RemovePhysics("neutronTrackingCut");
    physicsList->SetCutValue(0, "proton");
  }

  // set HP physics variables (formerly environmental variables); others are
  // default values so commented out
  G4ParticleHPManager::GetInstance()->SetSkipMissingIsotopes(true);
  G4ParticleHPManager::GetInstance()->SetDoNotAdjustFinalState(true);
  // G4ParticleHPManager::GetInstance()->SetUseOnlyPhotoEvaporation( false );
  G4ParticleHPManager::GetInstance()->SetNeglectDoppler(false);
  if (theInputManager->GetPhysicsListOpt2() == 1) {
    G4ParticleHPManager::GetInstance()->SetNeglectDoppler(true);
  }
  G4ParticleHPManager::GetInstance()->SetProduceFissionFragments(true);
  G4ParticleHPManager::GetInstance()->SetUseWendtFissionModel(true);
  // G4ParticleHPManager::GetInstance()->SetUseNRESP71Model( false );

  // cuts:
  G4double CutForGamma = theInputManager->GetCutForGamma();
  G4double CutForProton = theInputManager->GetCutForProton();
  physicsList->SetCutValue(CutForGamma, "gamma");
  physicsList->SetCutValue(CutForGamma, "e+");
  physicsList->SetCutValue(CutForGamma, "e-");
  physicsList->SetCutValue(CutForProton, "proton");
  runManager->SetUserInitialization(physicsList);

  // User action initialization
  C6D6ActionInitialization* myActionInitialization =
      new C6D6ActionInitialization();
  runManager->SetUserInitialization(myActionInitialization);

  runManager->Initialize();

  G4UImanager* UImanager = G4UImanager::GetUIpointer();
  if (theInputManager->GetPhysicsListOpt1() == 1) {
    UImanager->ApplyCommand("/process/had/rdm/deselectVolume Target");
  } else if (theInputManager->GetPhysicsListOpt1() == 2) {
    UImanager->ApplyCommand("/process/had/rdm/noVolumes");
  }

  if (ui) {
    // Initialize visualization
    //
    G4VisManager* visManager = new G4VisExecutive;
    // G4VisExecutive can take a verbosity argument - see /vis/verbose guidance.
    // G4VisManager* visManager = new G4VisExecutive("Quiet");
    visManager->Initialize();

    // interactive mode
    // UImanager->ApplyCommand("/control/execute init_vis.mac");
    // G4UImanager::GetUIpointer()->ApplyCommand("/control/execute
    // inputs/vis02.mac");

    ui->SessionStart();
    delete ui;
    delete visManager;
  } else {
    G4double NEventsToRun = theInputManager->GetNEventsToRun();
    // UImanager->ApplyCommand("/tracking/verbose 1");
    runManager->BeamOn(NEventsToRun);
  }

  delete runManager;
  delete theInputManager;

  return 0;
}
