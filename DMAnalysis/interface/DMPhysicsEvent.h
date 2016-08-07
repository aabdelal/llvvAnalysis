//
//  DMPhysicsEvent.h
//
//
//  Created by RENJIE WANG on 2/17/15.
//
//

#ifndef ____DMPhysicsEvent__
#define ____DMPhysicsEvent__

#include <stdio.h>
#include <vector>
#include "TH2F.h"

#include "llvvAnalysis/DMAnalysis/interface/DataEvtSummaryHandler.h"
#include "DataFormats/Math/interface/deltaR.h"

enum PhysicsObjects   { MET=0,JET=1,TOP=6,ELECTRON=11, MUON=13, TAU=15, GLUON=21, PHOTON=22, Z=23, W=24};
enum DileptonChannels { UNKNOWN=0,MUMU=1,EE=2,EMU=3,ETAU=4,MUTAU=5, GAMMA=22};



class PhysicsObject : public LorentzVector {
public :
    PhysicsObject(LorentzVector vec, Int_t id_):
        LorentzVector(vec), id(id_) { }
    Int_t id;
};




//
class PhysicsObject_Lepton : public LorentzVector {
public :
    PhysicsObject_Lepton(LorentzVector vec, Int_t id_):
        LorentzVector(vec), id(id_) { }
    void setLeptonIDInfo(bool isLooseMu_, bool isTightMu_, bool isMediumMu_, bool isSoftMu_, bool isHighPtMu_,
                         bool isElpassVeto_, bool isElpassLoose_, bool isElpassMedium_, bool isElpassTight_, bool isElpassMedium_noIso_,
			 bool isTauDM_) {
        isLooseMu = isLooseMu_;
        isTightMu = isTightMu_;
	isMediumMu = isMediumMu_;
        isSoftMu = isSoftMu_;
        isHighPtMu = isHighPtMu_;

        isElpassVeto = isElpassVeto_;
        isElpassLoose = isElpassLoose_;
        isElpassMedium = isElpassMedium_;
        isElpassTight = isElpassTight_;

        isElpassMedium_noIso = isElpassMedium_noIso_,
	isTauDM = isTauDM_;
    }

    void setLeptonIsoInfo(float mn_pileupIso_, float mn_chargedIso_, float mn_photonIso_, float mn_neutralHadIso_,
                          float en_pileupIso_, float en_chargedIso_, float en_photonIso_, float en_neutralHadIso_, float en_relIsoWithEA_,
                          bool ta_IsLooseIso_, bool ta_IsMediumIso_, bool ta_IsTightIso_, float ta_combIsoDBeta3Hits_ ) {

        mn_pileupIso = mn_pileupIso_;
        mn_chargedIso = mn_chargedIso_;
        mn_photonIso = mn_photonIso_;
        mn_neutralHadIso = mn_neutralHadIso_;

        en_pileupIso = en_pileupIso_;
        en_chargedIso = en_chargedIso_;
        en_photonIso = en_photonIso_;
        en_neutralHadIso = en_neutralHadIso_;
        en_relIsoWithEA = en_relIsoWithEA_;

        ta_IsLooseIso = ta_IsLooseIso_;
        ta_IsMediumIso = ta_IsMediumIso_;
        ta_IsTightIso = ta_IsTightIso_;
        ta_combIsoDBeta3Hits = ta_combIsoDBeta3Hits_;
    }
    void setLeptonIPInfo(float mn_d0_, float mn_dZ_, float mn_ip3d_) {
        mn_d0 = mn_d0_;
        mn_dZ = mn_dZ_;
        mn_ip3d = mn_ip3d_;
    }
    
    void setLeptonTrackInfo(Int_t mn_tkLayers_) {
		mn_tkLayers = mn_tkLayers_;
		}
	void setSCInfo(float en_EtaSC_, float en_R9_) {
		en_EtaSC = en_EtaSC_;
		en_R9 = en_R9_;
		}
		 
    float e_pfRelIsoDbeta() {
        return (en_chargedIso + TMath::Max(0., en_neutralHadIso + en_photonIso - 0.5 * en_pileupIso) )/pt();
    }

    float e_relIsoWithEA() {
	return en_relIsoWithEA;
    }

    float m_pfRelIsoDbeta() {
        return (mn_chargedIso + TMath::Max(0., mn_neutralHadIso + mn_photonIso - 0.5 * mn_pileupIso) )/pt();
    }

    Int_t id, mn_tkLayers;
    bool isLooseMu, isTightMu, isMediumMu, isSoftMu, isHighPtMu;
    bool isElpassVeto, isElpassLoose, isElpassMedium, isElpassTight, isElpassMedium_noIso;
    bool isTauDM;
    float mn_pileupIso, mn_chargedIso, mn_photonIso, mn_neutralHadIso;
    float en_pileupIso, en_chargedIso, en_photonIso, en_neutralHadIso;
    float en_EtaSC, en_R9; 
    float en_relIsoWithEA;
    float mn_dZ, mn_d0, mn_ip3d;
    bool ta_IsLooseIso, ta_IsMediumIso, ta_IsTightIso;
    float ta_combIsoDBeta3Hits;
};



//
class PhysicsObject_Jet : public LorentzVector {
public :
    PhysicsObject_Jet(LorentzVector vec, Float_t pumva_, Bool_t isPFLoose_, Bool_t isPFTight_):
        LorentzVector(vec), pumva(pumva_), isPFLoose(isPFLoose_), isPFTight(isPFTight_) { }

    void setBtagInfo(Float_t btag0_=0, Float_t btag1_=0, Float_t btag2_=0, Float_t btag3_=0, Float_t btag4_=0, Float_t btag5_=0, Float_t btag6_=0, Float_t btag7_=0) {
        btag0=btag0_;
        btag1=btag1_;
        btag2=btag2_;
        btag3=btag3_;
        btag4=btag4_;
        btag5=btag5_;
        btag6=btag6_;
        btag7=btag7_;
    }

    void setGenInfo(Int_t flavid_, Float_t genPt_)
    {
	flavid=flavid_;
	genPt=genPt_;
    }

    Float_t btag0, btag1, btag2, btag3, btag4, btag5, btag6, btag7;
    Float_t pumva;
    Bool_t isPFLoose,isPFTight;
    Int_t flavid;
    Float_t genPt;

};


typedef std::vector<PhysicsObject>        PhysicsObjectCollection;
typedef std::vector<PhysicsObject_Lepton> PhysicsObjectLeptonCollection;
typedef std::vector<PhysicsObject_Jet>    PhysicsObjectJetCollection;

//
struct PhysicsEvent_t {
    int run,event,lumi;
    int nvtx;

    PhysicsObjectLeptonCollection leptons;
    PhysicsObjectJetCollection jets;
    LorentzVector met, metNoHF, trkMET, caloMET;

    PhysicsObjectCollection genneutrinos,genleptons,genWIMPs,genGravitons;
    PhysicsObjectCollection genjets;
};



//
PhysicsEvent_t getPhysicsEventFrom(DataEvtSummary_t &ev);
int getDileptonId(int id1, int id2);

bool isDYToLL(int id1, int id2);
bool isDYToTauTau(int id1, int id2);
float getSFfrom2DHist(double xval, double yval, TH2F* h_);
float getSFfrom1DHist(double xval, TH1F* h_);

float getNLOEWKZZWeight(double trailing_pt);
float kfactor_qqZZ_qcd_dPhi(float GENdPhiZZ);



#endif /* defined(____DMPhysicsEvent__) */
