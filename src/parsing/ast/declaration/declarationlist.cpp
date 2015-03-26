#include "declarationlist.h"
#include "constdeclist.h"

#include <algorithm>

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

std::vector<std::string> DeclarationList::filterVariables(std::vector<std::string> ids) const {
  std::vector<std::string> varsOnly;
  for(auto id : ids) {
    auto dec = getDec(id);
    if(dec && dec->getType() == SymbolType::VAR) {
      varsOnly.push_back(id);
    }
  }
  return varsOnly;
}

std::set<std::string> DeclarationList::filterVariables(std::set<std::string> ids) const {
  std::set<std::string> varsOnly;
  for(auto id : ids) {
    auto dec = getDec(id);
    if(dec && dec->getType() == SymbolType::VAR) {
      varsOnly.insert(id);
    }
  }
  return varsOnly;
}

std::map<std::string, int> DeclarationList::getConstants() {
  std::map<std::string, int> constants;

  for(auto declaration : m_decs) {
    if(declaration->getType() == SymbolType::C) {
      auto constDecList = std::dynamic_pointer_cast<ConstDecList>(declaration);
      auto decs = constDecList->getDecList();
      for(auto dec : decs) {
        auto constDec = std::dynamic_pointer_cast<ConstDec>(dec);
        constants[constDec->getName()] = constDec->getValue();
      }
    }
  }

  return constants;
}
