#include<boost/math/special_functions/gamma.hpp>
#include<iostream>

using namespace std;

int main(){ 
  cout<<boost::math::tgamma(5,.01)<<endl;
  return 0; 
  }
