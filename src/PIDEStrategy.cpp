#include"../inc/PIDEStrategy.h"
#include <boost/math/special_functions/gamma.hpp>
#include <boost/math/special_functions/expint.hpp>

bool PIDEStrategy::Initialize(const double spot_){ 
  isInit = false;  //if initialization fails, this will be false

  //fill trial-specific parameters
  spot = spot_;
  if(margin==0){ std::cout<<"Error.  Set Margin to Non-Zero Double and Re-execute Strategy."; return isInit; }
  if(spot==0){  std::cout<<"Error. Set Spot to Non-Zero Value."; return isInit; }
  if(_TheGrid == NULL){  std::cout<<"Grid is Null."; return isInit; }
  
  //set the domains of the grid
  //this also initializes DeltaX and DeltaTau to the appropriate values
  SetSpaceDomain((1.0-margin)*log(spot),(1.0+margin)*log(spot));
  SetTimeDomain(0,_TheOption->Expiry());
  
  //compute constants for numerical results
  lambda_p = Lambda('p');
  lambda_n = Lambda('n');
  //perform subprocedures to initialize constants
  FillGVectors(_TheGrid->Columns());
  ComputeB();
  
  //set up TriMatrix
  if(_TheMatrix!=NULL){  delete _TheMatrix; }
  size_t matrix_size = _TheGrid->Rows()-2;
  _TheMatrix = new TriMatrix(matrix_size);
  std::vector<double> low(matrix_size-1,-BL);
  std::vector<double> high(matrix_size-1,-BU);
  std::vector<double> diag;
  for(size_t i = 0; i!= matrix_size; ++i){ 
    double temp = 1.0 + r*DeltaTau + BL + BU;
    temp += DeltaTau/nu*(pow(lambda_n,y)*_g3[i+1]+pow(lambda_p,y)*_g4[matrix_size-i-1]);
    diag.push_back(temp);
  }
  _TheMatrix->Initialize(diag,low,high);
  _TheMatrix->Print(); 
  isInit = true;
  return isInit; 
}

double PIDEStrategy::Execute(Option& _option, const double spot_){ 
  //Set the option of choice
  SetOption(_option);

  //Check initialization status 
  if(!isInit || spot!=spot_){ //check if not initialized or different spot price 
    if(!Initialize(spot_)){ //initialize if not initialized
      std::cout<<"Initialization Failed.  Exiting with Value -1."; 
      return -1; 
    }  
  }
  
  //Compute Grid
  FillBoundaryValues();
  FillInteriorValues();
  return -5; 
}

void PIDEStrategy::FillInteriorValues(){ 
  for(unsigned int col_index = 1; col_index!=_TheGrid->Columns(); ++col_index){ 
    std::vector<double> W_j = _TheGrid->Column(col_index-1); 
    std::vector<double> temp(W_j.begin()+1,W_j.end()-1);
    temp = Solve(*_TheMatrix,temp);
    temp.push_back((*_TheGrid)(_TheGrid->Rows()-1,col_index));
    temp.insert(temp.begin(),(*_TheGrid)(0,col_index));
    _TheGrid->InsertColumn(temp, col_index);
  }  
}

void PIDEStrategy::FillBoundaryValues(){ 
  for(unsigned int i = 0; i!=_TheGrid->Rows(); ++i)
    (*_TheGrid)(i,0)=std::max(_TheOption->Strike()-exp(SpaceDomain.first+static_cast<double>(i)*DeltaX),0.0);
  for(unsigned int j = 1; j!=_TheGrid->Columns(); ++j){  
    (*_TheGrid)(0,j) = (*_TheGrid)(0,j-1);
    (*_TheGrid)(_TheGrid->Rows()-1,j) = (*_TheGrid)(_TheGrid->Rows()-1,j-1);
  }
}

double PIDEStrategy::Lambda(char toggle) const { 
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

double PIDEStrategy::R(const unsigned int i, const unsigned int j) const { 
  double val = 0;
  
  for(unsigned int k = 1; k!= i; ++k ){ 
    double temp = ((*_TheGrid)(i-k-1,j)-(*_TheGrid)(i-k,j));
    val += pow(lambda_n,y)*((*_TheGrid)(i-k,j)-(*_TheGrid)(i,j)-static_cast<double>(k)*temp)*(_g3[k-1]-_g3[k]); // k-1 since g vectors 0 ... N-1  
    val += temp/(pow(lambda_n,1.0-y)*DeltaX)*(_g1[k-1]-_g1[k]);
  }
/*  
  for(unsigned int k=1; k!=(_TheGrid->Columns()-i-1);++k){  
    double temp = ((*_TheGrid)(i+k+1,j)- (*_TheGrid)(i+k,j));
    val += pow(lambda_p,y)*((*_TheGrid)(i+k,j)-(*_TheGrid)(i,j)-static_cast<double>(k)*temp)*(_g4[k-1]-_g4[k]);
    val += temp/(pow(lambda_p,1.0-y)*DeltaX)*(_g2[k-1]-_g2[k]);
  }

  val+= _TheOption->Strike()*pow(lambda_n,y)*_g3[i-1]-exp(SpaceDomain.first+static_cast<double>(i)*DeltaX)*pow(lambda_n+1.0,y)*_g5[i-1];
  */ 
  return val;
}

double PIDEStrategy::ComputeInteriorPoint(const unsigned int i,const unsigned int j) const { 
 
 return R(i,j); 
}

double PIDEStrategy::ComputeBoundaryPoint(const unsigned int i, const unsigned int j) const { 
//TODO
  return 1;  
}

double PIDEStrategy::G1(const double x) const{ 
  return y == 0 ? std::exp(-x) : boost::math::tgamma(x,1.0-y);   
}

double PIDEStrategy::G2(const double x) const { 
  if(y==0){ return -boost::math::expint(-x);  }
  return(std::exp(-x)*std::pow(x,-y)/y- boost::math::tgamma(x,1.0-y)/y);
}

void PIDEStrategy::FillGVectors(const unsigned int length){ 
  double valp = DeltaX*lambda_p;
  double valn = DeltaX*lambda_n;

  for(unsigned int k = 1; k!=(length+1); ++k){  
    _g1.push_back(G1(static_cast<double>(k)*valn));
    _g2.push_back(G1(static_cast<double>(k)*valp));
    _g3.push_back(G2(static_cast<double>(k)*valn));
    _g4.push_back(G2(static_cast<double>(k)*valp));
    _g5.push_back(G2(static_cast<double>(k+1)*valn));
    _g6.push_back(G2(static_cast<double>(k+1)*valp));
  }  
}

void PIDEStrategy::ComputeB(){ 
  double val1 = sig_squared(DeltaX)*DeltaTau/(2.0*DeltaX*DeltaX);
  double val2 = (r-q+omega(DeltaX)-.5*sig_squared(DeltaX))*DeltaTau/(2.0*DeltaX);
  BL = val1 - val2;
  BU = val1 + val2;
  }

double PIDEStrategy::sig_squared(const double eps) const {  
  
  double retval;
  retval = pow(lambda_p,y-2.0)/nu*(-pow(lambda_p*eps,1.0-y)*exp(-lambda_p*eps)+(1.0-y)*(G1(0)-G1(lambda_p*eps)));
  retval += pow(lambda_n,y-2.0)/nu*(-pow(lambda_n*eps,1.0-y)*exp(-lambda_n*eps)+(1.0-y)*(G1(0)-G1(lambda_n*eps)));
  return retval;  
}

double PIDEStrategy::omega(const double eps) const { 
  double retval;
  retval = pow(lambda_p,y)/nu*G2(lambda_p*eps);
  retval -= pow(lambda_p - 1.0,y)/nu*G2((lambda_p-1.0)*eps);
  retval += pow(lambda_n,y)/nu*G2(lambda_n*eps);
  retval -= pow(lambda_n+1.0,y)/nu*G2((lambda_n+1.0)*eps); 
  return retval;
}


