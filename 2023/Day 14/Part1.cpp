#include <bits/stdc++.h>
// took 1.3 seconds to compile and run on my machine

void cat_input(std::string file_name, std::vector<std::string> &lines)
{
    std::ifstream input_file("input.txt");

    if (input_file.is_open())
    {
        std::string line;
        while (getline(input_file, line)) lines.push_back(line);
        
        input_file.close();
    }
    else
    {
        std::cout << "Unable to open the file.\n";
    }
}

// Function making east the new north
std::vector<std::vector<char>> init_platform(const std::vector<std::string> &lines)
{
    int max_length = 0;
    for (const auto &line : lines)
        max_length = std::max(max_length, (int)line.size());

    std::vector<std::vector<char>> rotated_platform(max_length, std::vector<char>(lines.size(), ' '));

    for (int i = 0; i < lines.size(); ++i)
    {
        for (int j = 0; j < lines[i].size(); ++j)
        {
            rotated_platform[j][i] = lines[i][j];
        }
    }

    return rotated_platform;
}

// Let the boulders fight against gravity
void tilt_platform(std::vector<std::vector<char>> &vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        for (size_t j = 1; j < vec[i].size(); ++j)
        {   
            int m = i, n = j;
            while(vec[m][n] == 'O' && vec[m][n-1] == '.')
            {
                vec[m][n-1] = 'O';
                vec[m][n] = '.';
                if (n < 0) break; else --n;          
            }
        }
    }
}

void calc_load(const std::vector<std::vector<char>> &vec)
{
    int64_t load = 0;
    for (int64_t i = 0; i < vec.size(); i++)
    {
        for (int64_t j = vec[i].size() - 1; j >= 0; j--)
        {
            if (vec[i][j] == 'O')
            {
                load += vec[i].size() - j;
            }
        }
    }
    std::cout << "Load: " << load << '\n';
}

int main()
{
    std::vector<std::string> lines;

    cat_input("input.txt", lines);

    std::vector<std::vector<char>> rotated = init_platform(lines);

    lines.clear();

    tilt_platform(rotated);

    calc_load(rotated);

    return 0;
}