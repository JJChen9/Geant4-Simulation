
#ifndef B4PrimaryGeneratorAction_h
#define B4PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"
#include "G4GeneralParticleSource.hh"
#include "AnalysisManager.hh"
#include "G4ParticleGun.hh"

class G4Event;

class B4PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
  B4PrimaryGeneratorAction(AnalysisManager*);    
  virtual ~B4PrimaryGeneratorAction();

  virtual void GeneratePrimaries(G4Event* event);
  
  // set methods
  void SetRandomFlag(G4bool value);

private:
  G4GeneralParticleSource* gun;
  AnalysisManager* analysis;


};

#endif
