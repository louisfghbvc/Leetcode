// cuz val = -200~200. 4 digits.
// so just build a string. and like tree dp.
// hash each. cuz bottom up.
// O(N). build string maybe O(4*logN), not sure.

class Solution {
public:
    vector<TreeNode*> res;
    unordered_map<string, int> mp;
    string dfs(TreeNode* root){
        if(!root) return "#"; // can just return ""
        string tag = to_string(root->val)+ "," + dfs(root->left) + "," + dfs(root->right);
        if(mp[tag]++ == 1) res.push_back(root);
        return tag;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }
};
