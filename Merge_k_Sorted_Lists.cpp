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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if (n == 0) {
            return NULL;
        }
        if (n == 1) {
            return lists[0];
        }
        if (n > 2) {
            vector<ListNode *> first(lists.begin(), lists.begin() + n / 2);
            vector<ListNode *> second(lists.begin() + n / 2, lists.end());
            vector<ListNode *> newlist;
            newlist.push_back(mergeKLists(first));
            newlist.push_back(mergeKLists(second));
            return mergeKLists(newlist);   
        }
        ListNode * head = new ListNode(-1);
        ListNode * p = head;
        while(lists[0] != NULL && lists[1] != NULL) {
            if (lists[0]->val <= lists[1]->val) {
                p->next = lists[0];
                p = p->next;
                lists[0] = lists[0]->next;
            }
            else {
                p->next = lists[1];
                p = p->next;
                lists[1] = lists[1]->next;
            }
        }
        if (lists[0] != NULL) {
            p->next = lists[0];
        }
        else if (lists[1] != NULL) {
            p->next = lists[1];
        }
        return head->next;
    }
};