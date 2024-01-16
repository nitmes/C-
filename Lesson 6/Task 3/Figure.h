#pragma once
#include <string>


class Figure {
protected:
	std::string name;
	int count_sides = 0;
	bool status = false;
	virtual bool check();
public:
	Figure();
	std::string get_name();
	virtual void print_info();
};