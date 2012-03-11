#include"../inc/NumericStrategy.h"

using namespace std;

int main(){  
  EuropeanPut TheOption(1300);
  NumericStrategy TheStrategy;
  TheStrategy.NewGrid(10,10);
  TheStrategy.SetSpaceDomain(5,25);
  TheStrategy.PrintGrid();
  return 0;  
}
