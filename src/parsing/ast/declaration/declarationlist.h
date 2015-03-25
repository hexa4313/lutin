#ifndef DECLARATION_LIST_H
#define DECLARATION_LIST_H

#include <memory>
#include <vector>
#include <set>
#include "../symbol.h"
#include "declaration.h"
#include "../../../interpreter/symboltable.h"

class DeclarationList : public Symbol {
  private:
    std::vector<std::shared_ptr<Declaration>> m_decs;
    std::set<std::string> m_declaredIds;
  public:
    void toString(std::ostream &o) const;
    DeclarationList() : Symbol(SymbolType::DL) {};
    bool addDeclaration(std::shared_ptr<Declaration> d);
    void getDeclarationTable(SymbolTable& m_table) const;
    std::vector<std::shared_ptr<Declaration>> getDecs() { return m_decs; }

    bool isDeclared(std::string id) const;
    std::shared_ptr<SimpleDec> getDec(std::string id) const;
    std::vector<std::string> filterVariables(std::vector<std::string>) const;
};

#endif
