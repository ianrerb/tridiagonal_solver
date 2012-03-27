#include "../inc/BermudanStrategy.h"
#include<vector>

using namespace std;

int main(){  
  double Spot = 1300;
  EuropeanPut TheOption(1300,.5); 
  BermudanStrategy TheStrategy(.03,.015,.3,.4,-.3,0);
  TheStrategy.Margin(.95);
  TheStrategy.Verbose(true);  
  TheStrategy.NewGrid(200,500);
  cout<<TheStrategy.Execute(TheOption,Spot)<<"\n\n\n"; 
  return 0;
}



