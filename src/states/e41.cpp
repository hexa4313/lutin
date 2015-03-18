#include "e41.h"
#include "../state.h"

E41::E41 (std::string name) : State(name)
{

}

bool E41::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

  switch(*s) {
    case ID : 
      stateMachine.setState(s, new E19);
      break;
    case E : 
      stateMachine.setState(s, new E32);
      break;
    case VAL : 
      stateMachine.setState(s, new E18);
      break;
    case PO : 
      stateMachine.setState(s, new E18);
      break;
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
