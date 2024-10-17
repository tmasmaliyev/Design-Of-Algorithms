#include <stdio.h>

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

int hasCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    
    while (slow != NULL && fast != NULL) {
        if (fast->next == NULL)
            return false;

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}
