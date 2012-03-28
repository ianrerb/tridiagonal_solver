#ifndef NUMERICSTRATEGY_H
#define NUMERICSTRATEGY_H
#include "Option.h"
#include "Grid.h"
#include <iostream>
#include<utility>
#include<cmath>
//This class is abstract. It does not implement the virtual function Execute()

class NumericStrategy { 
  public:
    NumericStrategy(){_TheGrid = NULL; };
    //NumericStrategy(const NumericStrategy&);
    ~NumericStrategy(){delete _TheGrid; };

    virtual double Execute( Option& , const double) = 0;
    
    double dx() const {  return DeltaX; };  
    double dt() const { return DeltaTau; };

    double LowSpaceBound() const { return SpaceDomain.first; };
    double HighSpaceBound() const {  return SpaceDomain.second; };
    double LowTimeBound() const { return TimeDomain.first; };
    double HighTimeBound() const { return TimeDomain.second; };

    NumericStrategy& NewGrid(const unsigned int, const unsigned int);
    void PrintGrid() const { 
      double x = SpaceDomain.first;
      for(int i = 0; i!= _TheGrid->Rows(); ++i){  
	std::cout<<exp(x)<<": ";
	for(int j =0; j!= _TheGrid->Columns(); ++j){  
	  std::cout<<(*_TheGrid)(i,j)<<" ";
	}
	std::cout<<"\n";
	x+=DeltaX;
      }
    } 
  protected:
    NumericStrategy& SetOption( Option & option ){ _TheOption = &option; return *this;  }
    NumericStrategy& SetSpaceDomain(const double, const double);
    NumericStrategy& SetTimeDomain(const double, const double);
    NumericStrategy& RefreshDelta();
     
    //Member Variables 
    Option* _TheOption;
    Grid<double>* _TheGrid; //ptr to a grid instance
    std::pair<double,double>SpaceDomain; //lower and upper bounds on space domain
    std::pair<double,double>TimeDomain; //lower and upper bounds on time domain
    double DeltaX; //space step
    double DeltaTau; //time step
 };

#endif
