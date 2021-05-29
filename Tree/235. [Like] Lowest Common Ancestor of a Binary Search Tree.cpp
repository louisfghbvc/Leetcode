// O(H). 

class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return root;
        if(root->val > q->val)
            return dfs(root->left, p, q);
        else if(root->val < p->val)
            return dfs(root->right, p, q);
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)
            swap(p, q);
        return dfs(root, p, q);
    }
};
