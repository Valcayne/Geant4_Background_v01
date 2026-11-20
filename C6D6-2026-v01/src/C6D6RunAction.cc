
#include "C6D6RunAction.hh"


C6D6RunAction::C6D6RunAction(C6D6PrimaryGeneratorAction *pga)
    : G4UserRunAction() {
  // User Input
  C6D6InputManager* theInputManager=C6D6InputManager::getInstance();
  // Primary generator action
  myPrimaryGenerator = pga;
  TotalNEvents=0;
  
  G4AnalysisManager *theAnalysisManager = G4AnalysisManager::Instance();
  theAnalysisManager->SetVerboseLevel(0);
  //theAnalysisManager->SetNtupleMerging(true); //only for multi-threading
  theAnalysisManager->OpenFile(theInputManager->GetOutFname().c_str());

  char name[1000];

  NDet=theInputManager->GetTotalNC6D6Detectors();
  OutInf01=theInputManager->GetOutputInfo(0);
  OutInf02=theInputManager->GetOutputInfo(1);
  OutInf03=theInputManager->GetOutputInfo(2);
    
  //Histogramas 1D:
  if(OutInf01>0){
    for(G4int i=0;i<=NDet;i++){
      sprintf(name, "hEdep_%.2d",i);
      theAnalysisManager->CreateH1(name,"Edep histo",2000,0,20,"none","none","linear");
      theAnalysisManager->SetH1XAxisTitle(i,"Deposited energy (MeV)");
      theAnalysisManager->SetH1YAxisTitle(i,"counts/source");
    }
    sprintf(name, "hCaptures_TOF");
    theAnalysisManager->CreateH1(name,"TOF-Captures histo",140000,1e-1,1.e13,"none","none","log");
    theAnalysisManager->SetH1XAxisTitle(NDet+1,"Time-of-flight (ns)");
    theAnalysisManager->SetH1YAxisTitle(NDet+1,"captures/source");
    sprintf(name, "hDet_TOF");
    theAnalysisManager->CreateH1(name,"TOF-Detectors histo",140000,1e-1,1.e13,"none","none","log");
    theAnalysisManager->SetH1XAxisTitle(NDet+2,"Time-of-flight (ns)");
    theAnalysisManager->SetH1YAxisTitle(NDet+2,"counts/source");
     sprintf(name, "hTargetAct");
    theAnalysisManager->CreateH1(name,"Activation",100000,0.5,100000.5,"none","none","linear");
    theAnalysisManager->SetH1XAxisTitle(NDet+3,"ZA");
    theAnalysisManager->SetH1YAxisTitle(NDet+3,"production/source");
    sprintf(name, "hCaptures_En");
    theAnalysisManager->CreateH1(name,"En-Captures histo",70000,1.e-3,1.e11,"none","none","log");
    theAnalysisManager->SetH1XAxisTitle(NDet+4,"Neutron energy (eV)");
    theAnalysisManager->SetH1YAxisTitle(NDet+4,"captures/source");
    sprintf(name, "hSource_En");
    theAnalysisManager->CreateH1(name,"En-Source histo",70000,1.e-3,1.e11,"none","none","log");
    theAnalysisManager->SetH1XAxisTitle(NDet+5,"Source energy (eV)");
    theAnalysisManager->SetH1YAxisTitle(NDet+5,"particles/source");
 }
  
  //Histogramas bidimensionales TOF-Edep histo:
  if(OutInf02>0){
    for(G4int i=0;i<=NDet;i++){
      if(i==0 || OutInf02==1){ //if OutInf02==2 then only Det0 
	sprintf(name, "hTOFEdep_%.2d",i);
	theAnalysisManager->CreateH2(name,"TOF-Edep histo",1400,1e-1,1.e13,2000,0,20,"none","none","none","none","log","linear");
	theAnalysisManager->SetH2XAxisTitle(i,"Time-of-flight (ns)");
	theAnalysisManager->SetH2YAxisTitle(i,"Deposited energy (MeV)");
      }
    }
    if(OutInf02==3){
      sprintf(name, "hTOFAct_%.2d",1);
      theAnalysisManager->CreateH2(name,"TOF-Act histo",90,1e+1,1.e10,100000,0.5,100000.5,"none","none","none","none","log","linear");
      theAnalysisManager->SetH2XAxisTitle(1,"Time-of-flight (ns)");
      theAnalysisManager->SetH2YAxisTitle(1,"ZA");
    }
    if(OutInf02==4){
      sprintf(name, "hTOFEdep_Walls");
      theAnalysisManager->CreateH2(name,"TOF-Edep histo",1400,1e-1,1.e13,2000,0,20,"none","none","none","none","log","linear");
      theAnalysisManager->SetH2XAxisTitle(1,"Time-of-flight (ns)");
      theAnalysisManager->SetH2YAxisTitle(1,"Deposited energy (MeV)");
      sprintf(name, "hTOFEdep_C6D6");
      theAnalysisManager->CreateH2(name,"TOF-Edep histo",1400,1e-1,1.e13,2000,0,20,"none","none","none","none","log","linear");
      theAnalysisManager->SetH2XAxisTitle(2,"Time-of-flight (ns)");
      theAnalysisManager->SetH2YAxisTitle(2,"Deposited energy (MeV)");
    }
  }

  //N-tupla:
  if(OutInf03>0){
    sprintf(name, "C6D6_All");
    theAnalysisManager->CreateNtuple(name, name);
    theAnalysisManager->CreateNtupleDColumn("Event");
    theAnalysisManager->CreateNtupleDColumn("Det");
    theAnalysisManager->CreateNtupleDColumn("Edep");
    theAnalysisManager->CreateNtupleDColumn("Time");
    theAnalysisManager->FinishNtuple();
  }
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

C6D6RunAction::~C6D6RunAction() {

  G4AnalysisManager *theAnalysisManager = G4AnalysisManager::Instance();

  //Normalization:
  G4cout<<" Deleting run action. Run terminated after "<<TotalNEvents<<" events"<<G4endl;

  if(OutInf01>0){
    for(G4int i=0;i<=NDet+5;i++){
      theAnalysisManager->ScaleH1(i,1./TotalNEvents);
    }
  }
  if(OutInf02>0){
    for(G4int i=0;i<=NDet;i++){
      if(i==0 || OutInf02==1){ //if OutInf02==2 then only Det0 
	theAnalysisManager->ScaleH2(i,1./TotalNEvents);
      }
    }
    if(OutInf02==3){theAnalysisManager->ScaleH2(1,1./TotalNEvents);}
    if(OutInf02==4){
      theAnalysisManager->ScaleH2(1,1./TotalNEvents);
      theAnalysisManager->ScaleH2(2,1./TotalNEvents);
    }
 }
  
  theAnalysisManager->Write();
  theAnalysisManager->CloseFile();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6RunAction::BeginOfRunAction(const G4Run *) {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void C6D6RunAction::EndOfRunAction(const G4Run *C6D6run) {

  C6D6EventAction* theEventAction=(C6D6EventAction*)G4RunManager::GetRunManager()->GetUserEventAction();
  TotalNEvents=theEventAction->GetNEvents();

}
