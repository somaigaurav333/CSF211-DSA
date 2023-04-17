#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int leftCandle[n];
    int rightCandle[n];
    int prefixPlates[n];

    // left Candles

    if (s[0] == '|')
    {
        leftCandle[0] = 0;
    }
    else
    {
        leftCandle[0] = -1;
    }

    for (int i = 1; i < n; i++)
    {
        if (s[i] == '|')
        {
            leftCandle[i] = i;
        }
        else
        {
            leftCandle[i] = leftCandle[i - 1];
        }
    }

    // right Candles

    if (s[n - 1] == '|')
    {
        rightCandle[n - 1] = 0;
    }
    else
    {
        leftCandle[n - 1] = -1;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == '|')
        {
            rightCandle[i] = i;
        }
        else
        {
            rightCandle[i] = rightCandle[i + 1];
        }
    }

    // prefix Plates

    if (s[0] == '*')
    {
        prefixPlates[0] = 1;
    }
    else
    {
        prefixPlates[0] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        if (s[i] == '*')
        {
            prefixPlates[i] = 1 + prefixPlates[i - 1];
        }
        else
        {
            prefixPlates[i] = prefixPlates[i - 1];
        }
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int lcandle = rightCandle[l];
        int rcandle = leftCandle[r];
        if (lcandle == -1 || rcandle == -1)
        {
            cout << 0 << "\n";
        }
        else
        {
            int plates = prefixPlates[rcandle];
            if (l > 0)
            {
                plates -= prefixPlates[lcandle - 1];
            }

            cout << plates << "\n";
        }
    }

    return 0;
}