// Just consider small case. find the pattern. bottom up dp.
// u don't need to do this root, just add child need. pass to parent. 
// O(N).

class Solution {
public:
    int res = 0;
    int dfs(TreeNode* root){
        if(!root) return 0;
        // what u get in this children
        int left = dfs(root->left);
        int right = dfs(root->right);
        res += abs(left) + abs(right);
        int propagate = root->val - 1;
        return propagate + left + right;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return res;
    }
};
