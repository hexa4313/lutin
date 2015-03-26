#include "symbol.h"
#include <map>

static std::map<SymbolType, std::string> typeNames = {
    {SymbolType::P, "P"},
    {SymbolType::DL, "DL"},
    {SymbolType::IL, "IL"},
    {SymbolType::D, "D"},
    {SymbolType::V, "V"},
    {SymbolType::C, "C"},
    {SymbolType::I, "I"},
    {SymbolType::E, "E"},
    {SymbolType::OP_A, "OP_A"},
    {SymbolType::OP_M, "OP_M"},

    {SymbolType::AFF, "AFF"},
    {SymbolType::PV, "PV"},
    {SymbolType::VG, "VG"},
    {SymbolType::EQ, "EQ"},
    {SymbolType::ADD, "ADD"},
    {SymbolType::SUB, "SUB"},
    {SymbolType::MUL, "MUL"},
    {SymbolType::DIV, "DIV"},
    {SymbolType::PO, "PO"},
    {SymbolType::PF, "PF"},
    {SymbolType::VAR, "VAR"},
    {SymbolType::CST, "CST"},
    {SymbolType::W, "W"},
    {SymbolType::R, "R"},
    {SymbolType::I_R, "I_R"},
    {SymbolType::I_W, "I_W"},
    {SymbolType::ID, "ID"},
    {SymbolType::VAL, "VAL"},
    {SymbolType::E_VAL, "E_VAL"},
    {SymbolType::E_CNUM, "E_CNUM"},
    {SymbolType::E_PAR, "E_PAR"},

    {SymbolType::END, "END"}
};

boost::variant<int, std::string>  Symbol::getValue() const {
  assert(m_type == SymbolType::ID || m_type == SymbolType::VAL);

  return m_value;
}

void Symbol::toString(std::ostream &o) const {
  o << "Symbol(" << typeNames[m_type];
  if(m_type == SymbolType::ID || m_type == SymbolType::VAL) {
    o << ", " << getValue();
  }
  o << ")";
}