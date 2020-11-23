// Tree dp. use postorder concept.
// bottom-up.
// root choose or not choose.
// O(N).

class Solution {
public:
    pair<int, int> dfs(TreeNode* root){
        if(!root) return {0, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int choose_root = root->val + left.second + right.second;
        int nchoose = max(left.first, left.second) + max(right.first, right.second);
        return {choose_root, nchoose};
    }
    int rob(TreeNode* root) {
        auto ans = dfs(root);
        return max(ans.first, ans.second);
    }
};
