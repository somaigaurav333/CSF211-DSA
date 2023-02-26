#include <stdio.h>
#include <time.h>
#define ll long long

int main()
{

    int n;
    scanf("%d", &n);
    ll randomNumber;
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        scanf("%lld", &x);
        t = time(NULL);
        if (((t + x) % i) == 0)
        {
            randomNumber = x;
        }

        printf("Random Number: %lld\n", randomNumber);
    }

    return 0;
}