// O(N^3). Yeah! solve by myself.

class Solution {
public:
    vector<int> pre;
    vector<int> arr;
    int dp[505][505];
    int dfs(int l, int r){
        if(l == r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        // cout << "in: L " << l << " " << "R " << r << "\n";
        int tot = pre[r+1]-pre[l];
        int ps = 0, rem = 0, res = 0;
        for(int i = l; i <= r; ++i){
            ps += arr[i];
            rem = tot-ps;
            if(ps > rem){
                res = max(res, rem + dfs(i+1, r));
            }
            else if(ps < rem){
                res = max(res, ps + dfs(l, i));
            }
            else{
                res = max(res, ps + dfs(i+1, r));
                res = max(res, ps + dfs(l, i));
            }
            
        }
        // cout << "out: L " << l << " " << "R " << r << "\n";
        // cout << "get: " << res << "\n";
        return dp[l][r] = res;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        arr = stoneValue;
        pre = vector<int>(n+1);
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; ++i)
            pre[i+1] = pre[i] + stoneValue[i];
        return dfs(0, n-1);
    }
};
