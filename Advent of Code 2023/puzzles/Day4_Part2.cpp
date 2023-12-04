#include <bits/stdc++.h>

void format_line(std::string& line)
{
    line = line.substr(line.find(':') + 1, line.length() - 1);
}

void count_copies(std::vector<int>& nums_list, std::map<int, int>& cards_map, int card_no)
{
    std::sort(nums_list.begin(), nums_list.end());

    ++cards_map[card_no]; // initialise original copy count i.e. 1

    int copies_count = cards_map[card_no];

    // loop iterates for original + number of copies
    while(copies_count) {
        // reset current card number for each loop
        // as in the nested for loop we are incrementing 
        // the copies count value field in the map for the
        // the card_no counter
        int _card_no = card_no; 

        for (int i = 1; i < nums_list.size(); i++)
        {
            if (nums_list[i] == nums_list[i - 1])
            {   
                ++cards_map[++_card_no]; 
            }
        }
        copies_count--;
    }
}

void print_map(std::map<int, int>& cards_map){
    std::map<int, int>::iterator iter;

    for (iter = cards_map.begin(); iter != cards_map.end(); ++iter) {
        std::cout << iter->first << " - " << iter->second << std::endl;
    }
}

int main()
{
    std::ifstream input_file("../inputs/Day4_Input.txt");

    if (input_file.is_open())
    {
        std::string line;
        std::map<int, int> cards_map;
        int i = 0;
        while (getline(input_file, line))
        {
            ++i;
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
            count_copies(nums_list, cards_map, i);
        }
        input_file.close();

        const int result = std::accumulate(cards_map.begin(), cards_map.end(), 0,
            [](const int prev_sum, const std::pair<int, int> &entry) {
            return prev_sum + entry.second;
        });

        std::cout << "Result: " << result << std::endl;
    }

    else
    {
        std::cout << "Unable to open the file.\n";
    }

    return 0;
}
