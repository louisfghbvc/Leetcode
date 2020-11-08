// Simple Post order bottom up.
// O(N).

class Solution {
public:
    int tot = 0;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int lsum = dfs(root->left);
        int rsum = dfs(root->right);
        tot += abs(lsum - rsum);
        return root->val + lsum + rsum;
    }
    
    int findTilt(TreeNode* root) {
        dfs(root);
        return tot;
    }
};
