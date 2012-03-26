#include "../inc/PIDEStrategy.h"
#include <vector>
#include <cmath>
using namespace std;

int main(){
  double Spot = 1300;
  EuropeanPut TheOption(1300,.25);
  PIDEStrategy LowMarginStrategy(0.0025,.015,.25,.35,-.25,0.0);
  PIDEStrategy HighMarginStrategy(0.0025,.015,.25,.35,-.25,0.0);
  LowMarginStrategy.Verbose(true);
  HighMarginStrategy.Verbose(true);
  unsigned int rows = 100;
  unsigned int cols = 200;

  double low_margin = .15;
  double high_margin = .75;

  LowMarginStrategy.Margin(low_margin);
  HighMarginStrategy.Margin(high_margin);
  LowMarginStrategy.NewGrid(rows,cols);
  
  unsigned int high_size = floor(high_margin/low_margin*rows);
  HighMarginStrategy.NewGrid(high_size, cols);
  
  cout<<LowMarginStrategy.Execute(TheOption, Spot)<<"\n\n";
  cout<<HighMarginStrategy.Execute(TheOption, Spot)<<"\n\n";

  return 0;
}
