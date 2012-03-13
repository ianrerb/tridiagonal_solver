#ifndef PRICESTRATEGY_H
#define PRICESTRATEGY_H
#include "Option.h"

class PriceStrategy {  
  public:
    virtual double Execute( Option& ) const = 0;
};

#endif
