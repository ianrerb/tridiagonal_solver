#ifndef BERMUDANSTRATEGY_H
#define BERMUDANSTRATEGY_H
#include<vector>
#include"PIDEStrategy.h"

class BermudanStrategy : public PIDEStrategy {
  public:
    BermudanStrategy(double r_=0, double q_=0, double sigma_=0, double nu_=0, double theta_=0, double y_=0):PIDEStrategy(r_,q_,sigma_,nu_,theta_,y_){  };
    
    std::vector<double> CriticalBoundary;
  protected:  
    void AmericanAdjustment(std::vector<double> &);
  };

#endif
