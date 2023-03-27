#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    int tree[n];
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }

    int xindex = -1, yindex = -1;

    for (int i = 0; i < n; i++)
    {
        if (tree[i] == x)
        {
            xindex = i;
        }

        if (tree[i] == y)
        {
            yindex = i;
        }
    }

    unordered_map<int, bool> xancestors;
    while (xindex > 0)
    {
        xancestors[xindex] = 1;
        xindex = (xindex - 1) / 2;
    }

    int lca = 0;

    while (yindex > 0)
    {
        if (xancestors[yindex] == 1)
        {
            lca = yindex;
            break;
        }

        yindex = (yindex - 1) / 2;
    }

    cout << tree[lca] << "\n";

    return 0;
}