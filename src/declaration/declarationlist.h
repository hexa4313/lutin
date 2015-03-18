#ifndef DECLARATION_LIST_H
#define DECLARATION_LIST_H

#include <vector>
#include "../symbol.h"
#include "declaration.h"

class DeclarationList : public Symbol {
  private:
    std::vector<std::shared_ptr<Declaration>> m_decs;
  public:
    DeclarationList() : Symbol(SymbolType::DL) {};
    void addDeclaration(std::shared_ptr<Declaration> d) { m_decs.push_back(d); };
};

#endif
