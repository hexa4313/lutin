#ifndef _LUTIN_STATICANALYZER_H_
#define _LUTIN_STATICANALYZER_H_

#include "../parsing/ast/program.h"

class StaticAnalyzer {
  private:
    std::shared_ptr<Program> m_program;
    void checkReadInstruction(std::shared_ptr<Instruction>);
    void checkWriteInstruction(std::shared_ptr<Instruction>);
    void checkAssignInstruction(std::shared_ptr<Instruction>);

  public:
    StaticAnalyzer(std::shared_ptr<Program> p) : m_program(p) {}
    void checkProgram();
};

#endif //_LUTIN_STATICANALYZER_H_
