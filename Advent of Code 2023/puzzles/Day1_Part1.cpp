#include <bits/stdc++.h>

int digitChecker(std::string str) {
    std::vector<int> buffer;

    for(auto &i : str) {
        if(isdigit(i)) {
            buffer.push_back(i - 48);
        }
    }

    if (buffer.size() == 1) return 10 * buffer.front() + buffer.front();
    return buffer.back() + 10 * buffer.front();
}

int main () {
    int sum = 0;
    std::string line;

    std::ifstream StringList("Day1_Input.txt");

    if(StringList.is_open()) {
        while(getline(StringList, line)) {
            sum += digitChecker(line);
        }
        StringList.close();
    }
    else {
        std::cout << "Unable to open the file.";
    }

    std::cout << sum << std::endl;


    return 0;
}