#include <stdio.h>
#include <string.h>
#define ll long long

int main()
{

    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    int freq[n];
    memset(freq, 0, sizeof(freq));
    ll ans = 0;
    ll currsum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        currsum += arr[i];
        int currmod = currsum % k;
        if (currmod == 0)
        {
            ans += (1 + (freq[0]));
        }
        else
        {
            ans += (freq[currmod]);
        }

        freq[currmod]++;
    }

    printf("%lld\n", ans);

    return 0;
}