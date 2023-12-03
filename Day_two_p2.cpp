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
        cerr << "Error opening file" << endl;
    }
    int ans = 0;
    for (auto line : lines)
    {
        int red = 0, blue = 0, green = 0;
        for (int i = 7; i < line.size(); i++)
        {
            if (isdigit(line[i]))
            {
                if (!isdigit(line[i + 1]))
                {
                    if (line[i + 2] == 'r')
                    {
                        red = max(red, line[i] - '0');
                    }
                    if (line[i + 2] == 'b')
                    {
                        blue = max(blue, line[i] - '0');
                    }
                    if (line[i + 2] == 'g')
                    {
                        green = max(green, line[i] - '0');
                    }
                }
                else
                {
                    string cur = "";
                    cur += line[i];
                    cur += line[i + 1];
                    if (line[i + 3] == 'r')
                    {
                        red = max(red, stoi(cur));
                    }
                    if (line[i + 3] == 'b')
                    {
                        blue = max(blue, stoi(cur));
                    }
                    if (line[i + 3] == 'g')
                    {
                        green = max(green, stoi(cur));
                    }
                }
            }
        }
        ans += (red * green * blue);
    }
    cout << ans;
    return 0;
}