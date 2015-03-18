#ifndef STATE_H
#define STATE_H

#include <memory>
#include <string>
#include "statemachine.h"
#include "symbol.h"

class StateMachine;

class State {
  public:
    State(std::string name) : m_name(name) {};
    virtual ~State() {};

    //Fonction de transitions entre les états de la transition
    //Doit set le nouvel état de l'automate
    //Et renvoyer un booléen pour la réussite de la transition
    virtual bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s) = 0;

  protected:
    std::string m_name;
};

#endif