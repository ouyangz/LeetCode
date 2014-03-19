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
    ListNode *swapPairs(ListNode *head) {
        ListNode *first, *second, *prev, *third;
        first = head;
        if (first == NULL) {
            return NULL;
        }
        second = first->next;
        if (second == NULL) {
            return first;
        }
        third = second->next;
        first->next = third;
        second->next = first;
        return second; 
    }
};