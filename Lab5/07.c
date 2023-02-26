#include <stdio.h>
#include <string.h>

int minimum(int a, int b)
{
    return (a <= b) ? a : b;
}

int maximum(int a, int b)
{
    return (a >= b) ? a : b;
}

int minFairness(int buckets[], int currBucket, int n, int maxPeices, int peices[], int k)
{

    if (currBucket == n)
    {
        return maxPeices;
    }

    int currMinFairness = 99999999;

    for (int i = 0; i < k; i++)
    {
        peices[i] += buckets[currBucket];
        currMinFairness = minimum(currMinFairness, minFairness(buckets, currBucket + 1, n, maximum(maxPeices, peices[i]), peices, k));
        peices[i] -= buckets[currBucket];
    }

    return currMinFairness;
}

int main()
{

    int n, k;
    scanf("%d %d", &n, &k);
    int buckets[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &buckets[i]);
    }

    int peices[k];
    memset(peices, 0, sizeof(peices));

    printf("%d\n", minFairness(buckets, 0, n, 0, peices, k));

    return 0;
}