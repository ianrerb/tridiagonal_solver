#include "../inc/PIDEStrategy.h"
#include<vector>

using namespace std;

int main(){  
  double Spot = 100;
  EuropeanCall TheOption(90,.083333); 
  PIDEStrategy TheStrategy(.1,0,.12,.2,-.14,0);
  TheStrategy.Margin(.99);
  TheStrategy.Verbose(true);  
  for(unsigned int N = 500; N<501; N+=25){
    for(unsigned int M = 100; M<5000; M*=2){    
        TheStrategy.NewGrid(N,M);
	cout<<N<<" x "<<M<<endl;
	cout<<TheStrategy.Execute(TheOption,Spot)<<"\n\n\n"; 
    }
  }
  return 0;
}



