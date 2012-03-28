#include "../inc/PIDEStrategy.h"
#include<vector>

using namespace std;

int main(){  
  double Spot = 1300;
  EuropeanPut TheOption(1300,.5); 
  PIDEStrategy TheStrategy(.0025,0,.3,.4,-.3,0);
  TheStrategy.Margin(.99);
  TheStrategy.Verbose(true);  
  for(unsigned int N = 300; N<1001; N+=100){
    for(unsigned int M = 1000; M<3001; M+=1000){    
        TheStrategy.NewGrid(N,M);
	cout<<N<<" x "<<M<<endl;
	cout<<TheStrategy.Execute(TheOption,Spot)<<"\n\n\n"; 
    }
  }
  return 0;
}



