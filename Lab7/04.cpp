#include <bits/stdc++.h>
using namespace std;

int n;

int sum = 0;

void GST(int node, int tree[])
{
    if (node >= n || tree[node] == -1)
    {
        return;
    }

    GST(2 * node + 2, tree);
    sum += tree[node];
    tree[node] = sum;
    GST(2 * node + 1, tree);
}

int main()
{

    cin >> n;
    int tree[n];
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }

    GST(0, tree);

    for (int i = 0; i < n; i++)
    {
        cout << tree[i] << " ";
    }

    cout << "\n";

    return 0;
}