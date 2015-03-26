#include "optimizer.h"
#include "../parsing/ast/instruction/write.h"
#include "../parsing/ast/instruction/assign.h"

void Optimizer::optimizeProgram() {
  auto instructions = m_program->getInstList()->getInsts();

  for(auto instruction : instructions) {
    instruction->optimize(m_program);
  }
}