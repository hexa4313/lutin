cmake_minimum_required(VERSION 2.8)

set (PROJECT_NAME lutin)
set (EXECUTABLE_NAME lutinc)

project(${PROJECT_NAME})

find_package(Boost 1.50.0)
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

  main.cpp
)

SET (states_SRCS
  states/e1.h
  states/e1.cpp
  states/e4.h
  states/e4.cpp
  states/e6.h
  states/e6.cpp
  states/e13.h
  states/e13.cpp
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
)

SET (declaration_SRCS
  declaration/constdec.h
  declaration/constdeclist.h
  declaration/declaration.h
  declaration/declarationlist.h
  declaration/vardec.h
  declaration/vardeclist.h
)


SET (ALL_SRCS
  ${root_SRCS}
  ${states_SRCS}
  ${declaration_SRCS}
  ${instruction_SRCS}
)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(${EXECUTABLE_NAME} ${ALL_SRCS})
target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES})