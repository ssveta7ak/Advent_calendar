#include "day3.h"

void get_gamma_epsilon()
{
    std::ifstream infile("input/1day3_input.txt");
    std::string number;
    int len = 0;
    std::vector<int> ones(12);
    std::vector<int> zeros(12);
    std::vector<int> result(12);
    std::vector<int> invert(12);

    while (infile >> number )
    {
        len = number.length();
        for (int i = 0; i < number.length(); i++)
        {
            if (number[i] == '1')
                ones[i] += 1;
            if (number[i] == '0')
                zeros[i] += 1;
        }
    }
    infile.close();

    for (int i = 0; i < ones.size(); i++)
    {
        if (ones[i] > zeros[i])
        {
            result[i] = 1;
            invert[i] = 0;
        }
        else
        {
            result[i] = 0;
            invert[i] = 1;
        }
            
    }

    int gamma_rate = 0;
    int epsilon_rate = 0;
    std::cout << len << "\n";
    for (int i = 0; i < result.size(); i++)
    {
        gamma_rate += result[i] * pow(2, 11 - i);
        epsilon_rate += invert[i] * pow(2, 11 - i);

    }
    std::cout << gamma_rate * epsilon_rate<< "\n";

}
std::vector<int> get_commons_bits(std::vector<std::string> &numbers)
{
    std::vector<int> ones(12);
    std::vector<int> zeros(12);
    std::vector<int> commons(12);
    for (std::string number : numbers)
    {
        for (int i = 0; i < number.length(); i++)
        {
            if (number[i] == '1')
                ones[i] += 1;
            if (number[i] == '0')
                zeros[i] += 1;
        }
    }
    for (int i = 0; i < ones.size(); i++)
    {
        if (ones[i] >= zeros[i])
        {
            commons[i] = 1;
        }
        else
        {
            commons[i] = 0;
        }
    }
    return commons;
}

std::vector<int> get_fewest_bits(std::vector<std::string>& numbers)
{
    std::vector<int> commons = get_commons_bits(numbers);
    std::vector<int> fewers;
    for (int bit : commons)
    {
        if (bit == 1)
            fewers.push_back(0);
        if (bit == 0)
            fewers.push_back(1);
    }
    return fewers;
}

void get_life_support_rating()
{
    std::ifstream infile("input/day3_input.txt");
    std::string number;
    std::vector<std::string> numbers;

    while (infile >> number)
    {
        numbers.push_back(number);
    }
    infile.close();

    std::vector<int> commons = get_commons_bits(numbers);
    for (int i = 0; i < commons.size(); i++)
    {
        commons = get_commons_bits(numbers);
        if (numbers.size() == 1)
            break;
        for (int j = 0; j < numbers.size(); j++)
        {
            if ((numbers[j][i] - '0') != commons[i])
            {
                numbers[j] = numbers.back();
                if (numbers.size() == 1)
                    break;
                numbers.pop_back();
                j--;
            }
        }
    }

    std::vector<std::string> numbers2(numbers);
    std::vector<int> fewers = get_fewest_bits(numbers);
    for (int i = 0; i < fewers.size(); i++)
    {
        fewers = get_fewest_bits(numbers2);
        if (numbers2.size() == 1)
            break;
        for (int j = 0; j < numbers2.size(); j++)
        {
            if ((numbers2[j][i] - '0') != fewers[i])
            {
                numbers2[j] = numbers2.back();
                if (numbers2.size() == 1)
                    break;
                numbers2.pop_back();
                j--;
            }
        }
    }

    int oxygen_rating = 0;
    int c02_rating = 0;

    for (int i = 0; i < numbers[0].size(); i++)
    {
        oxygen_rating += (numbers[0][i] - '0') * pow(2, number.length() - 1 - i);
    }
    for (int i = 0; i < numbers2[0].size(); i++)
    {
        c02_rating += (numbers2[0][i] - '0') * pow(2, number.length() - 1 - i);
    }

    std::cout << oxygen_rating * c02_rating << "\n";

}
