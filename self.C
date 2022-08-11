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
  TFile f("build/result/photo347.root");

  // Create a canvas and divide it into 2x2 pads
  TCanvas* c1 = new TCanvas("c1", "", 20, 20, 1800, 1200);
  c1->Divide(3,2);
  
  // Draw Eabs histogram in the pad 1
  c1->cd(1);
  TH1D* hist1 = (TH1D*)f.Get("Energy_b");
  
  hist1 -> SetTitle("Without Shielding");
  hist1 -> GetXaxis() -> SetTitle("Energy/MeV");
  hist1 -> GetYaxis() -> SetTitle("count");
  hist1->Draw("HIST");
  
  // Draw Labs histogram in the pad 2
  c1->cd(2);
  TFile g("build/result/voidphoto347.root");

  TH1D* hist2  = (TH1D*)g.Get("Energy_b");

  hist2 -> SetTitle("Without the 2nd detector");
  hist2 -> GetXaxis() -> SetTitle("Energy/MeV");
  hist2 -> GetYaxis() -> SetTitle("count");
  hist2->Draw("HIST");

}  
