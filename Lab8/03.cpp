#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x, y;
    cin >> x >> y;

    int arrx[n];
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        arrx[i] = arr[i] - (x * i);
    }

    for (int i = 0; i < n; i++)
    {
        m[arr[i] - (y * i)]++;
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        m[arr[i] - (y * i)]--;
        ans += m[arr[i] - (x * i)];
    }

    cout << ans << "\n";

    return 0;
}