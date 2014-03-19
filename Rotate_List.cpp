/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *p, *q;
        p = head;
        q = head;
        if (head == NULL) {
            return NULL;
        }
        if (k == 0) {
            return head;
        }
        for (int i = 0; i < k; ++i) {
            if (q->next != NULL) {
                q = q->next;
            }
            else {
                q = head;
            }
        }
        while (q->next != NULL) {
            p = p->next;
            q = q->next;
        }
        q->next = head;
        head = p->next;
        p->next = NULL;
        return head;
    }
};