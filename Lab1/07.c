#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 1000

bool contains(int wfreq[], int sfreq[])
{

    for (int i = 0; i < 26; i++)
    {
        if (sfreq[i] < wfreq[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{

    char s[SIZE];
    gets(s);
    int n = strlen(s);
    char w[SIZE];
    gets(w);
    int wlen = strlen(w);
    int l = 0, r = 0;
    int sfreq[26];
    int wfreq[26];
    memset(sfreq, 0, sizeof(sfreq));
    memset(wfreq, 0, sizeof(wfreq));

    for (int i = 0; i < wlen; i++)
    {
        wfreq[w[i] - 'a']++;
    }

    sfreq[s[0] - 'a']++;

    int minl = 0;
    int minr = 0;
    int minsz = 2000;

    while (r < n)
    {

        if (l > r)
        {
            r++;
            if (r < n)
            {
                sfreq[s[r] - 'a']++;
            }
            continue;
        }

        if (contains(wfreq, sfreq))
        {
            int currsz = r - l + 1;
            if (currsz < minsz)
            {
                minsz = currsz;
                minl = l;
                minr = r;
            }
            sfreq[s[l] - 'a']--;
            l++;
        }
        else
        {

            r++;
            if (r < n)
            {
                sfreq[s[r] - 'a']++;
            }
        }
    }

    if (minsz == 2000)
    {
        printf("NO WINDOW\n");
    }
    else
    {
        printf("%d %d\n", minl + 1, minr + 1);
        for (int i = minl; i <= minr; i++)
        {
            printf("%c", s[i]);
        }
    }

    return 0;
}