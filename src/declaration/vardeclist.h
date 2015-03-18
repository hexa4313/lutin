#ifndef VARDECLIST_H
#define VARDECLIST_H

#include <vector>

class VarDecList : public Declaration {
  private:
    std::vector<VarDec> m_vars;

  public:
    void addVarDec(VarDec v) { m_vars.push_back(v); };
};

#endif
