#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class StackUsingLL
{
public:
    Node *head;
    int size;

    StackUsingLL()
    {
        head = NULL;
        size = 0;
        cout << "Stack initialized" << endl;
    }

    void push(int val)
    {
        if (head == NULL)
        {
            Node *newhead = new Node(val);
            newhead->next = head;
            head = newhead;
        }
        else
        {
            Node *newhead = new Node(val);
            newhead->next = head;
            head = newhead;
        }
        size++;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    int top()
    {
        if (head == NULL)
        {
            cout << "Stack empty" << endl;
            return -1;
        }

        return head->data;
    }

    int Size()
    {
        return size;
    }

    void print()
    {
        if (head == NULL)
        {
            return;
        }

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main()
{

    StackUsingLL st;

    cout << st.Size() << endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.print();
    cout << st.top() << endl;
    st.pop();
    st.pop();
    cout << st.top() << endl;
    st.print();

    return 0;
}