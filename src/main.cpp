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
#include "statemachine.h"

#define MIN_ARGS 2
#define MAX_ARGS 4

#define ERROR_NOT_ENOUGH_ARGS 1
#define ERROR_TOO_MANY_ARGS 1
#define ERROR_BAD_INPUT 1

void show_usage() {
  std::cerr << "Erreur, veuillez specifier des arguments" << std::endl;
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

  bool opt_print, opt_analyse, opt_execute, opt_optimize = false;
  std::string input_path;

  // Arguments number check

  if (argc < MIN_ARGS) {
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
    else if (arg == "-a") {
      opt_analyse = true;
    }
    else {
      input_path = arg;
    }
  }

  // Check if file exists

  if(!file_exists(input_path)) {
    std::cerr << "Unable to open file: " << input_path << '\n';
    exit(ERROR_BAD_INPUT);
  }

  std::cout << "\n" << "                ___,@";
  std::cout << "\n" << "             /  <";
  std::cout << "\n" << "        ,_  /    \\  _,";
  std::cout << "\n" << "    ?    \\`/______\\`/";
  std::cout << "\n" << " ,_(_).  |; (e  e) ;|";
  std::cout << "\n" << "  \\___ \\ \\/\\   7  /\\/    _\\8/_";
  std::cout << "\n" << "      \\/\\   \\'=='/      | /| /|";
  std::cout << "\n" << "       \\ \\___)--(_______|//|//|";
  std::cout << "\n" << "        \\___  ()  _____/|/_|/_|";
  std::cout << "\n" << "           /  ()  \\    `----'";
  std::cout << "\n" << "          /   ()   \\";
  std::cout << "\n" << "         '-.______.-'\"";
  std::cout << "\n" << "       _    |_||_|    _";
  std::cout << "\n" << "      (@____) || (____@)";
  std::cout << "\n" << "       \\______||______/\n";

  // My little state machine
  StateMachine stateMachine = StateMachine(input_path);
  stateMachine.read();
}
