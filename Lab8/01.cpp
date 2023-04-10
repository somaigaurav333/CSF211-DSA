#include <bits/stdc++.h>
using namespace std;

string sortString(string s)
{

    int freq[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'a']++;
    }

    string sortedString;

    for (int i = 0; i < 26; i++)
    {
        char curr_ch = 'a' + i;
        for (int j = 0; j < freq[i]; j++)
        {
            sortedString = sortedString + curr_ch;
        }
    }

    return sortedString;
}

int main()
{
    int n, a_random_useless_variable_for_retards_who_code_in_C;
    cin >> n >> a_random_useless_variable_for_retards_who_code_in_C;
    map<string, int> m;
    int ans = 0;
    while (n--)
    {
        string s;
        cin >> s;
        string sortedString = sortString(s);
        ans += m[sortedString];
        m[sortedString]++;
    }

    cout << ans << "\n";

    return 0;
}