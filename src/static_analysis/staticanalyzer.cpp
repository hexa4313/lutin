#include "staticanalyzer.h"

#include "../parsing/ast/instruction/read.h"
#include "../parsing/ast/instruction/write.h"
#include "../parsing/ast/instruction/assign.h"

void StaticAnalyzer::checkProgram() {

  auto instList = m_program->getInstList();
  auto instructions = instList->getInsts();

  for (auto instruction : instructions) {
    switch(instruction->getType()) {
      case SymbolType::I_R:
        checkReadInstruction(instruction);
        break;
      case SymbolType::I_W:
        checkWriteInstruction(instruction);
        break;
      case SymbolType::AFF:
        checkAssignInstruction(instruction);
        break;
      default:
        assert(false);
    }
  }
}


void StaticAnalyzer::checkReadInstruction(std::shared_ptr<Instruction> instruction) {

  auto read = std::dynamic_pointer_cast <Read> (instruction);

  auto id = read->getId();
  checkLValueID(id);
}

void StaticAnalyzer::checkAssignInstruction(std::shared_ptr<Instruction> instruction) {

  auto assign = std::dynamic_pointer_cast <Assign> (instruction);

  auto id = assign->getId();
  checkLValueID(id);

  auto ids = assign->getExpr()->getIdentifiers();
  checkRValueVariables(ids, instruction);

}

void StaticAnalyzer::checkWriteInstruction(std::shared_ptr<Instruction> instruction) {

  auto write = std::dynamic_pointer_cast <Write> (instruction);

  auto ids = write->getExpr()->getIdentifiers();
  checkRValueVariables(ids, instruction);
}

void StaticAnalyzer::checkLValueID(std::string id) {
  auto dec = m_decList->getDec(id);
  if(dec) {
    if(dec->getType() == SymbolType::CST) {
      //Variable of read instruction found as a constant
      std::cerr << "affectation : la variable " << id << " est une constante" << std::endl;
    }
  }
  else {
    //Variable of read instruction not found
    std::cerr << "la variable " << id << " n'a pas ete declaree." << std::endl;
  }
}

void StaticAnalyzer::checkRValueVariables(std::vector<std::string> ids, std::shared_ptr<Instruction> instruction) {

  auto vars = m_decList->filterVariables(ids);

  for(auto id : vars) {

    // Check for missing declaration
    if(!m_decList->isDeclared(id)) {
      std::cerr << "la variable " << id << " n'a pas ete declaree." << std::endl;
      return;
    }

    // Check for missing assignation
    if(!isAssigned(id, instruction)) {
      std::shared_ptr<Expression> expr;

      if(instruction->getType() == SymbolType::AFF) {
        expr = std::dynamic_pointer_cast<Assign>(instruction)->getExpr();
      }
      else if(instruction->getType() == SymbolType::I_W) {
        expr = std::dynamic_pointer_cast<Write>(instruction)->getExpr();
      }
      else {
        assert(false);
      }

      std::cerr << "une valeur dans l'expression " << *expr << " n'est pas connue." << std::endl;
    }
  }
}

bool StaticAnalyzer::isAssigned(std::string id, std::shared_ptr<Instruction> instruction) {
  bool assigned = false;
  auto allInst = m_instList->getInsts();

  // Search in previous instructions for an assignation or a read instruction
  for(auto it = allInst.begin(); *it != instruction; ++it) {
    auto prevInstruction = *it;
    if(prevInstruction->getType() == SymbolType::I_R) {
      auto r = std::dynamic_pointer_cast <Read> (prevInstruction);
      if(r->getId() == id) {
        assigned = true;
      }
    }
    else if(prevInstruction->getType() == SymbolType::AFF) {
      auto aff = std::dynamic_pointer_cast <Assign> (prevInstruction);
      if(aff->getId() == id) {
        assigned = true;
      }
    }
  }

  return assigned;
}