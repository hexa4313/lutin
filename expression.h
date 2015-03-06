#include "Symbol.h"

class Expression : public Symbol {
  public:
    Expression():Symbol(EXPRE) {}
    virtual ~Expression() {}
    virtual double eval(const map<string, double> & valeurs) = 0;
};
