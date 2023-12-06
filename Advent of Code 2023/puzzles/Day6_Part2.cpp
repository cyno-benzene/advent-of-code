#include <bits/stdc++.h>

uint64_t init_input(std::string &line)
{
    line = line.substr(line.find(':') + 1, line.length() - 1);

    std::stringstream ss(line);
    std::string num;

    std::string list;

    while (ss >> num)
    {
        list += num;
    }
    // std::cout << list << " ";
    uint64_t val = stoull(list);
    return val;
}

uint64_t calc_chances(uint64_t t, uint64_t d)
{
    uint64_t traversed;

    uint64_t chance = 0;

    for (uint64_t time = 0; time <= t; time++)
    {

        traversed = (t - time) * time;

        if (traversed > d)
        {
            chance++;
        }

    }   

    return chance;
}

int main()
{

    std::ifstream input_file("../inputs/Day6_Input.txt");

    if (input_file.is_open())
    {
        std::string line;

        std::getline(input_file, line);
        uint64_t time = init_input(line);

        std::getline(input_file, line);
        uint64_t distance = init_input(line);

        std::cout << "Chances: "<< calc_chances(time, distance);
        
        input_file.close();
    }
    else
    {
        std::cout << "Unable to open the file.\n";
    }

    return 0;
}