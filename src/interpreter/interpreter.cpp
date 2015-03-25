#include "interpreter.h"

void Interpreter::init() {
  m_program->getDecList()->getDeclarationTable(m_table);
  m_table.print();
}

bool Interpreter::step() {

}

void Interpreter::run() {
  while(step() == true);
}
