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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // goal: find the kth largest level sum
        // idea: bfs
            
        vector<long> levels;
        queue<TreeNode*> q;
        q.push(root);
        
        while (q.size()) {
            long sum = 0;
            for (int qs = q.size(); qs > 0; --qs) {
                TreeNode* cur = q.front(); q.pop();
                sum += cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            levels.push_back(sum);
        }
        
        // sort by descending
        sort(levels.rbegin(), levels.rend());
        
        k--;
        if (levels.size() <= k) return -1;
        return levels[k];
    }
};
