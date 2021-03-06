void data_pp_30_50()
{
//=========Macro generated from canvas: c5/
//=========  (Mon Nov 13 17:50:06 2017) by ROOT version6.02/13
   TCanvas *c5 = new TCanvas("c5", "",0,0,600,600);
   c5->SetHighLightColor(2);
   c5->Range(4.76834,-12.26066,6.055341,72.29563);
   c5->SetFillColor(0);
   c5->SetBorderMode(0);
   c5->SetBorderSize(2);
   c5->SetLeftMargin(0.18);
   c5->SetRightMargin(0.043);
   c5->SetBottomMargin(0.145);
   c5->SetFrameBorderMode(0);
   c5->SetFrameBorderMode(0);
   
   TH1D *h-513 = new TH1D("h-513","",50,5,6);
   h-513->SetBinContent(1,3);
   h-513->SetBinContent(2,7);
   h-513->SetBinContent(3,5);
   h-513->SetBinContent(4,3);
   h-513->SetBinContent(5,8);
   h-513->SetBinContent(6,1);
   h-513->SetBinContent(7,4);
   h-513->SetBinContent(8,5);
   h-513->SetBinContent(9,1);
   h-513->SetBinContent(10,5);
   h-513->SetBinContent(11,3);
   h-513->SetBinContent(12,9);
   h-513->SetBinContent(13,21);
   h-513->SetBinContent(14,30);
   h-513->SetBinContent(15,38);
   h-513->SetBinContent(16,17);
   h-513->SetBinContent(17,6);
   h-513->SetBinContent(18,4);
   h-513->SetBinContent(21,1);
   h-513->SetBinContent(22,1);
   h-513->SetBinContent(25,1);
   h-513->SetBinContent(30,1);
   h-513->SetBinContent(31,1);
   h-513->SetBinContent(33,1);
   h-513->SetBinContent(34,1);
   h-513->SetBinContent(35,2);
   h-513->SetBinContent(38,1);
   h-513->SetBinContent(41,1);
   h-513->SetBinContent(43,1);
   h-513->SetBinContent(44,1);
   h-513->SetBinContent(48,3);
   h-513->SetBinContent(50,1);
   h-513->SetBinError(1,1.732051);
   h-513->SetBinError(2,2.645751);
   h-513->SetBinError(3,2.236068);
   h-513->SetBinError(4,1.732051);
   h-513->SetBinError(5,2.828427);
   h-513->SetBinError(6,1);
   h-513->SetBinError(7,2);
   h-513->SetBinError(8,2.236068);
   h-513->SetBinError(9,1);
   h-513->SetBinError(10,2.236068);
   h-513->SetBinError(11,1.732051);
   h-513->SetBinError(12,3);
   h-513->SetBinError(13,4.582576);
   h-513->SetBinError(14,5.477226);
   h-513->SetBinError(15,6.164414);
   h-513->SetBinError(16,4.123106);
   h-513->SetBinError(17,2.44949);
   h-513->SetBinError(18,2);
   h-513->SetBinError(19,1);
   h-513->SetBinError(20,1);
   h-513->SetBinError(21,1);
   h-513->SetBinError(22,1);
   h-513->SetBinError(23,1);
   h-513->SetBinError(24,1);
   h-513->SetBinError(25,1);
   h-513->SetBinError(26,1);
   h-513->SetBinError(27,1);
   h-513->SetBinError(28,1);
   h-513->SetBinError(29,1);
   h-513->SetBinError(30,1);
   h-513->SetBinError(31,1);
   h-513->SetBinError(32,1);
   h-513->SetBinError(33,1);
   h-513->SetBinError(34,1);
   h-513->SetBinError(35,1.414214);
   h-513->SetBinError(36,1);
   h-513->SetBinError(37,1);
   h-513->SetBinError(38,1);
   h-513->SetBinError(39,1);
   h-513->SetBinError(40,1);
   h-513->SetBinError(41,1);
   h-513->SetBinError(42,1);
   h-513->SetBinError(43,1);
   h-513->SetBinError(44,1);
   h-513->SetBinError(45,1);
   h-513->SetBinError(46,1);
   h-513->SetBinError(47,1);
   h-513->SetBinError(48,1.732051);
   h-513->SetBinError(49,1);
   h-513->SetBinError(50,1);
   h-513->SetMinimum(0);
   h-513->SetMaximum(63.84);
   h-513->SetEntries(187);
   h-513->SetStats(0);
   h-513->SetLineWidth(4);
   h-513->SetMarkerStyle(20);
   h-513->SetMarkerSize(1.55);
   h-513->GetXaxis()->SetTitle("m_{B} (GeV/c^{2})");
   h-513->GetXaxis()->CenterTitle(true);
   h-513->GetXaxis()->SetNdivisions(-50205);
   h-513->GetXaxis()->SetLabelFont(42);
   h-513->GetXaxis()->SetLabelSize(0.055);
   h-513->GetXaxis()->SetTitleSize(0.055);
   h-513->GetXaxis()->SetTitleFont(42);
   h-513->GetYaxis()->SetTitle("Events / (20 MeV/c^{2})");
   h-513->GetYaxis()->CenterTitle(true);
   h-513->GetYaxis()->SetLabelFont(42);
   h-513->GetYaxis()->SetLabelSize(0.055);
   h-513->GetYaxis()->SetTitleSize(0.055);
   h-513->GetYaxis()->SetTitleOffset(1.4);
   h-513->GetYaxis()->SetTitleFont(42);
   h-513->GetZaxis()->SetLabelFont(42);
   h-513->GetZaxis()->SetLabelSize(0.035);
   h-513->GetZaxis()->SetTitleSize(0.035);
   h-513->GetZaxis()->SetTitleFont(42);
   h-513->Draw("e");
   
   TF1 *fBkpi56 = new TF1("fBkpi5","[0]*(3.12764e1*Gaus(x,5.33166,3.64663e-2)*(x<5.33166)+(x>=5.33166)*3.12764e1*Gaus(x,5.33166,1.5204e-1)+2.11124e2*TMath::Erf(-(x-5.14397)/6.43194e-2)+2.11124e2)",5,5.6);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#003300");
   fBkpi56->SetFillColor(ci);
   fBkpi56->SetFillStyle(3005);

   ci = TColor::GetColor("#003300");
   fBkpi56->SetLineColor(ci);
   fBkpi56->GetXaxis()->SetLabelFont(42);
   fBkpi56->GetXaxis()->SetLabelSize(0.035);
   fBkpi56->GetXaxis()->SetTitleSize(0.035);
   fBkpi56->GetXaxis()->SetTitleFont(42);
   fBkpi56->GetYaxis()->SetLabelFont(42);
   fBkpi56->GetYaxis()->SetLabelSize(0.035);
   fBkpi56->GetYaxis()->SetTitleSize(0.035);
   fBkpi56->GetYaxis()->SetTitleFont(42);
   fBkpi56->SetParameter(0,0.01166962);
   fBkpi56->SetParError(0,0);
   fBkpi56->SetParLimits(0,0,0);
   fBkpi56->Draw("same");
   
   TF1 *background57 = new TF1("background5","[0]+[1]*x",5,6);
   background57->SetFillColor(19);
   background57->SetFillStyle(0);
   background57->SetLineColor(4);
   background57->SetLineStyle(7);
   background57->GetXaxis()->SetLabelFont(42);
   background57->GetXaxis()->SetLabelSize(0.035);
   background57->GetXaxis()->SetTitleSize(0.035);
   background57->GetXaxis()->SetTitleFont(42);
   background57->GetYaxis()->SetLabelFont(42);
   background57->GetYaxis()->SetLabelSize(0.035);
   background57->GetYaxis()->SetTitleSize(0.035);
   background57->GetYaxis()->SetTitleFont(42);
   background57->SetParameter(0,-1.499711);
   background57->SetParError(0,0);
   background57->SetParLimits(0,0,0);
   background57->SetParameter(1,0.3551109);
   background57->SetParError(1,0);
   background57->SetParLimits(1,0,0);
   background57->Draw("same");
   
   TF1 *fmass58 = new TF1("fmass5","[0]*([3]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[3])*Gaus(x,[1],[4])/(sqrt(2*3.14159)*[4]))",5.16,5.4);

   ci = TColor::GetColor("#ff9900");
   fmass58->SetFillColor(ci);
   fmass58->SetFillStyle(3002);

   ci = TColor::GetColor("#ff9900");
   fmass58->SetLineColor(ci);
   fmass58->SetLineStyle(7);
   fmass58->GetXaxis()->SetLabelFont(42);
   fmass58->GetXaxis()->SetLabelSize(0.035);
   fmass58->GetXaxis()->SetTitleSize(0.035);
   fmass58->GetXaxis()->SetTitleFont(42);
   fmass58->GetYaxis()->SetLabelFont(42);
   fmass58->GetYaxis()->SetLabelSize(0.035);
   fmass58->GetYaxis()->SetTitleSize(0.035);
   fmass58->GetYaxis()->SetTitleFont(42);
   fmass58->SetParameter(0,2.490907);
   fmass58->SetParError(0,0.2299086);
   fmass58->SetParLimits(0,0,0);
   fmass58->SetParameter(1,5.278243);
   fmass58->SetParError(1,0.002402269);
   fmass58->SetParLimits(1,0,0);
   fmass58->SetParameter(2,0.04662016);
   fmass58->SetParError(2,0);
   fmass58->SetParLimits(2,0,0);
   fmass58->SetParameter(3,0.2569638);
   fmass58->SetParError(3,0);
   fmass58->SetParLimits(3,0,0);
   fmass58->SetParameter(4,0.01808542);
   fmass58->SetParError(4,0);
   fmass58->SetParLimits(4,0,0);
   fmass58->Draw("same");
   
   TF1 *f59 = new TF1("f5","[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8]))+[3]+[4]*x+[5]*(3.12764e1*Gaus(x,5.33166,3.64663e-2)*(x<5.33166)+(x>=5.33166)*3.12764e1*Gaus(x,5.33166,1.5204e-1)+2.11124e2*TMath::Erf(-(x-5.14397)/6.43194e-2)+2.11124e2)",0,1);
   f59->SetNpx(5000);
   f59->SetFillColor(19);
   f59->SetFillStyle(0);
   f59->SetLineColor(2);
   f59->SetChisquare(42.57159);
   f59->SetNDF(44);
   f59->GetXaxis()->SetLabelFont(42);
   f59->GetXaxis()->SetLabelSize(0.035);
   f59->GetXaxis()->SetTitleSize(0.035);
   f59->GetXaxis()->SetTitleFont(42);
   f59->GetYaxis()->SetLabelFont(42);
   f59->GetYaxis()->SetLabelSize(0.035);
   f59->GetYaxis()->SetTitleSize(0.035);
   f59->GetYaxis()->SetTitleFont(42);
   f59->SetParameter(0,2.490907);
   f59->SetParError(0,0.2299086);
   f59->SetParLimits(0,0,0);
   f59->SetParameter(1,5.278243);
   f59->SetParError(1,0.002402269);
   f59->SetParLimits(1,0,0);
   f59->SetParameter(2,0.04662016);
   f59->SetParError(2,0);
   f59->SetParLimits(2,0.04662016,0.04662016);
   f59->SetParameter(3,-1.499711);
   f59->SetParError(3,0.1365648);
   f59->SetParLimits(3,0,0);
   f59->SetParameter(4,0.3551109);
   f59->SetParError(4,0.02401802);
   f59->SetParLimits(4,-1000,1000);
   f59->SetParameter(5,0.01166962);
   f59->SetParError(5,0.002052997);
   f59->SetParLimits(5,0,0);
   f59->SetParameter(6,-564066.8);
   f59->SetParError(6,22.62742);
   f59->SetParLimits(6,0,0);
   f59->SetParameter(7,0.2569638);
   f59->SetParError(7,0);
   f59->SetParLimits(7,0.2569638,0.2569638);
   f59->SetParameter(8,0.01808542);
   f59->SetParError(8,0);
   f59->SetParLimits(8,0.01808542,0.01808542);
   f59->Draw("same");
   
   TH1D *h-5_copy14 = new TH1D("h-5_copy14","",50,5,6);
   h-5_copy14->SetBinContent(1,3);
   h-5_copy14->SetBinContent(2,7);
   h-5_copy14->SetBinContent(3,5);
   h-5_copy14->SetBinContent(4,3);
   h-5_copy14->SetBinContent(5,8);
   h-5_copy14->SetBinContent(6,1);
   h-5_copy14->SetBinContent(7,4);
   h-5_copy14->SetBinContent(8,5);
   h-5_copy14->SetBinContent(9,1);
   h-5_copy14->SetBinContent(10,5);
   h-5_copy14->SetBinContent(11,3);
   h-5_copy14->SetBinContent(12,9);
   h-5_copy14->SetBinContent(13,21);
   h-5_copy14->SetBinContent(14,30);
   h-5_copy14->SetBinContent(15,38);
   h-5_copy14->SetBinContent(16,17);
   h-5_copy14->SetBinContent(17,6);
   h-5_copy14->SetBinContent(18,4);
   h-5_copy14->SetBinContent(21,1);
   h-5_copy14->SetBinContent(22,1);
   h-5_copy14->SetBinContent(25,1);
   h-5_copy14->SetBinContent(30,1);
   h-5_copy14->SetBinContent(31,1);
   h-5_copy14->SetBinContent(33,1);
   h-5_copy14->SetBinContent(34,1);
   h-5_copy14->SetBinContent(35,2);
   h-5_copy14->SetBinContent(38,1);
   h-5_copy14->SetBinContent(41,1);
   h-5_copy14->SetBinContent(43,1);
   h-5_copy14->SetBinContent(44,1);
   h-5_copy14->SetBinContent(48,3);
   h-5_copy14->SetBinContent(50,1);
   h-5_copy14->SetBinError(1,1.732051);
   h-5_copy14->SetBinError(2,2.645751);
   h-5_copy14->SetBinError(3,2.236068);
   h-5_copy14->SetBinError(4,1.732051);
   h-5_copy14->SetBinError(5,2.828427);
   h-5_copy14->SetBinError(6,1);
   h-5_copy14->SetBinError(7,2);
   h-5_copy14->SetBinError(8,2.236068);
   h-5_copy14->SetBinError(9,1);
   h-5_copy14->SetBinError(10,2.236068);
   h-5_copy14->SetBinError(11,1.732051);
   h-5_copy14->SetBinError(12,3);
   h-5_copy14->SetBinError(13,4.582576);
   h-5_copy14->SetBinError(14,5.477226);
   h-5_copy14->SetBinError(15,6.164414);
   h-5_copy14->SetBinError(16,4.123106);
   h-5_copy14->SetBinError(17,2.44949);
   h-5_copy14->SetBinError(18,2);
   h-5_copy14->SetBinError(19,1);
   h-5_copy14->SetBinError(20,1);
   h-5_copy14->SetBinError(21,1);
   h-5_copy14->SetBinError(22,1);
   h-5_copy14->SetBinError(23,1);
   h-5_copy14->SetBinError(24,1);
   h-5_copy14->SetBinError(25,1);
   h-5_copy14->SetBinError(26,1);
   h-5_copy14->SetBinError(27,1);
   h-5_copy14->SetBinError(28,1);
   h-5_copy14->SetBinError(29,1);
   h-5_copy14->SetBinError(30,1);
   h-5_copy14->SetBinError(31,1);
   h-5_copy14->SetBinError(32,1);
   h-5_copy14->SetBinError(33,1);
   h-5_copy14->SetBinError(34,1);
   h-5_copy14->SetBinError(35,1.414214);
   h-5_copy14->SetBinError(36,1);
   h-5_copy14->SetBinError(37,1);
   h-5_copy14->SetBinError(38,1);
   h-5_copy14->SetBinError(39,1);
   h-5_copy14->SetBinError(40,1);
   h-5_copy14->SetBinError(41,1);
   h-5_copy14->SetBinError(42,1);
   h-5_copy14->SetBinError(43,1);
   h-5_copy14->SetBinError(44,1);
   h-5_copy14->SetBinError(45,1);
   h-5_copy14->SetBinError(46,1);
   h-5_copy14->SetBinError(47,1);
   h-5_copy14->SetBinError(48,1.732051);
   h-5_copy14->SetBinError(49,1);
   h-5_copy14->SetBinError(50,1);
   h-5_copy14->SetMinimum(0);
   h-5_copy14->SetMaximum(63.84);
   h-5_copy14->SetEntries(187);
   h-5_copy14->SetDirectory(0);
   h-5_copy14->SetStats(0);
   
   TF1 *f55 = new TF1("f5","[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8]))+[3]+[4]*x+[5]*(3.12764e1*Gaus(x,5.33166,3.64663e-2)*(x<5.33166)+(x>=5.33166)*3.12764e1*Gaus(x,5.33166,1.5204e-1)+2.11124e2*TMath::Erf(-(x-5.14397)/6.43194e-2)+2.11124e2)",5,6);
   f55->SetNpx(5000);
   f55->SetFillColor(19);
   f55->SetFillStyle(0);
   f55->SetLineColor(2);
   f55->SetChisquare(42.57159);
   f55->SetNDF(44);
   f55->GetXaxis()->SetLabelFont(42);
   f55->GetXaxis()->SetLabelSize(0.035);
   f55->GetXaxis()->SetTitleSize(0.035);
   f55->GetXaxis()->SetTitleFont(42);
   f55->GetYaxis()->SetLabelFont(42);
   f55->GetYaxis()->SetLabelSize(0.035);
   f55->GetYaxis()->SetTitleSize(0.035);
   f55->GetYaxis()->SetTitleFont(42);
   f55->SetParameter(0,2.490907);
   f55->SetParError(0,0.2299086);
   f55->SetParLimits(0,0,0);
   f55->SetParameter(1,5.278243);
   f55->SetParError(1,0.002402269);
   f55->SetParLimits(1,0,0);
   f55->SetParameter(2,0.04662016);
   f55->SetParError(2,0);
   f55->SetParLimits(2,0.04662016,0.04662016);
   f55->SetParameter(3,-1.499711);
   f55->SetParError(3,0.1365648);
   f55->SetParLimits(3,0,0);
   f55->SetParameter(4,0.3551109);
   f55->SetParError(4,0.02401802);
   f55->SetParLimits(4,-1000,1000);
   f55->SetParameter(5,0.01166962);
   f55->SetParError(5,0.002052997);
   f55->SetParLimits(5,0,0);
   f55->SetParameter(6,-564066.8);
   f55->SetParError(6,22.62742);
   f55->SetParLimits(6,0,0);
   f55->SetParameter(7,0.2569638);
   f55->SetParError(7,0);
   f55->SetParLimits(7,0.2569638,0.2569638);
   f55->SetParameter(8,0.01808542);
   f55->SetParError(8,0);
   f55->SetParLimits(8,0.01808542,0.01808542);
   h-5_copy14->GetListOfFunctions()->Add(f55);
   h-5_copy14->SetLineWidth(4);
   h-5_copy14->SetMarkerStyle(20);
   h-5_copy14->SetMarkerSize(1.55);
   h-5_copy14->GetXaxis()->SetTitle("m_{B} (GeV/c^{2})");
   h-5_copy14->GetXaxis()->CenterTitle(true);
   h-5_copy14->GetXaxis()->SetNdivisions(-50205);
   h-5_copy14->GetXaxis()->SetLabelFont(42);
   h-5_copy14->GetXaxis()->SetLabelSize(0.055);
   h-5_copy14->GetXaxis()->SetTitleSize(0.055);
   h-5_copy14->GetXaxis()->SetTitleFont(42);
   h-5_copy14->GetYaxis()->SetTitle("Events / (20 MeV/c^{2})");
   h-5_copy14->GetYaxis()->CenterTitle(true);
   h-5_copy14->GetYaxis()->SetLabelFont(42);
   h-5_copy14->GetYaxis()->SetLabelSize(0.055);
   h-5_copy14->GetYaxis()->SetTitleSize(0.055);
   h-5_copy14->GetYaxis()->SetTitleOffset(1.4);
   h-5_copy14->GetYaxis()->SetTitleFont(42);
   h-5_copy14->GetZaxis()->SetLabelFont(42);
   h-5_copy14->GetZaxis()->SetLabelSize(0.035);
   h-5_copy14->GetZaxis()->SetTitleSize(0.035);
   h-5_copy14->GetZaxis()->SetTitleFont(42);
   h-5_copy14->Draw("sameaxis");
   
   TLegend *leg = new TLegend(0.525,0.46,0.85,0.75,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.055);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("h-5","Data","pl");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.55);
   entry->SetTextFont(42);
   entry=leg->AddEntry("f5","Fit","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("fmass5","Signal","f");

   ci = TColor::GetColor("#ff9900");
   entry->SetFillColor(ci);
   entry->SetFillStyle(3002);

   ci = TColor::GetColor("#ff9900");
   entry->SetLineColor(ci);
   entry->SetLineStyle(7);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("background5","Combinatorial","l");
   entry->SetLineColor(4);
   entry->SetLineStyle(7);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("fBkpi5","B #rightarrow J/#psi X","f");

   ci = TColor::GetColor("#003300");
   entry->SetFillColor(ci);
   entry->SetFillStyle(3005);

   ci = TColor::GetColor("#003300");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(4);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TLatex *   tex = new TLatex(0.22,0.87,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.075);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.225,0.74,"B^{#plus}+B^{#minus}");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.055);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.95,0.94,"28.0 pb^{-1} (pp 5.02 TeV)");
tex->SetNDC();
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetTextSize(0.055);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.518,0.82,"30 < p_{T} < 50 GeV/c");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.055);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.735,0.75,"|y| < 2.4");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.055);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TF1 *f56 = new TF1("f5","[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8]))+[3]+[4]*x+[5]*(3.12764e1*Gaus(x,5.33166,3.64663e-2)*(x<5.33166)+(x>=5.33166)*3.12764e1*Gaus(x,5.33166,1.5204e-1)+2.11124e2*TMath::Erf(-(x-5.14397)/6.43194e-2)+2.11124e2)",5,6);
   f56->SetNpx(5000);
   f56->SetFillColor(19);
   f56->SetFillStyle(0);
   f56->SetLineColor(2);
   f56->SetChisquare(42.57159);
   f56->SetNDF(44);
   f56->GetXaxis()->SetLabelFont(42);
   f56->GetXaxis()->SetLabelSize(0.035);
   f56->GetXaxis()->SetTitleSize(0.035);
   f56->GetXaxis()->SetTitleFont(42);
   f56->GetYaxis()->SetLabelFont(42);
   f56->GetYaxis()->SetLabelSize(0.035);
   f56->GetYaxis()->SetTitleSize(0.035);
   f56->GetYaxis()->SetTitleFont(42);
   f56->SetParameter(0,2.490907);
   f56->SetParError(0,0.2299086);
   f56->SetParLimits(0,0,0);
   f56->SetParameter(1,5.278243);
   f56->SetParError(1,0.002402269);
   f56->SetParLimits(1,0,0);
   f56->SetParameter(2,0.04662016);
   f56->SetParError(2,0);
   f56->SetParLimits(2,0.04662016,0.04662016);
   f56->SetParameter(3,-1.499711);
   f56->SetParError(3,0.1365648);
   f56->SetParLimits(3,0,0);
   f56->SetParameter(4,0.3551109);
   f56->SetParError(4,0.02401802);
   f56->SetParLimits(4,-1000,1000);
   f56->SetParameter(5,0.01166962);
   f56->SetParError(5,0.002052997);
   f56->SetParLimits(5,0,0);
   f56->SetParameter(6,-564066.8);
   f56->SetParError(6,22.62742);
   f56->SetParLimits(6,0,0);
   f56->SetParameter(7,0.2569638);
   f56->SetParError(7,0);
   f56->SetParLimits(7,0.2569638,0.2569638);
   f56->SetParameter(8,0.01808542);
   f56->SetParError(8,0);
   f56->SetParLimits(8,0.01808542,0.01808542);
   f56->Draw("same");
   
   TH1D *h-515 = new TH1D("h-515","",50,5,6);
   h-515->SetBinContent(1,3);
   h-515->SetBinContent(2,7);
   h-515->SetBinContent(3,5);
   h-515->SetBinContent(4,3);
   h-515->SetBinContent(5,8);
   h-515->SetBinContent(6,1);
   h-515->SetBinContent(7,4);
   h-515->SetBinContent(8,5);
   h-515->SetBinContent(9,1);
   h-515->SetBinContent(10,5);
   h-515->SetBinContent(11,3);
   h-515->SetBinContent(12,9);
   h-515->SetBinContent(13,21);
   h-515->SetBinContent(14,30);
   h-515->SetBinContent(15,38);
   h-515->SetBinContent(16,17);
   h-515->SetBinContent(17,6);
   h-515->SetBinContent(18,4);
   h-515->SetBinContent(21,1);
   h-515->SetBinContent(22,1);
   h-515->SetBinContent(25,1);
   h-515->SetBinContent(30,1);
   h-515->SetBinContent(31,1);
   h-515->SetBinContent(33,1);
   h-515->SetBinContent(34,1);
   h-515->SetBinContent(35,2);
   h-515->SetBinContent(38,1);
   h-515->SetBinContent(41,1);
   h-515->SetBinContent(43,1);
   h-515->SetBinContent(44,1);
   h-515->SetBinContent(48,3);
   h-515->SetBinContent(50,1);
   h-515->SetBinError(1,1.732051);
   h-515->SetBinError(2,2.645751);
   h-515->SetBinError(3,2.236068);
   h-515->SetBinError(4,1.732051);
   h-515->SetBinError(5,2.828427);
   h-515->SetBinError(6,1);
   h-515->SetBinError(7,2);
   h-515->SetBinError(8,2.236068);
   h-515->SetBinError(9,1);
   h-515->SetBinError(10,2.236068);
   h-515->SetBinError(11,1.732051);
   h-515->SetBinError(12,3);
   h-515->SetBinError(13,4.582576);
   h-515->SetBinError(14,5.477226);
   h-515->SetBinError(15,6.164414);
   h-515->SetBinError(16,4.123106);
   h-515->SetBinError(17,2.44949);
   h-515->SetBinError(18,2);
   h-515->SetBinError(19,1);
   h-515->SetBinError(20,1);
   h-515->SetBinError(21,1);
   h-515->SetBinError(22,1);
   h-515->SetBinError(23,1);
   h-515->SetBinError(24,1);
   h-515->SetBinError(25,1);
   h-515->SetBinError(26,1);
   h-515->SetBinError(27,1);
   h-515->SetBinError(28,1);
   h-515->SetBinError(29,1);
   h-515->SetBinError(30,1);
   h-515->SetBinError(31,1);
   h-515->SetBinError(32,1);
   h-515->SetBinError(33,1);
   h-515->SetBinError(34,1);
   h-515->SetBinError(35,1.414214);
   h-515->SetBinError(36,1);
   h-515->SetBinError(37,1);
   h-515->SetBinError(38,1);
   h-515->SetBinError(39,1);
   h-515->SetBinError(40,1);
   h-515->SetBinError(41,1);
   h-515->SetBinError(42,1);
   h-515->SetBinError(43,1);
   h-515->SetBinError(44,1);
   h-515->SetBinError(45,1);
   h-515->SetBinError(46,1);
   h-515->SetBinError(47,1);
   h-515->SetBinError(48,1.732051);
   h-515->SetBinError(49,1);
   h-515->SetBinError(50,1);
   h-515->SetMinimum(0);
   h-515->SetMaximum(63.84);
   h-515->SetEntries(187);
   h-515->SetStats(0);
   h-515->SetLineWidth(4);
   h-515->SetMarkerStyle(20);
   h-515->SetMarkerSize(1.55);
   h-515->GetXaxis()->SetTitle("m_{B} (GeV/c^{2})");
   h-515->GetXaxis()->CenterTitle(true);
   h-515->GetXaxis()->SetNdivisions(-50205);
   h-515->GetXaxis()->SetLabelFont(42);
   h-515->GetXaxis()->SetLabelSize(0.055);
   h-515->GetXaxis()->SetTitleSize(0.055);
   h-515->GetXaxis()->SetTitleFont(42);
   h-515->GetYaxis()->SetTitle("Events / (20 MeV/c^{2})");
   h-515->GetYaxis()->CenterTitle(true);
   h-515->GetYaxis()->SetLabelFont(42);
   h-515->GetYaxis()->SetLabelSize(0.055);
   h-515->GetYaxis()->SetTitleSize(0.055);
   h-515->GetYaxis()->SetTitleOffset(1.4);
   h-515->GetYaxis()->SetTitleFont(42);
   h-515->GetZaxis()->SetLabelFont(42);
   h-515->GetZaxis()->SetLabelSize(0.035);
   h-515->GetZaxis()->SetTitleSize(0.035);
   h-515->GetZaxis()->SetTitleFont(42);
   h-515->Draw("e same");
   
   TPaveText *pt = new TPaveText(-0.35,0.9341608,0.35,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   AText = pt->AddText("[0]*([7]*Gaus(x,[1],[2])/(sqrt(2*3.14159)*[2])+(1-[7])*Gaus(x,[1],[8])/(sqrt(2*3.14159)*[8]))+[3]+[4]*x+[5]*(3.12764e1*Gaus(x,5.33166,3.64663e-2)*(x<5.33166)+(x>=5.33166)*3.12764e1*Gaus(x,5.33166,1.5204e-1)+2.11124e2*TMath::Erf(-(x-5.14397)/6.43194e-2)+2.11124e2)");
   pt->Draw();
   c5->Modified();
   c5->cd();
   c5->SetSelected(c5);
}
