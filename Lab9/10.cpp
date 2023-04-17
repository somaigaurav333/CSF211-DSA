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

    int ans = 0;

    int i = 0;

    while (i < n)
    {
        int lastTime = arr[i].second;
        int currStations = 1;
        int j = i + 1;
        while ((j < n) && (arr[j].first <= lastTime))
        {
            currStations++;
            lastTime = max(lastTime, arr[j].second);
            j++;
        }

        ans = max(ans, currStations);
        i = j;
    }

    cout << ans << "\n";

    return 0;
}