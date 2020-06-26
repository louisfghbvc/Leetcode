// Just DFS. O(N). if leaf add value.
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
class Solution {
public:
    int ans;
    void dfs(TreeNode* root, int val = 0){
        if(!root) return;
        val = val*10 + root->val;
        if(!root->left && !root->right) ans += val;
        dfs(root->left, val);
        dfs(root->right, val);
    }
    int sumNumbers(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
