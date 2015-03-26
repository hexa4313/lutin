#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <memory>
#include "symboltable.h"
#include "../parsing/ast/program.h"

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
