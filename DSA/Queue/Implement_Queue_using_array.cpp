#include <iostream>
#include <vector>
using namespace std;

class QueueUsingArray
{
public:
    int *arr;
    int front;
    int back;
    int size;
    int capacity;

    QueueUsingArray(int s)
    {
        arr = new int[s];
        front = 0;
        back = 0;
        size = 0;
        capacity = s;
    }

    int Size()
    {
        return size;
    }

    bool empty()
    {
        return size == 0;
    }

    void push(int val)
    {
        if (size == capacity)
        {
            cout << "Queue is full" << endl;
            return;
        }

        front = (front + 1) % capacity;
        arr[front] = val;
        size++;
    }

    int pop()
    {
        if (empty())
        {
            return -1;
        }
        int val = arr[back];
        back = (back + 1) % capacity;
        size--;
        return val;
    }

    int Front()
    {
        if (empty())
        {
            return -1;
        }
        return arr[front];
    }
};

int main()
{
    QueueUsingArray q(5);

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.Front() << endl;
    cout << "Size: " << q.Size() << endl;

    cout << "Pop: " << q.pop() << endl;
    cout << "Pop: " << q.pop() << endl;

    cout << "Front: " << q.Front() << endl;
    cout << "Size: " << q.Size() << endl;

    q.push(40);
    q.push(50);
    q.push(60);

    cout << "Front: " << q.Front() << endl;
    cout << "Size: " << q.Size() << endl;

    cout << "Pop: " << q.pop() << endl;
    cout << "Pop: " << q.pop() << endl;

    cout << "Front: " << q.Front() << endl;
    cout << "Size: " << q.Size() << endl;

    return 0;
}