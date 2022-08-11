#include "../include/SteppingAction.hh"
#include "G4RunManager.hh"
#include "../include/B4Analysis.hh"
#include "../include/B4cDetectorConstruction.hh"

#include "../include/B4cEventAction.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using std::ofstream;
using std::ifstream;
using std::ios;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(const B4cDetectorConstruction* detectorConstruction,B4cEventAction* eventAction,FILE *fout)
:G4UserSteppingAction(),
 file(fout),
 fDetConstruction(detectorConstruction),
 fEventAction(eventAction)
 {  }
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* aStep)
{

  const G4StepPoint*  endPointPost = aStep->GetPostStepPoint();
  const G4StepPoint*  endPointPre  = aStep->GetPreStepPoint();

  G4int Steppingoption;
  
   auto volume0 = aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
   auto volume1 = aStep->GetPostStepPoint()->GetTouchableHandle()->GetVolume(); 
  
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

  G4double energy0 = endPointPre->GetKineticEnergy();
  G4ThreeVector direction = endPointPost->GetMomentumDirection();
  G4double costeta = direction.x();


   if(fEventAction->stop==0)
  {
    if(volume1==fDetConstruction->AirHole_LaBrPV) {fEventAction->flag=1; fEventAction->stop =1;}
    else if(volume1==fDetConstruction->AirHole_HPGePV) {fEventAction->flag=2; fEventAction->stop =1;}
    else if(volume1==fDetConstruction->SSCLeakPV_l) {fEventAction->flag=3; fEventAction->stop =1;}
    else if(volume1==fDetConstruction->SSCLeakPV_r) {fEventAction->flag=4; fEventAction->stop =1;}
    else if(volume1==fDetConstruction->SSCLeakPV_t) {fEventAction->flag=5; fEventAction->stop =1;}
    else if(volume1==fDetConstruction->SSCLeakPV_b) {fEventAction->flag=6; fEventAction->stop =1;}
  }


    if(fEventAction->flag_abs == 0 && volume1==fDetConstruction->AbsorberPV)
   {
     analysisManager->FillH1(17, energy0);
     fEventAction->flag_abs=1;
   }

    if(fEventAction->flag_VD == 0 && volume1==fDetConstruction->VD101PV)
   {
     analysisManager->FillH1(18, energy0);
     fEventAction->flag_VD=1;
   }




//  if(energy < 0.001*MeV)
//  G4RunManager::GetRunManager()->AbortEvent();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


