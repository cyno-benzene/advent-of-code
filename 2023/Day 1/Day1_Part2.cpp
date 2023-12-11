#include <bits/stdc++.h>

std::map<std::string, int> number_mapping = {
    {"one", 1}, 
    {"two", 2}, 
    {"three", 3}, 
    {"four", 4}, 
    {"five", 5}, 
    {"six", 6}, 
    {"seven", 7}, 
    {"eight", 8}, 
    {"nine", 9}
};

int digitChecker(std::string str)
{
    std::vector<int> buffer;

    for (int i = 0; i < str.size(); i++)
    {
        // Check if the current character is a digit
        if (isdigit(str[i]))
        {
            buffer.push_back(str[i] - '0');
        }

        // Check if the current character or a
        // sequence of characters form a valid number word
        else
        {
            std::string word;
            for (int j = i; j < str.size(); j++)
            {
                word += str[j];
                bool is_valid_word = false;
                for (auto &keyval : number_mapping)
                {
                    if (word.find(keyval.first) == 0)
                    {
                        is_valid_word = true;
                        break;
                    }
                }
                if (is_valid_word)
                {
                    buffer.push_back(number_mapping[word]);
                    // Tricky way to skip characters as for eightwo = 82
                    // we want outer loop would start from previous letter 
                    // iterating over the same letter 't' twice. 
                    i = --j; 
                    break;
                }
            }
        }
    }
    if (buffer.size() == 1) return 10 * buffer.front() + buffer.front();
    return buffer.back() + 10 * buffer.front();
}

int main()
{
    int sum = 0;
    std::string line;

    std::ifstream StringList("../inputs/Day1_Input.txt");

    if (StringList.is_open())
    {
        while (getline(StringList, line))
        {
            sum += digitChecker(line);
        }
        StringList.close();
        std::cout << sum << std::endl;
    }
    else
    {
        std::cout << "Unable to open the file.";
    }


    return 0;
}