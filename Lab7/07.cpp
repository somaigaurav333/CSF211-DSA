#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    make_heap(v.begin(), v.end());
    int ans = 0;
    while (k--)
    {
        int t = v.front();
        pop_heap(v.begin(), v.end());
        v.pop_back();
        ans += ((t + 1) / 2);
        v.push_back(t / 2);
        push_heap(v.begin(), v.end());
    }

    cout << ans << "\n";

    return 0;
}