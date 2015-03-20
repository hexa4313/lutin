#include <assert.h>
#include <map>
#include <memory>
#include <vector>
#include "../symbol.h"
#include "../declaration/vardec.h"
#include "../declaration/constdec.h"
#include "symboltable.h"

void SymbolTable::appendVar(const std::string name, const int value) {
  m_table[name] = std::make_pair(value, SymbolType::VAR);
}

void SymbolTable::appendConst(const std::string name, const int value) {
  m_table[name] = std::make_pair(value, SymbolType::CST);
}

void SymbolTable::appendList(std::vector<std::shared_ptr<Symbol>> decsList) {
  for(auto symbol : decsList) {
    switch(symbol->getType()) {
      case SymbolType::CST: {
        auto c = std::dynamic_pointer_cast<ConstDec>(symbol);
        appendConst(c->getName(), c->getValue());
        break;
      }
      case SymbolType::VAR: {
        auto v = std::dynamic_pointer_cast<VarDec>(symbol);
        appendVar(v->getName(), v->getValue());
        break;
      }
      default:
        assert(false);
    }
  }
}

int SymbolTable::get(const std::string name, bool &isConst) const {
  std::pair<int, SymbolType> entry = m_table.at(name);
  isConst = entry.second == SymbolType::CST;
  return entry.first;
}

void SymbolTable::set(const std::string name, const int value) {
  assert(m_table[name].second != SymbolType::CST);
  m_table[name].first = value;
}
