#ifndef WRITE_H
#define WRITE_H

#include <string>
#include "instruction.h"

class Write : public Instruction {
  private:
    std::string m_buffer;
  public:
    Write(std::string buffer): m_buffer(buffer);
};

#endif
