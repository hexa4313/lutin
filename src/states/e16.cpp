#include "e16.h"
#include "../state.h"
#include "../instruction/instructionlist.h"
#include "../instruction/instruction.h"

bool E16::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto symbols = stateMachine.popSymbols(3);
  stateMachine.popStates(3);

  auto e1 = stateMachine.lastState();
  auto il = std::dynamic_pointer_cast<InstructionList>(symbols[2]);
  auto i =  std::dynamic_pointer_cast<Instruction>(symbols[1]);
  il->addInstruction(i);

  e1->transition(stateMachine, symbols[2]);

  return true;
}
