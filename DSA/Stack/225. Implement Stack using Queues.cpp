#include <queue>
#include <climits>
using namespace std;

class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        if (q.size() == 0)
        {
            q.push(x);
        }
        else
        {
            q.push(x);
            int n = q.size() - 1;
            while (n > 0)
            {
                q.push(q.front());
                q.pop();
                n--;
            }
        }
    }

    int pop()
    {
        if (q.empty())
        {
            return -1;
        }

        int val = q.front();
        q.pop();
        return val;
    }

    int top()
    {
        if (q.empty())
        {
            return -1;
        }

        return q.front();
    }

    bool empty()
    {
        if (q.empty())
        {
            return true;
        }
        return false;
    }
};