// Use Recursive make problem simple.
// Divide and Conquer.
// O(N). remember to recursive chain.
class Solution {
public:
    int l, r;
    TreeNode* helper(TreeNode* root){
        if(!root) return NULL;
        if(root->val > r){
            root = helper(root->left);
        }
        else if(root->val < l){
            root = helper(root->right);
        }
        else {
            root->left = helper(root->left);
            root->right = helper(root->right);
        }
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return NULL;
        l = L, r = R;
        return helper(root);
    }
};
