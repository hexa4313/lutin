#ifndef NUMERIC_H
#define NUMERIC_H

class NumericConst : public Expression {
  private:
    int m_value;
  public:
    NumericConst() : Expression(), m_type(SymbolType::E_CNUM) {}
    NumericConst(int value) : Expression(), m_type(SymbolType::E_CNUM), m_value(value) {}
};

#endif
