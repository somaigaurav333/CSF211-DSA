#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;
    map<int, int> loses; // frequency array would be more efficient
    while (n--)
    {
        int w, l;
        cin >> w >> l;
        loses[l]++;
    }

    for (int i = 1; i <= k; i++)
    {
        if (loses.find(i) == loses.end() || loses[i] <= 1)
        {
            cout << i << " ";
        }
    }

    return 0;
}