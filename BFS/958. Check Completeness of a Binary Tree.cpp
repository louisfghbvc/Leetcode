// BFS and use addtional data record the seq order.
// O(N).
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
    bool isCompleteTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        int prev = 0;
        while(q.size()){
            auto [cur, k] = q.front(); q.pop();
            if(prev+1 != k) return false;
            if(cur->left) q.push({cur->left, 2*k});
            if(cur->right) q.push({cur->right, 2*k+1});
            prev = k;
        }
        return true;
    }
};
