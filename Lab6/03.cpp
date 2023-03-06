#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<pair<int, int>> s; // num,index
    int maxarea = 0;
    s.push({-1, -1});

    for (int i = 0; i < n; i++)
    {
        int currheight;
        cin >> currheight;
        while (currheight <= s.top().first)
        {
            int popHeight = s.top().first;
            s.pop();
            int leftLimit = s.top().second;
            int rightLimit = i;
            int width = (rightLimit - leftLimit - 1);
            int currArea = popHeight * width;
            maxarea = max(maxarea, currArea);
        }

        s.push({currheight, i});
    }

    while (s.top().second > -1)
    {
        int popHeight = s.top().first;
        int rightLimit = n;
        s.pop();
        int leftLimit = s.top().second;
        int width = rightLimit - leftLimit - 1;
        int currArea = popHeight * width;
        maxarea = max(maxarea, currArea);
    }

    cout << maxarea << "\n";

    return 0;
}