#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inputFile("day_two_input.txt");
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
    int ans = 0;
    int count = 1;
    for (auto games : lines)
    {
        // cout << games;

        bool flag = true;

        for (int i = 7; i < games.size(); i++)
        {

            if (isdigit(games[i]) and isdigit(games[i + 1]))
            {

                string cur = "";
                cur += games[i];
                cur += games[i + 1];
                cout << cur << " ";
                // cout << games[i] << " ";
                if (stoi(cur) > 12 and games[i + 3] == 'r')
                {
                    // cout << "red" << stoi(cur)
                    //      << " ";
                    flag = false;
                    break;
                }
                if (stoi(cur) > 13 and games[i + 3] == 'g')
                {
                    // cout << "green" << stoi(cur) << " ";
                    flag = false;
                    break;
                }
                if (stoi(cur) > 14 and games[i + 3] == 'b')
                {
                    // cout << "blue" << stoi(cur) << " ";
                    flag = false;
                    break;
                }
            }
        }
        cout << flag << " ";

        if (flag)
        {
            ans += count;
        }
        cout << endl;
        count++;
        // cout << endl;
    }
    cout << ans;
    return 0;
}