#ifndef CONSTDECLIST_H
#define CONSTDECLIST_H

#include <vector>
#include <memory>
#include "declaration.h"
#include "constdec.h"

class ConstDecList : public Declaration {
  private:
    std::vector<std::shared_ptr<ConstDec>> m_consts;
  public:
    ConstDecList() : Declaration(SymbolType::C) {};
    void toString(std::ostream &o) const;
    void addConstDec(std::shared_ptr<ConstDec> c) { m_consts.push_back(c); };
    std::vector<std::shared_ptr<SimpleDec>> getDecList() const {return std::vector<std::shared_ptr<SimpleDec>>(m_consts.begin(), m_consts.end());};
};

#endif
