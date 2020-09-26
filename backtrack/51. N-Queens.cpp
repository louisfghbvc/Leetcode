// Classic backtracking. Simple Clean code.
class Solution {
public:
    vector<int> Q;
    vector<string> mp;
    vector<vector<string>> res;
    bool canPlace(int k){
        for(int i = 0; i < k; ++i)
            if(Q[i] == Q[k] || abs(Q[k]-Q[i]) == k-i) return false;
        return true;
    }
    void dfs(int i, int n){
        if(i == n){
            res.push_back(mp);
            return;
        }
        for(int col = 0; col < n; ++col){
            Q[i] = col;
            if(canPlace(i)){
                mp[i][col] = 'Q';
                dfs(i+1, n);
                mp[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        Q.resize(n);
        mp.resize(n);
        for(int i = 0; i < n; ++i) mp[i] = string(n, '.');
        dfs(0, n);
        return res;
    }
};
