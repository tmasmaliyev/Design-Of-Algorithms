#include <stdio.h>

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

int sum(ListNode *head)
{
    int res = 0;

    while (head != NULL) {
        res+= head->val;
        head = head->next;
    }

    return res;
}