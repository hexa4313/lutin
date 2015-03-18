#ifndef VARDEC_H
#define VARDEC_H

class VarDec : public Symbol {
  private:
    std::string name;
    std::string value;
    bool assigned;
};

#endif
