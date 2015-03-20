#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "symboltable.h"
#include "../program.h"

class Interpreter {
  private:
    std::shared_ptr<Program> m_program;
    SymbolTable m_table;
  public:
    Interpreter() {}
    Interpreter(std::shared_ptr<Program> prog) : m_program(prog) {}

    void init();
    bool step();
    void run();
};

#endif
