#ifndef PRICESTRATEGY_H
#define PRICESTRATEGY_H
#include "Option.h"

class PriceStrategy {  
  public:
    PriceStrategy& SetOption( Option & option ){ _TheOption = &option; return *this;  }
    virtual double Execute( Option& , const double) = 0;
  protected:
    Option* _TheOption;
};

#endif
