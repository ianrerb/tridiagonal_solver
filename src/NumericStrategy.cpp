#include"../inc/NumericStrategy.h"

NumericStrategy& NumericStrategy::NewGrid(const unsigned int rows, const unsigned int columns){ 
  TheGrid = Grid<double>(rows,columns); 
  return *this;
}  

NumericStrategy& NumericStrategy::SetSpaceDomain(const double a, const double b){ 
  SpaceDomain.first = std::min(a,b);
  SpaceDomain.second = std::max(a,b);
  return *this;
}

NumericStrategy& NumericStrategy::SetTimeDomain(const double a, const double b=0){ 
  TimeDomain.first = std::min(a,b);
  TimeDomain.second = std::max(a,b);
  return *this;
}

double NumericStrategy::Execute(Option& theOption, const double spot) const{ 
  return -5;
}
