#include <stdio.h>

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    bool hasCycle = false;

    while (slow != NULL && fast != NULL) {
        if (fast->next == NULL)
            break;

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    if (!hasCycle)
        return nullptr;
    
    slow = head;
    
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
}