// O(N). Tricky. Tree dp. postorder.
// only compare left and right
class Solution {
public:
    pair<TreeNode*, int> dfs(TreeNode* root){
        if(!root) return {NULL, 0};
        auto [left, lefth] = dfs(root->left);
        auto [right, righth]= dfs(root->right);
        if(lefth > righth) return {left, lefth+1};
        if(lefth < righth) return {right, righth+1};
        return {root, lefth+1};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};
