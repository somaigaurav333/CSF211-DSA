#include <stdio.h>
#define ll long long

int main()
{

    ll n;
    scanf("%lld", &n);
    ll l = 0, r = n;
    ll mid;
    while (l < r)
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
            l = mid;
            break;
        }
        else if (square < n)
        {

            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    printf("%lld\n", l);

    return 0;
}