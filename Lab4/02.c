#include <stdio.h>

void merge(int arr[], int l, int mid, int r)
{
    int temparr[r - l + 1];
    int k = 0;
    int i = l, j = mid + 1;
    while ((i <= mid) && (j <= r))
    {
        if (arr[i] <= arr[j])
        {
            temparr[k] = arr[i];
            i++;
        }
        else
        {
            temparr[k] = arr[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        temparr[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r)
    {
        temparr[k] = arr[j];
        j++;
        k++;
    }

    for (int st = l; st <= r; st++)
    {
        arr[st] = temparr[st - l];
    }
}

void mergeSort(int arr[], int l, int r)
{

    if (r <= l)
    {
        return;
    }

    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main()
{

    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    int i = n;
    for (; i >= 1; i--)
    {
        if ((arr[n - i] >= i) && (arr[n - i - 1] <= i))
        {
            break;
        }
    }

    printf("%d\n", i);

    return 0;
}