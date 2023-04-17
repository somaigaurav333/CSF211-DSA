#include <bits/stdc++.h>
using namespace std;

static bool f(string s1, string s2)
{
    return (s1 + s2) > (s2 + s1);
}

int main()
{
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n, f);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    cout << "\n";

    return 0;
}