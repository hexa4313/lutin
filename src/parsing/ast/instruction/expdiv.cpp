#include "expdiv.h"
#include "numericconst.h"

void ExpDiv::toString(std::ostream &o) const {
  o << *m_left << "/" << *m_right;
}

std::shared_ptr<Expression> ExpDiv::optimizeConstants(std::map<std::string, int> csts) {

  std::shared_ptr<Expression> left = m_left->optimizeConstants(csts);
  std::shared_ptr<Expression> right = m_right->optimizeConstants(csts);

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
