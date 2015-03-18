#include <cstdlib>
#include <iostream>
#include "statemachine.h"

#define MIN_ARGS 2
#define MAX_ARGS 4

#define ERROR_NOT_ENOUGH_ARGS 1
#define ERROR_TOO_MANY_ARGS 2
#define ERROR_BAD_INPUT 3

void show_usage() {
  std::cout << "\n" << "usage: lutinc [-paeo] <input>" << '\n';
  std::cout << "options:" << '\n';
  std::cout << "-p :\tPrint the code memory representation." << '\n';
  std::cout << "-a :\tStatic analysis and error extraction." << '\n';
  std::cout << "-e :\tInteractive execution of the program." << '\n';
  std::cout << "-o :\tOptimizes the program representation." << '\n';
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

  // My little state machine
  StateMachine stateMachine = StateMachine(input_path);
  stateMachine.read();


  /*       Grrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
                         ^\    ^
                        / \\  / \
                       /.  \\/   \      |\___/|
    *----*           / / |  \\    \  __/  O  O\
    |   /          /  /  |   \\    \_\/  \     \
   / /\/         /   /   |    \\   _\/    '@___@
  /  /         /    /    |     \\ _\/       |U
  |  |       /     /     |      \\\/        |
  \  |     /_     /      |       \\  )   \ _|_
  \   \       ~-./_ _    |    .- ; (  \_ _ _,\'
  ~    ~.           .-~-.|.-*      _        {-,
   \      ~-. _ .-~                 \      /\'
    \                   }            {   .*
     ~.                 '-/        /.-~----.
       ~- _             /        >..----.\\\
           ~ - - - - ^}_ _ _ _ _ _ _.-\\\           */
}
