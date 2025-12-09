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

Node *pairWiseSwap(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = pairWiseSwap(head->next->next);
    Node *hello = head->next;

    hello->next = head;
    head->next = temp;

    return hello;
}