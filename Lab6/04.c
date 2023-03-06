#include <stdio.h>
#include <string.h>

int main()
{

    int n;
    scanf("%d", &n);
    int uniquenumIndex = 0;
    int arr[n];
    int freqArr[n + 5];
    memset(freqArr, 0, sizeof(freqArr));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        freqArr[arr[i]]++;
        while ((uniquenumIndex <= i) && (freqArr[arr[uniquenumIndex]] != 1))
        {
            uniquenumIndex++;
        }

        if (uniquenumIndex > i)
        {
            printf("-1 ");
        }
        else
        {
            printf("%d ", arr[uniquenumIndex]);
        }
    }

    printf("\n");

    return 0;
}