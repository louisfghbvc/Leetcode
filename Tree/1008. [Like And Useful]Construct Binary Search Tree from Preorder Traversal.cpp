//O(N). Trick




//O(N log N), Simple and important
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
    TreeNode* bstFromPreorder(vector<int>& preorder, int l = 0, int r = 0) {
        if(r == 0) r = preorder.size();
        if(l == r) return NULL;
        int mid = find_if(preorder.begin() + l, preorder.begin() + r, [&](int v) { return v > preorder[l]; }) - preorder.begin();
        TreeNode* root = new TreeNode(preorder[l]);
        root->left = bstFromPreorder(preorder, l+1, mid);
        root->right = bstFromPreorder(preorder, mid, r);
        return root;
    }
};
