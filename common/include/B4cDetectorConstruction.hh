#ifndef B4cDetectorConstruction_h
#define B4cDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4GlobalMagFieldMessenger;
class G4Material;


class B4cDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    B4cDetectorConstruction();
    virtual ~B4cDetectorConstruction();

  public:
    virtual G4VPhysicalVolume* Construct();
    virtual void ConstructSDandField();

    G4VPhysicalVolume*   fLaBrPV;
    G4VPhysicalVolume*   fHPGePV;

    G4VPhysicalVolume*   AirWallXPV;
    G4VPhysicalVolume*   AirWallZPV;

    G4VPhysicalVolume*   HolePV;

    G4VPhysicalVolume*   LeadBackBlockPV;
    G4VPhysicalVolume*   CopperBackBlockPV;
    G4VPhysicalVolume*   AluminumBackBlockPV;

   
    G4VPhysicalVolume*   LeadInnerSPVR;
    G4VPhysicalVolume*   LeadInnerSPVL;
    G4VPhysicalVolume*   LeadInnerSPVTrap;
    G4VPhysicalVolume*   LeadInnerSPVF;
    G4VPhysicalVolume*   LeadInnerSPVB;

    G4VPhysicalVolume*   LeadInnerFPV1;
    G4VPhysicalVolume*   LeadInnerFPV2;
    G4VPhysicalVolume*   LeadInnerexPV;
    G4VPhysicalVolume*   LeadInnerS_extPV;
    G4VPhysicalVolume*   LeadInnerF_extPV;

    
    
    G4VPhysicalVolume*   CopperInnerSPVL;
    G4VPhysicalVolume*   CopperInnerSPVR;
    G4VPhysicalVolume*   CopperInnerSPVF;
    G4VPhysicalVolume*   CopperInnerSPVB;
    
    
    G4VPhysicalVolume*   CopperInnerSPV1;
    G4VPhysicalVolume*   CopperInnerSPV2;
    G4VPhysicalVolume*   CopperInnerSPV3;
    G4VPhysicalVolume*   CopperInnerFPV1;
    G4VPhysicalVolume*   CopperInnerFPV2;
    G4VPhysicalVolume*   CopperInnerFPV3;
    G4VPhysicalVolume*   CopperInnerFPV4;    
    
    
    G4VPhysicalVolume*   CopperInnerexPV1;
    G4VPhysicalVolume*   CopperInnerexPV2;
    G4VPhysicalVolume*   CopperInnerS_extPV;
    G4VPhysicalVolume*   CopperInnerF_extPV;

    G4VPhysicalVolume*   AluminumInnerSPV1;
    G4VPhysicalVolume*   AluminumInnerSPV2;
    G4VPhysicalVolume*   AluminumInnerSPV3;
    G4VPhysicalVolume*   AluminumInnerFPV1;
    G4VPhysicalVolume*   AluminumInnerFPV2;
    G4VPhysicalVolume*   AluminumInnerexPV1;
    G4VPhysicalVolume*   AluminumInnerexPV2;
    G4VPhysicalVolume*   AluminumInnerS_extPV;
    G4VPhysicalVolume*   AluminumInnerF_extPV;

    G4VPhysicalVolume*   AluminumTwallPV1;
    G4VPhysicalVolume*   AluminumTwallPV2;
    G4VPhysicalVolume*   CopperTwallPV;
    G4VPhysicalVolume*   LeadTwallPV1;
    G4VPhysicalVolume*   LeadTwallPV2;
    G4VPhysicalVolume*   BPTwallPV1;
    G4VPhysicalVolume*   BPTwallPV2;
    G4VPhysicalVolume*   CopperskirtLPV;
    G4VPhysicalVolume*   CopperskirtRPV;
    G4VPhysicalVolume*   CopperskirtR2PV;
    
    G4VPhysicalVolume*   LeadskirtLPV;
    G4VPhysicalVolume*   LeadskirtRPV;
    G4VPhysicalVolume*   LeadskirtR2PV;
    
    
    G4VPhysicalVolume*   TopGap_LBlockPV;
    G4VPhysicalVolume*   TopGap_RBlockPV;
    

    G4VPhysicalVolume*   AluminumBwallPV;
    G4VPhysicalVolume*   CopperBwallPV;
    G4VPhysicalVolume*   LeadBwallPV1;
    G4VPhysicalVolume*   LeadBwallPV2;
   
    
    G4VPhysicalVolume*   BPBwallPV1;
    G4VPhysicalVolume*   BPBwallPV2;

    G4VPhysicalVolume*   AluminumFwallPV;
    G4VPhysicalVolume*   CopperFwallPV;
    G4VPhysicalVolume*   Lead1FwallPV;
    G4VPhysicalVolume*   Lead2FwallPV;
    G4VPhysicalVolume*   Lead3FwallPV;
    
    
    G4VPhysicalVolume*   BPFwallPV0;
    G4VPhysicalVolume*   BPFwallPV1;
    G4VPhysicalVolume*   BPFwallPV2;
    
    
    
    G4VPhysicalVolume*   TungstenSSCPV;
    G4VPhysicalVolume*   FrontLeadBlockPV1;
    G4VPhysicalVolume*   FrontLeadBlockPV2;
    G4VPhysicalVolume*   FrontLeadBlockPV3;

    G4VPhysicalVolume*   AluminumRwallPV;
    G4VPhysicalVolume*   CopperRwallPV;
    G4VPhysicalVolume*   LeadRwallPV1;
    G4VPhysicalVolume*   LeadRwallPV2;
    G4VPhysicalVolume*   BPRwallPV1;
    G4VPhysicalVolume*   BPRwallPV2;

    G4VPhysicalVolume*   AluminumLwallPV;
    G4VPhysicalVolume*   CopperLwallPV;
    G4VPhysicalVolume*   LeadLwallPV1;
    G4VPhysicalVolume*   LeadLwallPV2;
    G4VPhysicalVolume*   BPLwallPV1;
    G4VPhysicalVolume*   BPLwallPV2;

    G4VPhysicalVolume*   ConcreteWallPV;

    G4VPhysicalVolume*   AirHole_LaBrPV;
    G4VPhysicalVolume*   AirHole_HPGePV;
    G4VPhysicalVolume*   SSCLeakPV_l;
    G4VPhysicalVolume*   SSCLeakPV_r;
    G4VPhysicalVolume*   SSCLeakPV_t;
    G4VPhysicalVolume*   SSCLeakPV_b;
    G4VPhysicalVolume*   SSCLeakPV_back;
    
    
    
    
    G4VPhysicalVolume*   CopperFrontEdgePV1;
    G4VPhysicalVolume*   AluminumFrontEdgePV1;
    G4VPhysicalVolume*   CopperFrontEdgePV2;
    G4VPhysicalVolume*   AluminumFrontEdgePV2;
    G4VPhysicalVolume*   CopperFrontEdgePV3;
    G4VPhysicalVolume*   AluminumFrontEdgePV3;

    G4VPhysicalVolume*  SupportPV;
    
    
    
    G4VPhysicalVolume*   BPBackPV;


    G4VPhysicalVolume*   RoofLeakPV;
    G4VPhysicalVolume*   AirTwallPV;
    G4VPhysicalVolume*   AbsorberPV;   
    G4VPhysicalVolume*   VD101PV;

  private:

    void DefineMaterials();
    G4VPhysicalVolume* DefineVolumes();
  
    static G4ThreadLocal G4GlobalMagFieldMessenger*  fMagFieldMessenger; 
                                      // magnetic field messenger

    G4bool  fCheckOverlaps; // option to activate checking of volumes overlaps
    G4int   fNofLayers;     // number of layers

};


#endif

