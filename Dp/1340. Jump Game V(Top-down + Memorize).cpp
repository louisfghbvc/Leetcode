class Solution {
    int dp[1001] = {};
    vector<int> v;
    int dfs(int i, int d, int res = 1){
        if(dp[i]) 
            return dp[i];
        int l = max(0, i - d), r = min(i + d, (int)v.size() - 1);
        for(int j = i - 1; j >= l && v[j] < v[i]; --j){
            res = max(res, 1 + dfs(j, d));
        }
        for(int j = i + 1; j <= r && v[j] < v[i]; ++j){
            res = max(res, 1 + dfs(j, d));
        }
        return dp[i] = res;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        v = arr;
        int mx = -1;
        for(int i = 0; i < arr.size(); ++i){
            mx = max(mx, dfs(i, d));
        }
        return mx;
    }
};
