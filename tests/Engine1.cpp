#include"../inc/OptionEngine.h"
#include"../inc/NumericStrategy.h"

using namespace std;

int main(){ 
  NumericStrategy TheStrategy;
  TheStrategy.NewGrid(10,10);
  OptionEngine TheEngine(TheStrategy);
  
  EuropeanPut a(100);  
  EuropeanPut b(200);

  TheEngine.AddOption(a);
  TheEngine.AddOption(b);
  
  TheEngine.PriceOptions(200);

  cout<<a.Premium()<<endl<<b.Premium()<<endl;
  return 0;
}
