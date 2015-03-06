#include "automate.h"
#include "symbole.h"

class State {
  public:
    State(string name);
    virtual ~State();

    //Fonction de transitions entre les états de la transition
    //Doit set le nouvel état de l'automate
    //Et renvoyer un booléen pour la réussite de la transition
    virtual bool transition(Automate & automate, Symbole * s) = 0;

  protected:
    string name;
}
