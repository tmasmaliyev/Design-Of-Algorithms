#include <stdio.h>

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeCycle(ListNode* head)
{
    ListNode *slow = head, *fast = head;

    bool hasCycle = false;

    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    if (!hasCycle)
        return NULL;

    slow = head;
    
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    
    fast->next = NULL;

    return head;
}