#ifndef _LUTIN_OPTIMIZATOR_H_
#define _LUTIN_OPTIMIZATOR_H_

#include <memory>
#include "../parsing/ast/program.h"

class Optimizer {
  private:
    std::shared_ptr<Program> m_program;

  public:
    Optimizer(std::shared_ptr<Program> p) : m_program(p) {}
    void optimizeProgram();
};

#endif //_LUTIN_OPTIMIZATOR_H_