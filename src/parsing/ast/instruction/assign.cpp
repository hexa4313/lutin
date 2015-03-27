#include "assign.h"

void Assign::toString(std::ostream &o) const {
  o << m_id << " := " << *m_expr << ";";
}

int Assign::eval(std::shared_ptr<SymbolTable> m_table) const {
  int val = m_expr->eval(m_table);
  m_table->set(m_id, val);
  return val;
}

void Assign::optimize(std::shared_ptr<Program> program) {
  m_expr = m_expr->optimize(program, shared_from_this());
}
