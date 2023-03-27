#include <bits/stdc++.h>
using namespace std;

int noOfPaths(int curr, int tree[], int n, int target)
{
    if (curr >= n || tree[curr] == -1)
    {
        return 0;
    }

    int leftindex = 2 * curr + 1;
    int rightindex = 2 * curr + 2;

    if ((leftindex >= n || tree[leftindex] == -1) && (rightindex >= n || tree[rightindex] == -1))
    {
        if (target == tree[curr])
        {
            return 1;
        }

        return 0;
    }

    return noOfPaths(leftindex, tree, n, target - tree[curr]) + noOfPaths(rightindex, tree, n, target - tree[curr]);
}

int main()
{
    int n, target;
    cin >> n >> target;
    int tree[n];
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }

    cout << noOfPaths(0, tree, n, target) << "\n";

    return 0;
}