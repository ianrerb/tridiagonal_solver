#ifndef NUMERICSTRATEGY_H
#define NUMERICSTRATEGY_H
#include "PriceStrategy.h"
#include "Grid.h"
#include <iostream>
#include<utility>
#include<cmath>

class NumericStrategy: public PriceStrategy { 
  public:
    NumericStrategy(){ };
    ~NumericStrategy(){ };
    
    NumericStrategy& NewGrid(const unsigned int, const unsigned int);
    double Execute( Option&, const double ) const;
    void PrintGrid() { std::cout<<TheGrid; };       

    NumericStrategy& SetSpaceDomain(const double, const double );
    NumericStrategy& SetTimeDomain(const double, const double );
    
  protected:
    Grid<double> TheGrid;
    std::pair<double,double>SpaceDomain;
    std::pair<double,double>TimeDomain;
 };

#endif
