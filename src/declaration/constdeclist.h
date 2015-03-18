#ifndef CONSTDECLIST_H
#define CONSTDECLIST_H

#import <list>

class ConstDecList : public Declaration {
  private:
    std::list<ConstDec> consts;
};

#endif
