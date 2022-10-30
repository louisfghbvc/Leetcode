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
    
    unordered_map<int, unordered_set<int>> mp; // level -> {nodes}
    unordered_map<int, int> h; // node -> maximum height
    
    int height(TreeNode* root, int level=1) {
        if (!root) return 0;
        mp[level].insert(root->val);
        int res = 1 + max(height(root->left, level+1), height(root->right, level+1));
        return h[root->val] = res;
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // goal: each queries, remove the subtree, calculate the height
        // idea: remove from child of each node
        // then do the queries
        
        // calculate the height
        // step1, level information, how many maximum height
        // step2, build all information
        // step3, level by level from bottom to top
        // step4, calculate node -> decrease the height?
        
        int total = height(root);  // 4
        unordered_map<int, int> ans;
        for (int l = total; l > 1; --l) {
            auto &nodes = mp[l];
            vector<pair<int, int>> vals; // height, x
            for (int x: nodes) {
                vals.push_back({h[x], x});
            }
            sort(vals.begin(), vals.end(), greater<>()); // optimized use find two maximum
            if (vals.size() == 1)
                ans[vals[0].second] = total-l+1; 
            else {
                ans[vals[0].second] = vals[0].first - vals[1].first; // 3-2: 1
            }
        }
        
        vector<int> res;
        for (int q: queries) {
            res.push_back(total - 1 - ans[q]);
        }
        return res;
    }
};
