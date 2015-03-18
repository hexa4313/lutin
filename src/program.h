#ifndef PROGRAM_H
#define PROGRAM_H

#import "declaration/declarationlist.h"
#import "instruction/instructionlist.h"

class Program : public Symbol {
  public:
    check_var_dec();
  private:
    DeclarationList dec_list;
    InstructionList inst_list;
};

#endif
