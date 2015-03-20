#ifndef DECLARATION_LIST_H
#define DECLARATION_LIST_H

#include <vector>
#include <memory>
#include "../symbol.h"
#include "../interpreter/symboltable.h"
#include "declaration.h"

class DeclarationList : public Symbol {
  private:
    std::vector<std::shared_ptr<Declaration>> m_decs;
  public:
    DeclarationList() : Symbol(SymbolType::DL) {};
    void addDeclaration(std::shared_ptr<Declaration> d);
    void getDeclarationTable(SymbolTable& m_table) const;
};

#endif
