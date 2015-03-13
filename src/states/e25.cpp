#include "e25.h"
#include "../state.h"

E25::E25 (std::string name) : State(name)
{

}

bool E25::transition (StateMachine & stateMachine, Symbol * s) {

// E25 est juste un état final, il faut donc juste dépiler l'état E25 puis E17 et faire une transition vers E29 avec lecture du symbole OpM
// Dépile E25
// Dépile E17
// setState (OpM, new E29)
}
