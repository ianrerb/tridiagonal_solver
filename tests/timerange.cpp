#include "../inc/PIDEStrategy.h"
#include <vector>

using namespace std;

int main(){
  double Spot = 1300;
  EuropeanPut TheOption(1300,.25);
  PIDEStrategy TheStrategy(0.0025,.015,.25,.35,-.25,0.0);
  TheStrategy.Margin(.25);
  TheStrategy.Verbose(true);
  vector<unsigned int> tau;
  tau.push_back(100);
  tau.push_back(500);
  tau.push_back(2000);

  for(vector<unsigned int>::iterator it = tau.begin(); it!= tau.end(); ++it){  
  TheStrategy.NewGrid(100,*it);
  cout<<TheStrategy.Execute(TheOption,Spot)<<"\n\n\n";
  }
  return 0;
}
