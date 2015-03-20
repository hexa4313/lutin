#include "interpreter.h"

void Interpreter::init() {
  m_decList.getDeclarationTable(m_table);

}

bool Interpreter::step() {

}

void Interpreter::run() {
  while(step() == true);
}
