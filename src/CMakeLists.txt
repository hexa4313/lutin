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

  symbol.h
  symbol.cpp

  lexer.h
  lexer.cpp

  main.cpp
)

SET (states_SRCS
  states/e1.h
  states/e1.cpp
)


SET (ALL_SRCS
  ${root_SRCS}
  ${states_SRCS}
)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(${EXECUTABLE_NAME} ${ALL_SRCS})
target_link_libraries(${EXECUTABLE_NAME} ${Boost_LIBRARIES})