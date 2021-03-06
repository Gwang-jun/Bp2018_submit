#include <TF1.h>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TLine.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TFile.h>


// Yen-Jie: systematics table for B meson
// Unit: In percentage
const int nPtBins=7;
double PtBins[nPtBins+1] = {5.,7.,10.,15.,20.,30.,50.,100.};//add a margin so that "FindBin" can work at the bin end

const int AnaBins=7;
double AnaPtBins[AnaBins+1] = {5.,7.,10.,15.,20.,30.,50.,100.};

const int nPtBinsCent=1;
double PtBinsCent[nPtBinsCent+1] = {5., 50.};

const int nCentBins=2;
double CentBins[nCentBins+1] = {0.,30.,90.};

// =============================================================================================================
// B meson decay
// =============================================================================================================
double BtomumuKBRUncertainty	= 2.80;			// from PDG
// =============================================================================================================
// pp uncertainty
// =============================================================================================================

// Normalization uncertainty
//double ppLumiUncertainty 	= 12;			// PAS 
double ppLumiUncertainty 	= 2.3;			// paper

// Point-to-point
double ppTrackingEfficiency 	= 4;   			// single track systematics from D* studies
double PbPbTrackingEfficiency 	= 5;   			// from charged particle analysis, paper
double ppAlignment = 2.8; //alignment systematic from pp 13 TeV analysis
double PbPbAlignment =0.0; //alignment systematic from pp 13 TeV analysis
double ppLifetime = 0.3; //from 13 TeV analysis
double PbPbLifetime = 0.0; //from 13 TeV analysis

TH1D*  ppSignalExtraction;
TH1D*  ppMesonSelection;
TH1D*  ppTagAndProbe;
TH1D*  ppAccUnc;

TF1 *fPPPtShape = new TF1("fPPPtShapeSig","[0]+[1]/(x)+[2]/x/x+[3]*x");

TFile* ppMCEfffile = new TFile("../CrossSection/ROOTfiles/MCstudiesPP.root");
TH1D* ppEff = (TH1D*)ppMCEfffile->Get("hEff");

// =============================================================================================================
// PbPb uncertainty
// =============================================================================================================

// Normalization uncertainty
double PbPbNMBUncertainty	= 0;		// uncertainty associated with minbias events,
double TAAUncertainty0to90	= 2.2;
double TAAUncertainty0to30	= 2.0;
double TAAUncertainty30to90     = 3.2;
double PbPbLumiUncertainty	= 0;		// 10% for the moment, to be updated (from Daniel), NOT used

// Point-to-point

TH1D*  PbPbSignalExtraction;			               
TH1D*  PbPbMesonSelection;				               
TH1D*  PbPbTagAndProbe;				                
TH1D*  PbPbAccUnc;
TH1D*  PbPbPtShape;
//TF1 *fPbPbPtShape= new TF1("fPbPbPtShapeSig","[0]+[1]/(x)+[2]/x/x+[3]*x");

TFile* PbPbMCEfffile = new TFile("../CrossSection/ROOTfiles/MCstudiesPbPb.root");
TH1D* PbPbEff = (TH1D*)PbPbMCEfffile->Get("hEff");

// RAA uncertainty, for systematic that can cancel such as PDF variation
TH1D*  RAASignalExtraction;

//RAA Rapidity
TFile* ppMCEfffileY = new TFile("../CrossSection/ROOTfiles/MCstudiesPP_Y.root");
TH1D* ppEffY = (TH1D*)ppMCEfffileY->Get("hEff");
TFile* PbPbMCEfffileY = new TFile("../CrossSection/ROOTfiles/MCstudiesPbPb_Y.root");
TH1D* PbPbEffY = (TH1D*)PbPbMCEfffileY->Get("hEff");

//RAA Centrality
TH1D*  TAAUncertainty;
TFile* ppMCEfffileCent = new TFile("../CrossSection/ROOTfiles/MCstudiesPP_INC.root");
TH1D* ppEffCent = (TH1D*)ppMCEfffileCent->Get("hEff");
TFile* PbPbMCEfffileCent = new TFile("../CrossSection/ROOTfiles/MCstudiesPbPb_CENT.root");
TH1D* PbPbEffCent = (TH1D*)PbPbMCEfffileCent->Get("hEff");

bool initialized = 0;

void initializationPP()
{
	ppMesonSelection = new TH1D("ppMesonSelection","",nPtBins,PtBins);
	ppMesonSelection->SetBinContent(1,		3.8);//PAS

	ppSignalExtraction = new TH1D("ppSignalExtraction","",nPtBins,PtBins);
//    ppSignalExtraction->SetBinContent(1,		2.7);//PAS
	ppSignalExtraction->SetBinContent(1,		2.9);//paper

	ppTagAndProbe = new TH1D("ppTagAndProbe","",AnaBins,AnaPtBins); 
	double tnpUnc_pp[7] = {5.386053, 5.386053, 3.814706, 3.235419, 3.014523, 2.819569, 2.819569};
	for(int i = 0; i < AnaBins; i++){
//		ppTagAndProbe->SetBinContent(i+1,		10.0);//PAS
		ppTagAndProbe->SetBinContent(i+1,tnpUnc_pp[i]);//paper
	}

	ppAccUnc = new TH1D("ppAccUnc","",AnaBins,AnaPtBins);
	double AccUnc_pp[7] = {0.111370, 0.111370, 0.100721, 0.248762, 0.292358, 0.411680, 0.411680};
	for(int i = 0; i < AnaBins; i++){
//		ppAccUnc->SetBinContent(i+1,0);//PAS
		ppAccUnc->SetBinContent(i+1,AccUnc_pp[i]);//paper
	}

	fPPPtShape->SetParameters(0.999265,-0.0458006,-0.181359,0);
}

void initializationPbPbCent090ptbin()
{

	PbPbMesonSelection = new TH1D("PbPbMesonSelection","",nPtBins,PtBins);
	PbPbMesonSelection->SetBinContent(1,14.66);
	PbPbMesonSelection->SetBinContent(2,8.26);
	PbPbMesonSelection->SetBinContent(3,9.12);
	PbPbMesonSelection->SetBinContent(4,13.7);
	PbPbMesonSelection->SetBinContent(5,9.57);
	PbPbMesonSelection->SetBinContent(6,8.92);
	PbPbMesonSelection->SetBinContent(7,10.6);

	PbPbSignalExtraction = new TH1D("PbPbSignalExtraction","",nPtBins,PtBins);
	PbPbSignalExtraction->SetBinContent(1,9.32);
	PbPbSignalExtraction->SetBinContent(2,4.79);
	PbPbSignalExtraction->SetBinContent(3,3.92);
	PbPbSignalExtraction->SetBinContent(4,7.29);
	PbPbSignalExtraction->SetBinContent(5,1.77);
	PbPbSignalExtraction->SetBinContent(6,7.65);
	PbPbSignalExtraction->SetBinContent(7,4.02);

	PbPbTagAndProbe = new TH1D("PbPbTagAndProbe","",AnaBins,AnaPtBins);
	double tnpUnc_pbpb[7] = {9.86, 3.14, 2.39, 1.86, 1.81, 1.88, 1.65};
	for(int i = 0; i < AnaBins; i++) {PbPbTagAndProbe->SetBinContent(i+1,tnpUnc_pbpb[i]);}

	PbPbAccUnc = new TH1D("PbPbAccUnc","",AnaBins,AnaPtBins);
	double AccUnc_PbPb[7] = {0.716141, 0.716141, 1.015990, 0.971805, 1.216616, 1.596899, 1.596899};
	for(int i = 0; i < AnaBins; i++) {PbPbAccUnc->SetBinContent(i+1,AccUnc_PbPb[i]);}

	PbPbPtShape = new TH1D("PbPbPtShape","",nPtBins,PtBins);
	PbPbPtShape->SetBinContent(1,4.52);
	PbPbPtShape->SetBinContent(2,2.84);
	PbPbPtShape->SetBinContent(3,0.65);
	PbPbPtShape->SetBinContent(4,0.47);
	PbPbPtShape->SetBinContent(5,0.43);
	PbPbPtShape->SetBinContent(6,0.10);
	PbPbPtShape->SetBinContent(7,0.00);

}

void initializationPbPbCent090()
{

	PbPbMesonSelection = new TH1D("PbPbMesonSelection","",nPtBinsCent,PtBinsCent);
	PbPbMesonSelection->SetBinContent(1,21.13);

	PbPbSignalExtraction = new TH1D("PbPbSignalExtraction","",nPtBinsCent,PtBinsCent);
	PbPbSignalExtraction->SetBinContent(1,7.71);

	PbPbTagAndProbe = new TH1D("PbPbTagAndProbe","",nPtBinsCent,PtBinsCent);
	PbPbTagAndProbe->SetBinContent(1,2.27);

	PbPbAccUnc = new TH1D("PbPbAccUnc","",nPtBinsCent,PtBinsCent);
	PbPbAccUnc->SetBinContent(1,0.);

	PbPbPtShape = new TH1D("PbPbPtShape","",nPtBinsCent,PtBinsCent);
	PbPbPtShape->SetBinContent(1,14.30);

}

void initializationPbPbCent3090()
{

	PbPbMesonSelection = new TH1D("PbPbMesonSelection","",nPtBinsCent,PtBinsCent);
	PbPbMesonSelection->SetBinContent(1,14.89);

	PbPbSignalExtraction = new TH1D("PbPbSignalExtraction","",nPtBinsCent,PtBinsCent);
	PbPbSignalExtraction->SetBinContent(1,11.38);

	PbPbTagAndProbe = new TH1D("PbPbTagAndProbe","",nPtBinsCent,PtBinsCent);
	PbPbTagAndProbe->SetBinContent(1,2.57);

	PbPbAccUnc = new TH1D("PbPbAccUnc","",nPtBinsCent,PtBinsCent);
	PbPbAccUnc->SetBinContent(1,0.);

	PbPbPtShape = new TH1D("PbPbPtShape","",nPtBinsCent,PtBinsCent);
	PbPbPtShape->SetBinContent(1,14.18);

}

void initializationPbPbCent030()
{

	PbPbMesonSelection = new TH1D("PbPbMesonSelection","",nPtBinsCent,PtBinsCent);
	PbPbMesonSelection->SetBinContent(1,24.12);

	PbPbSignalExtraction = new TH1D("PbPbSignalExtraction","",nPtBinsCent,PtBinsCent);
	PbPbSignalExtraction->SetBinContent(1,2.97);

	PbPbTagAndProbe = new TH1D("PbPbTagAndProbe","",nPtBinsCent,PtBinsCent);
	PbPbTagAndProbe->SetBinContent(1,2.18);

	PbPbAccUnc = new TH1D("PbPbAccUnc","",nPtBinsCent,PtBinsCent);
	PbPbAccUnc->SetBinContent(1,0.);

	PbPbPtShape = new TH1D("PbPbPtShape","",nPtBinsCent,PtBinsCent);
	PbPbPtShape->SetBinContent(1,14.34);

}


void initializationRAA()
{
	RAASignalExtraction = new TH1D("RAASignalExtraction","",nPtBins,PtBins);
	RAASignalExtraction->SetBinContent(1,	0.5);
}

void initializationRAACent()
{
	TAAUncertainty = new TH1D("TAAUncertainty","",nCentBins,CentBins);
	TAAUncertainty->SetBinContent(1,	1.7);
	TAAUncertainty->SetBinContent(2,	2.4);
	TAAUncertainty->SetBinContent(3,	4.9);
	TAAUncertainty->SetBinContent(4,	15.0);
}

void initialization(bool ptbinning=1, double centL=0,double centH=100){

	initializationPP();
	initializationRAA();
	initializationRAACent();
	if(ptbinning&&centL==0&&centH==90) initializationPbPbCent090ptbin();
	if(!ptbinning)
	  {
	    if (centL==0&&centH==90) initializationPbPbCent090();
	    if (centL==0&&centH==30) initializationPbPbCent030();
	    if (centL==30&&centH==90) initializationPbPbCent3090();
	  }
	initialized=0;

}

// =============================================================================================================
// RAA systematics
// =============================================================================================================
float normalizationUncertaintyForRAA(bool TAAhi = 1, double centL=0,double centH=100)
{
	double sys = 0;
	sys+=ppLumiUncertainty*ppLumiUncertainty;
	sys+=PbPbNMBUncertainty*PbPbNMBUncertainty;
	if (centL==0&&centH==10) {
		// 0-10%
	  sys+=TAAUncertainty0to30*TAAUncertainty0to30;
	} else {
		// 0-90%
	  sys+=TAAUncertainty0to90*TAAUncertainty0to90;
	}
	return sqrt(sys);
}

float systematicsForRAA(double pt,double centL=0,double centH=100, double HLT=0, int stage=0)
{
  if (!initialized && centL==0&&(centH==100||centH==90)) initialization(centL,centH);
	if (!initialized && centL==0&&centH==10) initialization(centL,centH);

	double sys=0;

	if (pt<7) return 0;
	if (pt >= PtBins[1]) pt = PtBins[1]-0.1;

	if (stage==1) return sqrt(sys);

	//sys+= RAASignalExtraction->GetBinContent(RAASignalExtraction->FindBin(pt))*
	//      RAASignalExtraction->GetBinContent(RAASignalExtraction->FindBin(pt));
	sys+= PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt))*
		PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt));
	sys+= ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt))*
		ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt));

	if (stage==2) return sqrt(sys);

	sys+= ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt))*
		ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt));
	sys+= PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt))*
		PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt));

	sys+= ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100*
		ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100;
	sys+= PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100*
		PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100;

	sys+=fPPPtShape->Eval(pt)*fPPPtShape->Eval(pt);
	//sys+=fPbPbPtShape->Eval(pt)*fPbPbPtShape->Eval(pt);

	sys+=(ppTrackingEfficiency)*(ppTrackingEfficiency);
	sys+=(PbPbTrackingEfficiency)*(PbPbTrackingEfficiency);
	sys+=ppAlignment*ppAlignment;
	sys+=ppLifetime*ppLifetime;
	sys+=PbPbAlignment*PbPbAlignment;
	sys+=PbPbLifetime*PbPbLifetime;

	if (stage==3) return sqrt(sys);

	sys+= ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt))*
		ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt));
	sys+= PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt))*
		PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt));

	sys+= ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt))*
		ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt));
	sys+= PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt))*
		PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt));

	return sqrt(sys);
}

float systematicsForRAA_Correlated(double pt,double centL=0,double centH=100, double HLT=0, int stage=0)
{
  if (!initialized && centL==0&&(centH==100||centH==90)) initialization(centL,centH);
	if (!initialized && centL==0&&centH==10) initialization(centL,centH);

	double sys=0;

	if (pt<7) return 0;
	if (pt >= PtBins[1]) pt = PtBins[1]-0.1;

	sys+= PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt))*
		PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt));
	sys+= ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt))*
		ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt));

	sys+= ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt))*
		ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt));
	sys+= PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt))*
		PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt));

	sys+=(ppTrackingEfficiency)*(ppTrackingEfficiency);
	sys+=(PbPbTrackingEfficiency)*(PbPbTrackingEfficiency);
	sys+=ppAlignment*ppAlignment;
	sys+=ppLifetime*ppLifetime;
	sys+=PbPbAlignment*PbPbAlignment;
	sys+=PbPbLifetime*PbPbLifetime;

	return sqrt(sys);
}

float systematicsForRAA_UnCorrelated(double pt,double centL=0,double centH=100, double HLT=0, int stage=0)
{
  if (!initialized && centL==0&&(centH==100||centH==90)) initialization(centL,centH);
	if (!initialized && centL==0&&centH==10) initialization(centL,centH);

	double sys=0;

	if (pt<7) return 0;
	if (pt >= PtBins[1]) pt = PtBins[1]-0.1;

	sys+= ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100*
		ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100;
	sys+= PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100*
		PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100;

	sys+=fPPPtShape->Eval(pt)*fPPPtShape->Eval(pt);
	//sys+=fPbPbPtShape->Eval(pt)*fPbPbPtShape->Eval(pt);

	sys+= ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt))*
		ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt));
	sys+= PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt))*
		PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt));

	sys+= ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt))*
		ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt));
	sys+= PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt))*
		PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt));

	return sqrt(sys);
}

// =============================================================================================================
// RAA systematics Rapidity
// =============================================================================================================
float systematicsForRAAY(double cent,double centL=0,double centH=100, double HLT=0, int stage=0)
{
  if (!initialized && centL==0&&(centH==100||centH==90)) initialization(centL,centH);
	if (!initialized && centL==0&&centH==10) initialization(centL,centH);

	double sys=0;

	if (stage==1) return sqrt(sys);

	sys+= PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(PtBins[0]))*
		PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(PtBins[0]));
	sys+= ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(PtBins[0]))*
		ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(PtBins[0]));

	if (stage==2) return sqrt(sys);

	sys+= ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(PtBins[0]))*
		ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(PtBins[0]));
	sys+= PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(PtBins[0]))*
		PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(PtBins[0]));

	sys+= ppEffY->GetBinError(ppEffY->FindBin(cent))/ppEffY->GetBinContent(ppEffY->FindBin(cent))*100*
		ppEffY->GetBinError(ppEffY->FindBin(cent))/ppEffY->GetBinContent(ppEffY->FindBin(cent))*100;
	sys+= PbPbEffY->GetBinError(PbPbEffY->FindBin(cent))/PbPbEffY->GetBinContent(PbPbEffY->FindBin(cent))*100*
		PbPbEffY->GetBinError(PbPbEffY->FindBin(cent))/PbPbEffY->GetBinContent(PbPbEffY->FindBin(cent))*100;

	sys+=fPPPtShape->Eval(PtBins[0])*fPPPtShape->Eval(PtBins[0]);
	//sys+=fPbPbPtShape->Eval(PtBins[0])*fPbPbPtShape->Eval(PtBins[0]);

	sys+=(ppTrackingEfficiency)*(ppTrackingEfficiency);
	sys+=(PbPbTrackingEfficiency)*(PbPbTrackingEfficiency);
	sys+=ppAlignment*ppAlignment;
	sys+=ppLifetime*ppLifetime;
	sys+=PbPbAlignment*PbPbAlignment;
	sys+=PbPbLifetime*PbPbLifetime;

	if (stage==3) return sqrt(sys);

	sys+= ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(PtBins[0]))*
		ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(PtBins[0]));
	sys+= PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(PtBins[0]))*
		PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(PtBins[0]));

	sys+= ppAccUnc->GetBinContent(ppAccUnc->FindBin(PtBins[0]))*
		ppAccUnc->GetBinContent(ppAccUnc->FindBin(PtBins[0]));
	sys+= PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(PtBins[0]))*
		PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(PtBins[0]));

	return sqrt(sys);
}
// =============================================================================================================
// RAA systematics Centrality
// =============================================================================================================
float normalizationUncertaintyForRAACent(double centL=0,double centH=100)
{
	double sys = 0;
	sys+=ppLumiUncertainty*ppLumiUncertainty;
	sys+=PbPbNMBUncertainty*PbPbNMBUncertainty;
	return sqrt(sys);
}

float systematicsForRAACent(double cent,double centL=0,double centH=100, double HLT=0, int stage=0)
{
  if (!initialized && centL==0&&(centH==100||centH==90)) initialization(centL,centH);
	if (!initialized && centL==0&&centH==10) initialization(centL,centH);

	double sys=0;

	if (cent<0) return 0;

	if (stage==1) return sqrt(sys);

	sys+= PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(PtBins[0]))*
		PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(PtBins[0]));
	sys+= ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(PtBins[0]))*
		ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(PtBins[0]));

	if (stage==2) return sqrt(sys);

	sys+= ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(PtBins[0]))*
		ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(PtBins[0]));
	sys+= PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(PtBins[0]))*
		PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(PtBins[0]));

	sys+= ppEffCent->GetBinError(ppEffCent->FindBin(PtBins[0]))/ppEffCent->GetBinContent(ppEffCent->FindBin(PtBins[0]))*100*
		ppEffCent->GetBinError(ppEffCent->FindBin(PtBins[0]))/ppEffCent->GetBinContent(ppEffCent->FindBin(PtBins[0]))*100;
	sys+= PbPbEffCent->GetBinError(PbPbEffCent->FindBin(cent))/PbPbEffCent->GetBinContent(PbPbEffCent->FindBin(cent))*100*
		PbPbEffCent->GetBinError(PbPbEffCent->FindBin(cent))/PbPbEffCent->GetBinContent(PbPbEffCent->FindBin(cent))*100;

	sys+=fPPPtShape->Eval(PtBins[0])*fPPPtShape->Eval(PtBins[0]);
	//sys+=fPbPbPtShape->Eval(PtBins[0])*fPbPbPtShape->Eval(PtBins[0]);

	sys+=(ppTrackingEfficiency)*(ppTrackingEfficiency);
	sys+=(PbPbTrackingEfficiency)*(PbPbTrackingEfficiency);
	sys+=ppAlignment*ppAlignment;
	sys+=ppLifetime*ppLifetime;
	sys+=PbPbAlignment*PbPbAlignment;
	sys+=PbPbLifetime*PbPbLifetime;

	sys+= TAAUncertainty->GetBinContent(TAAUncertainty->FindBin(cent))*
		TAAUncertainty->GetBinContent(TAAUncertainty->FindBin(cent));

	if (stage==3) return sqrt(sys);

	sys+= ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(PtBins[0]))*
		ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(PtBins[0]));
	sys+= PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(PtBins[0]))*
		PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(PtBins[0]));

	sys+= ppAccUnc->GetBinContent(ppAccUnc->FindBin(PtBins[0]))*
		ppAccUnc->GetBinContent(ppAccUnc->FindBin(PtBins[0]));
	sys+= PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(PtBins[0]))*
		PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(PtBins[0]));

	return sqrt(sys);
}

// =============================================================================================================
// RCP systematics
// =============================================================================================================
float normalizationUncertaintyForRCP(double centL=0,double centH=100)
{
	return 0;
}

float systematicsForRCP(double pt, double HLT=0,double centL=0,double centH=100)
{
  if (!initialized && centL==0&&centH==90) initializationPbPbCent090();
	if (!initialized && centL==0&&centH==30) initializationPbPbCent030();
	return 0.2;

}


// =============================================================================================================
// cross-section systematics for pp
// =============================================================================================================
float normalizationUncertaintyForPP()
{
	return sqrt((BtomumuKBRUncertainty*BtomumuKBRUncertainty)+(ppLumiUncertainty*ppLumiUncertainty));
}

float systematicsPP(double pt, double HLT=0,int stage=0)
{
	if (!initialized) initialization();
	double sys=0;

	if (pt >= PtBins[1]) pt = PtBins[1]-0.1;

	if (stage==1) return sqrt(sys);

	sys+= ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt))* 
		ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt));

	if (stage==2) return sqrt(sys);

	sys+=fPPPtShape->Eval(pt)*fPPPtShape->Eval(pt);
	sys+=(ppTrackingEfficiency)*(ppTrackingEfficiency);
	sys+=ppAlignment*ppAlignment;
	sys+=ppLifetime*ppLifetime;
	sys+= ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt))* 
		ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt));
	sys+= ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100*
		ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100;

	if (stage==3) return sqrt(sys);

	sys+= ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt))*
		ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt));
	sys+= ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt))*
		ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt));

	return sqrt(sys);
}

float systematicsPP_Correlated(double pt, double HLT=0,int stage=0)
{
	if (!initialized) initialization();
	double sys=0;
	if (pt >= PtBins[1]) pt = PtBins[1]-0.1;

	sys+= ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt))* 
		ppSignalExtraction->GetBinContent(ppSignalExtraction->FindBin(pt));
	sys+=(ppTrackingEfficiency)*(ppTrackingEfficiency);
	sys+=ppAlignment*ppAlignment;
	sys+=ppLifetime*ppLifetime;
	sys+= ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt))* 
		ppMesonSelection->GetBinContent(ppMesonSelection->FindBin(pt));

	return sqrt(sys);
}

float systematicsPP_UnCorrelated(double pt, double HLT=0,int stage=0)
{
	if (!initialized) initialization();
	double sys=0;
	if (pt >= PtBins[1]) pt = PtBins[1]-0.1;

	sys+=fPPPtShape->Eval(pt)*fPPPtShape->Eval(pt);
	sys+= ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100*
		ppEff->GetBinError(ppEff->FindBin(pt))/ppEff->GetBinContent(ppEff->FindBin(pt))*100;
	sys+= ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt))*
		ppTagAndProbe->GetBinContent(ppTagAndProbe->FindBin(pt));
	sys+= ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt))*
		ppAccUnc->GetBinContent(ppAccUnc->FindBin(pt));

	return sqrt(sys);
}

// =============================================================================================================
// cross-section systematics for PbPb
// =============================================================================================================
float normalizationUncertaintyForPbPb(bool TAAhi = 1, double centL=0,double centH=100)
{
	double sys = ((BtomumuKBRUncertainty*BtomumuKBRUncertainty)+(PbPbNMBUncertainty*PbPbNMBUncertainty));
	if (centL==0&&centH==10) {
		// 0-10%
	  sys+=TAAUncertainty0to30*TAAUncertainty0to30;
	} else {
		// 0-90%
	  sys+=TAAUncertainty0to90*TAAUncertainty0to90;
	}   
	return sqrt(sys);
}

float systematicsPbPb(double pt, bool ptbinning = 1, double centL=0,double centH=100, double HLT=0)
{
  if(ptbinning&&centL==0&&centH==90) initialization(1,centL,centH);
  if(!ptbinning)
    {
      if (!initialized && centL==0&&centH==90) initialization(0,centL,centH);
      if (!initialized && centL==0&&centH==30) initialization(0,centL,centH);
      if (!initialized && centL==30&&centH==90) initialization(0,centL,centH);
    }
  double sys=0;
  
  sys+= PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt))* 
    PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt));
  
  sys+= PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt))* 
    PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt));
  
  sys+= PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100*
    PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100;
  
  sys+=PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt))*
    PbPbPtShape->GetBinContent(PbPbPtShape->FindBin(pt));
  
  sys+=PbPbTrackingEfficiency*PbPbTrackingEfficiency;
  sys+=PbPbAlignment*PbPbAlignment;
  sys+=PbPbLifetime*PbPbLifetime;
  
  sys+= PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt))*
    PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt));
  
  sys+= PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt))*
    PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt));

  return sqrt(sys);
}

float systematicsPbPb_Correlated(double pt, bool TAAhi = 1, double centL=0,double centH=100, double HLT=0)
{
  if (!initialized && centL==0&&(centH==100||centH==90)) initialization(centL,centH);
    if (!initialized && centL==0&&centH==10) initialization(centL,centH);
	double sys=0;

	sys+= PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt))* 
		PbPbMesonSelection->GetBinContent(PbPbMesonSelection->FindBin(pt));

	sys+= PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt))* 
		PbPbSignalExtraction->GetBinContent(PbPbSignalExtraction->FindBin(pt));

	sys+=(PbPbTrackingEfficiency)*(PbPbTrackingEfficiency);
	sys+=PbPbAlignment*PbPbAlignment;
	sys+=PbPbLifetime*PbPbLifetime;

	return sqrt(sys);
}

float systematicsPbPb_UnCorrelated(double pt, bool TAAhi = 1, double centL=0,double centH=100, double HLT=0)
{
    if (!initialized && centL==0&&(centH==100||centH==90)) initialization(centL,centH);
    if (!initialized && centL==0&&centH==10) initialization(centL,centH);
	double sys=0;

	sys+= PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100*
		PbPbEff->GetBinError(PbPbEff->FindBin(pt))/PbPbEff->GetBinContent(PbPbEff->FindBin(pt))*100;

	//sys+=fPbPbPtShape->Eval(pt)*fPbPbPtShape->Eval(pt);

	sys+= PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt))*
		PbPbTagAndProbe->GetBinContent(PbPbTagAndProbe->FindBin(pt));

	sys+= PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt))*
		PbPbAccUnc->GetBinContent(PbPbAccUnc->FindBin(pt));

	return sqrt(sys);
}

// =============================================================================================================
// Drawer
// =============================================================================================================
void drawSys(double x1,double y1, double x2,double y2, int color = 1)
{
	TLine *l1 = new TLine(x1,y1/100.,x2,y2/100.);
	TLine *l2 = new TLine(x1,-y1/100.,x2,-y2/100.);
	l1->SetLineWidth(2);
	l2->SetLineWidth(2);
	l1->SetLineColor(color);
	l2->SetLineColor(color);
	l1->Draw();
	l2->Draw();

}

// =============================================================================================================
// Plot systematics for RAA
// =============================================================================================================
void plotSystematicsRAA(double centL=0,double centH=100)
{

	TCanvas*canvas=new TCanvas("canvas","canvas",600,600);//550,500
	canvas->cd();
	canvas->SetFillColor(0);
	canvas->SetBorderMode(0);
	canvas->SetBorderSize(2);
	canvas->SetLeftMargin(0.185);//0.200
	canvas->SetRightMargin(0.045);
	canvas->SetTopMargin(0.080);
	canvas->SetBottomMargin(0.150);
	canvas->SetFrameBorderMode(0);
	canvas->SetLogx();

	TH2F* hempty=new TH2F("hempty","",50,5,60.,10.,-0.8,0.8);
	hempty->GetXaxis()->CenterTitle();
	hempty->GetYaxis()->CenterTitle();
	hempty->GetYaxis()->SetTitle("Systematical Uncertainty");
	hempty->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
	hempty->GetXaxis()->SetTitleOffset(1.40);//0.9
	hempty->GetYaxis()->SetTitleOffset(1.45);//1.
	hempty->GetXaxis()->SetTitleSize(0.05);//0.045
	hempty->GetYaxis()->SetTitleSize(0.05);//0.045
	hempty->GetXaxis()->SetTitleFont(42);
	hempty->GetYaxis()->SetTitleFont(42);
	hempty->GetXaxis()->SetLabelFont(42);
	hempty->GetYaxis()->SetLabelFont(42);
	hempty->GetXaxis()->SetLabelSize(0.050);//0.035
	hempty->GetYaxis()->SetLabelSize(0.050);//0.035  
	hempty->GetXaxis()->SetLabelOffset(0.01);
	hempty->Draw();

	drawSys(6,0, 6,normalizationUncertaintyForRAA(centL,centH),2);
	drawSys(6,normalizationUncertaintyForRAA(centL,centH), 6.5,normalizationUncertaintyForRAA(centL,centH),2);
	drawSys(6.5,0, 6.5,normalizationUncertaintyForRAA(centL,centH),2);


	drawSys(PtBins[0],0, PtBins[0],systematicsForRAA(PtBins[0],centL,centH,0,0),1);
	drawSys(PtBins[nPtBins],0, PtBins[nPtBins],systematicsForRAA(PtBins[nPtBins],centL,centH,0,0),1);


	for (double i=PtBins[0];i<=PtBins[nPtBins];i+=0.1)
	{      
		drawSys(i,systematicsForRAA(i,centL,centH,0,0), i+0.1,systematicsForRAA(i+0.1,centL,centH,0,0),1);
		drawSys(i,sqrt((systematicsForRAA(i,centL,centH,0,2)*systematicsForRAA(i,centL,centH,0,2))-(systematicsForRAA(i,centL,centH,0,1)*systematicsForRAA(i,centL,centH,0,1))),
				i+0.1,sqrt((systematicsForRAA(i+0.1,centL,centH,0,2)*systematicsForRAA(i+0.1,centL,centH,0,2))-(systematicsForRAA(i+0.1,centL,centH,0,1)*systematicsForRAA(i+0.1,centL,centH,0,1))),4);
		drawSys(i,sqrt((systematicsForRAA(i,centL,centH,0,3)*systematicsForRAA(i,centL,centH,0,3))-(systematicsForRAA(i,centL,centH,0,2)*systematicsForRAA(i,centL,centH,0,2))),
				i+0.1,sqrt((systematicsForRAA(i+0.1,centL,centH,0,3)*systematicsForRAA(i+0.1,centL,centH,0,3))-(systematicsForRAA(i+0.1,centL,centH,0,2)*systematicsForRAA(i+0.1,centL,centH,0,2))),kGreen+2);
		drawSys(i,sqrt((systematicsForRAA(i,centL,centH,0,0)*systematicsForRAA(i,centL,centH,0,0))-(systematicsForRAA(i,centL,centH,0,3)*systematicsForRAA(i,centL,centH,0,3))),
				i+0.1,sqrt((systematicsForRAA(i+0.1,centL,centH,0,0)*systematicsForRAA(i+0.1,centL,centH,0,0))-(systematicsForRAA(i+0.1,centL,centH,0,3)*systematicsForRAA(i+0.1,centL,centH,0,3))),kMagenta);

	}

	TH1D *h1 = new TH1D("h1","",100,0,1);
	h1->SetLineWidth(2); h1->SetLineColor(1);
	TH1D *h2 = new TH1D("h2","",100,0,1);
	h2->SetLineWidth(2); h2->SetLineColor(2);
	TH1D *h4 = new TH1D("h4","",100,0,1);
	h4->SetLineWidth(2); h4->SetLineColor(4);
	TH1D *h5 = new TH1D("h5","",100,0,1);
	h5->SetLineWidth(2); h5->SetLineColor(kGreen+2);
	TH1D *h6 = new TH1D("h6","",100,0,1);
	h6->SetLineWidth(2); h6->SetLineColor(kMagenta);
	TH1D *h7 = new TH1D("h7","",100,0,1);
	h7->SetLineWidth(2); h7->SetLineColor(kYellow);

	TLatex* texlumi = new TLatex(0.19,0.936,"25.8 pb^{-1} (5.02 TeV pp) + 350.68 #mub^{-1} (5.02 TeV PbPb)");
	texlumi->SetNDC();
	//texlumi->SetTextAlign(31);
	texlumi->SetTextFont(42);
	texlumi->SetTextSize(0.036);
	texlumi->SetLineWidth(2);
	texlumi->Draw();
	TLatex* texcms = new TLatex(0.22,0.90,"CMS");
	texcms->SetNDC();
	texcms->SetTextAlign(13);
	texcms->SetTextFont(62);//61
	texcms->SetTextSize(0.06);
	texcms->SetLineWidth(2);
	texcms->Draw();
	TLatex* texpre = new TLatex(0.22,0.84,"Performance");
	texpre->SetNDC();
	texpre->SetTextAlign(13);
	texpre->SetTextFont(52);
	texpre->SetTextSize(0.04);
	texpre->SetLineWidth(2);
	texpre->Draw();

	TLatex * texY = new TLatex(0.5,0.8324607,"B^{+} R_{AA}, |y| < 2.4");//0.2612903,0.8425793
	texY->SetNDC();
	texY->SetTextColor(1);
	texY->SetTextFont(42);
	texY->SetTextSize(0.045);
	texY->SetLineWidth(2);
	texY->Draw();

	TString texper="%";
	TLatex * tlatexeff2 = new TLatex(0.5268456,0.7678883,Form("Centrality %.0f-%.0f%s",centL,centH,texper.Data()));//0.2612903,0.8425793
	tlatexeff2->SetNDC();
	tlatexeff2->SetTextColor(1);
	tlatexeff2->SetTextFont(42);
	tlatexeff2->SetTextSize(0.045);
	tlatexeff2->SetLineWidth(2);
	tlatexeff2->Draw();

	TLegend *leg = new TLegend(0.2147651,0.1762653,0.7818792,0.3717277);
	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->SetTextSize(0.04);
	leg->AddEntry(h2,"Overall Normalization (N_{MB}, Lumi)","l");
	leg->AddEntry(h1,"Total Systematics","l");
	leg->AddEntry(h4,"Signal Extraction","l");
	leg->AddEntry(h5,"B Meson Selection and Correction","l");
	leg->AddEntry(h6,"Tag and Probe","l");
	leg->Draw();
	canvas->SaveAs(Form("SystematicSummaryPbPb_Cent%d.pdf",(int)centH));
	canvas->SaveAs(Form("SystematicSummaryPbPb_Cent%d.png",(int)centH));


}

// =============================================================================================================
// Plot systematics for cross section
// =============================================================================================================
void plotSystematicsPP()
{
	TCanvas*canvas=new TCanvas("canvas","canvas",600,600);//550,500
	canvas->cd();
	canvas->SetFillColor(0);
	canvas->SetBorderMode(0);
	canvas->SetBorderSize(2);
	canvas->SetLeftMargin(0.185);//0.200
	canvas->SetRightMargin(0.045);
	canvas->SetTopMargin(0.080);
	canvas->SetBottomMargin(0.150);
	canvas->SetFrameBorderMode(0);
	canvas->SetLogx();

	TH2F* hempty=new TH2F("hempty","",50,5,60.,10.,-0.8,0.8);
	hempty->GetXaxis()->CenterTitle();
	hempty->GetYaxis()->CenterTitle();
	hempty->GetYaxis()->SetTitle("Systematical Uncertainty");
	hempty->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
	hempty->GetXaxis()->SetTitleOffset(1.40);//0.9
	hempty->GetYaxis()->SetTitleOffset(1.45);//1.
	hempty->GetXaxis()->SetTitleSize(0.05);//0.045
	hempty->GetYaxis()->SetTitleSize(0.05);//0.045
	hempty->GetXaxis()->SetTitleFont(42);
	hempty->GetYaxis()->SetTitleFont(42);
	hempty->GetXaxis()->SetLabelFont(42);
	hempty->GetYaxis()->SetLabelFont(42);
	hempty->GetXaxis()->SetLabelSize(0.050);//0.035
	hempty->GetYaxis()->SetLabelSize(0.050);//0.035  
	hempty->GetXaxis()->SetLabelOffset(0.01);
	hempty->Draw();

	drawSys(6,0, 6,normalizationUncertaintyForPP(),2);
	drawSys(6,normalizationUncertaintyForPP(), 6.5,normalizationUncertaintyForPP(),2);
	drawSys(6.5,0, 6.5,normalizationUncertaintyForPP(),2);


	drawSys(PtBins[0],0, PtBins[0],systematicsPP(PtBins[0]),1);
	drawSys(PtBins[nPtBins],0, PtBins[nPtBins],systematicsPP(PtBins[nPtBins]),1);

	for (double i=PtBins[0];i<PtBins[nPtBins];i+=0.1)
	{      
		drawSys(i,systematicsPP(i,0,0), i+0.1,systematicsPP(i+0.1,0,0),1);
		drawSys(i,sqrt((systematicsPP(i,0,2)*systematicsPP(i,0,2))-(systematicsPP(i,0,1)*systematicsPP(i,0,1))),
				i+0.1,sqrt((systematicsPP(i+0.1,0,2)*systematicsPP(i+0.1,0,2))-(systematicsPP(i+0.1,0,1)*systematicsPP(i+0.1,0,1))),4);
		drawSys(i,sqrt((systematicsPP(i,0,3)*systematicsPP(i,0,3))-(systematicsPP(i,0,2)*systematicsPP(i,0,2))),
				i+0.1,sqrt((systematicsPP(i+0.1,0,3)*systematicsPP(i+0.1,0,3))-(systematicsPP(i+0.1,0,2)*systematicsPP(i+0.1,0,2))),kGreen+2);
		drawSys(i,sqrt((systematicsPP(i,0,0)*systematicsPP(i,0,0))-(systematicsPP(i,0,3)*systematicsPP(i,0,3))),
				i+0.1,sqrt((systematicsPP(i+0.1,0,0)*systematicsPP(i+0.1,0,0))-(systematicsPP(i+0.1,0,3)*systematicsPP(i+0.1,0,3))),kMagenta);
	}

	TH1D *h1 = new TH1D("h1","",100,0,1);
	h1->SetLineWidth(2); h1->SetLineColor(1);
	TH1D *h2 = new TH1D("h2","",100,0,1);
	h2->SetLineWidth(2); h2->SetLineColor(2);
	TH1D *h4 = new TH1D("h4","",100,0,1);
	h4->SetLineWidth(2); h4->SetLineColor(4);
	TH1D *h5 = new TH1D("h5","",100,0,1);
	h5->SetLineWidth(2); h5->SetLineColor(kGreen+2);
	TH1D *h6 = new TH1D("h6","",100,0,1);
	h6->SetLineWidth(2); h6->SetLineColor(kMagenta);

	TLatex* texlumi = new TLatex(0.35,0.936,"25.8 pb^{-1} (5.02 TeV pp)");
	texlumi->SetNDC();
	//texlumi->SetTextAlign(31);
	texlumi->SetTextFont(42);
	texlumi->SetTextSize(0.045);
	texlumi->SetLineWidth(2);
	texlumi->Draw();
	TLatex* texcms = new TLatex(0.22,0.90,"CMS");
	texcms->SetNDC();
	texcms->SetTextAlign(13);
	texcms->SetTextFont(62);//61
	texcms->SetTextSize(0.06);
	texcms->SetLineWidth(2);
	texcms->Draw();
	TLatex* texpre = new TLatex(0.22,0.84,"Performance");
	texpre->SetNDC();
	texpre->SetTextAlign(13);
	texpre->SetTextFont(52);
	texpre->SetTextSize(0.04);
	texpre->SetLineWidth(2);
	texpre->Draw();

	TLatex * texY = new TLatex(0.5,0.8324607,"B^{+} d#sigma / dp_{T}, |y| < 2.4");//0.2612903,0.8425793
	texY->SetNDC();
	texY->SetTextColor(1);
	texY->SetTextFont(42);
	texY->SetTextSize(0.045);
	texY->SetLineWidth(2);
	texY->Draw();

	TLegend *leg = new TLegend(0.2147651,0.1762653,0.7818792,0.3717277);
	leg->SetBorderSize(0);
	leg->SetFillStyle(0);
	leg->SetTextSize(0.04);
	leg->AddEntry(h2,"Overall Normalization (Lumi + BR)","l");
	leg->AddEntry(h1,"Total Systematics","l");
	leg->AddEntry(h4,"Signal Extraction","l");
	leg->AddEntry(h5,"B Meson Selection and Correction","l");
	leg->AddEntry(h6,"Tag and Probe","l");
	leg->Draw();

	canvas->SaveAs("SystematicSummaryPP.pdf");
	canvas->SaveAs("SystematicSummaryPP.png");
}


void plotNormalisationUnc(){

	std::cout<<"normalisation uncertainty RAA 0-100="<<normalizationUncertaintyForRAA(0,100)<<std::endl;
	std::cout<<"normalisation uncertainty RAA 0-10="<<normalizationUncertaintyForRAA(0,10)<<std::endl;
	std::cout<<"normalisation uncertainty pp="<<normalizationUncertaintyForPP()<<std::endl;
	std::cout<<"normalisation uncertainty PbPb 0-100="<<normalizationUncertaintyForPbPb(0,100)<<std::endl;
	std::cout<<"normalisation uncertainty PbPb 0-10="<<normalizationUncertaintyForPbPb(0,10)<<std::endl;

}
