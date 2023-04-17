#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] -= k;
    }

    for (int i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
    }

    map<int, int> m;

    m[0] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += m[arr[i]];
        m[arr[i]]++;
    }

    cout << ans << "\n";

    return 0;
}