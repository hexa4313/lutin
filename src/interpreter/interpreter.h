#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <memory>
#include "symboltable.h"
#include "../parsing/ast/program.h"

class Interpreter {
  private:
    std::shared_ptr<Program> m_program;
    std::shared_ptr<SymbolTable> m_table;
    std::vector<std::shared_ptr<Instruction>> m_instructions;
  public:
    Interpreter() {}
    Interpreter(std::shared_ptr<Program> prog) : m_program(prog), m_table(std::make_shared<SymbolTable>()) {}

    void init();
    bool step();
    void run();
};

#endif
