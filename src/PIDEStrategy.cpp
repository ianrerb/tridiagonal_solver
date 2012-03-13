#include"../inc/PIDEStrategy.h"

PIDEStrategy& PIDEStrategy::Initialize(const double spot_, const double margin_, const double expiry_, unsigned int M_, unsigned int N_){ 
  NewGrid(M_,N_); 
  spot = spot_;
  margin=margin_;
  expiry = expiry_;
  SetSpaceDomain((1.0-margin)*log(spot),(1.0+margin)*log(spot));
  SetTimeDomain(0,expiry);
  lambda_p = ComputeLambda('p');
  lambda_n = ComputeLambda('n');

  return *this; 
}

double PIDEStrategy::Execute(Option& TheOption) const { 
  
  //fill in tau = 0 boundary conditions
  for(unsigned int i = 0; i!=_TheGrid->Rows(); ++i)
    (*_TheGrid)(i,0)=std::max(TheOption.Strike()-exp(SpaceDomain.first+static_cast<double>(i)*DeltaX),0.0);

  for(unsigned int i = 0; i!= _TheGrid->Rows(); ++i){ 
    for(unsigned int j = 1; j!= _TheGrid->Columns(); ++j){ 
      (*_TheGrid)(i,j) = (i==0 || (i ==_TheGrid->Rows()-1)) ? ComputeBoundaryPoint(i,j) : ComputeInteriorPoint(i,j);  
    }  
  }
  PrintGrid();
  return -5; 
}

double PIDEStrategy::ComputeLambda(char toggle) const { 
  double retval;
  retval = pow(theta/(sigma*sigma),2)+2/(pow(sigma,2)*nu);
  switch(toggle){ 
  case 'p':
    retval = pow(retval,.5) - theta/(sigma*sigma);
    break;
  
  case 'n':
    retval = pow(retval,.5) + theta/(sigma*sigma);
    break; 
  } 
  return retval;
}


//not implemented yet
double PIDEStrategy::ComputeInteriorPoint(const unsigned int i,const unsigned int j) const { 
 return 0; 
}

double PIDEStrategy::ComputeBoundaryPoint(const unsigned int i, const unsigned int j) const { 
  return 1;  
}
