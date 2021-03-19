// O(N). Bottom up dp. dfs, recursive.

class Solution {
public:
    int mx; // number of same value.
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int fre = 1, up = 0;
        if(root->left && root->val == root->left->val){
            fre += left;
            up = left;
        }
        if(root->right && root->val == root->right->val){
            fre += right;
            up = max(up, right);
        }
        mx = max(mx, fre);
        return 1 + up;
    }
    int longestUnivaluePath(TreeNode* root) {
        mx = 1;
        dfs(root);
        return mx-1;
    }
};
