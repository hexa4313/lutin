#ifndef INSTRUCTION_LIST_H
#define INSTRUCTION_LIST_H

class InstructionList : public Symbol {
  public:
    void static_analysis(Program program);
  private:
    std::list<Instruction> instructions;
};

#endif
