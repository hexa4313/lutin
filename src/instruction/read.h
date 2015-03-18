#ifndef READ_H
#define READ_H

#include "variable.h"
#include "instruction.h"

class Read : public Instruction {
  private:
    bool m_is_declared;
    bool m_has_value;
    Variable m_destination;
  public:
    Read();
    Read(Variable destination): m_destination(destination);
};

#endif
