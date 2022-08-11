#ifndef B4cEventAction_h
#define B4cEventAction_h 1

#include "G4UserEventAction.hh"

#include "B4cCalorHit.hh"

#include "globals.hh"
#include <fstream>
#include <iostream>
#include <stdio.h>
using std::ofstream;
using std::ifstream;
using std::ios;


class B4cEventAction : public G4UserEventAction
{
public:
  B4cEventAction(FILE *);
  virtual ~B4cEventAction();

  virtual void  BeginOfEventAction(const G4Event* event);
  virtual void    EndOfEventAction(const G4Event* event);

  G4int         EventID;  
  G4int         flag;
  G4int         stop;


  G4int         flag_abs;
  G4int         flag_VD;


  FILE          *file;


private:
  // methods
  B4cCalorHitsCollection* GetHitsCollection(G4int hcID,
                                            const G4Event* event) const;
  
  // data members                   
  G4int  fLaBrHCID;
  G4int  fHPGeHCID;
};
 
#endif   
