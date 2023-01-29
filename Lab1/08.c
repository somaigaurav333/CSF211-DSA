#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 1000

bool wordsEqual(char *word1, char *word2)
{

    int n1 = strlen(word1);
    int n2 = strlen(word2);
    if (n1 != n2)
    {
        return false;
    }

    for (int i = 0; i < n1; i++)
    {
        if (word1[i] != word2[i])
        {
            return false;
        }
    }

    return true;
}

char *reverseWord(char *word)
{

    int n = strlen(word);
    char *reverseWord = malloc(n * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        reverseWord[i] = word[n - i - 1];
    }
    return reverseWord;
}

int main()
{

    char s[SIZE];
    gets(s);
    int n = strlen(s);
    char *words[n];
    int st = 0;
    char currWord[n];
    memset(currWord, 0, sizeof(currWord));
    int currWordIndex = 0;
    int wordsIndex = 0;

    while (st <= n)
    {

        if ((s[st] == '\0') || (s[st] == ' '))
        {
            // create a new char array
            char *temp = (char *)malloc(currWordIndex * sizeof(char));
            strcpy(temp, currWord);

            // push it into words
            words[wordsIndex] = temp;
            wordsIndex++;

            for (int i = 0; i < currWordIndex; i++)
            {
                currWord[i] = 0;
            }
            currWordIndex = 0;
        }
        else
        {
            currWord[currWordIndex] = s[st];
            currWordIndex++;
        }
        st++;
    }

    char *wordsReverse[wordsIndex];
    for (int i = 0; i < wordsIndex; i++)
    {
        char *temp = reverseWord(words[i]);
        wordsReverse[i] = temp;
    }

    for (int i = 0; i < wordsIndex; i++)
    {
        printf("%s ", wordsReverse[i]);
    }

    printf("\n");

    int countPal = 0;

    for (int i = 0; i < wordsIndex; i++)
    {
        wordsReverse[i] = reverseWord(words[i]);
        if (strlen(wordsReverse[i]) == 1)
        {
            continue;
        }

        if (wordsEqual(words[i], wordsReverse[i]))
        {
            countPal++;
            printf("%s ", words[i]);
        }
    }

    if (countPal == 0)
    {
        printf("NO PALINDROMES\n");
    }

    return 0;
}