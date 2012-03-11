#ifndef NUMERICSTRATEGY_H
#define NUMERICSTRATEGY_H
#include "PriceStrategy.h"
#include "OptionGrid.h"
#include <iostream>

class NumericStrategy: public PriceStrategy { 
  public:
    NumericStrategy(double r_=0, double q_=0, double t_=0, double sigma_=0, double nu_=0, double theta_=0, double y_=0):r(r_),q(q_),t(t_),sigma(sigma_),nu(nu_),theta(theta_),y(y_),_TheGrid(NULL){ };
    ~NumericStrategy(){  };
    
    NumericStrategy& NewGrid(const unsigned int, const unsigned int);
    double Execute( Option&, const double ) const;
    void PrintGrid() const { std::cout<<(*_TheGrid); };       

    double RiskFreeRate() const {  return r; };
    double DividendRate() const {  return q; };
    double T() const {  return t; };
    double Sigma() const {  return sigma; };
    double Nu() const {  return nu; };
    double Theta() const {  return theta; };
    double Y() const {  return y; };
    
    NumericStrategy& RiskFreeRate(const double x) { r=x; return *this; };
    NumericStrategy& DividendRate(const double x) { q=x; return *this; };
    NumericStrategy& T(const double x) { t=x; return *this; };
    NumericStrategy& Sigma(const double x) { sigma=x; return *this; };
    NumericStrategy& Nu(const double x) { nu=x; return *this; };
    NumericStrategy& Theta(const double x) { theta=x; return *this; };
    NumericStrategy& Y(const double x) { y=x; return *this; };

  protected:
    OptionGrid * _TheGrid;
    double r, q, t, sigma, nu, theta, y;
 };

#endif