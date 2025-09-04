cmake_minimum_required(VERSION 3.20.0)

project(ini_parser)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_LIB "ini_parser.cpp" "ini_parser.h" "Ini_parser_exeption.h" "Ini_parser_exeption.cpp")

add_library(ini_parser STATIC ${SOURCE_LIB})