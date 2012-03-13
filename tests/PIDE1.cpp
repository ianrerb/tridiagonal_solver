#include"../inc/OptionEngine.h"
#include"../inc/PIDEStrategy.h"

using namespace std;

int main(){
  double Spot = 1300;
  EuropeanPut TheOption(1300.0,.5);
  PIDEStrategy TheStrategy(0.0025,.015,.3,.4-.3,0);
  TheStrategy.Initialize(Spot,.25,TheOption.Expiry(),20,10);
  OptionEngine TheEngine( TheStrategy );
  TheEngine.AddOption(TheOption);
  TheEngine.PriceOptions(); 
  return 0;
}
