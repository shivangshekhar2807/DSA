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

void removeLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    Node *slow = head;
    Node *fast = head;
    Node *start = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;

        fast = fast->next->next;
        if (slow == fast)
        {

            break;
        }
    }
    if (slow != fast)
    {
        return;
    }

    while (slow != start)
    {
        slow = slow->next;
        start = start->next;
    }

    while (slow->next != start)
    {
        slow = slow->next;
    }

    slow->next = NULL;
}