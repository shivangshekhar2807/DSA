#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int data)
    {
        val = data;
        next = nullptr;
    }
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == nullptr || n == 0)
    {
        return head;
    }

    ListNode *fast = head;
    ListNode *slow = head;

    while (n != 0 && fast != nullptr)
    {
        fast = fast->next;
        n--;
    }

    if (fast == nullptr)
    {
        return head->next;
    }

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return head;
}