#include <bits/stdc++.h>
// took like 20 seconds to compile and run oof
// A billion would probably require a month or somethin to complete

void cat_input(std::string file_name, std::vector<std::string> &lines)
{
    std::ifstream input_file("input.txt");

    if (input_file.is_open())
    {
        std::string line;
        while (getline(input_file, line))
            lines.push_back(line);

        input_file.close();
    }
    else
    {
        std::cout << "Unable to open the file.\n";
    }
}

// redundant step - realised it too late
// converts vector of string to vector of chars
std::vector<std::vector<char>> init_platform(const std::vector<std::string> &lines)
{
    std::vector<std::vector<char>> platform(lines[0].size(), std::vector<char>(lines.size(), ' '));

    for (int i = 0; i < lines.size(); ++i)
    {
        for (int j = 0; j < lines[i].size(); ++j)
        {
            platform[i][j] = lines[i][j];
        }
    }
    return platform;
}

void print_platform(const std::vector<std::vector<char>> &vec)
{
    std::cout << '\n';
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec[i].size(); ++j)
        {
            std::cout << vec[i][j];
        }
        std::cout << '\n';
    }
}

// Let the boulders fight against gravity
// An amatuer brute force approach
void tilt_platform(std::vector<std::vector<char>> &vec)
{
    // ^
    // |
    // |
    // |
    // tilt up
    bool moved;
    do
    {
        moved = false;
        for (size_t i = 1; i < vec.size(); ++i)
        {
            for (size_t j = 0; j < vec[i].size(); ++j)
            {
                if (vec[i - 1][j] == '.' && vec[i][j] == 'O')
                {
                    vec[i - 1][j] = 'O';
                    vec[i][j] = '.';
                    moved = true;
                }
            }
        }
    } while (moved);
    
    // <----
    // tilted left
    for (size_t i = 0; i < vec.size(); ++i)
    {
        for (size_t j = 1; j < vec[i].size(); ++j)
        {
            int m = i, n = j;
            while (vec[m][n] == 'O' && vec[m][n - 1] == '.')
            {
                vec[m][n - 1] = 'O';
                vec[m][n] = '.';
                if (n < 0)
                    break;
                else
                    --n;
            }
        }
    }

    // |
    // |
    // |
    // v
    // tilted down
    do
    {
        moved = false;
        for (size_t i = vec.size() - 1; i > 0; --i)
        {
            for (size_t j = 0; j < vec[i].size(); ++j)
            {
                if (vec[i][j] == '.' && vec[i - 1][j] == 'O')
                {
                    vec[i][j] = 'O';
                    vec[i - 1][j] = '.';
                    moved = true;
                }
            }
        }
    } while (moved);

    // --->
    // tilted right
    do
    {
        moved = false;
        for (size_t i = 0; i < vec.size(); ++i)
        {
            for (int j = vec[i].size() - 2; j >= 0; --j)
            {
                if (vec[i][j + 1] == '.' && vec[i][j] == 'O')
                {
                    vec[i][j + 1] = 'O';
                    vec[i][j] = '.';
                    moved = true;
                }
            }
        }
    } while (moved);
}

void calc_load(const std::vector<std::vector<char>> &vec)
{
    int64_t load = 0;
    for (int64_t i = 0; i < vec.size(); i++)
    {
        for (int64_t j = 0; j < vec[i].size(); j++)
        {
            if (vec[i][j] == 'O') load += vec.size() - i;
        }
    }
    std::cout << load << std::endl;
}

int main()
{
    std::vector<std::string> lines;

    cat_input("input.txt", lines);

    std::vector<std::vector<char>> rotated = init_platform(lines);

    lines.clear();

    // loop running a billion(thousand) times
    for (int i = 0; i < 1000; i++) tilt_platform(rotated);

    calc_load(rotated);
    
    return 0;
}