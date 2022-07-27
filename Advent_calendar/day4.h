#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

struct Table
{
    std::vector<std::string> draw_out;
    std::vector<std::string> tables;
};

void read_input_data();
std::string draw_out_number();
void update_tables(std::string num);
bool check_column();
bool check_row();
void run_task();

const Table& get_sub();

    
