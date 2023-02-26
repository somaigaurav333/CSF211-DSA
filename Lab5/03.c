#include <stdio.h>
#include <string.h>
#define ll long long

int check(int freq[], int k)
{
    for (int i = 0; i < k; i++)
    {
        if (freq[i] == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    ll n, k;
    scanf("%lld %lld\n", &n, &k);
    char s[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &s[i]);
    }

    int freq[k];
    memset(freq, 0, sizeof(freq));
    freq[s[0] - 'a']++;
    int i = 0, j = 0;
    ll ans = 0;

    while (j < n)
    {

        if (check(freq, k) == 1)
        {
            ans += (n - j);
            freq[s[i] - 'a']--;
            i++;
        }
        else
        {
            j++;
            freq[s[j] - 'a']++;
        }
    }

    printf("%lld\n", ans);

    return 0;
}