/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    const int mod = 1e9 + 7;
    int dfs(TreeNode* node){
        if(!node) return 0;
        return node->val + dfs(node->left) + dfs(node->right);
    }
    int dfs2(TreeNode *node, int &tot, long long &mx){
        if(!node) return 0;
        int sum = node->val + dfs2(node->left, tot, mx) + dfs2(node->right, tot, mx);
        mx = max((long long)sum * (tot - sum), mx);
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        int tot = dfs(root);
        long long ans = 0;
        dfs2(root, tot, ans);
        return ans % mod;
    }
};
