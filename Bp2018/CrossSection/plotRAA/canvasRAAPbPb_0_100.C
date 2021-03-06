void canvasRAAPbPb_0_100()
{
//=========Macro generated from canvas: canvasRAA/canvasRAA
//=========  (Fri Feb  8 12:08:43 2019) by ROOT version 6.14/04
   TCanvas *canvasRAA = new TCanvas("canvasRAA", "canvasRAA",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   canvasRAA->SetHighLightColor(2);
   canvasRAA->Range(-9.117646,-0.2310559,108.5294,1.69441);
   canvasRAA->SetFillColor(0);
   canvasRAA->SetBorderMode(0);
   canvasRAA->SetBorderSize(2);
   canvasRAA->SetLeftMargin(0.12);
   canvasRAA->SetRightMargin(0.03);
   canvasRAA->SetTopMargin(0.075);
   canvasRAA->SetBottomMargin(0.12);
   canvasRAA->SetFrameBorderMode(0);
   canvasRAA->SetFrameBorderMode(0);
   
   TH2F *hemptyEff__1 = new TH2F("hemptyEff__1","",50,5,105,10,0,1.55);
   hemptyEff__1->SetMinimum(0);
   hemptyEff__1->SetMaximum(2);
   hemptyEff__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hemptyEff__1->SetLineColor(ci);
   hemptyEff__1->SetMarkerStyle(20);
   hemptyEff__1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   hemptyEff__1->GetXaxis()->CenterTitle(true);
   hemptyEff__1->GetXaxis()->SetLabelFont(42);
   hemptyEff__1->GetXaxis()->SetTitleSize(0.05);
   hemptyEff__1->GetXaxis()->SetTitleFont(42);
   hemptyEff__1->GetYaxis()->SetTitle("R_{AA}");
   hemptyEff__1->GetYaxis()->CenterTitle(true);
   hemptyEff__1->GetYaxis()->SetLabelFont(42);
   hemptyEff__1->GetYaxis()->SetTitleSize(0.05);
   hemptyEff__1->GetYaxis()->SetTitleOffset(1.1);
   hemptyEff__1->GetYaxis()->SetTitleFont(42);
   hemptyEff__1->GetZaxis()->SetLabelFont(42);
   hemptyEff__1->GetZaxis()->SetLabelSize(0.035);
   hemptyEff__1->GetZaxis()->SetTitleSize(0.035);
   hemptyEff__1->GetZaxis()->SetTitleFont(42);
   hemptyEff__1->Draw("");
   TLine *line = new TLine(5,1,105,1);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   TLatex *   tex = new TLatex(0.4,0.595,"Centrality 0-100%");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.2,0.936,"28.0 pb^{-1} (pp 5.02 TeV) + 1.5 nb^{-1} (PbPb 5.02 TeV)");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.038);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.16,0.76,"B^{+}");
tex->SetNDC();
   tex->SetTextSize(0.08);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.16,0.9,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.16,0.72,"|y| < 2.4");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TLegend *leg = new TLegend(0.6036242,0.7474695,0.942953,0.8457592,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.04);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("gNuclearModification_UnCor","R_{AA}","pe");
   entry->SetLineStyle(1);

   ci = TColor::GetColor("#0033cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry->SetTextSize(0.038);
   entry=leg->AddEntry("gNuclearModification","Syst. uncert.","f");

   ci = 1179;
   color = new TColor(ci, 0, 0.6, 1, " ", 0.5);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1000);
   entry->SetLineStyle(1);
   entry->SetMarkerColor(4);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry->SetTextSize(0.03);
   entry=leg->AddEntry("TBox","Global uncert.","f");
   entry->SetFillColor(16);
   entry->SetFillStyle(1001);
   entry->SetLineColor(16);
   entry->SetLineStyle(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry->SetTextSize(0.03);
   leg->Draw();
   
   Double_t gNuclearModification_fx3001[6] = {
   8.5,
   12.5,
   17.5,
   25,
   40,
   75};
   Double_t gNuclearModification_fy3001[6] = {
   0.4515137,
   0.3450858,
   0.4527235,
   0.5063888,
   0.6779442,
   0.580066};
   Double_t gNuclearModification_felx3001[6] = {
   1.5,
   2.5,
   2.5,
   5,
   10,
   25};
   Double_t gNuclearModification_fely3001[6] = {
   0.0878727,
   0.05936694,
   0.07615833,
   0.08366641,
   0.1114905,
   0.09539504};
   Double_t gNuclearModification_fehx3001[6] = {
   1.5,
   2.5,
   2.5,
   5,
   10,
   25};
   Double_t gNuclearModification_fehy3001[6] = {
   0.0878727,
   0.05936694,
   0.07615833,
   0.08366641,
   0.1114905,
   0.09539504};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(6,gNuclearModification_fx3001,gNuclearModification_fy3001,gNuclearModification_felx3001,gNuclearModification_fehx3001,gNuclearModification_fely3001,gNuclearModification_fehy3001);
   grae->SetName("gNuclearModification");
   grae->SetTitle("Graph");

   ci = 1179;
   color = new TColor(ci, 0, 0.6, 1, " ", 0.5);
   grae->SetFillColor(ci);
   grae->SetFillStyle(1000);
   grae->SetLineColor(0);
   grae->SetLineWidth(0);

   ci = TColor::GetColor("#0033cc");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   grae->SetMarkerSize(1.2);
   
   TH1F *Graph_gNuclearModification3001 = new TH1F("Graph_gNuclearModification3001","Graph",100,0,109.3);
   Graph_gNuclearModification3001->SetMinimum(0.2353473);
   Graph_gNuclearModification3001->SetMaximum(0.8398063);
   Graph_gNuclearModification3001->SetDirectory(0);
   Graph_gNuclearModification3001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gNuclearModification3001->SetLineColor(ci);
   Graph_gNuclearModification3001->SetMarkerStyle(20);
   Graph_gNuclearModification3001->GetXaxis()->SetLabelFont(42);
   Graph_gNuclearModification3001->GetXaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3001->GetXaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3001->GetXaxis()->SetTitleFont(42);
   Graph_gNuclearModification3001->GetYaxis()->SetLabelFont(42);
   Graph_gNuclearModification3001->GetYaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3001->GetYaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3001->GetYaxis()->SetTitleOffset(0);
   Graph_gNuclearModification3001->GetYaxis()->SetTitleFont(42);
   Graph_gNuclearModification3001->GetZaxis()->SetLabelFont(42);
   Graph_gNuclearModification3001->GetZaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3001->GetZaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_gNuclearModification3001);
   
   grae->Draw("5");
   Double_t xAxis1[7] = {7, 10, 15, 20, 30, 50, 100}; 
   
   TH1D *hNuclearModification__2 = new TH1D("hNuclearModification__2","",6, xAxis1);
   hNuclearModification__2->SetBinContent(1,0.4515137);
   hNuclearModification__2->SetBinContent(2,0.3450858);
   hNuclearModification__2->SetBinContent(3,0.4527235);
   hNuclearModification__2->SetBinContent(4,0.5063888);
   hNuclearModification__2->SetBinContent(5,0.6779442);
   hNuclearModification__2->SetBinContent(6,0.580066);
   hNuclearModification__2->SetBinError(1,0.09450069);
   hNuclearModification__2->SetBinError(2,0.03605466);
   hNuclearModification__2->SetBinError(3,0.04235486);
   hNuclearModification__2->SetBinError(4,0.0475547);
   hNuclearModification__2->SetBinError(5,0.09520653);
   hNuclearModification__2->SetBinError(6,0.156416);
   hNuclearModification__2->SetEntries(189.9475);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification__2->SetLineColor(ci);
   hNuclearModification__2->SetLineWidth(3);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification__2->SetMarkerColor(ci);
   hNuclearModification__2->SetMarkerStyle(21);
   hNuclearModification__2->SetMarkerSize(1.2);
   hNuclearModification__2->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
   hNuclearModification__2->GetXaxis()->SetLabelFont(42);
   hNuclearModification__2->GetXaxis()->SetLabelSize(0.035);
   hNuclearModification__2->GetXaxis()->SetTitleSize(0.035);
   hNuclearModification__2->GetXaxis()->SetTitleFont(42);
   hNuclearModification__2->GetYaxis()->SetTitle("Uncorrected dN(D^{0})/dp_{T}");
   hNuclearModification__2->GetYaxis()->SetLabelFont(42);
   hNuclearModification__2->GetYaxis()->SetLabelSize(0.035);
   hNuclearModification__2->GetYaxis()->SetTitleSize(0.035);
   hNuclearModification__2->GetYaxis()->SetTitleOffset(0);
   hNuclearModification__2->GetYaxis()->SetTitleFont(42);
   hNuclearModification__2->GetZaxis()->SetLabelFont(42);
   hNuclearModification__2->GetZaxis()->SetLabelSize(0.035);
   hNuclearModification__2->GetZaxis()->SetTitleSize(0.035);
   hNuclearModification__2->GetZaxis()->SetTitleFont(42);
   hNuclearModification__2->Draw("same");
   TBox *box = new TBox(5,0.9586116,5.35,1.045662);
   box->SetFillColor(16);
   box->SetLineColor(16);
   box->Draw();
   Double_t xAxis2[7] = {7, 10, 15, 20, 30, 50, 100}; 
   
   TH1D *hNuclearModification__3 = new TH1D("hNuclearModification__3","",6, xAxis2);
   hNuclearModification__3->SetBinContent(1,0.4515137);
   hNuclearModification__3->SetBinContent(2,0.3450858);
   hNuclearModification__3->SetBinContent(3,0.4527235);
   hNuclearModification__3->SetBinContent(4,0.5063888);
   hNuclearModification__3->SetBinContent(5,0.6779442);
   hNuclearModification__3->SetBinContent(6,0.580066);
   hNuclearModification__3->SetBinError(1,0.09450069);
   hNuclearModification__3->SetBinError(2,0.03605466);
   hNuclearModification__3->SetBinError(3,0.04235486);
   hNuclearModification__3->SetBinError(4,0.0475547);
   hNuclearModification__3->SetBinError(5,0.09520653);
   hNuclearModification__3->SetBinError(6,0.156416);
   hNuclearModification__3->SetEntries(189.9475);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification__3->SetLineColor(ci);
   hNuclearModification__3->SetLineWidth(3);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification__3->SetMarkerColor(ci);
   hNuclearModification__3->SetMarkerStyle(21);
   hNuclearModification__3->SetMarkerSize(1.2);
   hNuclearModification__3->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
   hNuclearModification__3->GetXaxis()->SetLabelFont(42);
   hNuclearModification__3->GetXaxis()->SetLabelSize(0.035);
   hNuclearModification__3->GetXaxis()->SetTitleSize(0.035);
   hNuclearModification__3->GetXaxis()->SetTitleFont(42);
   hNuclearModification__3->GetYaxis()->SetTitle("Uncorrected dN(D^{0})/dp_{T}");
   hNuclearModification__3->GetYaxis()->SetLabelFont(42);
   hNuclearModification__3->GetYaxis()->SetLabelSize(0.035);
   hNuclearModification__3->GetYaxis()->SetTitleSize(0.035);
   hNuclearModification__3->GetYaxis()->SetTitleOffset(0);
   hNuclearModification__3->GetYaxis()->SetTitleFont(42);
   hNuclearModification__3->GetZaxis()->SetLabelFont(42);
   hNuclearModification__3->GetZaxis()->SetLabelSize(0.035);
   hNuclearModification__3->GetZaxis()->SetTitleSize(0.035);
   hNuclearModification__3->GetZaxis()->SetTitleFont(42);
   hNuclearModification__3->Draw("same p");
      tex = new TLatex(0.16,0.76,"B^{+}");
tex->SetNDC();
   tex->SetTextSize(0.08);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TH2F *hemptyEff_copy__4 = new TH2F("hemptyEff_copy__4","",50,5,105,10,0,1.55);
   hemptyEff_copy__4->SetMinimum(0);
   hemptyEff_copy__4->SetMaximum(2);
   hemptyEff_copy__4->SetDirectory(0);
   hemptyEff_copy__4->SetStats(0);

   ci = TColor::GetColor("#000099");
   hemptyEff_copy__4->SetLineColor(ci);
   hemptyEff_copy__4->SetMarkerStyle(20);
   hemptyEff_copy__4->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   hemptyEff_copy__4->GetXaxis()->CenterTitle(true);
   hemptyEff_copy__4->GetXaxis()->SetLabelFont(42);
   hemptyEff_copy__4->GetXaxis()->SetTitleSize(0.05);
   hemptyEff_copy__4->GetXaxis()->SetTitleFont(42);
   hemptyEff_copy__4->GetYaxis()->SetTitle("R_{AA}");
   hemptyEff_copy__4->GetYaxis()->CenterTitle(true);
   hemptyEff_copy__4->GetYaxis()->SetLabelFont(42);
   hemptyEff_copy__4->GetYaxis()->SetTitleSize(0.05);
   hemptyEff_copy__4->GetYaxis()->SetTitleOffset(1.1);
   hemptyEff_copy__4->GetYaxis()->SetTitleFont(42);
   hemptyEff_copy__4->GetZaxis()->SetLabelFont(42);
   hemptyEff_copy__4->GetZaxis()->SetLabelSize(0.035);
   hemptyEff_copy__4->GetZaxis()->SetTitleSize(0.035);
   hemptyEff_copy__4->GetZaxis()->SetTitleFont(42);
   hemptyEff_copy__4->Draw("sameaxis");
   canvasRAA->Modified();
   canvasRAA->cd();
   canvasRAA->SetSelected(canvasRAA);
}
