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
 
 // calculate the height
 // and when traversal, into the ans
 
class Solution {
public:
    vector<vector<int>> res;
    
    // return the height
    int dfs(TreeNode *root){
        if(!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        int cur_level = max(left, right);
        if(cur_level >= res.size())
            res.push_back(vector<int>());
        res[cur_level].push_back(root->val);
        return cur_level + 1;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return res;
    }
};
