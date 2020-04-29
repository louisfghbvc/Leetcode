/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 // 40ms 28.4MB
 // O(N). bottom-up
 // DFS, state max num. return can not both child. 3 case: self, self+left, self+right
 // Like dynamic programming.
class Solution {
public:
    int mx;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int cur = root->val;
        int res = cur;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left > 0)
            cur += left;
        if(right > 0)
            cur += right;
        mx = max(cur, mx);
        return max({res, res+left, res+right});
    }
    int maxPathSum(TreeNode* root) {
        mx = INT_MIN;
        dfs(root);
        return mx;
    }
};
