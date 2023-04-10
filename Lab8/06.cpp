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
    int prefixXor[n];

    prefixXor[0] = arr[0];

    map<int, int> freq; // unordered_map will be more efficient
    freq[0] = 1;
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        prefixXor[i] = prefixXor[i - 1] ^ arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        ans += freq[prefixXor[i]];
        freq[prefixXor[i]]++;
    }

    cout << ans << "\n";

    return 0;
}