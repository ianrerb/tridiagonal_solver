#include "../inc/PIDEStrategy.h"
#include<vector>
#include<cmath>
using namespace std;

int main(){  
  double Spot = exp((log(260)+log(10))/2.0);
  EuropeanCall TheOption(100,1); 
  PIDEStrategy TheStrategy(.066,0.012,.3,.25,-.3,0);
  TheStrategy.Margin(log(260.0)/log(Spot)-1.0);
  TheStrategy.Verbose(true);  
  TheStrategy.NewGrid(250,300);
  cout<<TheStrategy.Execute(TheOption,Spot)<<endl;;
  return 0;
}



