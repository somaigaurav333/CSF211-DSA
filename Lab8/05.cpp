#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<int, bool, greater<int>> maparray[m];

    unordered_map<int, int> freq;

    // first window

    for (int i = 0; i < m; i++)
    {
        int curr = arr[i];
        if (freq.find(curr) == freq.end())
        {
            freq[curr] = 1;
            maparray[0][curr] = 1;
        }
        else
        {
            int currfreq = freq[curr];
            maparray[currfreq - 1].erase(curr);
            freq[curr]++;
            maparray[currfreq][curr] = 1;
        }
    }

    if (maparray[k - 1].empty())
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << maparray[k - 1].begin()->first << "\n";
    }

    // rest windows

    for (int i = m; i < n; i++)
    {

        // removing the leftmost element from window
        int remove = arr[i - m];
        int currfreq = freq[remove];
        maparray[currfreq - 1].erase(remove);
        freq[remove]--;
        if (freq[remove] == 0)
        {
            freq.erase(remove);
        }
        else
        {
            maparray[freq[remove] - 1][remove] = 1;
        }

        // adding the rightmost element to the window

        int curr = arr[i];
        if (freq.find(curr) == freq.end())
        {
            freq[curr] = 1;
            maparray[0][curr] = 1;
        }
        else
        {
            int currfreq = freq[curr];
            maparray[currfreq - 1].erase(curr);
            freq[curr]++;
            maparray[currfreq][curr] = 1;
        }

        // printing the element

        if (maparray[k - 1].empty())
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << maparray[k - 1].begin()->first << "\n";
        }
    }

    return 0;
}