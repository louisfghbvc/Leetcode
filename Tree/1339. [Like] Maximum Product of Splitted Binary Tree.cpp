// O(N). Two dfs. tree dp
class Solution {
public:    
    int sum;
    long ans;
    const int mod = 1e9+7;
    int dfs(TreeNode* root){ // sum of the subtree
        if(!root) return 0;
        // go left
        int left = dfs(root->left);
        ans = max(left * 1L * (sum - left), ans);
        // go right
        int right = dfs(root->right);
        ans = max(right * 1L * (sum - right), ans);
        return left + right + root->val;
    }
    
    int maxProduct(TreeNode* root) {
        sum = 0;
        ans = 0;
        sum = dfs(root);
        dfs(root);
        return ans % mod;
    }
};
