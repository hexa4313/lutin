#ifndef STATE_H
#define STATE_H

#include <string>
#include "statemachine.h"
#include "symbol.h"

class State {
  public:
    State(std::string name);
    virtual ~State();

    //Fonction de transitions entre les états de la transition
    //Doit set le nouvel état de l'automate
    //Et renvoyer un booléen pour la réussite de la transition
    virtual bool transition(StateMachine & stateMachine, Symbol * s) = 0;

  protected:
    std::string name;
};

#endif