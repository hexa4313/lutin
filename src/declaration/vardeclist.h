#ifndef VARDECLIST_H
#define VARDECLIST_H

#include <vector>
#include "vardec.h"
#include "declaration.h"

class VarDecList : public Declaration {
  private:
    std::vector<VarDec> m_vars;
  public:
    VarDecList() : Declaration(SymbolType::V) {};
    VarDecList(std::vector<VarDec> varVector) : Declaration(SymbolType::V), m_vars(varVector) {};
    void addVarDec(VarDec v) { m_vars.push_back(v); };
};

#endif
