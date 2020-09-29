// Simple.
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
    bool dfs(TreeNode* root, TreeNode* data = NULL){
        if(!root) return true;
        if(!data) data = root;
        return data->val == root->val && dfs(root->left, data) && dfs(root->right, data);
    }
    bool isUnivalTree(TreeNode* root) {
        return dfs(root);
    }
};
