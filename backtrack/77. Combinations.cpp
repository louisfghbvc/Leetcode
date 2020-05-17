//56ms 12MB
class Solution {
public:
    void dfs(int &k, int &n, int st, vector<vector<int>> &res, vector<int> &tmp){
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
        vector<int> tmp;
        dfs(k, n, 1, res, tmp);
        return res;
    }
};

// not cut. 64ms 9.9MB
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int> &tmp, int &n, int &k, int now){
        if(tmp.size() == k){
            res.push_back(tmp);
            return;
        }
        for(int i = now+1; i <= n; ++i){
            tmp.push_back(i);
            dfs(tmp, n, k, i);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        dfs(tmp, n, k, 0);
        return res;
    }
};
