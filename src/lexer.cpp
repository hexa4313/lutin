#include <regex>
#include <fstream>
#include <sstream>
#include "lexer.h"
#include "symboltype.h"

static std::pair<SymbolType, std::regex> regexes[] = {
    make_pair(SymbolType::AFF, std::regex("^:=")),
    make_pair(SymbolType::PV,  std::regex("^;")),
    make_pair(SymbolType::VG,  std::regex("^,")),
    make_pair(SymbolType::EQ,  std::regex("^=")),
    make_pair(SymbolType::ADD, std::regex("^+")),
    make_pair(SymbolType::SUB, std::regex("^-")),
    make_pair(SymbolType::MUL, std::regex("^*")),
    make_pair(SymbolType::DIV, std::regex("^/")),
    make_pair(SymbolType::PO,  std::regex("^\\(")),
    make_pair(SymbolType::PF,  std::regex("^)")),
    make_pair(SymbolType::VAR, std::regex("^var")),
    make_pair(SymbolType::CST, std::regex("^const")),
    make_pair(SymbolType::W,   std::regex("^ecrire")),
    make_pair(SymbolType::R,   std::regex("^lire")),
    make_pair(SymbolType::ID,  std::regex("^[a-zA-Z][a-zA-Z0-9]*")),
    make_pair(SymbolType::VAL, std::regex("^[0-9]+"))
};

Lexer::Lexer(std::string path) {
  std::ifstream f;
  f.open(path);

  std::stringstream stream;
  stream << f.rdbuf();
  m_content = stream.str();

  f.close();
}

std::shared_ptr<Symbol> Lexer::getSymbol() {

  if(m_curSymbol) {
    return m_curSymbol;
  }

  std::smatch sm;

  for(const auto& reg: regexes) {
    if(std::regex_match(m_content, sm, reg.second)) {

      auto symbol = std::make_shared<Symbol>(reg.first, sm[0]);
      m_curSymbol = symbol;

      m_content.erase(0, sm[0].length());

      return m_curSymbol;
    }
  }

  return std::make_shared<Symbol>(SymbolType::$);
}

void Lexer::shift() {
  m_curSymbol = nullptr;
}