#ifndef CONSTDECLIST_H
#define CONSTDECLIST_H

#include <vector>

class ConstDecList : public Declaration {
  private:
    std::vector<ConstDec> m_consts;

  public:
    void addConstDec(ConstDec c) { m_consts.push_back(c); };
};

#endif
