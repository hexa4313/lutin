#ifndef _LUTIN_STATICANALYZER_H_
#define _LUTIN_STATICANALYZER_H_

#include "../parsing/ast/program.h"

class StaticAnalyzer {
  private:
    std::shared_ptr<Program> m_program;
    std::shared_ptr<DeclarationList> m_decList;
    std::shared_ptr<InstructionList> m_instList;
    void checkReadInstruction(std::shared_ptr<Instruction>);
    void checkWriteInstruction(std::shared_ptr<Instruction>);
    void checkAssignInstruction(std::shared_ptr<Instruction>);
    void checkLValueID(std::string id);
    void checkRValueVariables(std::vector<std::string> ids, std::shared_ptr<Instruction> instruction);
    bool isAssigned(std::string id, std::shared_ptr<Instruction> instruction);

  public:
    StaticAnalyzer(std::shared_ptr<Program> p) : m_program(p), m_decList(p->getDecList()), m_instList(p->getInstList()) {}
    void checkProgram();
};

#endif //_LUTIN_STATICANALYZER_H_
