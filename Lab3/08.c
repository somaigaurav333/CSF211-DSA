#include <stdio.h>
#define ll long long

int main()
{

    ll n;
    scanf("%lld", &n);
    ll l = 1, r = n;
    ll mid;
    ll ans = -1;
    while (l <= r)
    {
        mid = (r + l + 1) / 2;
        if (mid > 1e9)
        {
            r = mid - 1;
            continue;
        }

        ll square = mid * mid;
        if (square == n)
        {
            ans = mid;
            break;
        }
        else if (square < n)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    printf("%lld\n", ans);

    return 0;
}