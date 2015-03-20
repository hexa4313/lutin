#include "declarationlist.h"
#include "../interpreter/symboltable.h"

void addDeclaration(std::shared_ptr<Declaration> d) {
  m_decs.push_back(d);
};

void DeclarationList::getDeclarationTable(SymbolTable& m_table) const {
  std::vector<std::shared_ptr<Declaration>>::const_iterator it;
  for(it = m_decs.begin(); it != m_decs.end(); ++it) {
    m_table.appendList(*it.getDecList());
  }
}
