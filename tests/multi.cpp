#include "../inc/PIDEStrategy.h"
#include<vector>

using namespace std;

int main(){  
  double Spot = 1300;
  EuropeanPut TheOption(1300,.5); 
  PIDEStrategy TheStrategy(.0025,.015,.3,.4,-.3,0);
  TheStrategy.Margin(.35);
  unsigned int N = 200;
//  for(unsigned int N = 100; N<300; N+=100){
    for(unsigned int M = 200; M< 5000; M*=2){    
      TheStrategy.NewGrid(N,M);
      cout<<"GRID SIZE ("<<N+1<<","<<M<<").  Computed Premium: ";
      cout<<TheStrategy.Execute(TheOption,Spot)<<endl;   
    }
 // }
    
  return 0;
}



