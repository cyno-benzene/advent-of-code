#include <bits/stdc++.h>

std::vector<int> vectorize_input(std::string &line)
{
    line = line.substr(line.find(':') + 1, line.length() - 1);

    std::stringstream ss(line);
    std::string num;

    std::vector<int> list;

    while (ss >> num)
    {
        list.push_back(stoi(num));
    }
    return list;
}

int calc_chances(std::vector<int> &t, std::vector<int> &d)
{
    int product = 1, traversed;

    for (int i = 0; i < t.size(); i++)
    {

        int chance = 0;

        for (int time = 0; time <= t[i]; time++)
        {
            // speed and time are directly proportional(?)
            traversed = (t[i] - time) * time;

            if (traversed > d[i])
            {

                chance++;
            }
        }
        product *= chance;
    }
    return product;
}

int main()
{

    std::ifstream input_file("../inputs/Day6_Input.txt");

    if (input_file.is_open())
    {
        int i = 0;
        std::string line;

        std::getline(input_file, line);
        std::vector<int> times = vectorize_input(line);

        std::getline(input_file, line);
        std::vector<int> distances = vectorize_input(line);

        std::cout << std::endl;
        std::cout << "Chances: " << calc_chances(times, distances);

        input_file.close();
    }
    else
    {
        std::cout << "Unable to open the file.\n";
    }

    return 0;
}