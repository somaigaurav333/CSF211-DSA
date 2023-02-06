#include <stdio.h>
#include <stdlib.h>

struct Country
{
    char *name;
    int gold;
    int silver;
    int bronze;
};

typedef struct Country Country;

int isPosCorrect(Country c1, Country c2)
{
    if (c1.gold < c2.gold)
    {
        return 0;
    }

    if (c1.gold > c2.gold)
    {
        return 1;
    }

    if (c1.silver < c2.silver)
    {
        return 0;
    }

    if (c1.silver > c2.silver)
    {
        return 1;
    }

    if (c1.bronze < c2.bronze)
    {
        return 0;
    }
    if (c1.bronze > c2.bronze)
    {
        return 1;
    }

    return 0;
}

void bubbleSort(Country arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (isPosCorrect(arr[j], arr[j + 1]) == 0)
            {
                Country temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    Country arr[n];
    for (int i = 0; i < n; i++)
    {
        Country c;
        c.name = (char *)malloc(100 * sizeof(char));
        for (int i = 0; i < 100; i++)
        {
            c.name[i] = 0;
        }
        scanf("%s", c.name);
        scanf("%d", &c.gold);
        scanf("%d", &c.silver);
        scanf("%d", &c.bronze);
        arr[i] = c;
    }

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i].name);
    }

    return 0;
}