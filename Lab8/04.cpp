#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, q;
    cin >> n >> q;

    map<int, bool> ones; // set also works

    while (q--)
    {
        int query, k;
        cin >> query >> k;
        if (query == 1)
        {
            if (ones.find(k) == ones.end())
            {
                ones[k] = 1;
            }
            else
            {
                ones.erase(k);
            }
        }
        else if (query == 2)
        {
            auto ptr = ones.lower_bound(k);
            if (ptr == ones.end())
            {
                cout << -1 << " ";
            }
            else
            {
                cout << ptr->first << "\n";
            }
        }
        else if (query == 3)
        {
            auto ptr = ones.upper_bound(k);
            if (ones.empty() || ptr == ones.begin())
            {
                cout << -1 << " ";
            }
            else
            {

                ptr--;
                cout << ptr->first << "\n";
            }
        }
    }

    return 0;
}