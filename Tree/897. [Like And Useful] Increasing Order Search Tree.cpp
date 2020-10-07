// Inorder traversal O(N).
// Space optimal. change tree. good idea self-recursive.

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
        if(!root) return tail;
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;
    }
};
