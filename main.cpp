#include "inc/PIDEStrategy.h"
#include<vector>

using namespace std;

int main(){  
  double Spot = 1300;
  EuropeanPut TheOption(1300,.5); 
  PIDEStrategy TheStrategy(.0025,.015,.3,.4,-.3,0);

  vector<double> margin;
  margin.push_back(.15);
  margin.push_back(.25);
  margin.push_back(.35);
  margin.push_back(.45);

  

  cout<<TheStrategy.Execute(TheOption,Spot)<<"\n\n";

  return 0;
  }



