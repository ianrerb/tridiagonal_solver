#ifndef OPTION_H
#define OPTION_H
#include<string>

class Option {  
  public:
    Option(const double K,const double T):strike(K),expiry(T),premium(0){  };
    virtual ~Option(){  };
     
    virtual double Payoff(const double) const = 0;
    double Premium() const { return premium; };
    double Strike() const { return strike; };
    double Expiry() const {  return expiry;  };
    std::string Type() const {  return type_name;  };

    Option& Strike(const double k){  strike=k; return *this; };
    Option& Premium(const double x){ premium=x; return *this; };
    Option& Expiry(const double t){  expiry=t; return *this; };
  
  protected:
    std::string type_name;
    double strike, premium, expiry;
};

class EuropeanPut : public Option {  
  public:
    EuropeanPut(const double K, const double T):Option(K,T){ type_name="Put";  };  
    ~EuropeanPut(){  };
    double Payoff(const double spot) const;
};

class EuropeanCall : public Option {  
  public:
    EuropeanCall(const double K, const double T):Option(K,T){ type_name="Call";  };
    ~EuropeanCall(){  }
    double Payoff(const double spot) const;  
};

#endif
