#include <regex>
#include <fstream>
#include "lexer.h"
#include "symboltype.h"

static std::pair<SymbolType, std::regex> regexes[] = {
    std::pair(SymbolType::AFF, std::regex("^:=")),
    std::pair(SymbolType::PV,  std::regex("^;")),
    std::pair(SymbolType::VG,  std::regex("^,")),
    std::pair(SymbolType::EQ,  std::regex("^=")),
    std::pair(SymbolType::ADD, std::regex("^+")),
    std::pair(SymbolType::SUB, std::regex("^-")),
    std::pair(SymbolType::MUL, std::regex("^*")),
    std::pair(SymbolType::DIV, std::regex("^/")),
    std::pair(SymbolType::PO,  std::regex("^(")),
    std::pair(SymbolType::PF,  std::regex("^)")),
    std::pair(SymbolType::VAR, std::regex("^var")),
    std::pair(SymbolType::CST, std::regex("^const")),
    std::pair(SymbolType::W,   std::regex("^ecrire")),
    std::pair(SymbolType::R,   std::regex("^lire")),
    std::pair(SymbolType::ID,  std::regex("^[a-zA-Z][a-zA-Z0-9]*")),
    std::pair(SymbolType::VAL, std::regex("^[0-9]+"))
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

}

void Lexer::next() {
  m_curSymbol = nullptr;
}