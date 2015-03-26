#include "interpreter.h"

void Interpreter::init() {
  m_program->getDecList()->getDeclarationTable(m_table);
  m_instructions = m_program->getInstList()->getInsts();
}

bool Interpreter::step() {
  if(m_instructions.begin() == m_instructions.end()) {
    return false;
  }
  std::shared_ptr<Instruction> inst = m_instructions.front();
  inst->eval(m_table);
  m_instructions.erase(m_instructions.begin());
  return true;
}

void Interpreter::run() {
  while(step() == true);
}
