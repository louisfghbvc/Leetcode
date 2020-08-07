// O(N). Just DFS.
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
    int ans = 0;
    void dfs(TreeNode* cur, TreeNode* p, TreeNode* pp){
        if(cur == NULL)
            return;
        if(pp != NULL && pp->val % 2 == 0)
            ans += cur->val;
        dfs(cur->left, cur, p);
        dfs(cur->right, cur, p);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, NULL, NULL);
        return ans;
    }
};
