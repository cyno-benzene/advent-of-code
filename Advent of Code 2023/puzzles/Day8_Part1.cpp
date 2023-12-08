#include <bits/stdc++.h>

std::regex pattern(R"((\w+)\s*=\s*\((\w+),\s*(\w+)\))");

void init_input(std::string &line, std::map<std::string, std::pair<std::string, std::string>> &nodes)
{
    std::smatch matches;
    if (std::regex_search(line, matches, pattern))
    {
        nodes[matches.str(1)] = std::make_pair(matches.str(2), matches.str(3));
    }
}

int calc_steps(std::map<std::string, std::pair<std::string, std::string>> &node, std::string &turns)
{
    std::string left = "L";
    std::string start = "AAA", end = "ZZZ";
    std::string next;
    std::map<std::string, std::pair<std::string, std::string>>::iterator iter = node.begin();

    // first step with AAA
    if (turns[0] == left[0])
    {
        iter = node.find(start);        
        next = iter->second.first;
    }
    else
    {
        iter = node.find(start);
        next = iter->second.second;    
    }

    int steps = 1;
    int j = 1;

    while (next != end)
    {
        if (turns[j] == left[0])
        {   
            iter = node.find(next);
            next = iter->second.first;
            steps++;
        }
        else
        {
            iter = node.find(next);
            next = iter->second.second;
            steps++;  
        }

        if (j == turns.size() - 1 && next != end) j = 0;
        else j++;
    }

    return steps;
}

int main()
{

    std::ifstream input_file("../inputs/Day8_Input.txt");

    if (input_file.is_open())
    {
        std::string line;

        std::getline(input_file, line);

        std::string instructions = line;

        std::map<std::string, std::pair<std::string, std::string>> nodes;

        while (getline(input_file, line)) init_input(line, nodes);

        std::cout << calc_steps(nodes, instructions);

        input_file.close();
    }
    else std::cout << "Unable to open the file.\n";

    return 0;
}