#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <memory>
#include <map>
#include <string>
#include <vector>
#include "../parsing/ast/symboltype.h"
#include "../parsing/ast/symbol.h"

class SymbolTable {
  private:
    std::map<std::string, std::pair<int, SymbolType>> m_table;
  public:
//    const bool VAR = false;
//    const bool CONST = true;
    void appendVar(const std::string name, const int value);
    void appendConst(const std::string name, const int value);
    void appendList(std::vector<std::shared_ptr<Symbol>> list);
    int get(const std::string name, bool &isConst) const;
    void set(const std::string name, const int value);
    void print() const;
};

#endif
