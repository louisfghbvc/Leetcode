//176ms 63.1MB O(N)
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
    int mx = 0;
    void dfs(TreeNode* root, int dir, int dep){
        if(!root)
            return;
        dep++;
        mx = max(mx, dep);
        if(!dir){
            dfs(root->right, 1, dep);
            dfs(root->left, 0, 0);
        }
        else if(dir){
            dfs(root->left, 0, dep);
            dfs(root->right, 1, 0);
        }
            
    }
    int longestZigZag(TreeNode* root) {
        dfs(root->left, 0, 0);
        dfs(root->right, 1, 0);
        return mx;
    }
};
