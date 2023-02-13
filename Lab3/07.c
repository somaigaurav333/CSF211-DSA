#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    if (arr[0] > k)
    {
        printf("NOT POSSIBLE\n");
    }
    else
    {

        int l = 0, r = n - 1;
        int mid;
        while (l < r)
        {
            mid = (l + r + 1) / 2;
            if (arr[mid] <= k)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        printf("%d\n", arr[l]);
    }
    return 0;
}