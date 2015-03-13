#include "e38.h"
#include "../state.h"

E38::E38 (std::string name) : State(name)
{

}

bool E38::transition (StateMachine & stateMachine, Symbol * s) {

  switch(*s) {
    /*case "$" : 
      stateMachine.setState(s, ??);
      break;*/
    default :
    // TODO : gerer les erreurs
      break;
  }
  return false;
}
