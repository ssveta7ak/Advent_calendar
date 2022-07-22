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
    void move(std::string direction, int step);
    int get_multiplication_xy() { return x * y; }

private:
    int x = 0;
    int y = 0;
    int aim = 0;
};
