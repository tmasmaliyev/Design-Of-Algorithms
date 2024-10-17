#include <stdio.h>

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x) , next(NULL) {}
};

void PrintReverse(ListNode *head)
{
    if (head == NULL)
        return;

    PrintReverse(head->next);

    printf("%d\n", head->val);
}

int main() {
    ListNode *x, *x1 = new ListNode(0);
    x = x1;

    int n, val;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);

        ListNode *temp = new ListNode(val);
        x1->next = temp;
        x1 = x1->next;
    }
    x = x->next;

    PrintReverse(x);
}