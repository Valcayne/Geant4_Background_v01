#ifndef INPUTMANAGER_HH
#define INPUTMANAGER_HH 1

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>      // std::istringstream

#include "G4ThreeVector.hh"
#include "G4AnalysisManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4LogicalVolume.hh"

using namespace std;

#define MAXNDET 50

G4int ReadLine_d(ifstream& in,G4double* vals);
G4int ReadLine_i(ifstream& in,G4int* vals);
G4int ReadLine_s(ifstream& in,string* vals);

class C6D6InputManager{
 public:
  C6D6InputManager();
  ~C6D6InputManager(){}

  int Read(char* inpfilename);
  static C6D6InputManager* getInstance();

  void Print();

  //Geometry:
  string GetEARName(){return EARName;}
  string GetTargetName(){return TargetName;}
  G4double GetTotalNC6D6Detectors(){return TotalNC6D6Det;}
  void GetC6D6Parameters(G4int *theDetectorType,G4double *thez,G4double *thetaRot,G4double *phiRot){
    for (G4int i=1; i<(TotalNC6D6Det+1);i++){
      theDetectorType[i] = flagC6D6[i];
      thez[i] = zC6D6[i];
      thetaRot[i] = thetaC6D6[i];
      phiRot[i] = phiC6D6[i];
    }
  }
  G4bool IsB6D6Defined(){return IsC6D6TypeDefined[1];}
  G4bool IsL6D6Defined(){return IsC6D6TypeDefined[2];}
  G4bool IsS6D6Defined(){return IsC6D6TypeDefined[3];}
  G4bool IsESTIDefined(){return IsC6D6TypeDefined[4];}
  G4bool IsECLABR3Defined(){return IsC6D6TypeDefined[5];}
  G4int GetConcreteType(){return ConcreteType;}
  std::vector<G4double> GetConcreteValues(){return ConcreteVals;}
  G4double GetEAR1ScaleFactor(){return EAR1ScaleFactor;}

  //Source:
  G4int GetSourceType(){return SourceType;}
  void GetSourcePos(G4double& xpos,G4double& ypos,G4double& zpos,G4double& zlength,G4double& z_xs,G4double& radius,G4double& ang,G4String& BIFfname){xpos=sourcepos_x; ypos=sourcepos_y; zpos=sourcepos_z; zlength=sourcepos_zlength; z_xs=sourcepos_xs; radius=sourcepos_rad; ang=source_angle; BIFfname=BIFFname;}
  void GetSourceEne(G4double& sEmin,G4double& sEmax,G4double& sEsample){sEmin=source_Emin; sEmax=source_Emax; sEsample=source_Esample;}
  G4String GetSourcePar(){return source_par;}
  G4int GetSourceFnames(G4String* sFnames){
    for(G4int i=0;i<NSourceFnames;i++){sFnames[i]=SourceFname[i];}
    return NSourceFnames;
  }

  //Physics:
  G4String GetPhysicsListName(){return PhysicsListName;}
  G4int GetPhysicsListOpt1(){return PhysicsListOpt1;}
  G4int GetPhysicsListOpt2(){return PhysicsListOpt2;}
  G4int GetPhysicsListOpt3(){return PhysicsListOpt3;}
  G4LogicalVolume* Getlogic_target(){return logic_target;}
  void Setlogic_target(G4LogicalVolume* aLogVol){logic_target=aLogVol;}
  G4int GetPrintNeutronHistory(){return PrintNeutronHistory;}
  G4int GetTrackNeutronHistory(){return TrackNeutronHistory;}

  //Other:
  G4int GetNEventsToRun(){return NEvents;}
  G4int GetNDump(){return NDump;}
  G4double GetCutForGamma(){return CutForGamma;}
  G4double GetCutForProton(){return CutForProton;} 
  G4int GetSeed(){return Seed;}
  
  G4String GetInputFname(){return OutFname;}
  G4String GetOutFname(){return OutFname;}
  G4int GetOutputInfo(G4int i_val){return OutputInfo[i_val];}
  void GetEnergyResolutionPars(G4int DetN,G4double &a1,G4double &a2){
    a1=Eres_a1[DetN]; a2=Eres_a2[DetN];
  }
  G4bool IsInteractive(){return Interactive;}
  
 private:
  static C6D6InputManager* theInstance;

  //Geometry:
  string EARName,TargetName;
  G4int TotalNC6D6Det;
  G4int flagC6D6[MAXNDET];
  G4bool IsC6D6TypeDefined[100];
  G4double zC6D6[MAXNDET],thetaC6D6[MAXNDET],phiC6D6[MAXNDET];
  G4int ConcreteType=1;
  std::vector<G4double> ConcreteVals;
  G4double EAR1ScaleFactor=1;
  
  //Source:
  G4int SourceType;
  G4double sourcepos_x,sourcepos_y,sourcepos_z;
  G4double sourcepos_zlength,sourcepos_xs;
  G4double sourcepos_rad;
  G4double source_angle; //apertura
  G4String BIFFname;
  G4double source_Emin,source_Emax,source_Esample;
  G4String source_par;
  G4int NSourceFnames;
  G4String SourceFname[100];

  //Physics:
  G4String PhysicsListName="QGSP_BIC_HP";
  G4int PhysicsListOpt1=0;
  G4int PhysicsListOpt2=0;
  G4int PhysicsListOpt3=0;
  G4LogicalVolume *logic_target=0;
  G4int PrintNeutronHistory=0;
  G4int TrackNeutronHistory=0;

  //Other:
  G4int NEvents,NDump;
  G4double CutForGamma,CutForProton; //production thresholds
  G4int Seed;
  G4String InputFname;
  G4String OutFname;
  G4int OutputInfo[10]={0,0,0,0,0,0,0,0,0,0}; //Write: H1-Edep, H2-TOF-Edep, Tree, ...
  G4double Eres_a1[MAXNDET],Eres_a2[MAXNDET];
  G4bool Interactive;
  
};

#endif

