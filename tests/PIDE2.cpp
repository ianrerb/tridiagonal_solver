#include"../inc/OptionEngine.h"
#include"../inc/PIDEStrategy.h"

using namespace std;

int main(){
  double Spot = 1300;
  EuropeanPut TheOption(1300.0,.5);
  PIDEStrategy TheStrategy(0.0025,.015,.3,.4,-.3,0);
  TheStrategy.NewGrid(55,10);
  TheStrategy.Margin(.25);
  TheStrategy.Execute(TheOption,Spot);
  TheStrategy.PrintGrid();   
  return 0;
}
