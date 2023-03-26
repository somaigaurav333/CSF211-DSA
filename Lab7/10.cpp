#include <bits/stdc++.h>
using namespace std;

// For logic of this question :-   https://www.geeksforgeeks.org/k-maximum-sum-combinations-two-arrays/

class CombinationSum
{
public:
    int sum; // A[i] + B[j]
    int i;   // index i
    int j;   // index j

    CombinationSum(int sum, int i, int j)
    {
        this->sum = sum;
        this->i = i;
        this->j = j;
    }
};

/*
This class is used by the priority queue to compare the order of 2 elements
and swap them if their position according to the priority is wrong.

IMP: Note that you are overloading the function named "operator" from the library, so the name should be
exactly same. Notice the empty braces after the name of the function. Also note that the parameters are actually
addresses of the elements (pass by reference), and not just the classes

*/

class CompareClass
{
public:
    bool operator()(CombinationSum &below, CombinationSum &above)
    {
        if (below.sum <= above.sum)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    int A[n], B[n];

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    sort(A, A + n, greater<int>()); // Sort array A in descending order
    sort(B, B + n, greater<int>()); // Sort array B in descending order

    priority_queue<CombinationSum, vector<CombinationSum>, CompareClass> pq; // Basically a priority queue which can store element of type CombinationSum

    // This set keeps track of all (i, j) pairs which we have already accounted for, as we can't count them again
    set<pair<int, int>> s; // <i, j>

    s.insert({0, 0});
    pq.push(CombinationSum(A[0] + B[0], 0, 0));

    while (k--)
    {
        CombinationSum t = pq.top();
        pq.pop();
        cout << t.sum << " ";
        int i = t.i;
        int j = t.j;

        if ((s.find({i + 1, j}) == s.end()) && (i + 1 < n)) // basically (i+1,j) isn't in the set, so we haven't counted it yet, and index i+1 is in the bounds
        {
            pq.push(CombinationSum(A[i + 1] + B[j], i + 1, j));
            s.insert({i + 1, j});
        }

        if ((s.find({i, j + 1}) == s.end()) && (j + 1 < n)) // basically (i,j+1) isn't in the set, so we haven't counted it yet, and index j+1 is in the bounds
        {
            pq.push(CombinationSum(A[i] + B[j + 1], i, j + 1));
            s.insert({i, j + 1});
        }
    }

    return 0;
}