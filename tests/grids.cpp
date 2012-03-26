#include"../inc/PIDEStrategy.h"
#include<iostream>
using namespace std;

int main() {  
  double Spot = 1300;
  EuropeanPut TheOption(1300,.25);
  PIDEStrategy TheStrategy(0.0025,.015,.25,.35,-.25,0.0);
  TheStrategy.NewGrid(50,20);
  TheStrategy.Verbose(true);
   
  double margin1 = .25;
  double margin2 = .75;

  TheStrategy.Margin(margin1);
  cout<<TheStrategy.Execute(TheOption,Spot)<<"\n\n\n\n\n";
  TheStrategy.PrintGrid();

  TheStrategy.Margin(margin2);
  cout<<TheStrategy.Execute(TheOption,Spot)<<"\n\n\n\n\n";
  TheStrategy.PrintGrid();

  return 0;  
}
