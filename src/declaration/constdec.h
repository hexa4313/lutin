#ifndef CONSTDEC_H
#define CONSTDEC_H

class ConstDec : public Symbol {
  public:
    ConstDec(std::string name, int value) : m_name(name), m_value(value) {}
  private:
    std::string m_name;
    int m_value;
};

#endif
