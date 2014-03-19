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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode *head = new ListNode (-1);
        ListNode *p = head;

        while ((l1 != NULL) || (l2 != NULL)) {
            int value = carry;
            if (l1 != NULL) {
                value += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                value += l2->val;
                l2 = l2->next;
            }
            carry = value / 10;
            value = value % 10;
            p->next = new ListNode(value);
            p = p->next;
        }
        if (carry != 0) {
            p->next = new ListNode(carry);
        }
        
        return head->next;
    }
};