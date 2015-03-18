#ifndef CONSTDECLIST_H
#define CONSTDECLIST_H

#include <vector>
#include <string>
#include "declaration.h"
#include "constdec.h"

class ConstDecList : public Declaration {
  private:
    std::vector<ConstDec> m_consts;
  public:
    ConstDecList();
    ConstDecList(std::vector<ConstDec> constVector): m_consts(constVector) {};
    void addConstDec(ConstDec c) { m_consts.push_back(c); };
};

#endif
