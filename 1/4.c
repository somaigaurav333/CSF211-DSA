#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    int elements[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elements[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (elements[i] < 0)
        {
            printf("%d ", elements[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (elements[i] > 0)
        {
            printf("%d ", elements[i]);
        }
    }

    return 0;
}