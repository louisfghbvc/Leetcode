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

// O(N)

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // use hashtable <int, TreeNode*>
        // find root, use indegree=0 -> map<int, int> 
        
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, int> indegree; // indegree
        
        for(auto &d: descriptions){
            int parent = d[0], child = d[1], isLeft = d[2];
            if(!mp.count(parent)) mp[parent] = new TreeNode(parent);
            if(!mp.count(child)) mp[child] = new TreeNode(child);
            indegree[parent];
            indegree[child]++;
            if(isLeft)
                mp[parent]->left = mp[child];
            else
                mp[parent]->right = mp[child];
        }
        
        for(auto &[v, d]: indegree){
            if(d == 0)
                return mp[v];
        }
        
        return NULL;
    }
};
