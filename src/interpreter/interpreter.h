#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "symboltable.h"
#include "../program.h"

class Interpreter {
  private:
    Program m_program;
    SymbolTable m_table;
  public:
    Interpreter() {}
    Interpreter(Program prog) : m_program(prog), m_table(new SymbolTable()) {}

    void init();
    void step();
    void run();
};

#endif
