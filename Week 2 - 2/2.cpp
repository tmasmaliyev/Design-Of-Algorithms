#include <stdio.h>

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

int length(ListNode *head)
{
    int length = 0;

    while (head != NULL) {
        length++;
        head = head->next;
    }

    return length;
}
