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
int64_t gcd(int64_t a, int64_t b){
    if( b == 0) return a;
    else return gcd(b, a % b);
}

int64_t lcm(int64_t a,int64_t b){
    return a * b/ gcd(a, b);
}

int64_t calc_steps(std::map<std::string, std::pair<std::string, std::string>> &nodes, std::string &turns)
{
    std::string left = "L";
    std::map<std::string, std::pair<std::string, std::string>>::iterator iter = nodes.begin();
    std::string next;

    // filtered out element with A
    std::vector<std::string> filtered;
    for (const auto& key : nodes) {
        if (key.first.back() == 'A') {
            filtered.push_back(key.first);
        }
    }

    std::vector<int64_t> steps_buffer;
    // iterate over the filtered elements
    // reused the loop from part 1 with minor changes 
    for(auto& n : filtered) {

        if (turns[0] == left[0])
        {
            iter = nodes.find(n);        
            next = iter->second.first;
        }
        else
        {
            iter = nodes.find(n);
            next = iter->second.second;    
        }

        std::size_t steps = 1;
        int64_t j = 1;

        while (next.back() != 'Z')
        {
            if (turns[j] == left[0])
            {   
                iter = nodes.find(next);
                next = iter->second.first;
                steps++;
            }
            else
            {
                iter = nodes.find(next);
                next = iter->second.second;
                steps++;  
            }

            if (j == turns.size() - 1 && next.back() != 'Z') j = 0;
            else j++;
        }
        steps_buffer.push_back(steps);
    }
    int64_t ans = steps_buffer.at(0);
    for (std::size_t i = 1; i < steps_buffer.size(); i++) ans = lcm(steps_buffer.at(i), ans);



    return ans;
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




