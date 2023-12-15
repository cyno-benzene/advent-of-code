#include <bits/stdc++.h>
// 8 seconds something to run 
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
    else cout << "Unable to open the file.\n";
}


// HASH algorithm
int H(string &str)
{
    int hash = 0;
    string result;
    for (char c : str)
    {
        int ascii = static_cast<int>(c);
        result += to_string(ascii) + " ";
        hash = ((hash + ascii) * 17) % 256;
    }
    return hash;
}


int lens_boxing(string &line)
{
    int output = 0;
    vector<vector<pair<string, int>>> boxes(256);

    string result;
    size_t start = 0;
    size_t end = line.find(',');

    while (end != string::npos)
    {
        string substring = line.substr(start, end - start);
        if(substring.find("-") != string::npos) 
        {
            string label = substring.substr(0, substring.size() - 1);
            boxes[H(label)].erase(remove_if(boxes[H(label)].begin(), boxes[H(label)].end(), [&label](const pair<string, int> &p)
            { 
                return p.first == label; 
            }),
            boxes[H(label)].end());

        }
        else 
        {
           string label = substring.substr(0, substring.find('='));
           int level = stoi(substring.substr(substring.find('=')+1));
           vector<pair<string, int>>& target = boxes[H(label)];
           bool replaced = false;
           for (auto& l : target) 
           {
               if (l.first == label) 
               {
                  l.second = level;
                  replaced = true;
               }
           }
           if (!replaced) 
           {
               target.push_back({label, level});
           }
        }

        start = end + 1;
        end = line.find(',', start);
    }

    for (int i = 0; i < boxes.size(); i++) 
    {
       for (int j = 0; j < boxes[i].size(); j++) 
       {
           output += (i+1) * (j+1) * boxes[i][j].second;
       }
   }

    return output;
}


int main()
{
    string lines;
    cat_input("input.txt", lines);
    cout << lens_boxing(lines);
    return 0;
}