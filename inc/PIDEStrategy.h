#ifndef PIDESTRATEGY_H
#define PIDESTRATEGY_H
#include "NumericStrategy.h"
#include "TriSolver.h"
#include <cmath>
#include <vector>
#include <iostream>
#define PIDE_CUSHION 1


class PIDEStrategy : public NumericStrategy { 
  public:
    //constructor
    PIDEStrategy(double r_=0, double q_=0, double sigma_=0, double nu_=0, double theta_=0, double y_=0):NumericStrategy(),r(r_),q(q_),sigma(sigma_),nu(nu_),theta(theta_),y(y_),isInit(false), margin(0),_TheMatrix(NULL),verbose(false){ };

    //interface implementation
    double Execute(Option&, const double);
     
    //accessor functions
    double RiskFreeRate() const { return r; };
    double DividendRate() const { return q; };
    double Sigma() const { return sigma; };
    double Nu() const { return nu; };
    double Theta() const { return theta; };
    double Y() const { return y; };
    double Margin() const { return margin; };
    double Spot() const { return spot; }; 

    PIDEStrategy& Margin(const double x) { margin = x; return *this; };
    PIDEStrategy& RiskFreeRate(const double x) { r=x; return *this; };
    PIDEStrategy& DividendRate(const double x) { q=x; return *this; };
    PIDEStrategy& Sigma(const double x) { sigma=x; return *this; };
    PIDEStrategy& Nu(const double x) { nu=x; return *this; };
    PIDEStrategy& Theta(const double x) { theta=x; return *this; };
    PIDEStrategy& Y(const double x) { y=x; return *this; };
    PIDEStrategy& Verbose(const bool x) { verbose=x; return *this; };

  protected:
    bool verbose;
    double r, q, sigma, nu, theta, y, spot, margin; 
    double lambda_p, lambda_n;
    double BL,BU;
    std::vector<double> _g1, _g2, _g3, _g4, _g5, _g6;        
    mutable bool isInit;
    TriMatrix* _TheMatrix;     

    //helper functions for computing derivatives prices
    bool Initialize( const double );
    double Lambda(char) const;
    double G1(const double) const;
    double G2(const double) const;
    
    void FillGVectors(const unsigned int);
    void ComputeB(); 
    void FillInitialValues();
    virtual void FillInteriorValues(); //override in child strategies
     
    double sig_squared(const double) const;
    double omega(const double) const;
    double R(const unsigned int, const unsigned int) const;
    
};

#endif
