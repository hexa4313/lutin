#ifndef DECLARATION_LIST_H
#define DECLARATION_LIST_H

#include <vector>
#include "../symbol.h"

class DeclarationList : public Symbol {
  private:
    std::vector<Declaration> m_list;
  public:
    DeclarationList();
    DeclarationList(std::vector<Declaration> decList): m_list(decList);
};

#endif
