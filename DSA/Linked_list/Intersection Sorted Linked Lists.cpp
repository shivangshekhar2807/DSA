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

Node *findIntersection(Node *head1, Node *head2)
{
    Node *newhead = new Node(-1);
    Node *temp = newhead;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data == head2->data)
        {
            temp->next = head1;
            head1 = head1->next;
            head2 = head2->next;
            temp = temp->next;
            temp->next = NULL;
        }

        else if (head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else
        {
            head2 = head2->next;
        }
    }
    if (newhead == temp)
    {
        return NULL;
    }

    return newhead->next;
}