// O(NlogN)
// Just staright dfs. and use map+pair to sort

class Solution {
public:
    typedef pair<int, int> ii;
    map<int, vector<ii>> mp;
    void dfs(int x, int y, TreeNode* root){
        if(!root) return;
        mp[x].push_back({y, root->val});
        dfs(x-1, y-1, root->left);
        dfs(x+1, y-1, root->right);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        dfs(0, 0, root);
        for(auto& m : mp){
            sort(m.second.begin(), m.second.end(), [](ii &a, ii &b){
                    return (a.first == b.first && a.second < b.second) || a.first > b.first;
            });
            vector<int> tmp;
            for(auto &[a, b]: m.second) tmp.emplace_back(b);
            res.emplace_back(tmp);
        }
        return res;
    }
};
