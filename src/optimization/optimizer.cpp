#include "optimizer.h"
#include "../parsing/ast/instruction/write.h"
#include "../parsing/ast/instruction/assign.h"

void Optimizer::optimizeProgram() {
  auto declList = m_program->getDecList();
  auto instList = m_program->getInstList();

  auto instructions = instList->getInsts();

  for(auto instruction : instructions) {
    if(instruction->getType() == SymbolType::I_W) {
      auto write = std::dynamic_pointer_cast<Write>(instruction);
      auto optimized = write->getExpr()->optimize(declList);
      write->replaceExpr(optimized);
    }
    else if(instruction->getType() == SymbolType::AFF) {
      auto assign = std::dynamic_pointer_cast<Assign>(instruction);
      auto optimized = assign->getExpr()->optimize(declList);
      assign->replaceExpr(optimized);
    }
  }
}