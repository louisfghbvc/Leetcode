// O(N). Just dfs
// Simple
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
    int ans;
    void helper(TreeNode* root){
        if(!root) return;
        ans++;
         helper(root->left);
         helper(root->right);
    }
    int countNodes(TreeNode* root) {
        ans = 0;
        helper(root);
        return ans;
    }
};

// O(logn*logn) faster.
// caculate O(logN) height, height same then 2^H-1
// or next level.
class Solution {
public:
    int leftH(TreeNode* root){
        return root ? 1+leftH(root->left) : 0;
    }
    int rightH(TreeNode* root){
        return root ? 1+rightH(root->right) : 0;
    }
    int countNodes(TreeNode* root) {
        int left = leftH(root);
        int right = rightH(root);
        return left == right ? (1<<left)-1 : 1+countNodes(root->left)+countNodes(root->right);
    }
};
