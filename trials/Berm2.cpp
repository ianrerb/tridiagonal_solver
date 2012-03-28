#include "../inc/BermudanStrategy.h"
#include<vector>

using namespace std;

void RunTrial(unsigned int, unsigned int, double);
  
  //GLOBAL VARS
  double Spot = 1300;
  BermudanStrategy TheStrategy(.0025,0,.3,.4,-.3,0);
  EuropeanPut Option1100(1100,.5);
  EuropeanPut Option1200(1200,.5);
  EuropeanPut Option1300(1300,.5);
int main(){  
  
  TheStrategy.Margin(.99);
  TheStrategy.Verbose(true);

 
  RunTrial(500,1000,0);
  RunTrial(500,2000,0);
  RunTrial(500,3000,0);
  RunTrial(500,4000,0);
  
  return 0;
}

void RunTrial(unsigned int N, unsigned int M, double y){  
   TheStrategy.NewGrid(N,M);
   TheStrategy.Y(y);
    cout<<"****** Y= "<<TheStrategy.Y()<<" "<<"Grid= "<<N<<" x "<<M<<" ******\n"
	<<TheStrategy.Execute(Option1100,Spot)<<"\n\n"
        <<TheStrategy.Execute(Option1200,Spot)<<"\n\n"
	<<TheStrategy.Execute(Option1300,Spot)<<"\n\n";
  }



