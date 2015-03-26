#include "symboltable.h"

#include "../parsing/ast/declaration/constdec.h"
#include "../parsing/ast/declaration/vardec.h"

void SymbolTable::appendVar(const std::string name, const int value) {
  m_table[name] = std::make_pair(value, SymbolType::VAR);
}

void SymbolTable::appendConst(const std::string name, const int value) {
  m_table[name] = std::make_pair(value, SymbolType::CST);
}

void SymbolTable::appendList(std::vector<std::shared_ptr<SimpleDec>> decsList) {
  for(auto symbol : decsList) {
    switch(symbol->getType()) {
      case SymbolType::CST: {
        auto c = std::dynamic_pointer_cast<ConstDec>(symbol);
        appendConst(c->getName(), c->getValue());
        break;
      }
      case SymbolType::VAR: {
        auto v = std::dynamic_pointer_cast<VarDec>(symbol);
        appendVar(v->getName(), 0);
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

int SymbolTable::get(const std::string name) const {
  return m_table.at(name).first;
}

void SymbolTable::set(const std::string name, const int value) {
  assert(m_table[name].second != SymbolType::CST);
  m_table[name].first = value;
}

void SymbolTable::print() const {
  for(auto elem : m_table) {
    std::cout << elem.first << "\t(" << elem.second.first << ", " << (int)elem.second.second << ")\n";
  }
}
