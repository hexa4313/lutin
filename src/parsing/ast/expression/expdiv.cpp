#include "expdiv.h"
#include "numericconst.h"

#include <iostream>

void ExpDiv::toString(std::ostream &o) const {
  o << *m_left << "/" << *m_right;
}

std::shared_ptr<Expression> ExpDiv::optimize(std::shared_ptr<Program> program, std::shared_ptr<Instruction> curInst) {

  std::shared_ptr<Expression> left = m_left->optimize(program, curInst);
  std::shared_ptr<Expression> right = m_right->optimize(program, curInst);

  if(left->getType() == SymbolType::E_CNUM &&
      right->getType() == SymbolType::E_CNUM) {

    auto l = std::dynamic_pointer_cast<NumericConst>(left);
    auto r = std::dynamic_pointer_cast<NumericConst>(right);

    if(r->getValue() == 0) {
      std::cerr << "Division par 0!" << std::endl;
    }

    return std::make_shared<NumericConst>(l->getValue() / r->getValue());
  }
  else {
    if(left->getType() == SymbolType::E_CNUM) {
      auto l = std::dynamic_pointer_cast<NumericConst>(left);
      if(l->getValue() == 0) {
        return std::make_shared<NumericConst>(0);
      }
    }
    else if(right->getType() == SymbolType::E_CNUM) {
      auto r = std::dynamic_pointer_cast<NumericConst>(right);
      if(r->getValue() == 1) {
        return left;
      }
      else if(r->getValue() == 0) {
        std::cerr << "Division par 0!" << std::endl;
      }
    }
    return std::make_shared<ExpDiv>(left, right);
  }
}

int ExpDiv::eval(std::shared_ptr<SymbolTable> m_table) const {
  auto l = m_left->eval(m_table);
  auto r = m_right->eval(m_table);
  if(r == 0) {
    std::cerr << "Division par 0!" << std::endl;
    exit(1);
  }
  return l / r;
}