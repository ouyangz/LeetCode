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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *tail = head;
        ListNode *first, *temp;

        if (k <= 1) {
            return head;
        }

        for (int i = 0; i < k; ++i) {
            if (tail == NULL) {
                return head;
            }
            tail = tail->next;
        }
        
        tail = reverseKGroup(tail, k);
        first = head;
        for (int i = 0; i < k - 1; ++i) {
            temp = first->next;
            first->next = temp->next;
            temp->next = head;
            head = temp;
        }
        first->next = tail;
        return head;
    }
};