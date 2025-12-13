#include <stack>
#include <climits>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
                return false;

            if (c == ')')
            {
                if (st.top() != '(')
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
            else if (c == '}')
            {
                if (st.top() != '{')
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
            else if (c == ']')
            {
                if (st.top() != '[')
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
        }
    }
    if (!st.empty())
    {
        return false;
    }
    return true;
}