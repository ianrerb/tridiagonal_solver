#ifndef OPTIONENGINE_H
#define OPTIONENGINE_H
#include "PriceStrategy.h"
#include "Option.h"
#include<vector>

class OptionEngine {  
  public:
    OptionEngine( PriceStrategy& TheStrategy ):_strategy(&TheStrategy){  };
    ~OptionEngine(){   };

    OptionEngine& SetStrategy( PriceStrategy& TheStrategy){ _strategy = &TheStrategy; return *this; };
    OptionEngine& AddOption( Option& x){ _options.push_back(&x); return *this; };
    OptionEngine& ClearOptionList(){ _options.clear(); return *this; };
    OptionEngine& PriceOptions(); 
  
  private:
    PriceStrategy* _strategy;
    std::vector<Option*> _options;
};

#endif
