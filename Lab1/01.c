#include <stdio.h>
#include <string.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int ri, ci, rh, ch;
    int matrixA[m][n];
    int matrixB[m][n];
    int sum = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrixA[i][j]);
            sum += matrixA[i][j];
            matrixB[i][j] = sum;
        }
    }

    scanf("%d %d %d %d", &ri, &ci, &rh, &ch);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    if ((ri + rh > m) || (ci + ch > n))
    {
        printf("NOT POSSIBLE\n");
    }
    else
    {
        sum = 0;
        for (int i = ri; i < ri + rh; i++)
        {
            for (int j = ci; j < ci + ch; j++)
            {
                sum += matrixB[i][j];
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}