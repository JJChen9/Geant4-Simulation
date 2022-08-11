#include "../include/B4cEventAction.hh"
#include "../include/B4cCalorimeterSD.hh"
#include "../include/B4cCalorHit.hh"
#include "../include/B4Analysis.hh"

#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4UnitsTable.hh"

#include "Randomize.hh"
#include <iomanip>


B4cEventAction::B4cEventAction(FILE *fout)
 : G4UserEventAction(),
   EventID(0),
   flag_abs(0),
   flag(0),
   stop(0),
   flag_VD(0),
   file(fout),
   fLaBrHCID(-1),
   fHPGeHCID(-1)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4cEventAction::~B4cEventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4cCalorHitsCollection* 
B4cEventAction::GetHitsCollection(G4int hcID,
                                  const G4Event* event) const
{
  auto hitsCollection 
    = static_cast<B4cCalorHitsCollection*>(
        event->GetHCofThisEvent()->GetHC(hcID));
  
  if ( ! hitsCollection ) {
    G4ExceptionDescription msg;
    msg << "Cannot access hitsCollection ID " << hcID; 
    G4Exception("B4cEventAction::GetHitsCollection()",
      "MyCode0003", FatalException, msg);
  }         

  return hitsCollection;
}    

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


void B4cEventAction::BeginOfEventAction(const G4Event* /*event*/)
{ 
  flag=0;
  stop=0;
  flag_abs=0;
  flag_VD=0;
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4cEventAction::EndOfEventAction(const G4Event* event)
{ 


  // Get hits collections IDs (only once)
  if ( fLaBrHCID == -1 ) {
    fLaBrHCID 
      = G4SDManager::GetSDMpointer()->GetCollectionID("LaBrHitsCollection");
    fHPGeHCID 
      = G4SDManager::GetSDMpointer()->GetCollectionID("HPGeHitsCollection");
  }


  // Get hits collections
  auto LaBrHC = GetHitsCollection(fLaBrHCID, event);
  auto HPGeHC  = GetHitsCollection(fHPGeHCID, event);


  // Get hit with total values
  auto LaBrHit = (*LaBrHC)[LaBrHC->entries()-1];
  auto HPGeHit = (*HPGeHC)[HPGeHC->entries()-1];

 
  //
  auto eventID = event->GetEventID();

  // get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();
 

  G4double energy_LaBr = LaBrHit->GetEdep();
  G4double energy_HPGe = HPGeHit->GetEdep();


   if(energy_LaBr != 0)
  {
    analysisManager->FillH1(0, energy_LaBr);
    if(flag == 1)  analysisManager->FillH1(2, energy_LaBr);
    if(flag == 2)  analysisManager->FillH1(4, energy_LaBr);
    if(flag == 3)  analysisManager->FillH1(6, energy_LaBr);
    if(flag == 4)  analysisManager->FillH1(8, energy_LaBr);
    if(flag == 5)  analysisManager->FillH1(10, energy_LaBr);
    if(flag == 6)  analysisManager->FillH1(12, energy_LaBr);
    if(flag == 0)  analysisManager->FillH1(14, energy_LaBr);
    analysisManager->FillH1(16, flag);
  }


   if(energy_HPGe != 0)
  {
    analysisManager->FillH1(1, energy_HPGe);
    if(flag == 1)  analysisManager->FillH1(3, energy_HPGe);
    if(flag == 2)  analysisManager->FillH1(5, energy_HPGe);
    if(flag == 3)  analysisManager->FillH1(7, energy_HPGe);
    if(flag == 4)  analysisManager->FillH1(9, energy_HPGe);
    if(flag == 5)  analysisManager->FillH1(11, energy_HPGe);
    if(flag == 6)  analysisManager->FillH1(13, energy_HPGe);
    if(flag == 0)  analysisManager->FillH1(15, energy_HPGe);
    analysisManager->FillH1(16, flag);
  }



//fprintf(file,"\n"); 
//analysisManager->AddNtupleRow();  
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
