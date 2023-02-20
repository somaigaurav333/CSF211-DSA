#include <stdio.h>
#define ll long long

int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll mini_a = (((n / m) * (n / m - 1)) / 2);
    ll mini = (m * mini_a) + ((n % m) * (n / m));
    ll maxi = ((n - m + 1) * (n - m)) / 2;
    printf("%lld %lld\n", mini, maxi);

    return 0;
}