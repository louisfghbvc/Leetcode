// Inorder traversal O(N).
// Space optimal. change tree. good idea self-recursive.

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
        if(!root) return tail;
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;
    }
};

// Inorder traversal O(N).
// easy to understand.
class Solution {
public:
    TreeNode* res = NULL, *tmp = NULL;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        
        if(!tmp){
            tmp = root;
            res = root;
        }else{
            tmp->right = root;
            root->left = NULL;
            tmp = tmp->right;
        }
        
        dfs(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return NULL;
        dfs(root);
        return res;
    }
};
