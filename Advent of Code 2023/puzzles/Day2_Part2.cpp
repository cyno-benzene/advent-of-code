#include <bits/stdc++.h>

void format_string(std::string& line)
{
    size_t pos = line.find(':');
    if (pos != std::string::npos) {
        line = line.substr(pos + 1);
    }
}

int count_color(std::string& line, const std::string& color)
{
    size_t pos = line.find(color);
    if (pos != std::string::npos) {
        if (pos >= 3) {
            pos -= 3;
            std::string count_str = line.substr(pos, 2);
            return std::stoi(count_str);
        }
    }
    return 0;
}


int main()
{
    std::ifstream input_file("../inputs/Day2_Input.txt");
    std::string line;
    int count = 0;

    while (getline(input_file, line)) {
        format_string(line);
        line = line + ";";
        std::stringstream ss(line);
        std::string part;
        int red{1}, green{1}, blue{1};

        while (getline(ss, part, ';')) {
            red = std::max(red, count_color(part, "red"));
            green = std::max(green, count_color(part, "green"));
            blue = std::max(blue, count_color(part, "blue"));
        }

        count += red * green * blue;
    }
    input_file.close();

    std::cout << count << std::endl;

    return 0;
}

