cmake_minimum_required(VERSION 2.8)

set (PROJECT_NAME lutin)
set (EXECUTABLE_NAME lutinc)

project(${PROJECT_NAME})

find_package(Boost 1.50.0 COMPONENTS regex)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

SET (root_SRCS
  main.cpp
)

SET (states_SRCS
  parsing/states/state.h
  parsing/states/e0.h
  parsing/states/e0.cpp
  parsing/states/e1.h
  parsing/states/e1.cpp
  parsing/states/e2.h
  parsing/states/e2.cpp
  parsing/states/e3.h
  parsing/states/e3.cpp
  parsing/states/e4.h
  parsing/states/e4.cpp
  parsing/states/e5.h
  parsing/states/e5.cpp
  parsing/states/e6.h
  parsing/states/e6.cpp
  parsing/states/e7.h
  parsing/states/e7.cpp
  parsing/states/e8.h
  parsing/states/e8.cpp
  parsing/states/e9.h
  parsing/states/e9.cpp
  parsing/states/e10.h
  parsing/states/e10.cpp
  parsing/states/e11.h
  parsing/states/e11.cpp
  parsing/states/e12.h
  parsing/states/e12.cpp
  parsing/states/e13.h
  parsing/states/e13.cpp
  parsing/states/e14.h
  parsing/states/e14.cpp
  parsing/states/e15.h
  parsing/states/e15.cpp
  parsing/states/e16.h
  parsing/states/e16.cpp
  parsing/states/e17.h
  parsing/states/e17.cpp
  parsing/states/e18.h
  parsing/states/e18.cpp
  parsing/states/e19.h
  parsing/states/e19.cpp
  parsing/states/e20.h
  parsing/states/e20.cpp
  parsing/states/e21.h
  parsing/states/e21.cpp
  parsing/states/e22.h
  parsing/states/e22.cpp
  parsing/states/e23.h
  parsing/states/e23.cpp
  parsing/states/e24.h
  parsing/states/e24.cpp
  parsing/states/e25.h
  parsing/states/e25.cpp
  parsing/states/e26.h
  parsing/states/e26.cpp
  parsing/states/e27.h
  parsing/states/e27.cpp
  parsing/states/e28.h
  parsing/states/e28.cpp
  parsing/states/e29.h
  parsing/states/e29.cpp
  parsing/states/e30.h
  parsing/states/e30.cpp
  parsing/states/e31.h
  parsing/states/e31.cpp
  parsing/states/e32.h
  parsing/states/e32.cpp
  parsing/states/e33.h
  parsing/states/e33.cpp
  parsing/states/e34.h
  parsing/states/e34.cpp
  parsing/states/e35.h
  parsing/states/e35.cpp
  parsing/states/e36.h
  parsing/states/e36.cpp
  parsing/states/e37.h
  parsing/states/e37.cpp
  parsing/states/e38.h
  parsing/states/e38.cpp
  parsing/states/e39.h
  parsing/states/e39.cpp
  parsing/states/e40.h
  parsing/states/e40.cpp
  parsing/states/e41.h
  parsing/states/e41.cpp
)

SET (instruction_SRCS

  parsing/ast/instruction/instruction.h

  parsing/ast/instruction/instructionlist.h
  parsing/ast/instruction/instructionlist.cpp

  parsing/ast/instruction/assign.h
  parsing/ast/instruction/assign.cpp

  parsing/ast/instruction/read.h
  parsing/ast/instruction/read.cpp

  parsing/ast/instruction/write.h
  parsing/ast/instruction/write.cpp
)

SET (expression_SRCS

  parsing/ast/expression/expression.h

  parsing/ast/expression/binaryexp.h
  parsing/ast/expression/binaryexp.cpp

  parsing/ast/expression/identifier.h
  parsing/ast/expression/identifier.cpp

  parsing/ast/expression/expadd.h
  parsing/ast/expression/expadd.cpp

  parsing/ast/expression/expdiv.h
  parsing/ast/expression/expdiv.cpp

  parsing/ast/expression/expmult.h
  parsing/ast/expression/expmult.cpp

  parsing/ast/expression/expsub.h
  parsing/ast/expression/expsub.cpp

  parsing/ast/expression/exppar.h
  parsing/ast/expression/exppar.cpp

  parsing/ast/expression/numericconst.h
  parsing/ast/expression/numericconst.cpp
)

SET (declaration_SRCS

  parsing/ast/declaration/simpledec.h

  parsing/ast/declaration/constdec.h
  parsing/ast/declaration/constdec.cpp

  parsing/ast/declaration/constdeclist.h
  parsing/ast/declaration/constdeclist.cpp

  parsing/ast/declaration/declaration.h

  parsing/ast/declaration/declarationlist.h
  parsing/ast/declaration/declarationlist.cpp

  parsing/ast/declaration/vardec.h
  parsing/ast/declaration/vardec.cpp

  parsing/ast/declaration/vardeclist.h
  parsing/ast/declaration/vardeclist.cpp
)

SET (ast_SRCS
  ${declaration_SRCS}
  ${instruction_SRCS}
  ${expression_SRCS}

  parsing/ast/program.h
  parsing/ast/program.cpp

  parsing/ast/symboltype.h

  parsing/ast/symbol.h
  parsing/ast/symbol.cpp
)

SET (parsing_SRCS
  ${ast_SRCS}
  ${states_SRCS}

  parsing/statemachine.h
  parsing/statemachine.cpp

  parsing/lexer.h
  parsing/lexer.cpp
)

SET (interpreter_SRCS
  interpretation/interpreter.cpp
  interpretation/interpreter.h
  interpretation/symboltable.cpp
  interpretation/symboltable.h
)

SET (static_analysis_SRCS
  static_analysis/staticanalyzer.h
  static_analysis/staticanalyzer.cpp
)

SET (optimization_SRCS
  optimization/optimizer.h
  optimization/optimizer.cpp
)

SET (ALL_SRCS
  ${root_SRCS}
  ${parsing_SRCS}
  ${interpreter_SRCS}
  ${static_analysis_SRCS}
  ${optimization_SRCS}
)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -fno-default-inline -fno-inline")

add_executable(${EXECUTABLE_NAME} ${ALL_SRCS})
target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES})
