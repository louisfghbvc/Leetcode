// O(N). the deeper tree will return max height. so when compare subtree. who is deeper.
// if left deeper. lca is left. same as right, if height same return cur.
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
    pair<TreeNode*, int> help(TreeNode* root){
        if(!root) return {NULL, 0};
        auto [left, lh] = help(root->left);
        auto [right, rh] = help(root->right);
        if(lh > rh) return {left, lh+1};
        if(rh > lh) return {right, rh+1};
        return {root, lh+1};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return help(root).first;
    }
};
