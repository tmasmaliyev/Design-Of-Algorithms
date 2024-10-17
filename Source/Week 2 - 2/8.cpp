#include <stdio.h>

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode* MiddleElement(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    while (slow != NULL && fast->next != NULL) {
        slow = slow->next;

        if (fast->next->next != NULL)
            break;
        
        fast = fast->next->next;
    }

    return slow;
}