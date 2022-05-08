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
    int averageOfSubtree(TreeNode* root) {
        // goal: calculate the number of nodes that the value is equal to subtree avg
        // idea: postorder dfs
        
        int ans = 0;
        
        auto dfs = [&](const auto &self, TreeNode* root) -> pair<int, int> { // sum, number of nodes 
            if (!root) return {0, 0};
            
            auto left = self(self, root->left);
            auto right = self(self, root->right);
            
            int num = left.second + right.second + 1;
            int sum = left.first + right.first + root->val;

            if (sum / num == root->val) ans++;
            
            return {left.first + right.first + root->val, left.second + right.second + 1};
        };
        
        dfs(dfs, root);
            
        return ans;
    }
};
