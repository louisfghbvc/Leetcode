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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // goal: find if two tree equal if can swap same number of times
        // idea:
        //  1    1
        // 2 3  3 2
        // do the dfs ?
        // compare the node and compare leaf node!

        auto dfs = [&](auto &self, TreeNode* r1, TreeNode* r2) -> bool {
            if (!r1 && !r2) return true;
            if (!r1 || !r2) return false;
            if (r1->val != r2->val) return false;
            // no swap
            bool noSwap = self(self, r1->left, r2->left) && self(self, r1->right, r2->right);
            // swap
            bool swap = self(self, r1->left, r2->right) && self(self, r1->right, r2->left);
            return noSwap || swap;
        };

        return dfs(dfs, root1, root2);
    }
};
