// dfs, keep track the max node.
// then count it.
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
    void dfs(TreeNode* root, TreeNode* par){
        if(!root) return;
        if(root->val >= par->val){
            ans++;
        }
        if(root->val < par->val){
            dfs(root->left, par);
            dfs(root->right, par);
        }      
        else{
            dfs(root->left, root);
            dfs(root->right, root);
        }
            
        
        
    }
    int goodNodes(TreeNode* root) {
        ans = 0;
        dfs(root, root);
        return ans;
    }
};
