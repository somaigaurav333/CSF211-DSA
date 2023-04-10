#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<int, int> fraction(int numerator, int denominator)
{
    int num;
    int den;

    if (denominator == 0)
    {
        num = 0;
        den = 0;
    }
    else
    {
        int reduce = __gcd(numerator, denominator);
        num = numerator / reduce;
        den = denominator / reduce;
    }

    return {num, den};
}

int32_t main()
{

    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    map<pair<pair<int, int>, pair<int, int>>, int> m; // { <slopeNumerator, slopeDenominator> , <cNumeratorm, cDenominator>} : freq

    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            int slopeNumerator = y[j] - y[i];
            int slopeDenominator = x[j] - x[i];
            int c = 0;

            if (slopeDenominator == 0)
            {
                c = x[i];
                m[{fraction(0, 0), fraction(c, 1)}]++;
            }
            else
            {
                int cDen = slopeDenominator;
                int cNum = (y[i] * slopeDenominator) - (slopeNumerator * x[i]);

                m[{fraction(slopeNumerator, slopeDenominator), fraction(cNum, cDen)}]++;
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