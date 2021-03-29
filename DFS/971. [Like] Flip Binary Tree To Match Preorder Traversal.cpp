// O(N). DFS.

class Solution {
public:
    vector<int> res;
    
    int dfs(TreeNode* root, int &i, vector<int>& voyage){
        if(!root) return true;
        if(root->val != voyage[i]) return false;
        i++;
        int prev = i;
        bool left = dfs(root->left, i, voyage);
        if(!left){
            swap(root->left, root->right);
            if(root->left && dfs(root->left, prev, voyage)){
                i = prev;
                res.push_back(root->val);
            }
            else return false;
        }
        if(!dfs(root->right, i, voyage)) return false;
        return true;
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int i = 0;
        bool tmp = dfs(root, i, voyage);
        if(!tmp) return {-1};
        return res;
    }
};

// Awesome clean. O(N)
class Solution {
public:
    vector<int> res;
    
    int dfs(TreeNode* root, int &i, vector<int>& voyage){
        if(!root) return true;
        if(root->val != voyage[i++]) return false;
        if(root->left && root->left->val != voyage[i]){
            swap(root->left, root->right);
            res.push_back(root->val);
        }
        return dfs(root->left, i, voyage) && dfs(root->right, i, voyage);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int i = 0;
        return dfs(root, i, voyage) ? res : vector<int>(1, -1);
    }
};
