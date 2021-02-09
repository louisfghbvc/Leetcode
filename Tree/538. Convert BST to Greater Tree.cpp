// postorder O(N).
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
    TreeNode* dfs(TreeNode* root, int &add){
        if(!root) return root;
        root->right = dfs(root->right, add);
        root->val += add;
        add = root->val;
        root->left = dfs(root->left, add);
        return root;
    }
    TreeNode* convertBST(TreeNode* root) {
        int v = 0;
        return dfs(root, v);
    }
};
