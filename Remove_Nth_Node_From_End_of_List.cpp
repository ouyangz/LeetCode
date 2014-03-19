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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p = head;
        ListNode *q = head;
        ListNode *temp;
        for (int i = 0; i < n; ++i) {
            if (q->next != NULL) {
                q = q->next;
            }
            else if (i == n - 1){
                temp = head->next;
                free(head);
                return temp;
            }
            else return NULL;
        }
        while (q->next != NULL) {
            p = p->next;
            q = q->next;
        }
        temp = p->next;
        p->next = temp->next;
        free(temp);
        return head;
    }
};