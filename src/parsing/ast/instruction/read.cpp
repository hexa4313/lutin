#include "read.h"

#include <iostream>

void Read::toString(std::ostream &o) const {
  o << "lire " << m_id << ";";
}

int Read::eval(std::shared_ptr<SymbolTable> m_table) const {
  int x;
  std::cin >> x;
  while(std::cin.fail()) {
    std::cout << "Valeur non numerique." << std::endl;
    std::cin.clear();
    std::cin.ignore(256,'\n');
    std::cin >> x;
  }
  m_table->set(m_id, x);
  return x;
}