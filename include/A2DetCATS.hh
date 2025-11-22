#ifndef A2DetCATS_h
#define A2DetCATS_h 1

#include "A2Detector.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4VisAttributes.hh"
#include "G4PVPlacement.hh"
#include "G4Box.hh"
#include "A2SD.hh"
#include "A2VisSD.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4Region;
class A2SD;
class A2VisSD;

class A2DetCATS : public A2Detector 
{
	protected:
		G4bool fIsCheckOverlap;     // flag for volume overlap check

	public: 
		A2DetCATS();
		~A2DetCATS();

		virtual G4VPhysicalVolume* Construct( G4LogicalVolume* motherLogic); 

		void MakeCore();
		void MakeAnnulus();
		void MakeScintillators();
		void MakeVeto();

		void MakeSensitiveDetectors();

		void MakeRing();
		void MakeLeadShield();

	private:
		G4NistManager* fNistManager;

		// Logical and physical volumes that are part of every detector class
		G4LogicalVolume* fMotherLogic; 
		G4LogicalVolume* fMyLogic; 
		G4VPhysicalVolume* fMyPhysi; 

		// CATS Volumes
		G4LogicalVolume* fCoreLogic;
		G4VPhysicalVolume* fCorePhysi;

		G4LogicalVolume* fAnnulusLogic;
		G4VPhysicalVolume* fAnnulusPhysi;

		G4LogicalVolume* fScintLogic;
		G4VPhysicalVolume* fScintPhysi;

		G4LogicalVolume* fVetoLogic;
		G4VPhysicalVolume* fVetoPhysi;

		G4LogicalVolume* fRingLogic;
		G4VPhysicalVolume* fRingPhysi;

		G4LogicalVolume* fLeadConeLogic;
		G4VPhysicalVolume* fLeadConePhysi;	

		G4LogicalVolume* fLeadBoxLogic;
		G4VPhysicalVolume* fLeadBoxPhysi;

		A2VisSD* fCATSCoreVisSD;
		A2VisSD* fCATSAnnVisSD;
		A2VisSD* fCATSShieldVisSD;
		A2VisSD* fCATSVetoVisSD;
		A2SD* fCATSCoreSD;
		A2SD* fCATSAnnSD;
		A2SD* fCATSShieldSD;
		A2SD* fCATSVetoSD;
	
		G4Region* fregionCATS;
};

#endif
