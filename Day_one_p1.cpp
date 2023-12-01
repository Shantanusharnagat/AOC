#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main()
{
    ifstream inputFile("1input.txt");
    vector<string> lines;
    string line;
    while (getline(inputFile, line))
    {
        lines.push_back(line);
    }
    inputFile.close();
    // for (auto i : lines)
    // {
    //     cout << i << " ";
    // }
    int fin = 0;
    for (int z = 0; z < lines.size(); z++)
    {
        string cur = lines[z];
        string ans = "";
        for (int i = 0; i < cur.size(); i++)
        {
            if (isdigit(cur[i]))
            {
                ans = ans + cur[i];
                break;
            }
        }
        for (int i = cur.size() - 1; i >= 0; i--)
        {
            if (isdigit(cur[i]))
            {
                ans = ans + cur[i];
                break;
            }
        }

        fin += stoi(ans);
    }

    cout << fin << endl;
    return 0;
}