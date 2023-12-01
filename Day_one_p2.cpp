#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    unordered_map<string, int> mappings = {
        {"1", 1},
        {"2", 2},
        {"3", 3},
        {"4", 4},
        {"5", 5},
        {"6", 6},
        {"7", 7},
        {"8", 8},
        {"9", 9},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
    };

    ifstream inputFile("input.txt");
    vector<string> lines;

    if (inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {
            lines.push_back(line);
        }
        inputFile.close();
    }
    else
    {
        cerr << "Unable to open input file" << endl;
        return 1;
    }

    int tot = 0;
    for (const auto &line : lines)
    {
        vector<pair<int, int>> arr;
        for (const auto &entry : mappings)
        {
            size_t pos = line.find(entry.first);
            while (pos != string::npos)
            {
                arr.emplace_back(pos, entry.second);
                pos = line.find(entry.first, pos + 1);
            }
        }
        sort(arr.begin(), arr.end());
        int ans = stoi(to_string(arr[0].second) + to_string(arr.back().second));
        tot += ans;
    }

    cout << tot << endl;

    return 0;
}
