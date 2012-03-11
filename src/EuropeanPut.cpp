#include "../inc/Option.h"

double EuropeanPut::Payoff(const double spot) const { return (spot < strike ? strike - spot : 0); }
