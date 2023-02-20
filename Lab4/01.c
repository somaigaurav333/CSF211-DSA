#include <stdio.h>

struct Slot
{
    int st;
    int end;
};

typedef struct Slot Slot;

void merge(Slot arr[], int l, int mid, int r)
{

    int i = l, j = mid + 1;
    int k = 0;
    Slot temparr[r - l + 1];
    while ((i <= mid) && (j <= r))
    {
        if (arr[i].st < arr[j].st)
        {
            temparr[k++] = arr[i++];
        }
        else if (arr[i].st > arr[j].st)
        {
            temparr[k++] = arr[j++];
        }
        else
        {
            if (arr[i].end < arr[j].end)
            {
                temparr[k++] = arr[i++];
            }
            else
            {
                temparr[k++] = arr[j++];
            }
        }
    }

    while ((i <= mid))
    {
        temparr[k++] = arr[i++];
    }

    while ((j <= r))
    {
        temparr[k++] = arr[j++];
    }

    for (int x = l; x <= r; x++)
    {
        arr[x] = temparr[x - l];
    }
}

void mergeSort(Slot arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int mid = (l + r) / 2;

    mergeSort(arr, 0, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main()
{

    int n;
    scanf("%d", &n);
    Slot arr[n];
    for (int i = 0; i < n; i++)
    {
        Slot s;
        scanf("%d %d", &s.st, &s.end);
        arr[i] = s;
    }

    mergeSort(arr, 0, n - 1);

    Slot ans[n];
    int j = 0; // ans
    int i = 1; // arr
    ans[0] = arr[0];
    while (i < n)
    {
        if (arr[i].st <= ans[j].end)
        {
            if (ans[j].end < arr[i].end)
            {
                ans[j].end = arr[i].end;
            }
        }
        else
        {
            j++;
            ans[j] = arr[i];
        }

        i++;
    }

    printf("%d\n", j + 1);
    for (int x = 0; x <= j; x++)
    {
        printf("%d %d\n", ans[x].st, ans[x].end);
    }

    return 0;
}