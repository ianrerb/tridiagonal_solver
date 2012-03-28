#include <boost/math/special_functions/expint.hpp>
#include<boost/math/special_functions/gamma.hpp>
#include<iostream>

using namespace std;

int main(){ 
  cout<<boost::math::tgamma(5,.01)<<endl;
  cout<<boost::math::expint(1)<<endl;
  return 0; 
  }
