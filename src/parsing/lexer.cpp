#include <boost/regex.hpp>
#include <fstream>
#include "lexer.h"
#include "ast/unknown.h"

static std::pair<SymbolType, boost::regex> regexes[] = {
    std::make_pair(SymbolType::AFF, boost::regex("\\A(:=)")),
    std::make_pair(SymbolType::PV,  boost::regex("\\A(;)")),
    std::make_pair(SymbolType::VG,  boost::regex("\\A(,)")),
    std::make_pair(SymbolType::EQ,  boost::regex("\\A(=)")),
    std::make_pair(SymbolType::ADD, boost::regex("\\A(\\+)")),
    std::make_pair(SymbolType::SUB, boost::regex("\\A(-)")),
    std::make_pair(SymbolType::MUL, boost::regex("\\A(\\*)")),
    std::make_pair(SymbolType::DIV, boost::regex("\\A(/)")),
    std::make_pair(SymbolType::PO,  boost::regex("\\A(\\()")),
    std::make_pair(SymbolType::PF,  boost::regex("\\A(\\))")),
    std::make_pair(SymbolType::VAR, boost::regex("\\A(var)\\s+")),
    std::make_pair(SymbolType::CST, boost::regex("\\A(const)\\s+")),
    std::make_pair(SymbolType::W,   boost::regex("\\A(ecrire)\\s+")),
    std::make_pair(SymbolType::R,   boost::regex("\\A(lire)\\s+")),
    std::make_pair(SymbolType::ID,  boost::regex("\\A([a-zA-Z][a-zA-Z0-9]*)")),
    std::make_pair(SymbolType::VAL, boost::regex("\\A([0-9]+)")),
    std::make_pair(SymbolType::END, boost::regex("\\A\\z"))
};

static boost::regex whitespace("\\A(\\s)");

Lexer::Lexer(std::string path) {
  std::ifstream f;
  f.open(path);

  std::stringstream stream;
  stream << f.rdbuf();
  m_content = stream.str();

  f.close();

  m_line = 1;
  m_char = 1;
}

std::shared_ptr<Symbol> Lexer::getSymbol() {

  if(m_curSymbol) {
    return m_curSymbol;
  }

  trim();

  for(const auto& reg: regexes) {
    boost::smatch sm;
    if(boost::regex_search(m_content, sm, reg.second)) {

      std::shared_ptr<Symbol> symbol;

      switch(reg.first) {
        case SymbolType::ID:
          symbol = std::make_shared<Symbol>(reg.first, sm[1]);
          break;
        case SymbolType::VAL:
          symbol = std::make_shared<Symbol>(reg.first, std::stoi(sm[1]));
          break;
        default:
          symbol = std::make_shared<Symbol>(reg.first);
      }
      symbol->setPosition(m_line, m_char);
      m_curSymbol = symbol;

      auto matchlen = sm[1].length();
      m_char += matchlen;
      m_content.erase(0, matchlen);

      return m_curSymbol;
    }
  }

  auto unknown = std::make_shared<Unknown>(m_content[0]);
  unknown->setPosition(m_line, m_char);
  m_content.erase(0, 1);
  return unknown;
}

void Lexer::shift() {
  m_curSymbol = nullptr;
}

void Lexer::trim() {
  boost::smatch sm;
  while(boost::regex_search(m_content, sm, whitespace)) {
    for (int i = 0; i < sm.length(); ++i) {
      if (sm[i] == "\n") {
        m_line++;
        m_char = 1;
      }
      else {
        m_char++;
      }
      m_content.erase(0, sm[i].length());
    }
  }
}
