#include "staticanalyzer.h"

#include <algorithm>
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

  checkUninitializedVariables();
  checkUnusedVariables();
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

  m_affectedIds.insert(id);

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

  std::copy(ids.begin(), ids.end(), std::inserter(m_usedIds, m_usedIds.end()));

  auto vars = m_decList->filterVariables(ids);

  for(auto id : vars) {

    // Check for missing declaration
    if(!m_decList->isDeclared(id)) {
      std::cerr << "la variable " << id << " n'a pas ete declaree." << std::endl;
      return;
    }

    // Check for missing assignation
    if(!m_instList->lastAssignation(id, instruction)) {
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

void StaticAnalyzer::checkUnusedVariables() {
  auto allIds = m_decList->getDeclaredIds();
  std::set<std::string> unusedIds;
  std::set_difference(allIds.begin(), allIds.end(), m_usedIds.begin(), m_usedIds.end(),
      std::inserter(unusedIds, unusedIds.end()));

  for(auto id : unusedIds) {
    std::cerr << "variable non utilisee : " << id << std::endl;
  }
}

void StaticAnalyzer::checkUninitializedVariables() {
  auto varsIds = m_decList->filterVariables(m_decList->getDeclaredIds());

  std::set<std::string> unusedIds;
  std::set_difference(varsIds.begin(), varsIds.end(), m_affectedIds.begin(), m_affectedIds.end(),
      std::inserter(unusedIds, unusedIds.end()));

  for(auto id : unusedIds) {
    std::cerr << "variable non affectee : " << id << std::endl;
  }
}
