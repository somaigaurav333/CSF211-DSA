// Try using segmented seive once. For worst cases, this program takes upto 30s
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int maxFreq(int freqArr[])
{
    int num = 0;
    int freq = 0;
    for (int i = 0; i < 10; i++)
    {
        if (freqArr[i] > freq)
        {
            freq = freqArr[i];
            num = i;
        }
    }
    return num;
}

void calculateFreq(int num, int freqArr[])
{
    while (num > 0)
    {
        int lastDigit = num % 10;
        freqArr[lastDigit]++;
        num /= 10;
    }
}

void generateSeive(bool seive[], int n, int freqArr[])
{

    seive[1] = 1;

    for (int i = 2; i * i <= n; i++)
    {
        if (seive[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                seive[j] = 1;
            }
        }
    }
}

int main()
{

    int a, b;
    scanf("%d %d", &a, &b);
    bool *seive = (bool *)malloc((b + 1) * sizeof(bool));
    memset(seive, 0, sizeof(seive));
    int freqArr[10];
    memset(freqArr, 0, sizeof(freqArr));

    generateSeive(seive, b, freqArr);
    for (int i = a; i <= b; i++)
    {
        if (seive[i] == 0)
        {
            calculateFreq(i, freqArr);
        }
    }

    int maxNum = maxFreq(freqArr);
    printf("%d %d\n", maxNum, freqArr[maxNum]);

    return 0;
}