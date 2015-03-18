#ifndef DECLARATION_LIST_H
#define DECLARATION_LIST_H

#include <vector>
#include "../symbol.h"
#include "declaration.h"

class DeclarationList : public Symbol {
  private:
    std::vector<Declaration> m_decs;
  public:
    DeclarationList() : Symbol(SymbolType::DL) {};
    DeclarationList(std::vector<Declaration> decList) : Symbol(SymbolType::DL), m_decs(decList) {};
    void addDeclaration(Declaration d) { m_decs.push_back(d); };
};

#endif
