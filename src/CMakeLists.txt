cmake_minimum_required(VERSION 2.8)

set (PROJECT_NAME lutin)
set (EXECUTABLE_NAME lutinc)

project(${PROJECT_NAME})

find_package(Boost 1.50.0 COMPONENTS regex)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

SET (root_SRCS
  symboltype.h

  statemachine.h
  statemachine.cpp

  symbol.h
  symbol.cpp

  lexer.h
  lexer.cpp

  program.h
  program.cpp
  state.h

  main.cpp
)

SET (states_SRCS
  states/e0.h
  states/e0.cpp
  states/e1.h
  states/e1.cpp
  states/e2.h
  states/e2.cpp
  states/e3.h
  states/e3.cpp
  states/e4.h
  states/e4.cpp
  states/e5.h
  states/e5.cpp
  states/e6.h
  states/e6.cpp
  states/e7.h
  states/e7.cpp
  states/e8.h
  states/e8.cpp
  states/e9.h
  states/e9.cpp
  states/e10.h
  states/e10.cpp
  states/e11.h
  states/e11.cpp
  states/e12.h
  states/e12.cpp
  states/e13.h
  states/e13.cpp
  states/e14.h
  states/e14.cpp
  states/e15.h
  states/e15.cpp
  states/e16.h
  states/e16.cpp
  states/e17.h
  states/e17.cpp
  states/e18.h
  states/e18.cpp
  states/e19.h
  states/e19.cpp
  states/e20.h
  states/e20.cpp
  states/e21.h
  states/e21.cpp
  states/e22.h
  states/e22.cpp
  states/e23.h
  states/e23.cpp
  states/e24.h
  states/e24.cpp
  states/e25.h
  states/e25.cpp
  states/e26.h
  states/e26.cpp
  states/e27.h
  states/e27.cpp
  states/e28.h
  states/e28.cpp
  states/e29.h
  states/e29.cpp
  states/e30.h
  states/e30.cpp
  states/e31.h
  states/e31.cpp
  states/e32.h
  states/e32.cpp
  states/e33.h
  states/e33.cpp
  states/e34.h
  states/e34.cpp
  states/e35.h
  states/e35.cpp
  states/e36.h
  states/e36.cpp
  states/e37.h
  states/e37.cpp
  states/e38.h
  states/e38.cpp
  states/e39.h
  states/e39.cpp
  states/e40.h
  states/e40.cpp
  states/e41.h
  states/e41.cpp
)

SET (instruction_SRCS
  instruction/assign.h
  instruction/binaryexp.h
  instruction/expadd.h
  instruction/expdiv.h
  instruction/expmult.h
  instruction/exppar.h
  instruction/expression.h
  instruction/expsub.h
  instruction/instruction.h
  instruction/instructionlist.h
  instruction/read.h
  instruction/variable.h
  instruction/write.h
  instruction/numericconst.h
)

SET (declaration_SRCS
  declaration/constdec.h
  declaration/constdeclist.h
  declaration/declaration.h
  declaration/declarationlist.h
  declaration/declarationlist.cpp
  declaration/vardec.h
  declaration/vardeclist.h
)

SET (interpreter_SRCS
  interpreter/interpreter.cpp
  interpreter/interpreter.h
  interpreter/symboltable.cpp
  interpreter/symboltable.h
)

SET (ALL_SRCS
  ${root_SRCS}
  ${states_SRCS}
  ${declaration_SRCS}
  ${instruction_SRCS}
  ${interpreter_SRCS}
)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic")

add_executable(${EXECUTABLE_NAME} ${ALL_SRCS})
target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES})
