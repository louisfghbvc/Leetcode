// O(N). Simple.
// 2 line for fun.
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        return ((root->val >= low && root->val <= high) ? root->val : 0) + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
