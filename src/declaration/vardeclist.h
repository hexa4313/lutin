#ifndef VARDECLIST_H
#define VARDECLIST_H

#include <vector>
#include "vardec.h"
#include "declaration.h"

class VarDecList : public Declaration {
  private:
    std::vector<std::shared_ptr<VarDec>> m_vars;
  public:
    VarDecList() : Declaration(SymbolType::V) {};
    void addVarDec(std::shared_ptr<VarDec> v) { m_vars.push_back(v); };
    std::vector<std::shared_ptr<VarDec>> getVars() { return m_vars; };
};

#endif
