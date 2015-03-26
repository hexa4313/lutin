#include "interpreter.h"

void Interpreter::init() {
  m_program->getDecList()->getDeclarationTable(m_table);
  std::cout << "Execution\n";
  m_table.print();
}

bool Interpreter::step() {
  return true;
}

void Interpreter::run() {
  while(step() == true);
}
