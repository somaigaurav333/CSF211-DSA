#include <stdio.h>
#include <stdbool.h>

bool isLengthPossible(int arr[], int n, int l, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += (arr[i] / l);
        if (count >= k)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    int l = 0, r = 1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > r)
        {
            r = arr[i];
        }
    }

    int mid;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (isLengthPossible(arr, n, mid, k))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    printf("%d", l);
}