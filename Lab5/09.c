#include <stdio.h>
#define ll long long

int main()
{

    ll n, k;
    scanf("%lld %lld", &n, &k);
    int arr[n];
    int numodds = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] & 1)
        {
            numodds++;
        }
    }

    ll ans = 0;

    int oddindex[numodds];
    int ptr = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & 1)
        {
            oddindex[ptr++] = i;
        }
    }

    for (int i = 0; i <= (numodds - k); i++)
    {
        int j = (i + k - 1);
        ll startOptions = oddindex[i];
        ll endOptions = -oddindex[j];
        if (i == 0)
        {
            startOptions++;
        }
        else
        {
            startOptions -= oddindex[i - 1];
        }

        if (j == numodds - 1)
        {
            endOptions += n;
        }
        else
        {
            endOptions += oddindex[j + 1];
        }

        ans += (startOptions * endOptions);
    }

    printf("%lld\n", ans);

    return 0;
}