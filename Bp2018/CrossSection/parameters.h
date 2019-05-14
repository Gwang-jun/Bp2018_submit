const int nBins=7;
//double ptBins[nBins+1] = {5., 7.};
//double ptBins[nBins+1] = {50., 100.};
double ptBins[nBins+1] = {5., 7., 10., 15., 20., 30., 50., 100.};

//For Centrality Analysis, designate p_t bins.
const int nBinsInc=1;
double ptBinsInc[nBinsInc+1] = {7., 100.};

const int nBinsFine=95;
double ptBinsFine[nBinsFine+1] = {5., 6., 7., 8., 9., 10., 11., 12., 13., 14., 15., 16., 17., 18., 19., 20., 21., 22., 23., 24., 25., 26., 27., 28., 29., 30., 31., 32., 33., 34., 35., 36., 37., 38., 39., 40., 41., 42., 43., 44., 45., 46., 47., 48., 49., 50., 51., 52., 53., 54., 55., 56., 57., 58., 59., 60., 61., 62., 63., 64., 65., 66., 67., 68., 69., 70., 71., 72., 73., 74., 75., 76., 77., 78., 79., 80., 81., 82., 83., 84., 85., 86., 87., 88., 89., 90., 91., 92., 93., 94., 95., 96., 97., 98., 99., 100.};

const int nBinsY=4;
double ptBinsY[nBinsY+1] = {0.0, 0.5, 1.0, 1.5, 2.4};

//Use appropriate values for the designated centrality bins!!
const int nBinsCent=3;
double ptBinsCent[nBinsCent+1] = {0.*2, 20*2., 40.*2, 100.*2};
double TAA[nBinsCent] = {18.79, 6.82, 0.810};
double npart[nBinsCent] = {311.5, 160.3, 32.71};
//https://twiki.cern.ch/twiki/pub/CMS/HiCentrality2016/AN-15-080_temp_20160802.pdf
//https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideHeavyIonCentrality?rev=100#Ncoll_Npart_5_TeV
//https://twiki.cern.ch/twiki/pub/CMS/HI2015DailyMeetings/Ncoll_Npart_04Dec2015.pdf

const int nBinsReweight=7;
double ptBinsReweight[nBinsReweight+1]={5., 7., 10., 15., 20., 30., 50., 100.};

const int BIN_NUM=960;
const int HMIN=0;
const int HMAX=120;

const double binsize=((double)(HMAX)-(double)(HMIN))/(double)(BIN_NUM);
Double_t BRchain=6.02061e-5; //previous: 6.09604e-5


