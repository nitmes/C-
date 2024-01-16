#pragma once
#include <string>
#include "figure.h"
#include "Exception.h"

class figure {
protected:
    std::string name;
    // int side_count;
    // int ang_count;
    bool have4sides = false;
    int sides = 0;
    int side_a = 0;
    int side_b = 0;
    int side_c = 0;
    int side_d = 0;
    int ang_a = 0;
    int ang_b = 0;
    int ang_c = 0;
    int ang_d = 0;

public:
    std::string get_name();
    int get_have4sides();

    int get_side_a();
    int get_side_b();
    int get_side_c();
    int get_side_d();

    int get_ang_a();
    int get_ang_b();
    int get_ang_c();
    int get_ang_d();

};