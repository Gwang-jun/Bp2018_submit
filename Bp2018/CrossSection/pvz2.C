#include "TROOT.h"
#include "TH1.h"
#include "TTree.h"
#include "TH2.h"
#include "TF1.h"
#include "TFile.h"
#include "TMath.h"
#include "TSystem.h"
#include "TVector2.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TRandom.h"
#include <iostream>
#include <fstream>
#include "uti.h"
#include "parameters.h"

const int NPVz = 30;
const double PVzMin = -30;
const double PVzMax = 30;

//#include "his.h"                                                                                                                             
 
using namespace std;

using std::cout;
using std::endl;


void ReweightPVz(){

  gStyle->SetOptStat(0);

  TFile *finData = new TFile("/mnt/T2_US_MIT/submit-hi2/scratch/gwangjun/crab_Bfinder_20190513_HIDoubleMuonPsiPeri_HIRun2018A_04Apr2019_v1_1033p1_GoldenJSON_327123_327564_skimhltBsize_ntKp.root");
  TFile *finMC = new TFile("/mnt/T2_US_MIT/submit-hi2/scratch/gwangjun/crab_Bfinder_20190520_Hydjet_Pythia8_BuToJpsiK_1033p1_pt3tkpt0p7dls2_v2_addSamplePthat_pthatweight.root");

  TTree * tData = (TTree*) finData->Get("Bfinder/ntKp");
  TTree * tMC = (TTree*) finMC->Get("Bfinder/ntKp");
  TH1D * PVzData = new TH1D("PVzData","PVzData",NPVz,PVzMin,PVzMax);
  TH1D * PVzMC = new TH1D("PVzMC","PVzMC",NPVz,PVzMin,PVzMax);

  tData->Project("PVzData","PVz");
  PVzData->GetXaxis()->SetTitle("PVz (mm)");
  PVzData->GetYaxis()->SetTitle("Normalized Counts");
  PVzData->SetTitle("PVz Distribution in B^{+} Data");
  PVzData->SetMarkerStyle(20);
  PVzData->SetMarkerColor(kBlack);
  PVzData->SetMarkerSize(1);
  PVzData->Sumw2();
  PVzData->Scale(1.0/PVzData->Integral());

  tMC->Project("PVzMC","PVz - 0.321904");
  PVzMC->GetXaxis()->SetTitle("PVz (mm)");
  PVzMC->GetYaxis()->SetTitle("Normalized Counts");
  PVzMC->SetTitle("PVz Distribution in B^{+} MC");
  PVzMC->SetMarkerStyle(20);
  PVzMC->SetMarkerColor(kBlack);
  PVzMC->SetMarkerSize(1);
  PVzMC->Sumw2();
  PVzMC->Scale(1.0/PVzMC->Integral());

  TH1D * Ratio = (TH1D*) PVzData->Clone("Ratio");
  Ratio->Sumw2();
  Ratio->Divide(PVzMC);
  Ratio->GetXaxis()->SetTitle("PVz (mm)");
  Ratio->GetYaxis()->SetTitle("Ratio of the Normalized Counts");
  Ratio->SetTitle("Ratio of the PVz Distributions in B^{+}");
  Ratio->SetMarkerStyle(20);
  Ratio->SetMarkerColor(kBlack);
  Ratio->SetMarkerSize(1);
  Ratio->Scale(1.0/Ratio->Integral());

  TString FuncData;
  TString FuncMC;
  TString FuncRatio;

  TF1 * f1 = new TF1("f1","[0]*TMath::Exp(-[1]*(x-[2])*(x-[2]))",PVzMin,PVzMax);
  f1->SetParLimits(1,0,10);
  f1->SetParLimits(2,-10,10);

  TCanvas* c = new TCanvas("c","",600,600);
  c->cd();

  PVzData->Fit(f1,"R");
  double p0Data = f1->GetParameter(0);
  double p1Data = f1->GetParameter(1);
  double p2Data = f1->GetParameter(2);
  FuncData = Form("%f*TMath::Exp(-%f*(PVz-%f)*(PVz-%f))",f1->GetParameter(0),f1->GetParameter(1),f1->GetParameter(2),f1->GetParameter(2));
  cout << "Funct Data = " << FuncData.Data() << endl;
  PVzData->Draw("ep");
  c->SaveAs("PVzDataFit.png");

  PVzMC->Fit(f1,"R");
  double p0MC = f1->GetParameter(0);
  double p1MC = f1->GetParameter(1);
  double p2MC = f1->GetParameter(2);
  FuncMC = Form("%f*TMath::Exp(-%f*(PVz-%f)*(PVz-%f))",f1->GetParameter(0),f1->GetParameter(1),f1->GetParameter(2),f1->GetParameter(2));
  cout << "Funct MC = " << FuncMC.Data() << endl;
  PVzMC->Draw("ep");
  c->SaveAs("PVzMCFit.png");

  //Ratio->Fit(f1,"R");
  //double p0Ratio = f1->GetParameter(0);
  //double p1Ratio = f1->GetParameter(1);
  //double p2Ratio = f1->GetParameter(2);
  //FuncRatio = Form("%f*TMath::Exp(-%f*(PVz-%f)*(PVz-%f))",f1->GetParameter(0),f1->GetParameter(1),f1->GetParameter(2),f1->GetParameter(2));
  //cout << "Funct Ratio = " << FuncRatio.Data() << endl;
  Ratio->Draw("ep");
  c->SaveAs("PVzRatioFit.png");
}

int main()
{
  ReweightPVz();
  return 0;
}
