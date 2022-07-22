#include "day2.h"

void Submarine::move(std::string direction, int step)
{
    if (direction == "forward")
    {
        x += step;
        y += aim * step;
    }
    if (direction == "down")
    {
        aim += step;

    }
    if (direction == "up")
    {
        aim -= step;
    }
}

void Submarine::read_input()
{
    std::ifstream infile("input/day2_input.txt");
    std::string direction;
    int step = 0;
    
    while (infile >> direction >> step)
    {
        move(direction, step);
    }
    std::cout << get_multiplication_xy() << "\n";
}