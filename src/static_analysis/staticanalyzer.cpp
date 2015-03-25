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

  // Check r-value ID

  auto id = read->getId();
  auto dec = m_program->getDecList()->getDec(id);

  if(dec) {
    if(dec->getType() == SymbolType::CST) {
      //Variable of read instruction found as a constant
      std::cerr << "lire : la variable " << id << " est une constante" << std::endl;
    }
  }
  else {
    //Variable of read instruction not found
    std::cerr << "la variable " << id << " n'a pas ete declaree." << std::endl;
  }
}

void StaticAnalyzer::checkWriteInstruction(std::shared_ptr<Instruction> instruction) {
  auto write = std::dynamic_pointer_cast <Write> (instruction);

  // Check r-value expression

  auto declList = m_program->getDecList();
  auto variables = write->getExpr()->getVariables();
  for(auto id : variables) {
    if(!declList->isDeclared(id)) {
      std::cerr << "la variable " << id << " n'a pas ete declaree." << std::endl;
    }
  }

}

void StaticAnalyzer::checkAssignInstruction(std::shared_ptr<Instruction> instruction) {

  auto assign = std::dynamic_pointer_cast <Assign> (instruction);

  // Check l-value ID

  auto id = assign->getId();
  auto dec = m_program->getDecList()->getDec(id);

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

  // Check r-value expression

  auto declList = m_program->getDecList();
  auto variables = assign->getExpr()->getVariables();
  for(auto id : variables) {
    if(!declList->isDeclared(id)) {
      std::cerr << "la variable " << id << " n'a pas ete declaree." << std::endl;
    }
  }

}