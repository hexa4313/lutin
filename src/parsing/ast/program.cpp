#include "program.h"

#include "declaration/simpledec.h"
#include "instruction/read.h"

void Program::toString(std::ostream &o) const {
	o << *m_decList << *m_instList;
}

bool Program::StaticAnalysis(){
	//Take back every declaration
	auto declarations = m_decList->getDecs();

	//Take back every declared instructions
	auto instructions = m_instList->getInsts();

	//Check if every instructions' variables are declared
	for (auto instruction : instructions) {
		
		//Verify which type of instructions we have here
		if (instruction->getType() == SymbolType::I_R) {
			auto read = std::dynamic_pointer_cast <Read> (instruction);
			
			//Searching in the vector of declared variables if we find the variable used for read instruction
      auto dec = m_decList->getDec(read->getId());
      if(dec && dec->getType() == SymbolType::CST) {
        //Variable of read instruction found as a constant
        //Error : Impossible to modify a constant
      }
      else {
        //Variable of read instruction not found
        //Error : Variable not declared

      }

		} else if (instruction->getType() == SymbolType::I_W) {

		} else if (instruction->getType() == SymbolType::AFF) {

		}
	}
	return true;
}
