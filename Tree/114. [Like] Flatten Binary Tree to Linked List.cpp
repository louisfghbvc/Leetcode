// Tricky post order.
class Solution {
public:
    
    TreeNode* cur = NULL;
    
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = cur;
        root->left = NULL;
        cur = root;
    }
};

// Simple straight forward.

class Solution {
public:
    
    TreeNode* cur;
    
    void dfs(TreeNode* root){
        if(!root) return;

        // connect the linked list.
        TreeNode* todo = root->right;
        
        cur->right = root;
        cur = cur->right;
        
        // do left.
        dfs(root->left);
        root->left = NULL;
        
        // do right;
        dfs(todo);
    }
    
    void flatten(TreeNode* root) {
        cur = new TreeNode(0);
        dfs(root);
    }
};
