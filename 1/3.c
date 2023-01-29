#include <stdio.h>
#include <stdbool.h>

bool subsetSum(int set[], int currIndex, int n, int sum, bool combination[])
{

    if (sum == 0)
    {
        return true;
    }

    if (currIndex >= n)
    {
        return false;
    }

    if (set[currIndex] > sum)
    {
        return subsetSum(set, currIndex + 1, n, sum, combination);
    }

    if (subsetSum(set, currIndex + 1, n, sum, combination))
    {
        return true;
    }

    if (subsetSum(set, currIndex + 1, n, sum - set[currIndex], combination))
    {
        combination[currIndex] = 1;
        return true;
    }

    return false;
}

int main()
{
    int n, target;
    scanf("%d", &n);
    int set[n];
    bool combination[n];
    memset(combination, 0, sizeof(combination));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }
    scanf("%d", &target);

    if (subsetSum(set, 0, n, target, combination))
    {
        printf("POSSIBLE\n");
        for (int i = 0; i < n; i++)
        {
            if (combination[i])
            {
                printf("%d ", i);
            }
        }
    }
    else
    {
        printf("NOT POSSIBLE\n");
    }

    return 0;
}