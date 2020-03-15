//388ms 203.8MB, Postorder, keep min, max, cur. top-down, then combie
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
    //{smallnum, bignum, curnum} in tree
    vector<int> traverse(TreeNode* root, int &ans){
        if(!root) return {INT_MAX, INT_MIN, 0};
        vector<int> left = traverse(root->left, ans);
        vector<int> right = traverse(root->right, ans);
        //check if BST
        if(left.empty() || right.empty() || root->val <= left[1] || root->val >= right[0]) return {};
        int cur_num = left[2] + right[2] + root->val;
        ans = max(ans, cur_num);
        return {min(left[0], root->val), max(right[1], root->val), cur_num};
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        traverse(root, ans);
        return ans;
    }
};
