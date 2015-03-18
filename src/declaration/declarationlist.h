#ifndef DECLARATION_LIST_H
#define DECLARATION_LIST_H

#include <vector>

#include "declaration.h"

class DeclarationList : public Symbol {
  public:
    DeclarationList() : Symbol(SymbolType::DL) {}
    void addDeclaration(Declaration d) { m_list.push_back(d); };
  private:
    std::vector<Declaration> m_list;
};

#endif
