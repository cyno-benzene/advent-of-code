#include <bits/stdc++.h>
using namespace std;

void cat_input(string file_name, string &lines)
{
    ifstream input_file("input.txt");

    if (input_file.is_open())
    {
        string line;
        while (getline(input_file, line)) lines = line + ",";
        input_file.close();
    }
    else
    {
        cout << "Unable to open the file.\n";
    }
}

int hash_algorithm(string &line) {
    int output = 0;
    string result;
    size_t start = 0;
    size_t end = line.find(',');

    while (end != string::npos) {
        int n = 0;
        string substring = line.substr(start, end - start);
        for (char c : substring) {
            int ascii = static_cast<int>(c);
            result += to_string(ascii) + " ";
            n = ((n + ascii) * 17) % 256;
        }
        output += n;

        start = end + 1;
        end = line.find(',', start);
    }

    return output;
}

int main() {
    string lines;

    cat_input("input.txt", lines);
    cout << "\n" <<  hash_algorithm(lines); 

    return 0;
}