#ifndef VARDEC_H
#define VARDEC_H

#include <string>
#include "simpledec.h"

class VarDec : public SimpleDec {
  private:
    std::string m_name;
  public:
    VarDec(std::string name): SimpleDec(SymbolType::VAR), m_name(name) {};
    void toString(std::ostream &o) const;
    std::string getName() const {return m_name;}
};

#endif
