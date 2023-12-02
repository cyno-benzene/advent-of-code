#include <bits/stdc++.h>

const int MAX_RED = 12, MAX_GREEN = 13, MAX_BLUE = 14;

void format_line(std::string& line)
{
    line = line.substr(line.find(':') + 1, line.length() - 1);
}

bool count_cubes(std::string& line)
{
    int red{0}, green{0}, blue{0};
    if (line.find("red") != std::string::npos) {
        red = stoi(line.substr(line.find("red") - 3, 2));
    }

    if (line.find("green") != std::string::npos) {
        green = stoi(line.substr(line.find("green") - 3, 2));
    }

    if (line.find("blue") != std::string::npos) {
        blue = stoi(line.substr(line.find("blue") - 3, 2));
    }

    return (red <= MAX_RED && green <= MAX_GREEN && blue <= MAX_BLUE);
}

int main()
{
    int sum = 0;
    int id = 0;
    std::string line;

    std::ifstream input_file("../inputs/Day2_Input.txt");

    if (input_file.is_open())
    {
        while (getline(input_file, line))
        {
            ++id;
            format_line(line);
            line = line + ";";
            std::stringstream ss(line);
            std::string subline;
            bool is_valid = true;

            while (getline(ss, subline, ';') && is_valid) {
                is_valid = count_cubes(subline);
            }
            if (is_valid) {
                sum += id;
                std::cout << id <<std::endl;
            }
        }
        input_file.close();
        std::cout << "Sum of IDs: " << sum << std::endl;
    }
    else
    {
        std::cout << "Unable to open the file.\n";
    }

    return 0;
}