// Depth First Search. O(N).
// Simple maintain two value.

class Solution {
public:
    int dfs(TreeNode* root, int mx = 0, int mn = 1e9){
        if(!root) return mx - mn;
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        return max(dfs(root->left, mx, mn), dfs(root->right, mx, mn));
    }
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root);
    }
};
