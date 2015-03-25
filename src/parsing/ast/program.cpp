#include "program.h"

void Program::toString(std::ostream &o) const {
	o << *m_decList << *m_instList;
}