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
  TFile f("build/B4.root");

  // Create a canvas and divide it into 2x2 pads
  TCanvas* c1 = new TCanvas("c1", "", 20, 20, 1000, 600);
  c1->Divide(2,1);
  
  // Draw Eabs histogram in the pad 1
  c1->cd(1);
  TH1D* hist1 = (TH1D*)f.Get("Energy_r");
  
  hist1 -> SetTitle("The Energy of Scattered gamma");
  hist1 -> GetXaxis() -> SetTitle("Energy/MeV");
  hist1 -> GetYaxis() -> SetTitle("count");
  hist1->Draw("HIST");
  
  // Draw Labs histogram in the pad 2
  c1->cd(2);
  TH1D* hist2 = (TH1D*)f.Get("CosTheta_r");
  hist2 -> SetTitle("The Direction of Scattered gamma");
  hist2 -> GetXaxis() -> SetTitle("cos theat");
  hist2 -> GetYaxis() -> SetTitle("count");
  hist2->Draw("HIST");
  
}  
