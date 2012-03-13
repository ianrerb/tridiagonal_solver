#include"../inc/NumericStrategy.h"

NumericStrategy& NumericStrategy::NewGrid(const unsigned int rows, const unsigned int columns){ 
  if(_TheGrid != NULL){  delete _TheGrid; }
  _TheGrid = new Grid<double>(rows,columns); 
  return RefreshDelta();
}  

NumericStrategy& NumericStrategy::SetSpaceDomain(const double a, const double b){ 
  SpaceDomain.first = std::min(a,b);
  SpaceDomain.second = std::max(a,b);
  return RefreshDelta();
}

NumericStrategy& NumericStrategy::SetTimeDomain(const double a, const double b=0){ 
  TimeDomain.first = std::min(a,b);
  TimeDomain.second = std::max(a,b);
  return RefreshDelta();
}

NumericStrategy& NumericStrategy::RefreshDelta(){ 
  if(_TheGrid == NULL){ DeltaX = DeltaTau = 0; return *this; }
  double N = _TheGrid->Rows()-1.0;
  double M = _TheGrid->Columns()-1.0;

  DeltaX = (SpaceDomain.second - SpaceDomain.first)/N;
  DeltaTau = (TimeDomain.second - TimeDomain.first)/M;
  return *this;
}
