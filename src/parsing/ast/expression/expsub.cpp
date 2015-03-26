#include "expsub.h"
#include "numericconst.h"
#include "expmult.h"

void ExpSub::toString(std::ostream &o) const {
  o << *m_left << "-" << *m_right;
}

std::shared_ptr<Expression> ExpSub::optimizeConstants(std::map<std::string, int> csts) {

  std::shared_ptr<Expression> left = m_left->optimizeConstants(csts);
  std::shared_ptr<Expression> right = m_right->optimizeConstants(csts);

  if(left->getType() == SymbolType::E_CNUM &&
      right->getType() == SymbolType::E_CNUM) {

    auto l = std::dynamic_pointer_cast<NumericConst>(left);
    auto r = std::dynamic_pointer_cast<NumericConst>(right);

    auto value = l->getValue() - r->getValue();
    if(value < 0) {
      return std::make_shared<ExpSub>(l, r);
    }
    else {
      return std::make_shared<NumericConst>(value);
    }
  }
  else {
    if(left->getType() == SymbolType::E_CNUM) {
      auto l = std::dynamic_pointer_cast<NumericConst>(left);
      if(l->getValue() == 0) {
        return std::make_shared<ExpMult>(std::make_shared<NumericConst>(-1), right);
      }
    }
    else if(right->getType() == SymbolType::E_CNUM) {
      auto r = std::dynamic_pointer_cast<NumericConst>(right);
      if(r->getValue() == 0) {
        return left;
      }
    }
    return std::make_shared<ExpSub>(left, right);
  }
}

int ExpSub::eval(std::shared_ptr<SymbolTable> m_table) const {
  return m_left->eval(m_table) - m_right->eval(m_table);
}