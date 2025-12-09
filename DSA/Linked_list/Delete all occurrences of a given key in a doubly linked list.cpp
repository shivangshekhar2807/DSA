
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

class Solution
{
public:
    void deleteAllOccurOfX(struct Node **head, int x)
    {
        if (*head == NULL)
        {
            return;
        }

        if ((*head)->data == x)
        {
            *head = (*head)->next;
            if (*head != NULL)
            {
                (*head)->prev = NULL;
            }
            deleteAllOccurOfX(head, x);
            return;
        }

        Node *temp = (*head)->next;

        deleteAllOccurOfX(&temp, x);

        (*head)->next = temp;
        if (temp != NULL)
        {
            temp->prev = *head;
        }

        return;
    }
};