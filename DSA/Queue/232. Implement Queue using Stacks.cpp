#include <stack>
#include <climits>
using namespace std;

class MyQueue
{
public:
    stack<int> one;
    stack<int> two;
    MyQueue()
    {
    }

    void push(int x)
    {
        one.push(x);
    }

    int pop()
    {
        if (!two.empty())
        {
            int val = two.top();
            two.pop();
            return val;
        }
        else
        {
            if (one.empty())
            {
                return -1;
            }
            else
            {
                while (!one.empty())
                {
                    two.push(one.top());
                    one.pop();
                }
                int val = two.top();
                two.pop();
                return val;
            }
        }
    }

    int peek()
    {
        if (!two.empty())
        {
            int val = two.top();

            return val;
        }
        else
        {
            if (one.empty())
            {
                return -1;
            }
            else
            {
                while (!one.empty())
                {
                    two.push(one.top());
                    one.pop();
                }
                int val = two.top();

                return val;
            }
        }
    }

    bool empty()
    {
        if (one.empty() && two.empty())
        {
            return true;
        }
        return false;
    }
};