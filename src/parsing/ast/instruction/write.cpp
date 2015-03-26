#include "write.h"

void Write::toString(std::ostream &o) const {
  o << "ecrire " << *m_expr << ";";
}

int Write::eval(std::shared_ptr<SymbolTable> m_table) const {
  std::cout << m_expr->eval(m_table);
}
