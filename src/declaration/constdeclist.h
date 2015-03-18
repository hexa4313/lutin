#ifndef CONSTDECLIST_H
#define CONSTDECLIST_H

#include <vector>
#include <string>
#include "declaration.h"
#include "constdec.h"

class ConstDecList : public Declaration {
  private:
    std::vector<std::shared_ptr<ConstDec>> m_consts;
  public:
    ConstDecList() : Declaration(SymbolType::C) {};
    void addConstDec(std::shared_ptr<ConstDec> c) { m_consts.push_back(c); };
};

#endif
