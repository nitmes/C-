#pragma once
#include <stdexcept>

class Ini_parser_exeption: public std::runtime_error
{
public :
	Ini_parser_exeption(const int number_line, const std::string& error);
	Ini_parser_exeption(const std::string& error);
};
