#ifndef PRICESTRATEGY_H
#define PRICESTRATEGY_H
#include "Option.h"

class PriceStrategy {  
  public:
    virtual double Execute( Option&, const double ) const = 0;
};

#endif
