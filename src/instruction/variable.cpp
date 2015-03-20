#include "variable.h"

std::vector<std::shared_ptr<Variable>> getAllVar() {
	std::vector<std::shared_ptr<Variable>> variable;
	variable.push_back(*this);
	
	return variable;
}
