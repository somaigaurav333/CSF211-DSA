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

    int ans = 0;
    int j = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        while (j < n && (sum + arr[j]) <= k)
        {
            sum += arr[j];
            j++;
        }

        ans += (j - i);

        sum -= arr[i];
    }

    cout << ans << "\n";

    return 0;
}