#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node *delPos(Node *head, int x)
{

    int count = 1;

    if (x == 0)
    {
        return head;
    }

    if (x == 1)
    {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        return head;
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
    if (temp->next != NULL) 
        temp->next->prev = temp;

    return head;
}



//Recursive Approach

Node *delPos(Node *head, int x)
{
    if (head == NULL)
    {
        return head;
    }

    if (x == 1)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        return head;
    }

    Node *temp = delPos(head->next, x - 1);

    head->next = temp;
    if (temp != NULL)
    {
        temp->prev = head;
    }

    return head;
}