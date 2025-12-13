#include <stack>
#include <climits>
using namespace std;

class MinStack
{
public:
    stack<int> st;
    stack<int> temp;
    int min;
    MinStack()
    {
        min = INT_MAX;
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            min = val;
        }
        else
        {
            if (val < min)
            {
                min = val;
            }
            st.push(val);
        }
    }

    void pop()
    {
        if (st.empty())
        {
            return;
        }
        else
        {
            st.pop();
            min = INT_MAX;
            while (!st.empty())
            {
                if (st.top() < min)
                {
                    min = st.top();
                }
                temp.push(st.top());
                st.pop();
            }

            while (!temp.empty())
            {
                st.push(temp.top());
                temp.pop();
            }
        }
    }

    int top()
    {
        if (st.empty())
        {
            return -1;
        }
        return st.top();
    }

    int getMin()
    {
        if (st.empty())
        {
            return -1;
        }
        return min;
    }
};



//O(1). Approach

class MinStack
{
public:
    stack<int> st;
    stack<int> mini;
    MinStack()
    {
    }

    void push(int val)
    {
        if (mini.empty())
        {
            mini.push(val);
            st.push(val);
        }
        else
        {
            if (val <= mini.top())
            {
                mini.push(val);
            }
            st.push(val);
        }
    }

    void pop()
    {
        if (st.empty())
        {
            return;
        }
        else
        {
            if (st.top() == mini.top())
            {
                st.pop();
                mini.pop();
            }
            else
            {
                st.pop();
            }
        }
    }

    int top()
    {
        if (st.empty())
        {
            return -1;
        }
        return st.top();
    }

    int getMin()
    {
        if (mini.empty())
        {
            return -1;
        }
        return mini.top();
    }
};
