#include <boost/regex.hpp>
#include <fstream>
#include "lexer.h"

static std::pair<SymbolType, boost::regex> regexes[] = {
    std::make_pair(SymbolType::AFF, boost::regex("\\A\\s*(:=)\\s*")),
    std::make_pair(SymbolType::PV,  boost::regex("\\A\\s*(;)\\s*")),
    std::make_pair(SymbolType::VG,  boost::regex("\\A\\s*(,)\\s*")),
    std::make_pair(SymbolType::EQ,  boost::regex("\\A\\s*(=)\\s*")),
    std::make_pair(SymbolType::ADD, boost::regex("\\A\\s*(\\+)\\s*")),
    std::make_pair(SymbolType::SUB, boost::regex("\\A\\s*(-)\\s*")),
    std::make_pair(SymbolType::MUL, boost::regex("\\A\\s*(\\*)\\s*")),
    std::make_pair(SymbolType::DIV, boost::regex("\\A\\s*(/)\\s*")),
    std::make_pair(SymbolType::PO,  boost::regex("\\A\\s*(\\()\\s*")),
    std::make_pair(SymbolType::PF,  boost::regex("\\A\\s*(\\))\\s*")),
    std::make_pair(SymbolType::VAR, boost::regex("\\A\\s*(var)\\s+")),
    std::make_pair(SymbolType::CST, boost::regex("\\A\\s*(const)\\s+")),
    std::make_pair(SymbolType::W,   boost::regex("\\A\\s*(ecrire)\\s+")),
    std::make_pair(SymbolType::R,   boost::regex("\\A\\s*(lire)\\s+")),
    std::make_pair(SymbolType::ID,  boost::regex("\\A\\s*([a-zA-Z][a-zA-Z0-9]*)\\s*")),
    std::make_pair(SymbolType::VAL, boost::regex("\\A\\s*([0-9]+)\\s*"))
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

      //std::cout << "Lecture de " << *symbol << std::endl;

      m_curSymbol = symbol;

      m_content.erase(0, sm[0].length());

      return m_curSymbol;
    }
  }

  auto eof = std::make_shared<Symbol>(SymbolType::$);
  //std::cout << "Lecture de " << *eof << std::endl;
  return eof;
}

void Lexer::shift() {
  m_curSymbol = nullptr;
}