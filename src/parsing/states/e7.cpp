#include "e7.h"
#include "../ast/program.h"
#include "../ast/declaration/declarationlist.h"
#include "../ast/instruction/instructionlist.h"

bool E7::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto symbols = stateMachine.popSymbols(3);
  auto dl = std::dynamic_pointer_cast<DeclarationList>(symbols[2]);
  auto il = std::dynamic_pointer_cast<InstructionList>(symbols[1]);
  auto p = std::make_shared<Program>(dl, il);
  stateMachine.accept(p);

  return true;

}
