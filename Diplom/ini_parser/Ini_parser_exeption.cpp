#include "Ini_parser_exeption.h"
#include <string>

Ini_parser_exeption::Ini_parser_exeption(const int number_line, const std::string& error)
	:runtime_error("Error format ini file from " + std::to_string(number_line) + " line. " + error)
{}
Ini_parser_exeption::Ini_parser_exeption(const std::string & error)
	:runtime_error("Error ini file: " + error)
{}

