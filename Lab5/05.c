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

    int i = 0, j = 0;
    int ans = 0;
    int cnt = (arr[0] == 0);
    while (j < n)
    {

        if (cnt > k)
        {
            cnt -= (arr[i] == 0);
            i++;
        }
        else
        {
            j++;
            if (j == n)
            {
                break;
            }
            cnt += (arr[j] == 0);

            int currWindowLength = (j - i + 1);
            if ((cnt <= k) && (currWindowLength > ans))
            {
                ans = currWindowLength;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}