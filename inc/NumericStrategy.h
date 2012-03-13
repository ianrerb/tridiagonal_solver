#ifndef NUMERICSTRATEGY_H
#define NUMERICSTRATEGY_H
#include "PriceStrategy.h"
#include "Grid.h"
#include <iostream>
#include<utility>
#include<cmath>

class NumericStrategy: public PriceStrategy { 
  public:
    NumericStrategy(){_TheGrid = NULL; };
    //NumericStrategy(const NumericStrategy&);
    ~NumericStrategy(){delete _TheGrid; };
    
    void PrintGrid() const { std::cout<<(*_TheGrid); }; 
    virtual double Execute( Option& ) const =0;

   
  protected:
    NumericStrategy& NewGrid(const unsigned int, const unsigned int);
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
