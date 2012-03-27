#include "../inc/PIDEStrategy.h"
#include <vector>

using namespace std;

int main(){
  double Spot = 1300;
  EuropeanPut TheOption(1300,.25);
  PIDEStrategy TheStrategy(0.0025,.015,.25,.35,-.25,0.0);
  TheStrategy.NewGrid(101,1000);
  TheStrategy.Verbose(true);
  vector<double>margin;
 
  margin.push_back(.25);
  
  for(vector<double>::iterator it = margin.begin(); it!= margin.end(); ++it){  
  TheStrategy.Margin(*it);
  cout<<TheStrategy.Execute(TheOption,Spot)<<"\n\n\n";
  }
  //TheStrategy.PrintGrid();  
  return 0;
}
