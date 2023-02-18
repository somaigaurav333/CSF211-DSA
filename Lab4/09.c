#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int finalGcd = 0;
    int removeNumIndex = 0;
    for (int i = 0; i < n; i++)
    {
        int newGcd;
        newGcd = gcd(finalGcd, arr[i]);
        if (newGcd != finalGcd)
        {
            removeNumIndex = i;
        }

        finalGcd = newGcd;
    }

    int maxGcd = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == removeNumIndex)
        {
            continue;
        }

        maxGcd = gcd(maxGcd, arr[i]);
    }

    printf("%d  \n", maxGcd);
}