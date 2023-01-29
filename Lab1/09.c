#include <stdio.h>
#include <string.h>

int main()
{
    int n, k;
    scanf("%d %d", &k, &n);
    int elements[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elements[i]);
    }

    int mid = (k + 1) / 2;

    for (int i = 0; i < n; i++)
    {
        if (elements[i] < mid)
        {
            printf("%d ", elements[i]);
        }
    }

    printf("%d ", mid);

    for (int i = 0; i < n; i++)
    {
        if (elements[i] > mid)
        {
            printf("%d ", elements[i]);
        }
    }

    return 0;
}