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
    int maxDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        else{
            int leftD = maxDepth(root->left);
            int rightD = maxDepth(root->right);
            if (leftD >= rightD)
                return (leftD + 1);
            else
                return (rightD + 1);
        }
    }
};
