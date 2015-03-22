#include "declarationlist.h"

void DeclarationList::addDeclaration(std::shared_ptr<Declaration> d) {
  m_decs.push_back(d);
}

void DeclarationList::getDeclarationTable(SymbolTable& m_table) const {
  /*for(auto it = m_decs.begin(); it != m_decs.end(); ++it) {
    m_table.appendList(*it->getDecList());
  }*/
}

void DeclarationList::toString(std::ostream &o) const {
  o << "DeclarationList([" << std::endl;
  for(auto dec : m_decs) {
    o << *dec << std::endl;
  }

  o << "])";
}
