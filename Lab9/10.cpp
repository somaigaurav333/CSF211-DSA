#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++)
    {
        int a, d;
        cin >> a >> d;
        arr[i] = {a, d};
    }

    sort(arr, arr + n);

    priority_queue<int, vector<int>, greater<int>> pq;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        while ((!pq.empty()) && (arr[i].first > pq.top()))
        {
            pq.pop();
        }

        pq.push(arr[i].second);
        ans = max(ans, (int)pq.size());
    }

    cout << ans << "\n";

    return 0;
}