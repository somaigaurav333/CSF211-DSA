#include <stdio.h>
#define ll long long

int main()
{

    ll n, k;
    scanf("%lld %lld", &n, &k);
    ll odds = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        scanf("%lld", &x);
        odds += (x & 1);
    }

    if (odds < k)
    {
        printf("0\n");
    }
    else
    {
        printf("%lld\n", odds - k + 1);
    }

    return 0;
}