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

    {SymbolType::AFF, ":="},
    {SymbolType::PV, ";"},
    {SymbolType::VG, ","},
    {SymbolType::EQ, "="},
    {SymbolType::ADD, "+"},
    {SymbolType::SUB, "-"},
    {SymbolType::MUL, "*"},
    {SymbolType::DIV, "/"},
    {SymbolType::PO, "("},
    {SymbolType::PF, ")"},
    {SymbolType::VAR, "var"},
    {SymbolType::CST, "const"},
    {SymbolType::W, "ecrire"},
    {SymbolType::R, "lire"},
    {SymbolType::I_R, "I_R"},
    {SymbolType::I_W, "I_W"},
    {SymbolType::ID, "ID"},
    {SymbolType::VAL, "VAL"},
    {SymbolType::E_VAL, "E_VAL"},
    {SymbolType::E_CNUM, "E_CNUM"},
    {SymbolType::E_PAR, "E_PAR"},

    {SymbolType::END, "END"},
    {SymbolType::UNKNOWN, "UNKNOWN"}
    
};

boost::variant<int, std::string>  Symbol::getValue() const {
  //assert(m_type == SymbolType::ID || m_type == SymbolType::VAL);

  return m_value;
}

void Symbol::toString(std::ostream &o) const {
  o << typeNames[m_type];
  if(m_type == SymbolType::ID || m_type == SymbolType::VAL) {
    o << ", " << getValue();
  }
  //o << ")";
}
