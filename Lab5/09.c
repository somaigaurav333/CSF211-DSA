#include <stdio.h>
#define ll long long

int main()
{

    ll n, k;
    scanf("%lld %lld", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int i = 0, j = 0;
    ll ans = 0;
    ll odds = (arr[0] % 2);
    while (j < n)
    {
        if (odds == k)
        {
            ans++;
            j++;
            if (j == n)
            {
                break;
            }
            odds += (arr[j] % 2);
        }
        else if (odds > k)
        {
            odds -= (arr[i] % 2);
            i++;
        }
        else
        {
            j++;
            if (j == n)
            {
                break;
            }
            odds += (arr[j] % 2);
        }
    }

    printf("%lld\n", ans);

    return 0;
}