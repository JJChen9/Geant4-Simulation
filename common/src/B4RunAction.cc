#include "../include/B4RunAction.hh"
#include "../include/B4Analysis.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include <fstream>
#include <iostream>
#include "g4root.hh"

using std::ofstream;
using std::ifstream;


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4RunAction::B4RunAction(FILE *fout)
 : G4UserRunAction(),file(fout)
{ 
  // set printing event number per each event
  G4RunManager::GetRunManager()->SetPrintProgress(0);     

  // Create analysis manager
  // The choice of analysis technology is done via selectin of a namespace
  // in B4Analysis.hh
  auto analysisManager = G4AnalysisManager::Instance();
  G4cout << "Using " << analysisManager->GetType() << G4endl;

  // Create directories 
  //analysisManager->SetHistoDirectoryName("histograms");
  //analysisManager->SetNtupleDirectoryName("ntuple");
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetNtupleMerging(true);
  
  // Creating histograms
  analysisManager->CreateH1("Edep_LaBr_All","Edep in LaBr, All", 800000, 0, 80*MeV);
  analysisManager->CreateH1("Edep_HPGe_All","Edep in HPGe, All", 800000, 0, 80*MeV);

  analysisManager->CreateH1("Edep_LaBr_BigHole","Edep in LaBr, Big Hole", 800000, 0, 80*MeV);
  analysisManager->CreateH1("Edep_HPGe_BigHole","Edep in HPGe, Big Hole", 800000, 0, 80*MeV);
  analysisManager->CreateH1("Edep_LaBr_SmallHole","Edep in LaBr, Small Hole", 800000, 0, 80*MeV);
  analysisManager->CreateH1("Edep_HPGe_SmallHole","Edep in HPGe, Small Hole", 800000, 0, 80*MeV);

  analysisManager->CreateH1("Edep_LaBr_SSC_Left","Edep in LaBr,Left SSC Leak", 800000, 0, 80*MeV);
  analysisManager->CreateH1("Edep_HPGe_SSC_Left","Edep in HPGe,Left SSC Leak", 800000, 0, 80*MeV);
  analysisManager->CreateH1("Edep_LaBr_SSC_Right","Edep in LaBr,Right SSC Leak", 800000, 0, 80*MeV);
  analysisManager->CreateH1("Edep_HPGe_SSC_Right","Edep in HPGe,Right SSC Leak", 800000, 0, 80*MeV);
  analysisManager->CreateH1("Edep_LaBr_SSC_Top","Edep in LaBr,Top SSC Leak", 800000, 0, 80*MeV);
  analysisManager->CreateH1("Edep_HPGe_SSC_Top","Edep in HPGe,Top SSC Leak", 800000, 0, 80*MeV);
  analysisManager->CreateH1("Edep_LaBr_SSC_Bottom","Edep in LaBr,Bottom SSC Leak", 800000, 0, 80*MeV);
  analysisManager->CreateH1("Edep_HPGe_SSC_Bottom","Edep in HPGe,Bottom SSC Leak", 800000, 0, 80*MeV);

  analysisManager->CreateH1("Edep_LaBr_Shield","Edep in LaBr, Shield", 800000, 0, 80*MeV);
  analysisManager->CreateH1("Edep_HPGe_Shield","Edep in HPGe, Shield", 800000, 0, 80*MeV);

  analysisManager->CreateH1("flag","flag", 7, -0.5, 6.5);

  analysisManager->CreateH1("E_VD115","Energy at VD115", 7500, 0., 75*MeV);
  analysisManager->CreateH1("E_VD101","Energy at VD101", 7500, 0., 75*MeV);


}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4RunAction::~B4RunAction()
{
  delete G4AnalysisManager::Instance();  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4RunAction::BeginOfRunAction(const G4Run* /*run*/)
{ 
  //inform the runManager to save random number seed
  //G4RunManager::GetRunManager()->SetRandomNumberStore(true);
  
  // Get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();
  G4cout<<"Come Here, Begining of RunAction"<<G4endl;

//fprintf(file,"Begining of Run\n");

  // Open an output file
  //
//  G4String fileName = "B4";
  analysisManager->OpenFile();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4RunAction::EndOfRunAction(const G4Run* /*run*/)
{

  // print histogram statistics
  //
  auto analysisManager = G4AnalysisManager::Instance();


  G4cout<<"Come Here, Ending of RunAction"<<G4endl;

  // save histograms & ntuple
  //
  analysisManager->Write();
  analysisManager->CloseFile();
//  fprintf(file,"Ending of Run\n");
  fclose(file);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
