#include <stdio.h>

int count(int n, int i, int open, int close)
{
    if ((open + close) == n)
    {
        return 1;
    }

    int num = 0;

    if (open < (n / 2))
    {
        num += count(n, i + 1, open + 1, close);
    }

    if (close < open)
    {
        num += count(n, i + 1, open, close + 1);
    }

    return num;
}

void printSequences(int n, int i, int open, int close, char sequence[])
{

    if (i == n)
    {
        printf("%s\n", sequence);
    }

    if (open < (n / 2))
    {
        sequence[i] = '(';
        printSequences(n, i + 1, open + 1, close, sequence);
    }

    if (close < open)
    {
        sequence[i] = ')';
        printSequences(n, i + 1, open, close + 1, sequence);
    }
}

int main()
{

    int n;
    scanf("%d", &n);
    printf("%d\n", count(n, 0, 0, 0));
    char sequence[n + 1];
    sequence[n] = 0;
    printSequences(n, 0, 0, 0, sequence);
}