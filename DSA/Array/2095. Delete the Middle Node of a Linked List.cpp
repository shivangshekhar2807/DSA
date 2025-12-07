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

Node *DeleteMiddleNode(Node *head)
{

    if (!head || !head->next)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    prev->next = slow->next;
    delete slow;

    return head;
}

int main()
{

    cout << "Enter the List values and to Stop Enter -1" << endl;

    Node *head = NULL;
    Node *move = head;

    int n;

    while (cin >> n && n != -1)
    {

        if (n == -1)
        {
            break;
        }
        if (head == NULL)
        {
            Node *newhead = new Node(n);
            head = newhead;
            move = head;
        }
        else
        {
            Node *newhead = new Node(n);
            move->next = newhead;
            move = move->next;
        }
    }

    Node *temp = DeleteMiddleNode(head);

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}