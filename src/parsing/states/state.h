#ifndef STATE_H
#define STATE_H

#include <string>
#include <ostream>
#include <memory>
#include "../ast/symbol.h"
#include "../statemachine.h"

class State {
  public:
    State(std::string name) : m_name(name) {};
    virtual ~State() {};
    friend std::ostream& operator<<(std::ostream& o, const State& s) {
      o << "State(" << s.m_name << ")";
      return o;
    }

    //Fonction de transitions entre les états de la transition
    //Doit set le nouvel état de l'automate
    //Et renvoyer un booléen pour la réussite de la transition
    virtual bool transition(StateMachine & stateMachine, std::shared_ptr<Symbol> s) = 0;
    std::string name() { return m_name; }

  protected:
    std::string m_name;
};

#endif