#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int val)
    {
        next = NULL;
        data = val;
    }
};

class QueueusingLL
{
public:
    Node *head;
    Node *tail;
    int size;

    QueueusingLL()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void push(int val)
    {
        Node *newhead = new Node(val);

        if (head == NULL)
        {
            head = newhead;
            tail = head;
        }
        else
        {
            tail->next = newhead;
            tail = tail->next;
        }
        size++;
    }

    int pop()
    {
        if (size == 0)
        {
            return -1;
        }

        int val = Front();
        head = head->next;
        size--;
        return val;
    }

    int Front()
    {
        if (size == 0)
        {
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
    QueueusingLL q;

    q.push(10);
    q.push(20);
    q.push(30);

    q.print();

    cout << "Front element: " << q.Front() << endl;
    cout << "Size: " << q.Size() << endl;

    cout << q.pop() << endl;
    cout << q.pop() << endl;

    cout << "Front element now: " << q.Front() << endl;
    cout << "Size now: " << q.Size() << endl;

    cout << q.pop() << endl;

    cout << "Trying to pop from empty queue: " << q.pop() << endl;
    cout << "Front on empty queue: " << q.Front() << endl;

    return 0;
}