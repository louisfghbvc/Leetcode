// iawesome clean code. so use the root unique property.
// and use validate BST.
// and use the unordered_map size to make sure not inner cycle, and done
// and make sure only one node can not mapping to itself
class Solution {
public:
    
    unordered_map<int, TreeNode*> mp; // record the root
    bool dfs(TreeNode* root, int L = INT_MIN, int R = INT_MAX){
        if(!root) return true;
        if(!(root->val > L && root->val < R)) return false;
        if(!root->left && !root->right){
            auto it = mp.find(root->val);
            if(it != mp.end() && root != it->second){ // one node can map to itself
                root->left = it->second->left;
                root->right = it->second->right;
                mp.erase(it);
            }
        }
        return dfs(root->left, L, root->val) && dfs(root->right, root->val, R);
    }
    
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        int n = trees.size();
        
        unordered_map<int, int> ind; // indegree of tree
        for(TreeNode *r: trees){
            mp[r->val] = r;
            if(r->left) ind[r->left->val]++;
            if(r->right) ind[r->right->val]++;
        }
        
        for(TreeNode* r: trees){
            if(ind[r->val] == 0){
                return dfs(r) && mp.size() == 1 ? r : NULL; 
            }
        }
        return NULL;
    }
};
