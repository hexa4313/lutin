#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include "../symbol.h"
#include "../../../interpreter/symboltable.h"

class Expression : public Symbol {
  public:
    Expression(SymbolType t) : Symbol(t) {}
    virtual ~Expression() {}
    virtual std::vector<std::string> getIdentifiers() = 0;
    virtual int eval(std::shared_ptr<SymbolTable> m_table) const = 0;
};

#endif
