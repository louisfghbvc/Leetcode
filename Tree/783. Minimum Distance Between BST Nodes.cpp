// Same problem as 530. Boring
// O(N).

class Solution {
public:
    TreeNode* prev;
    int res;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        if(prev) res = min(res, root->val - prev->val);
        prev = root;
        dfs(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        prev = NULL;
        res = INT_MAX;
        dfs(root);
        return res;
    }
};
