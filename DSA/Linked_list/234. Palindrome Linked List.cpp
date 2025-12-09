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

bool isPalindrome(ListNode *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *temp = nullptr;

    while (fast != nullptr && fast->next != nullptr)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *curr = slow;
    ListNode *N = nullptr;
    ListNode *P = nullptr;
    temp->next = nullptr;

    while (curr != nullptr)
    {
        N = curr->next;
        curr->next = P;
        P = curr;
        curr = N;
    }

    while (head != nullptr && P != nullptr)
    {
        if (head->val != P->val)
        {
            return false;
        }
        head = head->next;
        P = P->next;
    }

    return true;
}