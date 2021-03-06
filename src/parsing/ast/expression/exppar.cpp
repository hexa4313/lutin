#include "exppar.h"

void ExpPar::toString(std::ostream &o) const {
  o << "(" << *m_expr << ")";
}

std::vector<std::string> ExpPar::getIdentifiers() {
  return m_expr->getIdentifiers();
}

std::shared_ptr<Expression> ExpPar::optimize(std::shared_ptr<Program> program, std::shared_ptr<Instruction> curInst) {

  auto expr = m_expr->optimize(program, curInst);

  switch(expr->getType()) {
    case SymbolType::E_CNUM:
      return expr;
    case SymbolType::OP_M:
      return expr;
    default:
      return std::make_shared<ExpPar>(expr);
  }
}

int ExpPar::eval(std::shared_ptr<SymbolTable> m_table) const {
  return m_expr->eval(m_table);
}