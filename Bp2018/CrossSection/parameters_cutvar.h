//List of the optimal cuts for each pt bin
const int nBins = 1;
const int nvar = 5; // number of variables
const int ncutvar = 10; // number of varied cuts (in equal spacing)

double ptBins[nBins+1] = {5., 7.};
double cutvarref[nvar] = {17.347, 0.968, 0.520, 0.995, 0.095}; // optimized cut values for each variable for the ptBin
//double ptBins[nBins+1] = {7., 10.};
//double cutvarref[nvar] = {6.151, -0.279, 3.379, 1.184, 0.050};
//double ptBins[nBins+1] = {10., 15.};
//double cutvarref[nvar] = {9.641, -0.510, 3.464, 1.287, 0.185};
//double ptBins[nBins+1] = {15., 20.};
//double cutvarref[nvar] = {6.520, 0.971, 0.0, 1.837, 0.089};
//double ptBins[nBins+1] = {20., 30.};
//double cutvarref[nvar] = {4.171, 0.998, 0.0, 1.692, 0.050};
//double ptBins[nBins+1] = {30., 50.};
//double cutvarref[nvar] = {3.850, 0.571, 0.0, 1.723, 0.050};
//double ptBins[nBins+1] = {50., 100.};
//double cutvarref[nvar] = {2.0, 0.743, 0.203, 2.973, 0.062};

TString cutvarname[nvar]; // dls3D, costheta, dxysig, trkpt, chisq
TString cutvar[nvar]; // (BsvpvDistance/BsvpvDisErr), cos(Bdtheta), TMath::Abs(Btrk1Dxy1/Btrk1DxyError1), Btrk1Pt, Bchi2cl

double cutvarmin[nvar] = {2.0, -1.0, 0.0, 0.9, 0.050}; // customize
double cutvarmax[nvar] = {25.0, 0.99, 8.0, 3.0, 0.550}; // customize
double cutspacing;

double yieldData_ref;
double yieldErrData_ref;
double yieldMC_ref;
double yieldErrMC_ref;

double yieldData[ncutvar];
double yieldErrData[ncutvar];
double yieldMC[ncutvar];
double yieldErrMC[ncutvar];

double RatioData[ncutvar];
double RatioErrData[ncutvar];
double RatioMC[ncutvar];
double RatioErrMC[ncutvar];

double DoubleRatio[ncutvar];
double DoubleRatioErr[ncutvar];

TF1* fData_ref;
TF1* fMC_ref;
TF1* fData[ncutvar];
TF1* fMC[ncutvar];
TF1* totalmass;
