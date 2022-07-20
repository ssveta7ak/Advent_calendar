#include "day1.h"

//get count how many times the depth measurement is 
//incremented from the previous measurement
int get_count()
{
    std::ifstream infile("input/day1_input.txt");
    std::string line;
    int prev_number = 0;
    int count = 0;
    while (std::getline(infile, line))
    {
        int number = std::stoi(line);
        if (number > prev_number && prev_number != 0)
            count++;
        prev_number = number;
    }
    std::cout << count << std::endl;
    return count;
}


//get count of sums are larger than the previous sum
int get_sum_count()
{
    std::ifstream infile("input/day1_2_input.txt");
    std::string line;
    int sum_count = 0;
    int prev_sum = 0;
    int a = 0;
    int b = 0;
    while (std::getline(infile, line))
    {
        int c = std::stoi(line);
        int cur_sum = 0;
        if (a != 0 && b != 0 && c != 0)
        {
            cur_sum = a + b + c;
            if (prev_sum != 0 && cur_sum > prev_sum)
                sum_count++;
        }
        a = b;
        b = c;
        prev_sum = cur_sum;
    }
    std::cout << sum_count << std::endl;
    return sum_count;
}
