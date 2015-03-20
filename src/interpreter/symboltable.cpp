#include <assert.h>
#include <map>
#include <memory>
#include <vector>
#include "../symbol.h"
#include "symboltable.h"

void SymbolTable::appendVar(const std::string name, const int value) {
  m_table[name] = std::make_pair(value, SymbolType::VAR);
}

void SymbolTable::appendConst(const std::string name, const int value) {
  m_table[name] = std::make_pair(value, SymbolType::CST);
}

void SymbolTable::appendList(std::vector<std::shared_ptr<Symbol>> decsList) {
  for(auto symbol : decsList) {
    switch(*symbol->getType()) {
      case SymbolType::CST:
        appendConst(*symbol->getName(), *symbol->getValue());
        break;
      case SymbolType::VAR:
        appendVar(*symbol->getName(), *symbol->getValue());
        break;
    }
  }
}

int SymbolTable::get(const std::string name, bool &isConst) throw(out_of_range) {
  std::pair<int, SymbolType> entry = m_table.at(name);
  isConst = entry->second == SymbolType::CST;
  return entry->first;
}

void SymbolTable::set(const std::string name, const int value) {
  assert(m_table[name]->second != SymbolType::CST);
  m_table[name]->first = value;
}
