#ifndef PIDESTRATEGY_H
#define PIDESTRATEGY_H
#include "NumericStrategy.h"
#include <cmath>

class PIDEStrategy : public NumericStrategy { 
  public:
    //constructor
    PIDEStrategy(double r_=0, double q_=0, double sigma_=0, double nu_=0, double theta_=0, double y_=0):NumericStrategy(),r(r_),q(q_),sigma(sigma_),nu(nu_),theta(theta_),y(y_){ };

    //interface implementation
    double Execute(Option&) const;

    //strategy initialization
    PIDEStrategy& Initialize(const double, const double, const double, unsigned int, unsigned int);
   
    //accessor functions
    double RiskFreeRate() const {  return r; };
    double DividendRate() const {  return q; };
    double Sigma() const {  return sigma; };
    double Nu() const {  return nu; };
    double Theta() const {  return theta; };
    double Y() const {  return y; };
    
    PIDEStrategy& RiskFreeRate(const double x) { r=x; return *this; };
    PIDEStrategy& DividendRate(const double x) { q=x; return *this; };
    PIDEStrategy& Sigma(const double x) { sigma=x; return *this; };
    PIDEStrategy& Nu(const double x) { nu=x; return *this; };
    PIDEStrategy& Theta(const double x) { theta=x; return *this; };
    PIDEStrategy& Y(const double x) { y=x; return *this; };


  private:
    double r, q, sigma, nu, theta, y;
    double spot, margin, expiry;    
    double lambda_p, lambda_n;    
    
    //helper functions for computing derivatives prices
    double ComputeLambda(char) const;

    double ComputeBoundaryPoint(const unsigned int, const unsigned int) const;
    double ComputeInteriorPoint(const unsigned int, const unsigned int) const;
};

#endif
