#include "identifier.h"
#include "numericconst.h"
#include "../instruction/assign.h"

void Identifier::toString(std::ostream &o) const {
  o << m_name;
}

std::vector<std::string> Identifier::getIdentifiers() {
  std::vector<std::string> vars;
  vars.push_back(m_name);
  return vars;
}

std::shared_ptr<Expression> Identifier::optimize(std::shared_ptr<Program> program, std::shared_ptr<Instruction> curInst) {

  std::map<std::string, int> consts = program->getDecList()->getConstants();

  auto value = consts.find(m_name);

  if(value != consts.end()) {
    return std::make_shared<NumericConst>(consts[m_name]);
  }
  else {
    auto lastAssign = program->getInstList()->lastAssignation(m_name, curInst);

    if(lastAssign && lastAssign->getType() == SymbolType::AFF) {
      auto assign = std::dynamic_pointer_cast<Assign>(lastAssign);
      auto assignexpr = assign->getExpr();
      if(assignexpr->getType() == SymbolType::E_CNUM) {
        auto constNum = std::dynamic_pointer_cast<NumericConst>(assignexpr);
        return std::make_shared<NumericConst>(constNum->getValue());
      }
    }

    return std::make_shared<Identifier>(m_name);
  }
}

int Identifier::eval(std::shared_ptr<SymbolTable> m_table) const {
  return m_table->get(m_name);
}