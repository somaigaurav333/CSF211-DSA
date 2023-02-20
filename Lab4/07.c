#include <stdio.h>

void countingSort(int arr[], int n, int place)
{
    int output[n + 1];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        int ele = (arr[i] / place) % 10;
        count[ele]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {

        int ele = (arr[i] / place) % 10;
        int index = count[ele] - 1;
        count[ele]--;
        output[index] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void radixSort(int arr[], int n)
{

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }

    int place = 1;
    for (place = 1; maxi / place > 0; place *= 10)
    {
        countingSort(arr, n, place);
    }
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

    radixSort(arr, n);
}