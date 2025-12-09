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

Node *deleteNode(Node *head, int x)
{

    int count = 1;

    if (x == 0)
    {
        return head;
    }

    if (x == 1)
    {
        return head->next;
    }

    Node *temp = head;

    while (temp != NULL && count <= x)
    {
        if (x - count == 1)
        {
            break;
        }
        count++;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return head;
    }

    temp->next = temp->next->next;
    return head;
}


//Recursive Approach

Node *deleteNode(Node *head, int x)
{

    if (head == NULL)
    {
        return head;
    }

    if (x == 1)
    {
        return head->next;
    }

    Node *temp = deleteNode(head->next, x - 1);

    head->next = temp;
    return head;
}