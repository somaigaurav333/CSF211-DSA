#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int ans = 0;

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);
        if ((n % 2) == 1)
        {
            ans ^= x;
        }
    }

    if ((m % 2 == 1))
    {
        for (int i = 0; i < n; i++)
        {
            ans ^= a[i];
        }
    }

    printf("%d\n", ans);

    return 0;
}