#include "declarationlist.h"

bool DeclarationList::addDeclaration(std::shared_ptr<Declaration> d) {

  for(auto dec : d->getDecList()) {
    std::string id = dec->getName();
    if(isDeclared(id)) {
      std::cerr << "la variable " << id << " est deja declaree";
    }
    m_declaredIds.insert(id);
  }
  m_decs.push_back(d);

  return true;
}

std::shared_ptr<SimpleDec> DeclarationList::getDec(std::string id) const {

  for(auto d : m_decs) {
    for (auto dec : d->getDecList()) {
      if(dec->getName() == id) {
        return dec;
      }
    }
  }

  return nullptr;
}

bool DeclarationList::isDeclared(std::string id) const {
  return m_declaredIds.find(id) != m_declaredIds.end();
}

void DeclarationList::getDeclarationTable(SymbolTable& m_table) const {
  /*for(auto it = m_decs.begin(); it != m_decs.end(); ++it) {
    m_table.appendList(*it->getDecList());
  }*/
}

void DeclarationList::toString(std::ostream &o) const {
  for(auto dec : m_decs) {
    o << *dec << std::endl;
  }
}
