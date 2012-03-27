#include"../inc/BermudanStrategy.h"
#include<cmath>

void BermudanStrategy::FillInteriorValues(){ 
  //perform implicit step for columns 1...end
  for(unsigned int col_index = 1; col_index!=_TheGrid->Columns(); ++col_index){ 
    std::vector<double> W_j = _TheGrid->Column(col_index-1); //last time step 
    std::vector<double> temp(W_j.begin()+PIDE_CUSHION,W_j.end()-PIDE_CUSHION); //leave off x0 and xN to be treated separately (boundary conditions)
    
    //add to each element in temp[i] the value R(i,-j)
    for(unsigned int i = 0; i!= temp.size(); ++i) 
      temp[i]+= R(i+PIDE_CUSHION,col_index-1)*DeltaTau/nu;
    
    temp = Solve(*_TheMatrix,temp);
    
    //compute x0 xN
    double end = temp.size()-1;
    double x0 = temp[0]*4.0/(2.0+DeltaX)-temp[1]*(2.0-DeltaX)/(2.0+DeltaX);
    double xN = temp[end]*4.0/(2.0+DeltaX)-temp[end-1]*(2.0-DeltaX)/(2.0+DeltaX);

    temp.push_back(xN);
    temp.insert(temp.begin(),x0);
    
    //Perform Bermudan Adjustment
    double x = SpaceDomain.first;
    for(std::vector<double>::iterator it = temp.begin(); it!= temp.end(); it++){  
      if(_TheOption->Payoff(exp(x)) > *it){ *it = _TheOption->Payoff(exp(x)); }  
      x +=DeltaX;
    }
    
    _TheGrid->InsertColumn(temp, col_index);
  }  
}

