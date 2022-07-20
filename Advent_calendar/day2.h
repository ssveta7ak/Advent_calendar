#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

class Submarine
{
public:
    void read_input();
private:
    int horizontal = 0;
    int depth = 0;
    std::string move;
    int step;

};
