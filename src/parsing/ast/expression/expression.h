#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include "../symbol.h"
#include "../../../interpretation/symboltable.h"
#include "../declaration/declarationlist.h"
#include "../program.h"

class Expression : public Symbol {
  public:
    Expression(SymbolType t) : Symbol(t) {}
    virtual ~Expression() {}
    virtual std::vector<std::string> getIdentifiers() = 0;

    // Renvoie une nouvelle instance optimisée équivalente à l'instante courante
    virtual std::shared_ptr<Expression> optimize(std::shared_ptr<Program>, std::shared_ptr<Instruction>) = 0;
    virtual int eval(std::shared_ptr<SymbolTable> m_table) const = 0;
};

#endif
