#include <regex>
#include <fstream>
#include "lexer.h"

static std::regex keyword("^(var|const|ecrire|lire)");
static std::regex id("^[a-zA-Z][a-zA-Z0-9]*");
static std::regex val("^[0-9]+");
static std::regex pv("^;");
static std::regex aff(":=");

Lexer::Lexer(std::string path) {
  std::ifstream f;
  f.open(path);

  std::stringstream stream;
  stream << f.rdbuf();
  content = stream.str();

  f.close();
}

Symbol Lexer::getSymbol() {
  std::smatch sm;
  std::regex_match(content, sm, keyword);

  if(sm.size() > 0) {
    if(sm[0] == "var") {
    
    }
    else if(sm[0] == "const") {

    }
    else if(sm[0] == "ecrire") {

    }
    else if(sm[0] == "lire") {

    }
  }

  std::regex_match(content, sm, id);
  if(sm.size() > 0) {
  
  }
  
  std::regex_match(content, sm, val);
  if(sm.size() > 0) {
  
  }
  
  std::regex_match(content, sm, pv);
  if(sm.size() > 0) {
  
  }
  
  std::regex_match(content, sm, aff);
  if(sm.size() > 0) {
  
  }

}
