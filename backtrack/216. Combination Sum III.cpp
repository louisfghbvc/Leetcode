class Solution {
public:
    int k, n;
    void dfs(vector<vector<int>> &res, int v, vector<int> tmp, int used, int digit){
        if(v > n) return;
        if(tmp.size() == k && v == n){
            res.push_back(tmp);
            return;
        }
        for(int i = digit; i <= 9; ++i){
            if(used & (1<<i)) continue;
            tmp.push_back(i);
            dfs(res, v + i, tmp, used | (1<<i), i + 1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        this->k = k;
        this->n = n;
        dfs(res, 0, {}, 0, 1);
        return res;
    }
};
