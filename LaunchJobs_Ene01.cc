
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

#include "TRandom2.h"

using namespace std;

/*

Lanza NBINS inputs, haciendo un binning entre ENEMIN y ENEMAX
Bines logarítmicos
 */

int main(int argc,char** argv){

  if(argc!=5 && argc!=6){
    cout<<" ###### input has to be like LaunchJobs_Ene01 InputFname NBINS ENEMIN ENEMAX [xula] ######"<<endl;
    return 1;
  }
  string scommand;

  char* InputFname=argv[1];

  string parname1="PAR01";
  string parname2="PAR02";
  int nbins=atoi(argv[2]);
  double Emin=atof(argv[3]);
  double Emax=atof(argv[4]);
  char partext[10000];

  string xulaqueue="xula2";
  if(argc>5){
    xulaqueue=argv[5];
  }
  
  scommand=string("launcher01  --partition ")+xulaqueue+string(" -n 5 ejecutar01.exe");
  for(int i=0;i<nbins;i++){
    double par01=Emin*pow(Emax/Emin,i/(double)(nbins));
    double par02=Emin*pow(Emax/Emin,(i+1)/(double)(nbins));
    sprintf(partext,"  %s %s %.2e %s %.2e",InputFname,parname1.c_str(),par01,parname2.c_str(),par02);
    scommand+=string(partext);
    cout<<partext<<endl;
  }
  cout<<" Command is: "<<scommand<<endl;
  
  int check=system(scommand.c_str());
  if(check!=0){
    cout<<" ########## Error executing command: "<<scommand<<" ##########"<<endl;
    exit(1);
  }
  
  return 0;
}


