#ifndef CONSTDECLIST_H
#define CONSTDECLIST_H

#include <vector>
#include <string>
#include "declaration.h"

class ConstDecList : public Declaration {
  private:
    std::vector<ConstDec> m_consts;
  public:
    ConstDecList();
    ConstDecList(std::vector<ConstDec> constVector): m_consts(constVector) {};
};

#endif
