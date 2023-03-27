#include <bits/stdc++.h>
using namespace std;

vector<int> postOrd;

void postOrder(int node, int n, int tree[])
{
    if (node >= n || tree[node] == -1)
    {
        return;
    }

    postOrder(2 * node + 1, n, tree);
    postOrder(2 * node + 2, n, tree);
    postOrd.push_back(tree[node]);
}

int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    int tree[n];
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }

    postOrder(0, n, tree);

    for (int x : postOrd)
    {
        if (x <= r && x >= l)
        {
            cout << x << " ";
        }
    }

    cout << "\n";

    return 0;
}