//68ms 17.2MB
class Solution {
public:
    void dfs(int &k, int &n, int st, vector<vector<int>> &res, vector<int> tmp){
        if(tmp.size() == k){
            res.push_back(tmp);
            return;
        }
        for(int i = st; i <= n - (k - tmp.size()) + 1; ++i){
            tmp.push_back(i);
            dfs(k, n, i + 1, res, tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        dfs(k, n, 1, res, {});
        return res;
    }
};
