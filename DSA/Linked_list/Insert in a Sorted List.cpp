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

Node *sortedInsert(Node *head, int key)
{

    if (head == NULL)
    {
        Node *newhead = new Node(key);
        return newhead;
    }

    if (key <= head->data)
    {
        Node *newhead = new Node(key);
        newhead->next = head;
        return newhead;
    }

    Node *temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        if (key <= temp->next->data)
        {
            break;
        }
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        Node *newhead = new Node(key);
        temp->next = newhead;
        return head;
    }
    Node *newhead = new Node(key);
    newhead->next = temp->next;
    temp->next = newhead;
    return head;
}