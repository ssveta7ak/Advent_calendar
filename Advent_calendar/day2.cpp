#include "day2.h"

void Submarine::read_input()
{
    std::ifstream infile("day2_input.txt");
    std::string line;
    int step = 0;
    
    while (infile >> line >> step)
    {
        std::cout << line;
        std::cout << step << "\n";
        
    }
    
}