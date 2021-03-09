// O(N). use extra param to pass
class Solution {
public:
    pair<TreeNode*, int> dfs(TreeNode* root){
        if(!root) return {NULL, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        root->left = left.first;
        root->right = right.first;
        int newval = root->val + left.second + right.second;
        if(newval == 0) return {NULL, 0};
        return {root, newval};
    }
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root).first;
    }
};


// O(N). Clean, just consider root->val and left and right is NULL
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->val == 0 && !root->left && !root->right) return NULL;
        return root;
    }
};
