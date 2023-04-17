#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    int happiness = 0;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {

        happiness += arr[i];
        ans++;
        if (arr[i] < 0)
        {
            pq.push(-arr[i]);
            while (happiness < 0)
            {
                ans--;
                happiness += pq.top();
                pq.pop();
            }
        }
    }

    cout << ans << "\n";

    return 0;
}