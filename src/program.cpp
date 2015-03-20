#include <iostream>
#include <vector>
#include <boost/variant.hpp>

#include "program.h"

bool StaticAnalysis(){
	std::vector<std::shared_ptr<VarDec>> varDec = m_decList.getDecs().getVars();
	std::vector<std::shared_ptr<ConstDec>> constDec = m_instList.getDecs().getConsts();
	std::vector<std::shared_ptr<Instruction>> insts = m_instList.getInsts();

	//Check if read variable is declared

}
