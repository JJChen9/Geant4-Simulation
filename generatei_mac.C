#include<stdio.h>

 void generatei_mac()
{

TFile* in_file= new TFile("spectrum.root");

cout<<"/gps/particle gamma"<<endl;
cout<<"##########################"<<endl;
cout<<"/gps/position -1.465 0 0 cm"<<endl;
cout<<"/gps/direction 0 0 1"<<endl;

cout<<"/gps/ene/type Arb"<<endl;
cout<<"/gps/ene/diffspec 1"<<endl;
cout<<"/gps/hist/type arb"<<endl;
cout<<"##########################"<<endl;

a -> Rebin(2);
for(int i=0; i<=15;i++)
{
 cout<<"/gps/hist/point ";
 
 x = double(i)*4/1000;
 y = a -> GetBinContent(i);
 printf("%4.3lf  %.1lf\n",x,y);
}

a -> Rebin(15);

for(int i=2; i<=1000;i++)
{
 cout<<"/gps/hist/point ";

 x = double(i)*6/100;
 y = a -> GetBinContent(i);

 printf("%4.2lf  %.1lf\n",x,y);
}

cout<<"##########################"<<endl;
cout<<"/gps/hist/inter Lin"<<endl;

}




