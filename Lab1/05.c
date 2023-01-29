#include <stdio.h>
#include <string.h>

int main()
{

    int n;
    scanf("%d", &n);
    int sz = 2 * n - 1;
    int matrix[sz][sz];
    memset(matrix, 0, sizeof(matrix));
    int left = 0;
    int right = sz - 1;
    int top = 0;
    int bottom = sz - 1;
    int currnum = 2 * n * n;
    int i = sz - 1, j = sz - 1;
    //-1 = - , -2 = |

    while (currnum > 2)
    {
        while (j > left)
        {
            matrix[i][j] = currnum;
            currnum -= 2;
            j--;
            matrix[i][j] = -1;
            j--;
        }

        bottom -= 2;

        while (i > top)
        {
            matrix[i][j] = currnum;
            currnum -= 2;
            i--;
            matrix[i][j] = -2;
            i--;
        }

        left += 2;

        while (j < right)
        {
            matrix[i][j] = currnum;
            currnum -= 2;
            j++;
            matrix[i][j] = -1;
            j++;
        }

        top += 2;

        while (i < bottom)
        {
            matrix[i][j] = currnum;
            currnum -= 2;
            i++;
            matrix[i][j] = -2;
            i++;
        }

        matrix[i][j] = currnum;
        right -= 2;
    }

    if (n % 2 == 1)
    {
        matrix[sz / 2][sz / 2] = 2;
    }

    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            if (matrix[i][j] == -1)
            {
                printf(" - ");
            }
            else if (matrix[i][j] == -2)
            {
                printf(" | ");
            }
            else if (matrix[i][j] == 0)
            {
                printf("   ");
            }
            else
            {
                printf("%3d", matrix[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}