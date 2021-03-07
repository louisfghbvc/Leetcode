// O(2^N). Tree recursive. memo

class Solution {
public:
    unordered_map<int, vector<TreeNode*>> dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n == 1) return {new TreeNode()};
        if(dp.count(n)) return dp[n];
        
        vector<TreeNode*> res;
        for(int l = 1; l < n; l += 2){
            int r = n-1-l;
            for(TreeNode *left : allPossibleFBT(l)){
                for(TreeNode *right : allPossibleFBT(r)){
                    TreeNode* root = new TreeNode();
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return dp[n] = res;
    }
};
