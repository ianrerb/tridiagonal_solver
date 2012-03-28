#include"../inc/BermudanStrategy.h"
#include<cmath>
#include<vector>

void BermudanStrategy::AmericanAdjustment(std::vector<double> &temp){ 
  //Perform Bermudan Adjustment
  double x = SpaceDomain.first;
  int critical = 0;
  
  for(std::vector<double>::iterator it = temp.begin(); it!= temp.end(); it++){  
    if(_TheOption->Payoff(exp(x)) > *it){ 
      *it = _TheOption->Payoff(exp(x)); 
      if(_TheOption->Type()=="Put"){ critical = x; }  
    x +=DeltaX;           
    }
  }
  CriticalBoundary.push_back(exp(x));
}  

