#include <stdio.h>

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

int CycleLength(ListNode* head)
{
    ListNode *slow = head, *fast = head, *cycle;

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
        return -1;
    
    slow = head;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    cycle = slow->next;

    int length = 1;

    while (cycle != slow) {
        cycle = cycle->next;
        length++;
    }

    return length;
}