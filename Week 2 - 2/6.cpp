#include <stdio.h>

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode *l1, ListNode *l2)
{
    ListNode *tmp_res = new ListNode(0);
    ListNode *x = tmp_res;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val >= l2->val) {
            tmp_res->next = new ListNode(l2->val);
            l2 = l2->next;
        }
        else if (l1->val < l2->val) {
            tmp_res->next = new ListNode(l1->val);
            l1 = l1->next;
        }
        tmp_res = tmp_res->next;
    }

    while (l1 != NULL) {
        tmp_res->next = new ListNode(l1->val);
        l1 = l1->next;
        tmp_res = tmp_res->next;
    }

    while (l2 != NULL) {
        tmp_res->next = new ListNode(l2->val);
        l2 = l2->next;
        tmp_res = tmp_res->next;
    }


    return x->next;
}