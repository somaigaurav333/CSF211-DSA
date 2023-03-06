#include <iostream>
#include <stack>

using namespace std;

int main()
{

    stack<pair<int, int>> s;
    int n;
    cin >> n;
    s.push({10000000, -1});

    for (int i = 0; i < n; i++)
    {
        int currstock;
        cin >> currstock;
        while ((s.top().first) <= currstock)
        {
            s.pop();
        }

        cout << i - s.top().second << " ";

        s.push({currstock, i});
    }

    cout << "\n";

    return 0;
}