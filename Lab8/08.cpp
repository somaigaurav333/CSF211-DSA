#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    map<string, int> m; // unordered_map will be more efficient

    for (int i = 0; i < n - 9; i++)
    {
        string currstr = s.substr(i, 10);
        m[currstr]++;
    }

    int cnt = 0;

    for (auto ele : m)
    {
        if (ele.second > 1)
        {
            cnt++;
        }
    }

    cout << cnt << "\n";

    for (auto ele : m)
    {
        if (ele.second > 1)
        {
            cout << ele.first << "\n";
        }
    }

    return 0;
}