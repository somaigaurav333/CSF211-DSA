#include <stdio.h>
#include <string.h>

int generateSeive(int arr[], int n)
{

    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }

        for (int j = i * i; j <= n; j += i)
        {
            arr[j] = 0;
        }
    }
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    int seive[n + 1];
    seive[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        seive[i] = 1;
    }

    generateSeive(seive, n);

    for (int i = 2; i <= n; i++)
    {
        seive[i] += seive[i - 1];
    }

    while (q--)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", seive[x]);
    }

    return 0;
}