// 3 lines. Simple traversal
// O(N)
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool left = false) {
        if(!root) return 0;
        if(!root->left && !root->right && left) return root->val;
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};
