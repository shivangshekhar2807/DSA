#include <iostream>
#include <vector>
using namespace std;

class stackusingarray
{
public:
    int *arr;
    int ind;
    int size;
    int capacity;

    stackusingarray(int s)
    {
        arr = new int[s];
        ind = -1;
        size = 0;
        capacity = s;

        cout << "Stack initisalized" << endl;
    }

    void push(int val)
    {
        if (size == capacity)
        {
            cout << "Stack in full" << endl;
            return;
        }

        ind++;
        arr[ind] = val;

        size++;
        return;
    }

    int pop()
    {
        if (empty())
        {
            return -1;
        }

        int val = top();
        ind--;
        size--;
        return val;
    }

    int top()
    {
        if (empty())
        {
            return -1;
        }
        return arr[ind];
    }

    bool empty()
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    stackusingarray st(5);

    cout << st.pop() << endl;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.top() << endl;
    cout << st.empty() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.top() << endl;
    cout << st.empty() << endl;

    return 0;
}