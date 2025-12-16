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
        next = nullptr;
    }
};

Node *segregate(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *zero = zeroHead;

    Node *oneHead = new Node(-1);
    Node *one = oneHead;

    Node *twoHead = new Node(-1);
    Node *two = twoHead;

    while (head != NULL)
    {
        if (head->data == 0)
        {
            zero->next = head;
            zero = zero->next;
        }
        else if (head->data == 1)
        {
            one->next = head;
            one = one->next;
        }
        else
        {
            two->next = head;
            two = two->next;
        }
        head = head->next;
    }

    zero->next = oneHead->next != NULL ? oneHead->next : twoHead->next;

    one->next = twoHead->next;

    two->next = NULL;

    return zeroHead->next;
}