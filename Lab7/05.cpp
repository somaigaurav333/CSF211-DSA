#include <bits/stdc++.h>
using namespace std;

int n, k;

int curr = 0;

int ans = -1;

void klargest(int node, int tree[])
{
    if (node >= n || tree[node] == -1)
    {
        return;
    }

    klargest(2 * node + 2, tree);

    curr++;

    if (curr == k)
    {
        ans = tree[node];
    }

    klargest(2 * node + 1, tree);
}

int main()
{

    cin >> n;
    int tree[n];

    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }

    cin >> k;

    klargest(0, tree);

    cout << ans << "\n";

    return 0;
}