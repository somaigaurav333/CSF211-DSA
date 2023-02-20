#include <stdio.h>
#include <string.h>
#define ll long long

ll freq[1000000];

int main()
{

    memset(freq, 0, sizeof(freq));
    int n;
    scanf("%d", &n);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        scanf("%lld", &x);
        x = (x / 5) * 5; // *5 not necessary if you want to optimize the code
        if (x > maxi)
        {
            maxi = x;
        }

        freq[x]++;
    }

    ll ans = 0;
    for (int i = 0; i <= maxi; i++)
    {
        ll f = freq[i];
        ans += (f * (f - 1)) / 2;
    }

    printf("%lld\n", ans);
}