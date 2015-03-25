#ifndef SYMBOLTYPE_H
#define SYMBOLTYPE_H

// En cas de changement ici, ne pas oublier de changer dans Symbol.cpp la variable typeNames
enum class SymbolType {

  P,
  DL,
  IL,
  D,
  V,
  C,
  I,
  E,
  OP_A,
  OP_M,

  AFF,
  PV,
  VG,
  EQ,
  ADD,
  SUB,
  MUL,
  DIV,
  PO,
  PF,
  VAR,
  CST,
  W,
  R,
  I_R,
  I_W,
  ID,
  VAL,
  E_VAL,
  E_CNUM,
  E_PAR,

  EOF
};

#endif