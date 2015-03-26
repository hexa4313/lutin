#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include <map>
#include "../symbol.h"

class Expression : public Symbol {
  public:
    Expression(SymbolType t) : Symbol(t) {}
    virtual ~Expression() {}
    virtual std::vector<std::string> getIdentifiers() = 0;

    // Renvoie une nouvelle instance optimisée équivalente à l'instante courante
    virtual std::shared_ptr<Expression> optimizeConstants(std::map<std::string, int>) = 0;
};

#endif
