#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int main()
{

    int a, b;
    scanf("%d %d", &a, &b);
    int ans = 1;
    for (int i = 1; i * i <= a; i++)
    {

        if ((a % i) > 0)
        {
            continue;
        }

        int div2 = a / i;
        if ((div2 > ans) && (gcd(div2, b) == 1))
        {
            ans = div2;
        }
        else if ((div2 != i) && (i > ans) && (gcd(i, b) == 1))
        {
            ans = i;
        }
    }

    printf("%d\n", ans);

    return 0;
}