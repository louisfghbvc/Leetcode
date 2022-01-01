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
 
 // recursive art. O(N)
 
class Solution {
public:
    
    TreeNode* dfs(TreeNode* root, bool is_root=true){
        if(!root) return NULL;
        bool is_delete = to_del.count(root->val);
        if(is_root && !is_delete) res.push_back(root);
        root->left = dfs(root->left, is_delete);
        root->right = dfs(root->right, is_delete);
        return is_delete ? NULL : root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return res;
        to_del = unordered_set<int>(to_delete.begin(), to_delete.end());
        dfs(root);
        return res;
    }
    
private:
    unordered_set<int> to_del;
    vector<TreeNode*> res;
};
