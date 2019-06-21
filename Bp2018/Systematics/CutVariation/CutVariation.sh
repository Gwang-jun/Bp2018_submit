
doppCutVariation=0
doPbPbCutVariation=1



ppData="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/D0Local/skim_Dntuple_crab_pp_MinimumBias1to20_AOD_D0Dsy1p1_tkpt0p5eta2p0_04122016.root"
ppMC="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/D0Local/ntD_EvtBase_20161206_DfinderMC_pp_20160502_dPt0tkPt0p5_D0_prompt_Dpt1Dy1p5tkPt0p5Decay2p9Dalpha0p14Skim_pthatweight.root"

PbPbData="/mnt/T2_US_MIT/submit-hi2/scratch/gwangjun/crab_Bfinder_20190513_HIDoubleMuonPsiPeri_HIRun2018A_04Apr2019_v1_1033p1_GoldenJSON_327123_327564_skimhltBsize_ntKp.root"
PbPbMC="/mnt/T2_US_MIT/submit-hi2/scratch/gwangjun/crab_Bfinder_20190520_Hydjet_Pythia8_BuToJpsiK_1033p1_pt3tkpt0p7dls2_v2_pthatweight_hardcut.root"


BASECUTPbPb="Btrk1Pt>0.9 && Bpt>5.0 && (BsvpvDistance/BsvpvDisErr)>2.0 && Bchi2cl>0.05 && TMath::Abs(Btrk1Eta)<2.4 && TMath::Abs(By)<2.4 && TMath::Abs(PVz)<15 && Bmass>5 && Bmass<6 && TMath::Abs(Bmumumass-3.096900)<0.15 && Bmu1SoftMuID && Bmu2SoftMuID && Bmu1isAcc && Bmu2isAcc && Bmu1isTriggered && Bmu2isTriggered && (Btrk1PixelHit+Btrk1StripHit)>=11 && (Btrk1Chi2ndf/(Btrk1nStripLayer+Btrk1nPixelLayer))<0.18 && TMath::Abs(Btrk1PtErr/Btrk1Pt)<0.1"
CUTPbPb=${BASECUTPbPb}"&&((Bpt>5 && Bpt<7 && (BsvpvDistance/BsvpvDisErr)>13.028 && cos(Bdtheta)>-0.785 && TMath::Abs(Btrk1Dxy1/Btrk1DxyError1)>3.664 && Btrk1Pt>1.104 && Bchi2cl>0.224) || (Bpt>7 && Bpt<10 && (BsvpvDistance/BsvpvDisErr)>6.151 && cos(Bdtheta)>-0.279 && TMath::Abs(Btrk1Dxy1/Btrk1DxyError1)>3.379 && TMath::Abs(Btrk1Dz1/Btrk1DzError1)>0.628 && Btrk1Pt>1.185) || (Bpt>10 && Bpt<15 && (BsvpvDistance/BsvpvDisErr)>9.641 && cos(Bdtheta)>-0.510 && TMath::Abs(Btrk1Dxy1/Btrk1DxyError1)>3.464 && Btrk1Pt>1.287 && Bchi2cl>0.185) || (Bpt>15 && Bpt<20 && (BsvpvDistance/BsvpvDisErr)>6.520 && cos(Bdtheta)>0.971 && Btrk1Pt>1.837 && Bchi2cl>0.089) || (Bpt>20 && Bpt<30 && (BsvpvDistance/BsvpvDisErr)>4.171 && cos(Bdtheta)>0.998 && Btrk1Pt>1.692) || (Bpt>30 && Bpt<50 && (BsvpvDistance/BsvpvDisErr)>3.850 && cos(Bdtheta)>0.571 && Btrk1Pt>1.723) || (Bpt>50 && Bpt<100 && cos(Bdtheta)>0.743 && TMath::Abs(Btrk1Dxy1/Btrk1DxyError1)>0.203 && Btrk1Pt>2.973 && Bchi2cl>0.062))"
#CUTPbPb=${CUTPbPb}"&&abs(PVz)<15&&pclusterCompatibilityFilter&&pprimaryVertexFilter"


if [ $doppCutVariation -eq 1 ]; then
g++ CutVariation.C $(root-config --cflags --libs) -g -o CutVariation.exe 
./CutVariation.exe "pp" "$ppData"  "$ppMC" "$CUTPP"
rm CutVariation.exe
fi

if [ $doPbPbCutVariation -eq 1 ]; then
g++ CutVariation.C $(root-config --cflags --libs) -g -o CutVariation.exe 
./CutVariation.exe "PbPb" "$PbPbData"  "$PbPbMC" "$CUTPbPb"
rm CutVariation.exe
fi
