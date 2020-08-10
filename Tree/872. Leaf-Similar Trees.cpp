// use two array. and compare
class Solution {
public:
    
    void dfs(vector<int> &arr, TreeNode* root){
        if(!root) return;
        if(!root->left && !root->right) arr.push_back(root->val);
        dfs(arr, root->left);
        dfs(arr, root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        dfs(a, root1);
        dfs(b, root2);
        return a == b;
    }
};
