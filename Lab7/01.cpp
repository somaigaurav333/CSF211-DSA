#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<int> prices;
    for (int i = 0; i < n; i++)
    {
        int price;
        cin >> price;
        prices.push(price);
    }

    for (int i = 0; i < m; i++)
    {

        int maxPrice = prices.top();
        prices.pop();
        prices.push(maxPrice / 2);
    }

    int cost = 0;
    while (!prices.empty())
    {
        int t = prices.top();
        prices.pop();
        cost += t;
    }

    cout << cost << "\n";

    return 0;
}