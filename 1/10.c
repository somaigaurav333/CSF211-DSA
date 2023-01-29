#include <stdio.h>
#include <string.h>
#define SIZE 1000

int findChar(char *s, char currChar, int n, int visited[])
{
    for (int i = 0; i < n; i++)
    {
        if ((s[i] == currChar) && (visited[i] == 0))
        {
            return i;
        }
    }
    return -1;
}

void isAnagram(char *s, char *a, int n, int visited[])
{

    int isAnagram = 1;
    int mapping[n];
    for (int i = 0; i < n; i++)
    {
        int currChar = a[i];
        int mappedChar = findChar(s, currChar, n, visited);
        if (mappedChar == -1)
        {
            isAnagram = 0;
            break;
        }
        else
        {
            mapping[i] = mappedChar;
            visited[mappedChar] = 1;
        }
    }

    if (isAnagram == 0)
    {
        printf("NOT POSSIBLE\n");
    }
    else
    {
        printf("POSSIBLE\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", mapping[i] + 1);
        }
        printf("\n");
    }
}

int main()
{
    char s[SIZE];
    char a[SIZE];
    gets(s);
    gets(a);
    int n = strlen(s);
    int visited[n];
    memset(visited, 0, sizeof(visited));
    isAnagram(s, a, n, visited);

    return 0;
}