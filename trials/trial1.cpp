#include "../inc/PIDEStrategy.h"
#include<vector>

using namespace std;

int main(){  
  double Spot = 1300;
  EuropeanPut TheOption(1300,.5); 
  PIDEStrategy TheStrategy(.0025,.015,.3,.4,-.3,0);
  TheStrategy.Margin(.95);
  TheStrategy.Verbose(true);  
  for(unsigned int N = 100; N<1001; N*=2){
    for(unsigned int M = 100; M<10000; M*=2){    
        TheStrategy.NewGrid(N,M);
	cout<<N<<" x "<<M<<endl;
	cout<<TheStrategy.Execute(TheOption,Spot)<<"\n\n\n"; 
    }
  }
  return 0;
}



