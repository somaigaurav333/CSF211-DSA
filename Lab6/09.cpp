#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int main()
{

    stack<string> s;

    string path;
    cin >> path;
    int i = 0;
    int n = path.length();
    while (i < n)
    {
        while ((i < n) && (path[i] == '/'))
        {
            i++;
        }

        if (i == n)
        {
            break;
        }

        string currDirectory;

        while ((i < n) && (path[i] != '/'))
        {
            currDirectory += path[i];
            i++;
        }

        if (currDirectory == ".")
        {
            continue;
        }
        else if (currDirectory == "..")
        {
            s.pop();
        }
        else
        {
            s.push(currDirectory);
        }
    }

    string simplifiedPath;

    if (s.empty())
    {
        cout << "/\n";
    }
    else
    {
        while (!s.empty())
        {
            simplifiedPath = '/' + s.top() + simplifiedPath;
            s.pop();
        }

        cout << simplifiedPath << "\n";
    }

    return 0;
}