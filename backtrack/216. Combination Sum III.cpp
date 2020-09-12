// Just backtracking.
// incresing order.
class Solution {
public:
    vector<vector<int>> res;
    int n, k;
    void dfs(int sum, int len, vector<int> &tmp, int c = 1){
        if(sum > n || len > k) return;
        if(sum == n && len == k){
            res.push_back(tmp);
            return;
        }
        for(int i = c; i <= 9; ++i){
            tmp.push_back(i);
            dfs(sum+i, len+1, tmp, i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k, this->n = n;
        vector<int> buf;
        dfs(0, 0, buf);
        return res;
    }
};
