#include <bits/stdc++.h>
using namespace std;

class Compare
{
public:
    bool operator()(pair<int, int> &below, pair<int, int> &above)
    {
        return above.first < below.first;
    }
};

int main()
{
    int k;
    cin >> k;
    vector<int> v[k];
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq; // val, index of vector
    int indices[k];
    for (int i = 0; i < k; i++)
    {
        pq.push({v[i][0], i});
        indices[i] = 1;
    }

    while (!pq.empty())
    {
        int val = pq.top().first;
        int i = pq.top().second;
        pq.pop();
        cout << val << " ";
        if (indices[i] < v[i].size())
        {
            pq.push({v[i][indices[i]], i});
            indices[i]++;
        }
    }

    return 0;
}