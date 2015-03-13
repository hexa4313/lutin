#ifndef DECLARATION_LIST_H
#define DECLARATION_LIST_H

class DeclarationList : public Symbol {
  private:
    std::list<Declaration> list;
};

#endif
