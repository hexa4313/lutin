#ifndef VARDECLIST_H
#define VARDECLIST_H

#include <vector>
#include <memory>
#include "declaration.h"
#include "vardec.h"

class VarDecList : public Declaration {
  private:
    std::vector<std::shared_ptr<VarDec>> m_vars;
  public:
    VarDecList() : Declaration(SymbolType::V) {};
    void toString(std::ostream &o) const;
    void addVarDec(std::shared_ptr<VarDec> v) { m_vars.push_back(v); };
    std::vector<std::shared_ptr<SimpleDec>> getDecList() const {return std::vector<std::shared_ptr<SimpleDec>>(m_vars.begin(), m_vars.end());};
};

#endif
