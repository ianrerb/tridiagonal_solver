#include "../inc/BermudanStrategy.h"
#include<vector>

using namespace std;

int main(){  
  double Spot = 1300;
  EuropeanPut TheOption(1300,.5); 
  BermudanStrategy TheStrategy(.03,.015,.3,.4,-.3,0);
  TheStrategy.Margin(.99);
  TheStrategy.Verbose(true);  
  
  vector<unsigned int> N;
  vector<unsigned int> M;

  N.push_back(200);
  N.push_back(300);
  N.push_back(400);

  M.push_back(500);
  M.push_back(800);
  M.push_back(1000);
  M.push_back(1500);

  for(vector<unsigned int>::iterator Nit = N.begin(); Nit!=N.end(); ++Nit){  
    for(vector<unsigned int>::iterator Mit = M.begin(); Mit!=M.end(); ++Mit){  
      TheStrategy.NewGrid(*Nit,*Mit);
      cout<<TheStrategy.Execute(TheOption,Spot)<<"\n\n";
    }
  }
  cout<<TheStrategy.Execute(TheOption,Spot)<<"\n\n\n"; 
  return 0;
}



