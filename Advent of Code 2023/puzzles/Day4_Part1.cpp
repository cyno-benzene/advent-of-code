#include <bits/stdc++.h>

void format_line(std::string& line)
{
    line = line.substr(line.find(':') + 1, line.length() - 1);
}

int count_points(std::vector<int>& nums_list)
{
    std::sort(nums_list.begin(), nums_list.end());
    int points = 0, power = 0;

    for (int i = 1; i < nums_list.size(); i++)
    {
        if (nums_list[i] == nums_list[i - 1])
        {
            points = std::pow(2, power++);
        }
    }
    return points;
}

int main()
{
    std::ifstream input_file("../inputs/Day4_Input.txt");

    if (input_file.is_open())
    {
        int sum = 0;
        std::string line;

        while (getline(input_file, line))
        {
            format_line(line);
            std::vector<int> nums_list;
            std::stringstream ss(line);
            std::string num, separtor = "|";

            while (ss >> num)
            {
                if (num == separtor)
                {
                    continue;
                }
                nums_list.push_back(stoi(num));
            }

            sum += count_points(nums_list);
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
