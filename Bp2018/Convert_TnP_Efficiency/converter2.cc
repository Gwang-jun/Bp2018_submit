#include <iostream>
#include "parameters.h"
#include "branchStruct.h"
#include "tnp_weight_lowptPbPb.h"
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <TTree.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLorentzVector.h>
#include <TGraphAsymmErrors.h>

using namespace std;

bool ispp = 0;
TString inputmc;

int _nBins = nBins;
double *_ptBins = ptBins;

void converter2(){
  string label = "";
  if(ispp){
    label = "pp"; 
    inputmc = "/afs/cern.ch/work/g/gwkim/private/samples/Bntuple20160816_Bpt7svpv5p5Bpt10svpv3p5_BfinderMC_pp_Pythia8_BuToJpsiK_TuneCUEP8M1_20160816_bPt0jpsiPt0tkPt0p5_Bp_pthatweight_JingBDT.root";
  }
  else{
    label = "pbpb";
    inputmc = "/mnt/T2_US_MIT/submit-hi2/scratch/gwangjun/crab_Bfinder_20190624_Hydjet_Pythia8_Official_BuToJpsiK_1033p1_pt3tkpt0p7dls2_allpthat_pthatweight.root";
  }
  TFile* infMC = new TFile(inputmc.Data());
  TTree* ntKp = (TTree*)infMC->Get("Bfinder/ntKp");
  TTree* ntHlt = (TTree*)infMC->Get("hltanalysis/HltTree");
  TTree* ntSkim = (TTree*)infMC->Get("skimanalysis/HltTree");
  TTree* ntHi = (TTree*)infMC->Get("hiEvtAnalyzer/HiTree");
  TTree* ntGen = (TTree*)infMC->Get("Bfinder/ntGen");
  ntKp->AddFriend("hltanalysis/HltTree");
  ntKp->AddFriend("hiEvtAnalyzer/HiTree");
  ntKp->AddFriend("skimanalysis/HltTree");
  ntKp->AddFriend("Bfinder/ntGen");
  setAddressTree(ntKp, ntHlt, ntSkim, ntHi, ntGen, ispp);
  int nevents_total = ntKp->GetEntries();
  //int nevents_total = 50000;

  TFile *f= new TFile(Form("results_%s.root", label.c_str()), "recreate");
  TH1D* hGen = new TH1D("hGen","",_nBins,_ptBins);

  TH1D* hNominal = new TH1D("hNominal","",_nBins,_ptBins);
  TH1D* hScale = new TH1D("hScale","",_nBins,_ptBins);

  TH1D* hStatHiTrg = new TH1D("hStatHiTrg","",_nBins,_ptBins);
  TH1D* hStatHiTrk = new TH1D("hStatHiTrk","",_nBins,_ptBins);
  TH1D* hStatHiMuid = new TH1D("hStatHiMuid","",_nBins,_ptBins);
  TH1D* hStatLoTrg = new TH1D("hStatLoTrg","",_nBins,_ptBins);
  TH1D* hStatLoTrk = new TH1D("hStatLoTrk","",_nBins,_ptBins);
  TH1D* hStatLoMuid = new TH1D("hStatLoMuid","",_nBins,_ptBins);

  TH1D* hSysHiTrg  = new TH1D("hSysHiTrg","",_nBins,_ptBins);
  TH1D* hSysHiTrk  = new TH1D("hSysHiTrk","",_nBins,_ptBins);
  TH1D* hSysHiMuid = new TH1D("hSysHiMuid","",_nBins,_ptBins);
  TH1D* hSysLoTrg  = new TH1D("hSysLoTrg","",_nBins,_ptBins);
  TH1D* hSysLoTrk  = new TH1D("hSysLoTrk","",_nBins,_ptBins);
  TH1D* hSysLoMuid = new TH1D("hSysLoMuid","",_nBins,_ptBins);

  TH1D* hNominal2 = new TH1D("hNominal2","",_nBins,_ptBins);
  TH1D* hScale2 = new TH1D("hScale2","",_nBins,_ptBins);

  TH1D* hStatHiTrg2 = new TH1D("hStatHiTrg2","",_nBins,_ptBins);
  TH1D* hStatHiTrk2 = new TH1D("hStatHiTrk2","",_nBins,_ptBins);
  TH1D* hStatHiMuid2 = new TH1D("hStatHiMuid2","",_nBins,_ptBins);
  TH1D* hStatLoTrg2 = new TH1D("hStatLoTrg2","",_nBins,_ptBins);
  TH1D* hStatLoTrk2 = new TH1D("hStatLoTrk2","",_nBins,_ptBins);
  TH1D* hStatLoMuid2 = new TH1D("hStatLoMuid2","",_nBins,_ptBins);

  TH1D* hSysHiTrg2  = new TH1D("hSysHiTrg2","",_nBins,_ptBins);
  TH1D* hSysHiTrk2  = new TH1D("hSysHiTrk2","",_nBins,_ptBins);
  TH1D* hSysHiMuid2 = new TH1D("hSysHiMuid2","",_nBins,_ptBins);
  TH1D* hSysLoTrg2  = new TH1D("hSysLoTrg2","",_nBins,_ptBins);
  TH1D* hSysLoTrk2  = new TH1D("hSysLoTrk2","",_nBins,_ptBins);
  TH1D* hSysLoMuid2 = new TH1D("hSysLoMuid2","",_nBins,_ptBins);

  TH1D* hStatUnc = new TH1D("hStatUnc","",_nBins,_ptBins);
  TH1D* hSysUnc = new TH1D("hSysUnc","",_nBins,_ptBins);
  TH1D* hAllUnc = new TH1D("hAllUnc","",_nBins,_ptBins);
  TH1D* hSF = new TH1D("hSF","",_nBins,_ptBins);

  for(int entry=0; entry<nevents_total; entry++)
    {
      if ((entry%10000) == 0) printf("Loading event #%d out of %d.\n",entry,nevents_total);
      ntKp->GetEntry(entry);
      ntHlt->GetEntry(entry);
      ntSkim->GetEntry(entry);
      ntHi->GetEntry(entry);
      ntGen->GetEntry(entry);

      for(int b=0;b<Bsize;b++)
	{
      /*
	if(ispp){
	if(HLT_HIL1DoubleMu0ForPPRef_v1)
	if(abs(PVz)<15&&pBeamScrapingFilter&&pPAprimaryVertexFilter
	&&TMath::Abs(By[b])<2.4&&TMath::Abs(Bmumumass[b]-3.096916)<0.15&&Bmass[b]>5&&Bmass[b]<6
	&& ((abs(Bmu1eta[b])<1.2 && Bmu1pt[b]>3.5) || (abs(Bmu1eta[b])>1.2 && abs(Bmu1eta[b])<2.1 && Bmu1pt[b]>(5.77-1.8*abs(Bmu1eta[b]))) || (abs(Bmu1eta[b])>2.1 && abs(Bmu1eta[b])<2.4 && Bmu1pt[b]>1.8)) 
	&& ((abs(Bmu2eta[b])<1.2 && Bmu2pt[b]>3.5) || (abs(Bmu2eta[b])>1.2 && abs(Bmu2eta[b])<2.1 && Bmu2pt[b]>(5.77-1.8*abs(Bmu2eta[b]))) || (abs(Bmu2eta[b])>2.1 && abs(Bmu2eta[b])<2.4 && Bmu2pt[b]>1.8)) 
	&& Bmu1TMOneStationTight[b] && Bmu2TMOneStationTight[b] 
	&& Bmu1InPixelLayer[b] > 0 && (Bmu1InPixelLayer[b]+Bmu1InStripLayer[b]) > 5
	&& Bmu2InPixelLayer[b]> 0 && (Bmu2InPixelLayer[b]+Bmu2InStripLayer[b]) > 5 
	&& Bmu1dxyPV[b]< 0.3 && Bmu2dxyPV[b]< 0.3 && Bmu1dzPV[b]<20 && Bmu2dzPV[b]<20 
	&& Bmu1isGlobalMuon[b] && Bmu2isGlobalMuon[b] 
	&& Bmu1TrgMatchFilterE[b]>0 && Bmu2TrgMatchFilterE[b]>0 
	&& Btrk1highPurity[b] && abs(Btrk1Eta[b])<2.4 && Btrk1Pt[b]>0.5 && Bchi2cl[b]>0.005 
	&& ((Bpt[b]<10 && (BsvpvDistance[b]/BsvpvDisErr[b])>5.5) || (Bpt[b]>10 && (BsvpvDistance[b]/BsvpvDisErr[b])>3.5)) 
	&& ((Bpt[b]>7 && Bpt[b]<10 && Btrk1Pt[b]>0.748 && Bchi2cl[b]>0.0322 && (BsvpvDistance[b]/BsvpvDisErr[b])>0 && cos(Bdtheta[b])>0.989 && abs(Btrk1Eta[b])<2.4) 
	|| (Bpt[b]>10 && Bpt[b]<15 && Btrk1Pt[b]>0.878 && Bchi2cl[b]>0.0014 && (BsvpvDistance[b]/BsvpvDisErr[b])>0 && cos(Bdtheta[b])>0.971 && abs(Btrk1Eta[b])<2.39) 
	|| (Bpt[b]>15 && Bpt[b]<20 && Btrk1Pt[b]>0.818 && Bchi2cl[b]>0.00838 && (BsvpvDistance[b]/BsvpvDisErr[b])>0 && cos(Bdtheta[b])>0.959 && abs(Btrk1Eta[b])<2.42) 
	|| (Bpt[b]>20 && Bpt[b]<30 && Btrk1Pt[b]>0.84 && Bchi2cl[b]>0.014 && (BsvpvDistance[b]/BsvpvDisErr[b])>0 && cos(Bdtheta[b])>0.603 && abs(Btrk1Eta[b])<2.38) 
	|| (Bpt[b]>30 && Bpt[b]<50 && Btrk1Pt[b]>1.06 && Bchi2cl[b]>0.0155 && (BsvpvDistance[b]/BsvpvDisErr[b])>3.53 && cos(Bdtheta[b])>0.995 && abs(Btrk1Eta[b])<2.37))
	)
	if(Bgen[b]==23333){
	double _weight = pthatweight*((pow(10,-0.094152+0.008102*Bgenpt[b]+Bgenpt[b]*Bgenpt[b]*0.000171+Bgenpt[b]*Bgenpt[b]*Bgenpt[b]*-0.000005+Bgenpt[b]*Bgenpt[b]*Bgenpt[b]*Bgenpt[b]*-0.000000+Bgenpt[b]*Bgenpt[b]*Bgenpt[b]*Bgenpt[b]*Bgenpt[b]*0.000000)));
	hNominal->Fill(Bpt[b], _weight);

	//passed and fill
	double scale = tnp_weight_trg_pp(Bmu1pt[b], Bmu1eta[b], 0)*tnp_weight_trk_pp(0)*tnp_weight_trg_pp(Bmu2pt[b], Bmu2eta[b], 0)*tnp_weight_trk_pp(0);
	hScale->Fill(Bpt[b], _weight*scale);
	for(int i = 1; i <= 100; i ++){
	double statTrg = tnp_weight_trg_pp(Bmu1pt[b], Bmu1eta[b], i)*tnp_weight_trk_pp(0)*tnp_weight_trg_pp(Bmu2pt[b], Bmu2eta[b], i)*tnp_weight_trk_pp(0);
	double statMuid = scale*tnp_weight_muid_pp(Bmu1pt[b], Bmu1eta[b], i)*tnp_weight_muid_pp(Bmu2pt[b], Bmu2eta[b], i);
	double statSTA = scale*tnp_weight_sta_pp(Bmu1pt[b], Bmu1eta[b], i)*tnp_weight_sta_pp(Bmu2pt[b], Bmu2eta[b], i);
	hStatTrg[i-1]->Fill(Bpt[b], _weight*statTrg);
	hStatMuid[i-1]->Fill(Bpt[b], _weight*statMuid);
	hStatSTA[i-1]->Fill(Bpt[b], _weight*statSTA);
	}
	double sysHiTrg = tnp_weight_trg_pp(Bmu1pt[b], Bmu1eta[b], -1)*tnp_weight_trk_pp(0)*tnp_weight_trg_pp(Bmu2pt[b], Bmu2eta[b], -1)*tnp_weight_trk_pp(0);
	double sysLoTrg = tnp_weight_trg_pp(Bmu1pt[b], Bmu1eta[b], -2)*tnp_weight_trk_pp(0)*tnp_weight_trg_pp(Bmu2pt[b], Bmu2eta[b], -2)*tnp_weight_trk_pp(0);
	double sysHiTrk = tnp_weight_trg_pp(Bmu1pt[b], Bmu1eta[b], 0)*tnp_weight_trk_pp(-1)*tnp_weight_trg_pp(Bmu2pt[b], Bmu2eta[b], 0)*tnp_weight_trk_pp(-1);
	double sysLoTrk = tnp_weight_trg_pp(Bmu1pt[b], Bmu1eta[b], 0)*tnp_weight_trk_pp(-2)*tnp_weight_trg_pp(Bmu2pt[b], Bmu2eta[b], 0)*tnp_weight_trk_pp(-2);
	double sysHiMuid = scale*tnp_weight_muid_pp(Bmu1pt[b], Bmu1eta[b], -1)*tnp_weight_muid_pp(Bmu2pt[b], Bmu2eta[b], -1);
	double sysLoMuid = scale*tnp_weight_muid_pp(Bmu1pt[b], Bmu1eta[b], -2)*tnp_weight_muid_pp(Bmu2pt[b], Bmu2eta[b], -2);
	double sysHiSTA = scale*tnp_weight_sta_pp(Bmu1pt[b], Bmu1eta[b], -1)*tnp_weight_sta_pp(Bmu2pt[b], Bmu2eta[b], -1);
	double sysLoSTA = scale*tnp_weight_sta_pp(Bmu1pt[b], Bmu1eta[b], -2)*tnp_weight_sta_pp(Bmu2pt[b], Bmu2eta[b], -2);
	double sysbinnedTrg = tnp_weight_trg_pp(Bmu1pt[b], Bmu1eta[b], -10)*tnp_weight_trk_pp(0)*tnp_weight_trg_pp(Bmu2pt[b], Bmu2eta[b], -10)*tnp_weight_trk_pp(0);
	hSysHiTrg ->Fill(Bpt[b], _weight*sysHiTrg);
	hSysHiTrk ->Fill(Bpt[b], _weight*sysHiTrk);
	hSysHiMuid->Fill(Bpt[b], _weight*sysHiMuid);
	      hSysHiSTA ->Fill(Bpt[b], _weight*sysHiSTA);
	      hSysLoTrg ->Fill(Bpt[b], _weight*sysLoTrg);
	      hSysLoTrk ->Fill(Bpt[b], _weight*sysLoTrk);
	      hSysLoMuid->Fill(Bpt[b], _weight*sysLoMuid);
	      hSysLoSTA ->Fill(Bpt[b], _weight*sysLoSTA);
	      hSysBinnedTrg ->Fill(Bpt[b], _weight*sysbinnedTrg);
	      }
	      }
      */      
	  if(!ispp)
	    {
	      if(HLT_HIL3Mu0NHitQ10_L2Mu0_MAXdR3p5_M1to5_v1 && Bgen[b]==23333 && pprimaryVertexFilter && phfCoincFilter2Th4 && pclusterCompatibilityFilter && Btrk1Pt[b]>0.7 && Bpt[b]>5.0 && (BsvpvDistance[b]/BsvpvDisErr[b])>2.0 && Bchi2cl[b]>0.05 && TMath::Abs(Btrk1Eta[b])<2.4 && TMath::Abs(By[b])<2.4 && TMath::Abs(PVz)<15 && Bmass[b]>5 && Bmass[b]<6 && TMath::Abs(Bmumumass[b]-3.096900)<0.15 
		 && Bmu1SoftMuID[b] && Bmu2SoftMuID[b] && Bmu1isAcc[b] && Bmu2isAcc[b] && Bmu1isTriggered[b] && Bmu2isTriggered[b] && (Btrk1PixelHit[b]+Btrk1StripHit[b])>=11 && (Btrk1Chi2ndf[b]/(Btrk1nStripLayer[b]+Btrk1nPixelLayer[b]))<0.18 && TMath::Abs(Btrk1PtErr[b]/Btrk1Pt[b])<0.1 && ((Bpt[b]>5 && Bpt[b]<7 && (BsvpvDistance[b]/BsvpvDisErr[b])>16.457 && cos(Bdtheta[b])>0.987 && TMath::Abs(Btrk1Dxy1[b]/Btrk1DxyError1[b])>0.005 && Btrk1Pt[b]>1.092 && Bchi2cl[b]>0.065) || (Bpt[b]>7 && Bpt[b]<10 && (BsvpvDistance[b]/BsvpvDisErr[b])>12.714 && cos(Bdtheta[b])>0.947 && TMath::Abs(Btrk1Dxy1[b]/Btrk1DxyError1[b])>2.928 && Btrk1Pt[b]>0.838 && Bchi2cl[b]>0.053) || (Bpt[b]>10 && Bpt[b]<15 && (BsvpvDistance[b]/BsvpvDisErr[b])>9.086 && cos(Bdtheta[b])>0.994 && TMath::Abs(Btrk1Dxy1[b]/Btrk1DxyError1[b])>1.540 && Btrk1Pt[b]>1.262 && Bchi2cl[b]>0.055) || (Bpt[b]>15 && Bpt[b]<20 && (BsvpvDistance[b]/BsvpvDisErr[b])>7.587 && cos(Bdtheta[b])>0.757 && TMath::Abs(Btrk1Dxy1[b]/Btrk1DxyError1[b])>0.000 && Btrk1Pt[b]>1.813 && Bchi2cl[b]>0.056) || (Bpt[b]>20 && Bpt[b]<30 && (BsvpvDistance[b]/BsvpvDisErr[b])>4.004 && cos(Bdtheta[b])>0.996 && TMath::Abs(Btrk1Dxy1[b]/Btrk1DxyError1[b])>0.000 && Btrk1Pt[b]>1.822 && Bchi2cl[b]>0.050) || (Bpt[b]>30 && Bpt[b]<50 && (BsvpvDistance[b]/BsvpvDisErr[b])>2.000 && cos(Bdtheta[b])>0.998 && TMath::Abs(Btrk1Dxy1[b]/Btrk1DxyError1[b])>0.000 && Btrk1Pt[b]>2.046 && Bchi2cl[b]>0.050) || (Bpt[b]>50 && Bpt[b]<100 && (BsvpvDistance[b]/BsvpvDisErr[b])>4.084 && cos(Bdtheta[b])>-0.112 && TMath::Abs(Btrk1Dxy1[b]/Btrk1DxyError1[b])>0.000 && Btrk1Pt[b]>1.645 && Bchi2cl[b]>0.050))
		 ){

		cout<<b<<"-st passed evt"<<endl;
		
		double _weight = pthatweight*Ncoll*(TMath::Gaus(PVz,0.427450,4.873825)/(sqrt(2*3.14159)*4.873825))/(TMath::Gaus(PVz,0.909938,4.970989)/(sqrt(2*3.14159)*4.970989))*((2.907795+-0.436572*Bgenpt[b]+0.006372*Bgenpt[b]*Bgenpt[b])*TMath::Exp(-0.157563*Bgenpt[b])+1.01308);
		hNominal->Fill(Bpt[b], _weight);
		hNominal2->Fill(Bpt[b], 1);
		
		//passed and fill
		double scale = tnp_weight_trg_pbpb(Bmu1pt[b], Bmu1eta[b], 1, 0)*tnp_weight_trk_pbpb(Btrk1Eta[b], 0)*tnp_weight_trg_pbpb(Bmu2pt[b], Bmu2eta[b], 1, 0)*tnp_weight_trk_pbpb(Btrk1Eta[b], 0);
		hScale->Fill(Bpt[b], _weight*scale);
		hScale2->Fill(Bpt[b], scale);
		
		if(_weight==0) cout<<"_weight zero!!!!!!"<<endl;
		if(scale==0) cout<<"scale zero!!!!!!"<<endl;
		
		double statHiTrg = tnp_weight_trg_pbpb(Bmu1pt[b], Bmu1eta[b], 1, 1)*tnp_weight_trk_pbpb(Btrk1Eta[b], 0)*tnp_weight_trg_pbpb(Bmu2pt[b], Bmu2eta[b], 1, 1)*tnp_weight_trk_pbpb(Btrk1Eta[b], 0);
		double statLoTrg = tnp_weight_trg_pbpb(Bmu1pt[b], Bmu1eta[b], 1, 2)*tnp_weight_trk_pbpb(Btrk1Eta[b], 0)*tnp_weight_trg_pbpb(Bmu2pt[b], Bmu2eta[b], 1, 2)*tnp_weight_trk_pbpb(Btrk1Eta[b], 0);
		double statHiTrk = tnp_weight_trg_pbpb(Bmu1pt[b], Bmu1eta[b], 1, 0)*tnp_weight_trk_pbpb(Btrk1Eta[b], 1)*tnp_weight_trg_pbpb(Bmu2pt[b], Bmu2eta[b], 1, 0)*tnp_weight_trk_pbpb(Btrk1Eta[b], 1);
		double statLoTrk = tnp_weight_trg_pbpb(Bmu1pt[b], Bmu1eta[b], 1, 0)*tnp_weight_trk_pbpb(Btrk1Eta[b], 2)*tnp_weight_trg_pbpb(Bmu2pt[b], Bmu2eta[b], 1, 0)*tnp_weight_trk_pbpb(Btrk1Eta[b], 2);
		double statHiMuid = scale*tnp_weight_muid_pbpb(Bmu1pt[b], Bmu1eta[b], 1)*tnp_weight_muid_pbpb(Bmu2pt[b], Bmu2eta[b], 1);
		double statLoMuid = scale*tnp_weight_muid_pbpb(Bmu1pt[b], Bmu1eta[b], 2)*tnp_weight_muid_pbpb(Bmu2pt[b], Bmu2eta[b], 2);
		
		hStatHiTrg ->Fill(Bpt[b], _weight*statHiTrg);
		hStatHiTrk ->Fill(Bpt[b], _weight*statHiTrk);
		hStatHiMuid->Fill(Bpt[b], _weight*statHiMuid);
		hStatLoTrg ->Fill(Bpt[b], _weight*statLoTrg);
		hStatLoTrk ->Fill(Bpt[b], _weight*statLoTrk);
		hStatLoMuid->Fill(Bpt[b], _weight*statLoMuid);
		
		hStatHiTrg2 ->Fill(Bpt[b], statHiTrg);
		hStatHiTrk2 ->Fill(Bpt[b], statHiTrk);
		hStatHiMuid2->Fill(Bpt[b], statHiMuid);
		hStatLoTrg2 ->Fill(Bpt[b], statLoTrg);
		hStatLoTrk2 ->Fill(Bpt[b], statLoTrk);
		hStatLoMuid2->Fill(Bpt[b], statLoMuid);
		
		if(statHiTrg==0) cout<<"statHiTrg problem!!!!!!"<<endl;
		if(statHiTrk==0) cout<<"statHiTrk problem!!!!!!"<<endl;
		if(statHiMuid==0) cout<<"statHiMuid problem!!!!!!"<<endl;
		if(statLoTrg==0) cout<<"statLoTrg problem!!!!!!"<<endl;
		if(statLoTrk==0) cout<<"statLoTrk problem!!!!!!"<<endl;
		if(statLoMuid==0) cout<<"statLoMuid problem!!!!!!"<<endl;
		
		double sysHiTrg = tnp_weight_trg_pbpb(Bmu1pt[b], Bmu1eta[b], 1, -1)*tnp_weight_trk_pbpb(Btrk1Eta[b], 0)*tnp_weight_trg_pbpb(Bmu2pt[b], Bmu2eta[b], 1, -1)*tnp_weight_trk_pbpb(Btrk1Eta[b], 0);
		double sysLoTrg = tnp_weight_trg_pbpb(Bmu1pt[b], Bmu1eta[b], 1, -2)*tnp_weight_trk_pbpb(Btrk1Eta[b], 0)*tnp_weight_trg_pbpb(Bmu2pt[b], Bmu2eta[b], 1, -2)*tnp_weight_trk_pbpb(Btrk1Eta[b], 0);
		double sysHiTrk = tnp_weight_trg_pbpb(Bmu1pt[b], Bmu1eta[b], 1, 0)*tnp_weight_trk_pbpb(Btrk1Eta[b], -1)*tnp_weight_trg_pbpb(Bmu2pt[b], Bmu2eta[b], 1, 0)*tnp_weight_trk_pbpb(Btrk1Eta[b], -1);
		double sysLoTrk = tnp_weight_trg_pbpb(Bmu1pt[b], Bmu1eta[b], 1, 0)*tnp_weight_trk_pbpb(Btrk1Eta[b], -2)*tnp_weight_trg_pbpb(Bmu2pt[b], Bmu2eta[b], 1, 0)*tnp_weight_trk_pbpb(Btrk1Eta[b], -2);
		double sysHiMuid = scale*tnp_weight_muid_pbpb(Bmu1pt[b], Bmu1eta[b], -1)*tnp_weight_muid_pbpb(Bmu2pt[b], Bmu2eta[b], -1);
		double sysLoMuid = scale*tnp_weight_muid_pbpb(Bmu1pt[b], Bmu1eta[b], -2)*tnp_weight_muid_pbpb(Bmu2pt[b], Bmu2eta[b], -2);
		
		hSysHiTrg ->Fill(Bpt[b], _weight*sysHiTrg);
		hSysHiTrk ->Fill(Bpt[b], _weight*sysHiTrk);
		hSysHiMuid->Fill(Bpt[b], _weight*sysHiMuid);
		hSysLoTrg ->Fill(Bpt[b], _weight*sysLoTrg);
		hSysLoTrk ->Fill(Bpt[b], _weight*sysLoTrk);
		hSysLoMuid->Fill(Bpt[b], _weight*sysLoMuid);
		
		hSysHiTrg2 ->Fill(Bpt[b], sysHiTrg);
		hSysHiTrk2 ->Fill(Bpt[b], sysHiTrk);
		hSysHiMuid2->Fill(Bpt[b], sysHiMuid);
		hSysLoTrg2 ->Fill(Bpt[b], sysLoTrg);
		hSysLoTrk2 ->Fill(Bpt[b], sysLoTrk);
		hSysLoMuid2->Fill(Bpt[b], sysLoMuid);
		
		if(sysHiTrg==0) cout<<"sysHiTrg problem!!!!!!"<<endl;
		if(sysHiTrk==0) cout<<"sysHiTrk problem!!!!!!"<<endl;
		if(sysHiMuid==0) cout<<"sysHiMuid problem!!!!!!"<<endl;
		if(sysLoTrg==0) cout<<"sysLoTrg problem!!!!!!"<<endl;
		if(sysLoTrk==0) cout<<"sysLoTrk problem!!!!!!"<<endl;
		if(sysLoMuid==0) cout<<"sysLoMuid problem!!!!!!"<<endl;
	      }
	    }
	}//Bsize loop
    }//event loop
  
  f->cd();
  hNominal->Write();
  hScale->Write();
  hStatHiTrg ->Write();
  hStatHiTrk ->Write();
  hStatHiMuid->Write();
  hStatLoTrg ->Write();
  hStatLoTrk ->Write();
  hStatLoMuid->Write();
  hSysHiTrg ->Write();
  hSysHiTrk ->Write();
  hSysHiMuid->Write();
  hSysLoTrg ->Write();
  hSysLoTrk ->Write();
  hSysLoMuid->Write();

  hNominal2->Write();
  hScale2->Write();
  hStatHiTrg2 ->Write();
  hStatHiTrk2 ->Write();
  hStatHiMuid2->Write();
  hStatLoTrg2 ->Write();
  hStatLoTrk2 ->Write();
  hStatLoMuid2->Write();
  hSysHiTrg2 ->Write();
  hSysHiTrk2 ->Write();
  hSysHiMuid2->Write();
  hSysLoTrg2 ->Write();
  hSysLoTrk2 ->Write();
  hSysLoMuid2->Write();


  cout<<"Stat. unc."<<endl;
  cout<<"vNominal"<<endl;
  for(int i = 0; i < _nBins; i++){	printf("%.2f, ", hNominal->GetBinContent(i+1));}printf("\n");
  cout<<"vScale"<<endl;
  for(int i = 0; i < _nBins; i++){	printf("%.2f, ", hScale->GetBinContent(i+1));}printf("\n");
  cout<<"vStatHiTrg"<<endl;
  for(int i = 0; i < _nBins; i++){	printf("%.2f, ", hStatHiTrg->GetBinContent(i+1));}printf("\n");
  cout<<"vStatLoTrg"<<endl;
  for(int i = 0; i < _nBins; i++){	printf("%.2f, ", hStatLoTrg->GetBinContent(i+1));}printf("\n");
  cout<<"vStatHiTrk"<<endl;
  for(int i = 0; i < _nBins; i++){	printf("%.2f, ", hStatHiTrk->GetBinContent(i+1));}printf("\n");
  cout<<"vStatLoTrk"<<endl;
  for(int i = 0; i < _nBins; i++){	printf("%.2f, ", hStatLoTrk->GetBinContent(i+1));}printf("\n");
  cout<<"vStatHiMuid"<<endl;
  for(int i = 0; i < _nBins; i++){	printf("%.2f, ", hStatHiMuid->GetBinContent(i+1));}printf("\n");
  cout<<"vStatLoMuid"<<endl;
  for(int i = 0; i < _nBins; i++){	printf("%.2f, ", hStatLoMuid->GetBinContent(i+1));}printf("\n");
  
  //Calculate Stat. unc.
  printf("vStatTrg, vStatTrk, vStatMuid, Statall\n");
  for(int i = 0; i < _nBins; i++){
    double vStatTrg = max(fabs(hStatHiTrg->GetBinContent(i+1)-hScale->GetBinContent(i+1)), fabs(hStatLoTrg->GetBinContent(i+1)-hScale->GetBinContent(i+1)))/hScale->GetBinContent(i+1);
    double vStatTrk = max(fabs(hStatHiTrk->GetBinContent(i+1)-hScale->GetBinContent(i+1)), fabs(hStatLoTrk->GetBinContent(i+1)-hScale->GetBinContent(i+1)))/hScale->GetBinContent(i+1);
    double vStatMuid = max(fabs(hStatHiMuid->GetBinContent(i+1)-hScale->GetBinContent(i+1)), fabs(hStatLoMuid->GetBinContent(i+1)-hScale->GetBinContent(i+1)))/hScale->GetBinContent(i+1);
    double Statall = vStatTrg*vStatTrg + vStatTrk*vStatTrk + vStatMuid*vStatMuid;
    Statall = sqrt(Statall);
    printf("%.4f, %.4f, %.4f, %.4f\n", vStatTrg, vStatTrk, vStatMuid, Statall);
    hStatUnc->SetBinContent(i+1, Statall);
  }
  
  cout<<"Sys. unc."<<endl;
  cout<<"vNominal"<<endl;
  for(int i = 0; i < _nBins; i++){	printf("%.2f, ", hNominal->GetBinContent(i+1));}printf("\n");
  cout<<"vScale"<<endl;
  for(int i = 0; i < _nBins; i++){	printf("%.2f, ", hScale->GetBinContent(i+1));}printf("\n");
  cout<<"vSysHiTrg"<<endl;
  for(int i = 0; i < _nBins; i++){	printf("%.2f, ", hSysHiTrg->GetBinContent(i+1));}printf("\n");
  cout<<"vSysLoTrg"<<endl;
  for(int i = 0; i < _nBins; i++){	printf("%.2f, ", hSysLoTrg->GetBinContent(i+1));}printf("\n");
  cout<<"vSysHiTrk"<<endl;
  for(int i = 0; i < _nBins; i++){	printf("%.2f, ", hSysHiTrk->GetBinContent(i+1));}printf("\n");
  cout<<"vSysLoTrk"<<endl;
  for(int i = 0; i < _nBins; i++){	printf("%.2f, ", hSysLoTrk->GetBinContent(i+1));}printf("\n");
  cout<<"vSysHiMuid"<<endl;
  for(int i = 0; i < _nBins; i++){	printf("%.2f, ", hSysHiMuid->GetBinContent(i+1));}printf("\n");
  cout<<"vSysLoMuid"<<endl;
  for(int i = 0; i < _nBins; i++){	printf("%.2f, ", hSysLoMuid->GetBinContent(i+1));}printf("\n");
  
  //Calculate sys. unc.
  printf("vSysTrg, vSysTrk, vSysMuid, Sysall\n");
  for(int i = 0; i < _nBins; i++){
    double vSysTrg = max(fabs(hSysHiTrg->GetBinContent(i+1)-hScale->GetBinContent(i+1)), fabs(hSysLoTrg->GetBinContent(i+1)-hScale->GetBinContent(i+1)))/hScale->GetBinContent(i+1);
    double vSysTrk = max(fabs(hSysHiTrk->GetBinContent(i+1)-hScale->GetBinContent(i+1)), fabs(hSysLoTrk->GetBinContent(i+1)-hScale->GetBinContent(i+1)))/hScale->GetBinContent(i+1);
    double vSysMuid = max(fabs(hSysHiMuid->GetBinContent(i+1)-hScale->GetBinContent(i+1)), fabs(hSysLoMuid->GetBinContent(i+1)-hScale->GetBinContent(i+1)))/hScale->GetBinContent(i+1);
    double Sysall = vSysTrg*vSysTrg + vSysTrk*vSysTrk + vSysMuid*vSysMuid;
    Sysall = sqrt(Sysall);
    printf("%.4f, %.4f, %.4f, %.4f\n", vSysTrg, vSysTrk, vSysMuid, Sysall);
    hSysUnc->SetBinContent(i+1, Sysall);
  }

  printf("sys uncertainty:\n");
  printf("double tnpUnc_%s[%d] = {", label.c_str(), _nBins);
  for(int i = 0; i < _nBins; i++){
    double sys = hSysUnc->GetBinContent(i+1);
    double stat = hStatUnc->GetBinContent(i+1);
    double all = sqrt(sys*sys + stat*stat);
    hAllUnc->SetBinContent(i+1, sys);	
    printf("%4f, ", sys*100.);
    }printf("};\n");
  printf("scaling:\n");
  for(int i = 0; i < _nBins; i++){	
    double SF = hScale->GetBinContent(i+1)/hNominal->GetBinContent(i+1);
    hSF->SetBinContent(i+1, SF);
    printf("%.4f, ", SF);
  }printf("\n");
  printf("double sf_%s[%d] = {", label.c_str(), _nBins);
  for(int i = 0; i < _nBins; i++){	
    printf("%.2f/%.2f, ", hScale->GetBinContent(i+1), hNominal->GetBinContent(i+1));
  }printf("};\n");
}

int main()
{
  converter2();
  return 0;
}
