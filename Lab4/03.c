#include <stdio.h>
#include <string.h>

int freq[1000000];

int main()
{

    memset(freq, 0, sizeof(freq));
    int n;
    scanf("%d", &n);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        x = (x / 5) * 5; // *5 not necessary if you want to optimize the code
        if (x > maxi)
        {
            maxi = x;
        }

        freq[x]++;
    }

    long int ans = 0;
    for (int i = 0; i <= maxi; i++)
    {
        int f = freq[i];
        ans += (f * (f - 1)) / 2;
    }

    printf("%ld\n", ans);
}