#include"../inc/NumericStrategy.h"

NumericStrategy& NumericStrategy::NewGrid(const unsigned int rows, const unsigned int columns){ 
  delete _TheGrid; 
  _TheGrid = new OptionGrid(rows,columns); 
}  

double NumericStrategy::Execute(Option& theOption, const double spot) const{ 
  if(_TheGrid==0){ throw("Grid Not Initialized."); }
  _TheGrid->Reset();
  return -5;
}
