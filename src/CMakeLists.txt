cmake_minimum_required(VERSION 2.8.4)
project(lutin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


SET (root_SRCS
  symboltype.h

  symbol.h
  symbol.cpp

  lexer.h
  lexer.cpp
)

SET (states_SRCS
  states/e1.h
  states/e1.cpp
)


SET (ALL_SRCS
  ${root_SRCS}
  ${states_SRCS}
)


add_executable(lutinc ${ALL_SRCS})