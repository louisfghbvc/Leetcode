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
    unordered_map<int, vector<int>> graph;
    
    void dfs(TreeNode* root, TreeNode* par=nullptr) {
        if (!root) return;
        if (par) {
            graph[par->val].push_back(root->val);
            graph[root->val].push_back(par->val);
        }
        dfs(root->left, root);
        dfs(root->right, root);
    }
    
    int dfs2(int u, int p = -1) { // node number
        int mx = 0;
        for (int v: graph[u]) {
            if (v != p) {
                mx = max(dfs2(v, u), mx);
            }    
        }
        return mx+1;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        // goal: find the minimum time to infected all tree
        // idea: reroot the tree
        // traverse from start node
        // try to reach the deepest value
        
        dfs(root);
        
        return dfs2(start) - 1;
    }
};
