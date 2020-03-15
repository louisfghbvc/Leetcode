//188ms 52.4MB. Fisrt inorder build a sort array, then build a binary search tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }
    
    TreeNode* arrayToBST(int l, int r){
        if(l > r) return NULL;
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = arrayToBST(l, mid - 1);
        root->right = arrayToBST(mid + 1, r);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;
        dfs(root);
        return arrayToBST(0, v.size() - 1);
    }
};
