#include "../inc/OptionEngine.h"

//_options is a vector of pointers, so need to dereference it twice in for loop
OptionEngine& OptionEngine::PriceOptions(){ 
  for(std::vector<Option*>::iterator it = _options.begin(); it!=_options.end(); ++it) 
    (*it)->Premium( _strategy->Execute(**it) );
}
