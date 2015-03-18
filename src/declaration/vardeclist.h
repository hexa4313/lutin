#ifndef VARDECLIST_H
#define VARDECLIST_H

#import <list>

class VarDecList : public Declaration {
  private:
    std::list<VarDec> vars;
};

#endif
