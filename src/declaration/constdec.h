#ifndef CONSTDEC_H
#define CONSTDEC_H

class ConstDec : public Symbol {
  private:
    std::string name;
    std::string value;
    bool assigned;
};

#endif
