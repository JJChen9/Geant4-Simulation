 void  makespectrum()
{
//  TFile* in_file= new TFile("Poly_110_0.root");
  TFile *f = new TFile("Poly_110_0.root");
  TFile out_file("spectrum.root","RECREATE");

  TDirectory *dir = f -> GetDirectory("ke_r");
  TH2F *gr;
  dir -> GetObject("h2_ke_r_101",gr);
  
  gr -> Draw();  
//  spectrum = (TH1F *)( gr -> ProjectionX());

  TH1F *spectrum = (TH1F *)( gr -> ProjectionX("a",22,35,""));
  new TCanvas();
  spectrum -> Draw();

  spectrum -> Write();
  out_file.Close();

}




