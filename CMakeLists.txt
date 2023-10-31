cmake_minimum_required(VERSION 3.25)
project(Programming_Language_V2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Programming_Language_V2 main.cpp Token.h TokenType.h Lexer.cpp Lexer.h Parser.cpp Parser.h Ast.h)
