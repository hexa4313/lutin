#include "e25.h"
#include "../state.h"

bool E25::transition (StateMachine & stateMachine, std::shared_ptr<Symbol> s) {

// E25 est juste un état final, il faut donc juste dépiler l'état E25 puis E17 et faire une transition vers E29 avec lecture du symbole OpM
// Dépile E25
// Dépile E17
// setState (OpM, std::make_shared<E29>())
}
