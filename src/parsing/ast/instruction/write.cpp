#include "write.h"

void Write::toString(std::ostream &o) const {
  o << "ecrire " << *m_expr << ";";
}

int Write::eval(std::shared_ptr<SymbolTable> m_table) const {
  std::cout << m_expr->eval(m_table) << "\n";
  return 0;
}

void Write::optimize(std::shared_ptr<Program> program) {
  m_expr = m_expr->optimize(program, shared_from_this());
}