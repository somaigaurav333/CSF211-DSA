#include <stdio.h>
#define ll long long

int main()
{

    ll int n;
    scanf("%lld", &n);
    int totalops = n * (n - 1) / 2;
    int reqops = totalops / 2;
    int l = 0, r = n;
    int mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        int currops = totalops - (((n - mid) * (n - mid - 1)) / 2);
        if (currops < reqops)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }

    printf("%d\n", r);

    return 0;
}