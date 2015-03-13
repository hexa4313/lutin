#include "e17.h"
#include "../state.h"

E17::E17 (std::string name) : State(name)
{

}
 
bool E17::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    case MUL :
      stateMachine.setState(s, new E25);
      break;
    case DIV :
      stateMachine.setState(s, new E26);
      break;
    case SUB :
      stateMachine.setState(s, new E27);
      break;
    case ADD :
      stateMachine.setState(s, new E28);
      break;
    case OPM :
      stateMachine.setState(s, new E29);
      break;
      
    default :
    /*
    depiler E9
    depiler E3
    stateMachine.setState(s, new E8);
    */
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
