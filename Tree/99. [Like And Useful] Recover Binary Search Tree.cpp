// O(N). Inorder traveral
// find first violate and final violate.
class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* p = NULL; // current point, use for inorder.
    
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        
        if(p){
            if(!first && p->val >= root->val){
                first = p;
            }
            if(first && p->val >= root->val){
                second = root;
            }
        }
        
        p = root;
        dfs(root->right);
    }
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first->val, second->val);
    }
};

// Space O(1). Morris Traversal
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
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* p = NULL;
        TreeNode* first = NULL;
        TreeNode* last = NULL;
        while(root){
            if(root->left){
                prev = root->left; // predecessor
                while(prev->right && prev->right != root) prev = prev->right;
                if(!prev->right){
                    prev->right = root;
                    root = root->left;
                }
                else{
                    prev->right = NULL;
                    if(p){ // inorder
                        if(!first && p->val >= root->val) first = p;
                        if(first && p->val >= root->val) last = root;
                    }
                    p = root;
                    root = root->right;
                }
            }
            else{
                if(p){ // inorder
                    if(!first && p->val >= root->val) first = p;
                    if(first && p->val >= root->val) last = root;
                }
                p = root;
                root = root->right;
            }
        }
        swap(first->val, last->val);
    }
};
