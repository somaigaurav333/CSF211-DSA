#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int main()
{

    int n;
    cin >> n;
    int arr[n];
    int maxi = -1;
    int maxindex = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > maxi)
        {
            maxi = arr[i];
            maxindex = i;
        }
    }

    stack<pair<int, int>> s1; //<num,index>
    stack<pair<int, int>> s2; //<num,index>
    s2.push({maxi, maxindex});
    for (int i = maxindex + 1; i < n; i++)
    {
        s1.push({arr[i], i});
    }

    for (int i = 0; i < maxindex; i++)
    {
        s1.push({arr[i], i});
    }

    int output[n];
    output[maxindex] = -1;
    while (!s1.empty())
    {
        while ((!s2.empty()) && ((s1.top().first >= s2.top().first)))
        {
            s2.pop();
        }

        if (s2.empty())
        {
            output[s1.top().second] = -1;
        }
        else
        {
            int minvisits = (s2.top().second - s1.top().second);
            if (minvisits < 0)
            {
                minvisits += n;
            }
            output[s1.top().second] = minvisits;
        }

        s2.push(s1.top());
        s1.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << output[i] << " ";
    }
    cout << "\n";

    return 0;
}