#include <stdio.h>

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

int lengthOfListNode(ListNode *head) {
    
    int length = 0;

    while (head != NULL) {
        length++;
        head = head->next;
    }

    return length;
}

void moveForward(ListNode *&head, int steps) {

    for (int i = 0; i < steps; i++)
        head = head->next;
}

ListNode *intersection(ListNode *l1, ListNode *l2)
{
    int length_1 = lengthOfListNode(l1);
    int length_2 = lengthOfListNode(l2);


    if (length_1 > length_2) 
        moveForward(l1, length_1 - length_2);
    else if (length_1 < length_2)
        moveForward(l2, length_2 - length_1);

    while (l1 != l2) {
        l1 = l1->next;
        l2 = l2->next;
    }
    
    return l1;
}

int main() {
    ListNode *tmp = new ListNode(0);
    ListNode *x = tmp;

    int n, val;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);

        tmp->next = new ListNode(val);
        tmp = tmp->next;
    }

}