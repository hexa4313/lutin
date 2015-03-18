#ifndef VARDECLIST_H
#define VARDECLIST_H

#include <vector>
#include "declaration.h"

class VarDecList : public Declaration {
  private:
    std::vector<VarDec> m_vars;
  public:
    VarDecList();
    VarDecList(std::vector<VarDec> varVector): m_vars(varVector) {};
    void addVarDec(VarDec v) { m_vars.push_back(v); };
};

#endif
