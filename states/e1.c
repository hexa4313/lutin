#include "e1.h"

E1 (string name) : State(name)
{
	
}

E1::transition (Automate & automate, Symbole * s) {
	
	switch(*s) {
		case D : 
			automate.setState(s, new E2);
			break;
		case IL : 
			automate.setState(s, new E3);
			break;
		case VAR : 
			automate.setState(s, new E4);
			break;
		case CST : 
			automate.setState(s, new E5);
			break;
		default :
		// TODO : gerer les erreurs
			break;
	}
	return false;
}
