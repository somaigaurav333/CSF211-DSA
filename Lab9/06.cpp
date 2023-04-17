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
    }

    sort(arr, arr + n);

    int r = (n + 1) / 2;
    int ans = 0;
    for (int l = 0; l < n / 2; l++)
    {
        while (r < n && arr[r] < (arr[l] + k))
        {
            r++;
        }

        if (r < n)
        {
            ans++;
            r++;
        }
    }

    cout << ans << "\n";

    return 0;
}
