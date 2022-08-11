 void gamma_read()
{
  TFile *input_file = new TFile("HPGe_gamma1.root","READ");

  cout<<"LaBr All :           \t"<<Edep_LaBr_All -> GetEntries()<<"\t"<<Edep_LaBr_All -> GetMean()<<endl;
  cout<<"LaBr BigHole:        \t"<<Edep_LaBr_BigHole   -> GetEntries()<<"\t"<<Edep_LaBr_BigHole -> GetMean()<<endl;
  cout<<"LaBr SmallHole:      \t"<<Edep_LaBr_SmallHole -> GetEntries()<<"\t"<<Edep_LaBr_SmallHole -> GetMean()<<endl;
  cout<<"LaBr SSC left:       \t"<<Edep_LaBr_SSC_Left  -> GetEntries()<<"\t"<<Edep_LaBr_SSC_Left -> GetMean()<<endl;
  cout<<"LaBr SSC right:      \t"<<Edep_LaBr_SSC_Right -> GetEntries()<<"\t"<<Edep_LaBr_SSC_Right -> GetMean()<<endl;
  cout<<"LaBr SSC top:        \t"<<Edep_LaBr_SSC_Top   -> GetEntries()<<"\t"<<Edep_LaBr_SSC_Top -> GetMean()<<endl;
  cout<<"LaBr SSC bottom:     \t"<<Edep_LaBr_SSC_Bottom-> GetEntries()<<"\t"<<Edep_LaBr_SSC_Bottom -> GetMean()<<endl;
  cout<<"LaBr Shield:         \t"<<Edep_LaBr_Shield    -> GetEntries()<<"\t"<<Edep_LaBr_Shield -> GetMean()<<endl;

  cout<<endl<<"#########################"<<endl;

  cout<<"HPGe All :           \t"<<Edep_HPGe_All -> GetEntries()<<"\t"<<Edep_HPGe_All -> GetMean()<<endl;
  cout<<"HPGe BigHole:        \t"<<Edep_HPGe_BigHole   -> GetEntries()<<"\t"<<Edep_HPGe_BigHole -> GetMean()<<endl;
  cout<<"HPGe SmallHole:      \t"<<Edep_HPGe_SmallHole -> GetEntries()<<"\t"<<Edep_HPGe_SmallHole -> GetMean()<<endl;
  cout<<"HPGe SSC left:       \t"<<Edep_HPGe_SSC_Left  -> GetEntries()<<"\t"<<Edep_HPGe_SSC_Left -> GetMean()<<endl;
  cout<<"HPGe SSC right:      \t"<<Edep_HPGe_SSC_Right -> GetEntries()<<"\t"<<Edep_HPGe_SSC_Right -> GetMean()<<endl;
  cout<<"HPGe SSC top:        \t"<<Edep_HPGe_SSC_Top   -> GetEntries()<<"\t"<<Edep_HPGe_SSC_Top -> GetMean()<<endl;
  cout<<"HPGe SSC bottom:     \t"<<Edep_HPGe_SSC_Bottom-> GetEntries()<<"\t"<<Edep_HPGe_SSC_Bottom -> GetMean()<<endl;
  cout<<"HPGe Shield:         \t"<<Edep_HPGe_Shield    -> GetEntries()<<"\t"<<Edep_HPGe_Shield -> GetMean()<<endl;

}
