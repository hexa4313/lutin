#ifndef VARDECLIST_H
#define VARDECLIST_H

#include <vector>
#include "declaration.h"

class VarDecList : public Declaration {
  private:
    std::vector<VarDec> m_vars;
  public:
    VarDecList() : Symbol(SymbolType::V) {};
    VarDecList(std::vector<VarDec> varVector): VarDecList(), m_vars(varVector) {};
    void addVarDec(VarDec v) { m_vars.push_back(v); };
};

#endif
