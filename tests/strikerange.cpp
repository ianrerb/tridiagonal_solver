#include "../inc/PIDEStrategy.h"
#include <vector>

using namespace std;

int main(){
  double Spot = 1300;
  EuropeanPut TheOption(1300,.25);
  PIDEStrategy TheStrategy(0.0025,.015,.25,.35,-.25,0.0);
  TheStrategy.Margin(.20).Verbose(true).NewGrid(50,1000);
  vector<double> strike;
  strike.push_back(1100);
  strike.push_back(1150);
  strike.push_back(1200);
  strike.push_back(1250);
  strike.push_back(1300);

  for(vector<double>::iterator it = strike.begin(); it!= strike.end(); ++it){  
  TheOption.Strike(*it);
  cout<<TheStrategy.Execute(TheOption,Spot)<<"\n\n\n";
  }
  return 0;
}
