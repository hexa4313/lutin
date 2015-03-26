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
    void getDeclarationTable(std::shared_ptr<SymbolTable> m_table) const;
    std::vector<std::shared_ptr<Declaration>> getDecs() { return m_decs; }
    std::set<std::string> getDeclaredIds() const { return m_declaredIds; };

    bool isDeclared(std::string id) const;
    std::map<std::string, int> getConstants();
    std::shared_ptr<SimpleDec> getDec(std::string id) const;
    std::vector<std::string> filterVariables(std::vector<std::string>) const;
    std::set<std::string> filterVariables(std::set<std::string> ids) const;
};

#endif
