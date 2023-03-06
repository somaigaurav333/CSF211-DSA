#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int main()
{

    string s;
    cin >> s;
    int n = s.length();
    stack<char> seq;
    int ops = 0;
    for (int i = 0; i < n; i++)
    {
        char currbracket = s[i];
        if (currbracket == '(')
        {
            seq.push(currbracket);
        }
        else
        {
            if (seq.empty())
            {
                ops++;
            }
            else
            {
                seq.pop();
            }
        }
    }

    ops += seq.size();
    cout << ops << "\n";

    return 0;
}