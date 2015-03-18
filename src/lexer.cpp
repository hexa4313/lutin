#include <boost/regex.hpp>
#include <fstream>
#include <sstream>
#include "lexer.h"
#include "symboltype.h"

static std::pair<SymbolType, boost::regex> regexes[] = {
    std::make_pair(SymbolType::AFF, boost::regex("^:=")),
    std::make_pair(SymbolType::PV,  boost::regex("^;")),
    std::make_pair(SymbolType::VG,  boost::regex("^,")),
    std::make_pair(SymbolType::EQ,  boost::regex("^=")),
    std::make_pair(SymbolType::ADD, boost::regex("^\\+")),
    std::make_pair(SymbolType::SUB, boost::regex("^-")),
    std::make_pair(SymbolType::MUL, boost::regex("^\\*")),
    std::make_pair(SymbolType::DIV, boost::regex("^/")),
    std::make_pair(SymbolType::PO,  boost::regex("^\\(")),
    std::make_pair(SymbolType::PF,  boost::regex("^\\)")),
    std::make_pair(SymbolType::VAR, boost::regex("^var")),
    std::make_pair(SymbolType::CST, boost::regex("^const")),
    std::make_pair(SymbolType::W,   boost::regex("^ecrire")),
    std::make_pair(SymbolType::R,   boost::regex("^lire")),
    std::make_pair(SymbolType::ID,  boost::regex("^[a-zA-Z][a-zA-Z0-9]*")),
    std::make_pair(SymbolType::VAL, boost::regex("^[0-9]+"))
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

  boost::smatch sm;

  for(const auto& reg: regexes) {
    if(boost::regex_match(m_content, sm, reg.second)) {

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