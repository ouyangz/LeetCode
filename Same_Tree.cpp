/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if ((p == NULL) && (q == NULL))
            return true;
        else if ((p == NULL) || (q == NULL))
            return false;
        else if (p->val != q->val)
            return false;
        else if (isSameTree(p->left, q->left) == false)
            return false;
        else if (isSameTree(p->right, q->right) == false)
            return false;
        else 
            return true;
    }
};