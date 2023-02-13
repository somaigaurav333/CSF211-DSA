#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int k = 1;
    int currval = arr[0];
    int l = 0, r = n - 1, mid = 0;
    bool next = 1;
    int nextIndex = 0;

    while (arr[nextIndex] != arr[n - 1])
    {
        k++;
        int currIndex = nextIndex;
        l = currIndex, r = n - 1;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (arr[mid] == arr[currIndex])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        nextIndex = l;
    }

    printf("%d\n", k);

    return 0;
}