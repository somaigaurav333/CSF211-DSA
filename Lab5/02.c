#include <stdio.h>
#define ll long long

ll survivor(ll n, int lefttoright)
{

    if (n == 1)
    {
        return 1;
    }

    if (lefttoright == 1)
    {
        return 2 * (survivor(n / 2, 0));
    }

    if (n % 2 == 0)
    {
        return (2 * (survivor((n + 1) / 2, 1))) - 1;
    }

    return 2 * (survivor(n / 2, 1));
}

int main()
{

    ll n;
    scanf("%lld", &n);
    printf("%lld\n", survivor(n, 1));

    return 0;
}