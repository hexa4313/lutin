/*
88                                88
88                         ,d     ""
88                         88
88          88       88  MM88MMM  88  8b,dPPYba,
88          88       88    88     88  88P'   `"8a
88          88       88    88     88  88       88
88          "8a,   ,a88    88,    88  88       88
88888888888  `"YbbdP'Y8    "Y888  88  88       88
                ___,@
               /  <
          ,_  /    \  _,
      ?    \`/______\`/
   ,_(_).  |; (e  e) ;|
    \___ \ \/\   7  /\/    _\8/_
        \/\   \'=='/      | /| /|
         \ \___)--(_______|//|//|
          \___  ()  _____/|/_|/_|
             /  ()  \    `----'
            /   ()   \
           '-.______.-'
   jgs   _    |_||_|    _
        (@____) || (____@)
         \______||______/
*/

#include <cstdlib>
#include <iostream>
#include "parsing/statemachine.h"
#include "interpretation/interpreter.h"
#include "static_analysis/staticanalyzer.h"
#include "optimization/optimizer.h"

#define MIN_ARGS 2
#define MAX_ARGS 4

#define ERROR_NOT_ENOUGH_ARGS 1
#define ERROR_TOO_MANY_ARGS 1
#define ERROR_BAD_INPUT 1
#define ERROR_INCORRECT_PROGRAM 1

void show_usage() {
  std::cerr << "  Utilisation :" << std::endl;
  std::cerr << "    ../lut [-p] [-a] [-e] [-o] source.lt" << std::endl;
  std::cerr << "      [-p] affiche le code source reconnu" << std::endl;
  std::cerr << "      [-a] analyse le programme de maniere statique" << std::endl;
  std::cerr << "      [-e] execute interactivement le programme" << std::endl;
  std::cerr << "      [-o] optimise les expressions et instructions" << std::endl;
}

inline bool file_exists (const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

int main(int argc, char ** argv) {

  bool opt_print = false, opt_analyse = false;
  bool opt_execute = false, opt_optimize = false;
  std::string input_path;

  // Arguments number check

  if (argc < MIN_ARGS) {
    std::cerr << "Erreur, veuillez specifier des arguments" << std::endl;
    show_usage();
    exit(ERROR_NOT_ENOUGH_ARGS);
  }
  if (argc > MAX_ARGS) {
    show_usage();
    exit(ERROR_TOO_MANY_ARGS);
  }

  // Arguments reading

  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if ((arg == "-h") || (arg == "--help")) {
      show_usage();
      return 0;
    }

    if (arg == "-p") {
      opt_print = true;
    }
    else if (arg == "-a") {
      opt_analyse = true;
    }
    else if (arg == "-e") {
      opt_execute = true;
    }
    else if (arg == "-o") {
      opt_optimize = true;
    }
    else if (arg[0] == '-') {
      std::cerr << "Argument invalide." << std::endl;
      show_usage();
      exit(1);
    }
    else {
      input_path = arg;
    }
  }

  // Check if file exists

  if(!file_exists(input_path)) {
    std::cerr << "Erreur a l'ouverture du fichier " << input_path << std::endl;
    exit(ERROR_BAD_INPUT);
  }

  StateMachine stateMachine = StateMachine(input_path);
  std::shared_ptr<Program> program = stateMachine.read();

  if(!program) {
    exit(ERROR_INCORRECT_PROGRAM);
  }

  if(opt_analyse) {
    StaticAnalyzer analyzer(program);
    analyzer.checkProgram();
  }

  if(opt_optimize) {
    Optimizer optimizer(program);
    optimizer.optimizeProgram();
  }

  if(opt_print) {
    std::cout << *program;
  }

  if(opt_execute) {
    Interpreter interpreter(program);
    interpreter.init();
    interpreter.run();
  }

}
