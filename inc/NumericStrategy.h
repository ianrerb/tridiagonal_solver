#ifndef NUMERICSTRATEGY_H
#define NUMERICSTRATEGY_H
#include "PriceStrategy.h"
#include "Grid.h"
#include <iostream>
#include<utility>
#include<cmath>
//This class is abstract. It does not implement the virtual function Execute()

class NumericStrategy: public PriceStrategy { 
  public:
    NumericStrategy(){_TheGrid = NULL; _TheOption = NULL;};
    //NumericStrategy(const NumericStrategy&);
    ~NumericStrategy(){delete _TheGrid; };
    
    NumericStrategy& NewGrid(const unsigned int, const unsigned int);
    void PrintGrid() const { std::cout<<(*_TheGrid); }; 
   
  protected:
    NumericStrategy& SetSpaceDomain(const double, const double );
    NumericStrategy& SetTimeDomain(const double, const double);
    NumericStrategy& RefreshDelta();
     
    //Member Variables 
    Grid<double>* _TheGrid; //ptr to a grid instance
    std::pair<double,double>SpaceDomain; //lower and upper bounds on space domain
    std::pair<double,double>TimeDomain; //lower and upper bounds on time domain
    double DeltaX; //space step
    double DeltaTau; //time step
 };

#endif
