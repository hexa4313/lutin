#include "e21.h"
#include "../state.h"
#include "e3.h"

#include "../instruction/instructionlist.h"
#include "../instruction/instruction.h"
#include "../instruction/read.h"
#include "../instruction/variable.h"

bool E21::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  auto states = stateMachine.popStates(2);
  auto symbols = stateMachine.popSymbols(2);

  auto il = std::dynamic_pointer_cast<InstructionList>(stateMachine.lastSymbol());

  auto id = boost::get<std::string>(symbols[0]->getValue());
  auto read = std::make_shared<Read>(std::make_shared<Variable>(id));

  il->addInstruction(read);
  stateMachine.lastState()->transition(stateMachine, read);

  return false;
}
