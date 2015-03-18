#ifndef VARDEC_H
#define VARDEC_H

class VarDec : public Symbol {

  public:
    VarDec(std::string name) : m_name(name), m_assigned(false) {};

  private:
    std::string m_name;
    int m_value;
    bool m_assigned;
};

#endif
