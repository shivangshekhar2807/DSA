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

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> arr;
    if (head == NULL)
    {
        return arr;
    }

    Node *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    while (tail != head && tail->next != head)
    {
        if (head->data + tail->data == target)
        {
            arr.push_back({head->data, tail->data});
            head = head->next;
            tail = tail->prev;
        }
        else if (head->data + tail->data > target)
        {
            tail = tail->prev;
        }
        else
        {
            head = head->next;
        }
    }

    return arr;
}