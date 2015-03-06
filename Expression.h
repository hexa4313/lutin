#include "Symbole.h"

class Expression : public Symbole {
  public:
    Expression():Symbole(EXPRE) {}
    virtual ~Expression() {}
    virtual double eval(const map<string, double> & valeurs) = 0;
};
