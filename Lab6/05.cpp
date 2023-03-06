#include <iostream>
#include <string.h>
#include <deque>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    deque<pair<int, int>> d; // num, index

    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        while ((!d.empty()) && (d.back().first <= x))
        {
            d.pop_back();
        }

        d.push_back({x, i});
    }

    cout << d.front().first << " ";

    for (int i = k; i < n; i++)
    {
        int x;
        cin >> x;
        if (d.front().second <= (i - k))
        {
            d.pop_front();
        }

        while ((!d.empty()) && (d.back().first <= x))
        {
            d.pop_back();
        }

        d.push_back({x, i});

        cout << d.front().first << " ";
    }

    cout << "\n";
    return 0;
}