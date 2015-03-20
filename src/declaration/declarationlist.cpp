#include "declarationlist.h"

void DeclarationList::addDeclaration(std::shared_ptr<Declaration> d) {
  m_decs.push_back(d);
}

void DeclarationList::getDeclarationTable(SymbolTable& m_table) const {
  /*for(auto it = m_decs.begin(); it != m_decs.end(); ++it) {
    m_table.appendList(*it->getDecList());
  }*/
}
