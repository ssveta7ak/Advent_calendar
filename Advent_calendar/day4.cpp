#include "day4.h"

Table sub;
int win_table = 0;

const Table& get_sub()
{
    return sub;
}

void read_input_data()
{
    std::ifstream infile("input/day4_input.txt");
    std::string line;

    while (infile >> line)
    {
        sub.tables.push_back(line);
    }

    //read first line with draw out numbers
    std::string guess = sub.tables.front();
    std::istringstream f(guess);
    std::string s;
   // std::vector<int> draw_out;
    while (getline(f, s, ',')) {
       // std::cout << s << std::endl;
        sub.draw_out.push_back(s);
    }

    //delete line with draw out numbers from data
    sub.tables.erase(sub.tables.begin());
}

std::string draw_out_number()
{
    std::string num = sub.draw_out.front();
    sub.draw_out.erase(sub.draw_out.begin());
    return num;
}

void update_tables(std::string num)
{
    //std::cout << num << "\n";

    while (std::find(sub.tables.begin(), sub.tables.end(), num) != sub.tables.end())
    {
        auto iter = std::find(sub.tables.begin(), sub.tables.end(), num);
        if (iter != sub.tables.end())
        {
            *iter = "*";
            iter++;
        }
    }
}

// return true if any row is equal "*****" after draw number
bool check_row()
{
    int num_rows = sub.tables.size() / 5;
    for (int k = 0; k < num_rows; k++)
    {
        std::string row = "";
        for (int i = 0; i < 5; i++)
        {
            row.append(sub.tables[5 * k + i]);
        }
        if (row == "*****")
        {

            win_table = (5 * k) / 25;
            return true;
        }
            
    }
    return false;
}

// return true if any colomn is equal "*****" after draw number
bool check_column()
{
    int num_tables = sub.tables.size() / 25;
    for (int m = 0; m < num_tables; m++)
    {
        for (int k = 0; k < 5 ; k++)
        {
            std::string colomn = "";
            for (int i = 0; i < 5; i++)
            {
                colomn.append(sub.tables[k + 5 * i + 25 * m]);
            }
            if (colomn == "*****")
            {
                win_table = m;
                return true;
            }
        }
    }
    return false;
}

void run_task()
{
    read_input_data();
    int i = 0;
    bool is_raw_win = false;
    bool is_colomn_win = false;
    std::string num = "";

    // draw next number and check tables for winner
    while ((i < sub.draw_out.size()) && !is_raw_win && !is_colomn_win)
    {
        num = draw_out_number();
        update_tables(num);
        is_raw_win = check_row();
        is_colomn_win = check_column();
        i++;
    }

    // count the sum of unmarked numbers in the winner table
    int score = 0;
    for (int i = 0; i < 25; i++)
    {
        if (sub.tables[win_table * 25 + i] != "*")
        {
            score += stoi(sub.tables[win_table * 25 + i]);
        }
    }

    // count the total score - multiplication of the score and last draw number
    int total_score = score * stoi(num);

    std::cout<< total_score << "\n";
}