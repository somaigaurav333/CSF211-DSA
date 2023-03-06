#include <iostream>
using namespace std;
#define SIZE 100005

class MinStack
{

        int size;
        int arr[SIZE];
        int minele;

public:
        MinStack()
        {
                size = 0;
        }

        void push(int val)
        {
                if (size == 0)
                {
                        minele = val;
                        arr[size++] = val;
                }
                else
                {
                        if (val < minele)
                        {
                                arr[size++] = (2 * val - minele);
                                minele = val;
                        }
                        else
                        {
                                arr[size++] = val;
                        }
                }
        }

        void pop()
        {
                if (arr[size - 1] >= minele)
                {
                        size--;
                }
                else
                {
                        minele = 2 * minele - arr[size - 1];
                        size--;
                }
        }

        int top()
        {
                return arr[size - 1] < minele ? minele : arr[size - 1];
        }

        int getMin()
        {
                return minele;
        }
};

int main()
{

        int n;
        cin >> n;
        MinStack s = MinStack();
        for (int i = 0; i < n; i++)
        {
                int x;
                cin >> x;
                s.push(x);
        }

        int m;
        cin >> m;
        while (m--)
        {
                int op;
                cin >> op;

                if (op == 1)
                {
                        int val;
                        cin >> val;
                        s.push(val);
                }
                else if (op == 2)
                {
                        s.pop();
                }
                else if (op == 3)
                {
                        cout << s.top() << "\n";
                }
                else
                {
                        cout << s.getMin() << "\n";
                }
        }

        return 0;
}