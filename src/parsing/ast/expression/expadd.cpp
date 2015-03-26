#include "expadd.h"
#include "numericconst.h"

void ExpAdd::toString(std::ostream &o) const {
  o << *m_left << "+" << *m_right;
}

std::shared_ptr<Expression> ExpAdd::optimize(std::shared_ptr<DeclarationList> declList) {

  std::shared_ptr<Expression> left = m_left->optimize(declList);
  std::shared_ptr<Expression> right = m_right->optimize(declList);

  if(left->getType() == SymbolType::E_CNUM &&
      right->getType() == SymbolType::E_CNUM) {

    auto l = std::dynamic_pointer_cast<NumericConst>(left);
    auto r = std::dynamic_pointer_cast<NumericConst>(right);

    return std::make_shared<NumericConst>(l->getValue() + r->getValue());
  }
  else {
    if(left->getType() == SymbolType::E_CNUM) {
      auto l = std::dynamic_pointer_cast<NumericConst>(left);
      if(l->getValue() == 0) {
        return right;
      }
    }
    else if(right->getType() == SymbolType::E_CNUM) {
      auto r = std::dynamic_pointer_cast<NumericConst>(right);
      if(r->getValue() == 0) {
        return left;
      }
    }
    return std::make_shared<ExpAdd>(left, right);
  }
}

int ExpAdd::eval(std::shared_ptr<SymbolTable> m_table) const {
  return m_left->eval(m_table) + m_right->eval(m_table);
}
