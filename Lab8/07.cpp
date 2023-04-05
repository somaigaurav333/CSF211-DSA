#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

/*
Note that double has a precision of approx 15 digits, so most of the cases will work, but if the slope of lines has more
than 15 digits, then the program can give errors

Refer to 07Precise for code that is completely precise
*/

int main()
{

    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    map<pair<double, double>, int> m; // Slope, c : freq

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int slopeNumerator = y[j] - y[i];
            int slopeDenominator = x[j] - x[i];
            double c = 0;

            if (slopeDenominator == 0)
            {
                c = x[i];
                m[{INF, c}]++;
            }
            else
            {
                c = y[i] - (slopeNumerator / slopeDenominator) * x[i];
                m[{(1.0 * slopeNumerator / slopeDenominator), c}]++;
            }
        }
    }

    int ans = (n * (n - 1) * (n - 2)) / 6; // nC3
    for (auto ele : m)
    {
        int freq = ele.second;
        ans -= (freq * (freq - 1) * (freq - 2)) / 6; // ans -= freqC3
    }

    cout << ans << "\n";

    return 0;
}