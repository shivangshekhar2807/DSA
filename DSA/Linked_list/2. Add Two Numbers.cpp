struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}  ListNode(int x) : val(x), next(nullptr){} ListNode(int x, ListNode *next) : val(x), next(next){}
                                                                                                                                      
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *curr = l1;
    ListNode *P = nullptr;
    ListNode *N = nullptr;

    while (curr != nullptr)
    {
        N = curr->next;
        curr->next = P;
        P = curr;
        curr = N;
    }

    l1 = P;

    curr = l2;
    P = nullptr;
    N = nullptr;

    while (curr != nullptr)
    {
        N = curr->next;
        curr->next = P;
        P = curr;
        curr = N;
    }

    l2 = P;

    ListNode *newhead = new ListNode(-1);
    ListNode *temp = newhead;
    int carry = 0;

    while (l1 != nullptr && l2 != nullptr)
    {
        int sum = l1->val + l2->val + carry;

        carry = sum / 10;
        sum = sum % 10;

        ListNode *head = new ListNode(sum);
        temp->next = head;
        temp = temp->next;

        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != nullptr)
    {
        int sum = l1->val + carry;

        carry = sum / 10;
        sum = sum % 10;

        ListNode *head = new ListNode(sum);
        temp->next = head;
        temp = temp->next;

        l1 = l1->next;
    }

    while (l2 != nullptr)
    {
        int sum = l2->val + carry;

        carry = sum / 10;
        sum = sum % 10;

        ListNode *head = new ListNode(sum);
        temp->next = head;
        temp = temp->next;

        l2 = l2->next;
    }

    if (carry > 0)
    {
        ListNode *head = new ListNode(carry);
        temp->next = head;
        temp = temp->next;
    }

    return newhead->next;
}