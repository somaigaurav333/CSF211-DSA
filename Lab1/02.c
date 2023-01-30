#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool colEqual(int **A, int **B, int i, int j, int m, int n, int p, int q)
{

    for (int bCol = 0; bCol < q; bCol++)
    {
        bool areEqual = 1;
        for (int x = 0; x < p; x++)
        {
            if (B[x][bCol] != A[i + x][j])
            {
                areEqual = 0;
                break;
            }
        }
        if (areEqual)
        {
            return 1;
        }
    }

    return 0;
}

bool rowEqual(int **A, int **B, int i, int j, int m, int n, int p, int q)
{
    for (int bRow = 0; bRow < p; bRow++)
    {
        bool areEqual = 1;
        for (int y = 0; y < q; y++)
        {
            if (B[bRow][y] != A[i][j + y])
            {
                areEqual = 0;
                break;
            }
        }
        if (areEqual)
        {
            return 1;
        }
    }

    return 0;
}

bool areEqual(int **A, int **B, int i, int j, int m, int n, int p, int q)
{

    for (int x = 0; x < p; x++)
    {
        for (int y = 0; y < q; y++)
        {
            if (B[x][y] != A[x + i][y + j])
            {
                return 0;
            }
        }
    }

    return 1;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int **A = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        int *temp = (int *)malloc(n * sizeof(int));
        A[i] = temp;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &temp[j]);
        }
    }

    int p, q;
    scanf("%d %d", &p, &q);
    int **B = (int **)malloc(p * sizeof(int *));
    for (int i = 0; i < p; i++)
    {
        int *temp = (int *)malloc(q * sizeof(int));
        B[i] = temp;
        for (int j = 0; j < q; j++)
        {
            scanf("%d", &temp[j]);
        }
    }

    bool submatrix = 0;
    for (int i = 0; i + p - 1 < m; i++)
    {
        for (int j = 0; j + q - 1 < n; j++)
        {
            if (areEqual(A, B, i, j, m, n, p, q))
            {
                submatrix = 1;
                break;
            }
        }
    }

    if (submatrix)
    {
        printf("YES\n");
    }
    else
    {
        bool partial = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j + q - 1 < n; j++)
            {
                if (rowEqual(A, B, i, j, m, n, p, q))
                {
                    partial = 1;
                    break;
                }
            }
        }

        if (!partial)
        {
            for (int i = 0; i + p - 1 < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (colEqual(A, B, i, j, m, n, p, q))
                    {
                        partial = 1;
                        break;
                    }
                }
            }
        }

        if (partial)
        {
            printf("PARTIAL\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}