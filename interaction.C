// ROOT macro file for plotting example B4 histograms 
// 
// Can be run from ROOT session:
// root[0] .x plotHisto.C

{
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  
  // Draw histos filled by Geant4 simulation 
  //   

  // Open file filled by Geant4 simulation 
  TFile f("crosstalk1/build/result/crosstalknoshield.root");

  // Create a canvas and divide it into 2x2 pads
  TCanvas* c1 = new TCanvas("c1", "", 20, 20, 1400, 1200);
  c1->Divide(3,2);
  
  TH1D* hist1;  

  // Draw Eabs histogram in the pad 1
  c1->cd(1);
  hist1 = (TH1D*)f.Get("Energy_r");
  
  hist1 -> SetTitle("Without Shielding");
  hist1 -> GetXaxis() -> SetTitle("Energy/MeV");
  hist1 -> GetYaxis() -> SetTitle("count");
  hist1 -> GetXaxis() -> SetRangeUser(0,20);

  hist1->Draw("HIST");
  
  // Draw Labs histogram in the pad 2
  TFile g("crosstalk1/build/result/crosstalk.root");
  c1->cd(4);
  hist1 = (TH1D*)g.Get("Energy_r");

  hist1 -> SetTitle("With Shielding");
  hist1 -> GetXaxis() -> SetTitle("Energy/MeV");
  hist1 -> GetYaxis() -> SetTitle("count");
  hist1 -> GetXaxis() -> SetRangeUser(0,20);
  hist1->Draw("HIST");

  TFile h("crosstalk2/build/result/crosstalknoshield.root");
  c1->cd(2);
  hist1 = (TH1D*)h.Get("Energy_r");

  hist1 -> SetTitle("Without Shielding");
  hist1 -> GetXaxis() -> SetTitle("Energy/MeV");
  hist1 -> GetYaxis() -> SetTitle("count");
  hist1 -> GetXaxis() -> SetRangeUser(0,50);
  hist1->Draw("HIST");

  TFile j("crosstalk2/build/result/crosstalk.root");
  c1->cd(5);
  hist1 = (TH1D*)j.Get("Energy_r");

  hist1 -> SetTitle("With Shielding");
  hist1 -> GetXaxis() -> SetTitle("Energy/MeV");
  hist1 -> GetYaxis() -> SetTitle("count");
  hist1 -> GetXaxis() -> SetRangeUser(0,50);

  hist1->Draw("HIST");

  TFile k("crosstalk3/build/result/crosstalknoshield.root");
  c1->cd(3);
  hist1 = (TH1D*)k.Get("Energy_b");

  hist1 -> SetTitle("Without Shielding");
  hist1 -> GetXaxis() -> SetTitle("Energy/MeV");
  hist1 -> GetYaxis() -> SetTitle("count");
  hist1 -> GetXaxis() -> SetRangeUser(0,8);
  hist1->Draw("HIST");


  TFile l("crosstalk3/build/result/crosstalk.root");
  c1->cd(6);
  hist1 = (TH1D*)l.Get("Energy_b");

  hist1 -> SetTitle("With Shielding");
  hist1 -> GetXaxis() -> SetTitle("Energy/MeV");
  hist1 -> GetYaxis() -> SetTitle("count");
  hist1 -> GetXaxis() -> SetRangeUser(0,8);
  hist1->Draw("HIST");

  c1 -> SaveAs("./graph/comptoncrosstalk.gif");
 
}  
