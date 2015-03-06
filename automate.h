#IFNDEF AUTOMATE_H
#DEFINE AUTOMATE_H

class Automate {
	class State * s;
  	public:
		void setState(Symbole * symbole, State * state);
	private:
    		void lecture();
};

#ENDIF
