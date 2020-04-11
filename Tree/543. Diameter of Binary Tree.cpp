//Every node record max l, r. and max l+r
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
public:
    int ans = 0;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        ans = max(ans, l+r);
        return max(l, r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
