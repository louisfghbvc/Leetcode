// O(N). Trick, Hard to Think. use dfs preorder.
// mid first then left node, final right node.
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
    int id = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int p_max = INT_MAX) {
        if(id >= preorder.size() || preorder[id] > p_max) return 0;
        auto root = new TreeNode(preorder[id++]);
        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, p_max);
        return root;
    }
};

//O(N log N), Simple and important
class Solution {
public:
    TreeNode* bst(vector<int> &pre, int l, int r){
        if(l >= r) return 0;
        int mid = pre[l];
        TreeNode* root = new TreeNode(mid);
        int k = l+1;
        for(; k < r; ++k) if(pre[k] > mid) break;
        root->left = bst(pre, l+1, k);
        root->right = bst(pre, k, r);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bst(preorder, 0, preorder.size());
    }
};
