#include <bits/stdc++.h>
using namespace std;

bool satisfies(int arr[], int n, int k, int m)
{

    int people = 1;
    int currPages = 0;

    for (int i = 0; i < n; i++)
    {
        if (currPages + arr[i] > k)
        {
            currPages = arr[i];
            people++;
        }
        else
        {
            currPages += arr[i];
        }
    }

    return people <= m;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int arr[n];
    int l = 1, r = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        l = max(l, arr[i]);
        r += arr[i];
    }

    int mid;

    while (l < r)
    {
        mid = (l + r) / 2;
        if (satisfies(arr, n, mid, m))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << r << "\n";

    return 0;
}