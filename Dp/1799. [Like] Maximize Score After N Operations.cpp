// Dp, backtracking.

class Solution {
public:
    int n;
    vector<int> arr;
    vector<vector<int>> dp;
    int dfs(long vis, int op){
        if(__builtin_popcount(vis) == n) return 0;
        if(dp[vis][op] != -1) return dp[vis][op];
        int res = 0;
        for(int i = 0; i < n; ++i){
            if((vis>>i&1)) continue;
            for(int j = i+1; j < n; ++j){
                if((vis>>j&1)) continue;
                int gain = (op+1) * __gcd(arr[i], arr[j]) + dfs(vis | (1LL<<i) | (1LL<<j) , op+1);
                res = max(res, gain);
            }    
        }
        return dp[vis][op] = res;
    }
    
    int maxScore(vector<int>& nums) {
        arr = nums;
        n = arr.size();
        dp = vector<vector<int>> (1<<n, vector<int>(n, -1));
        return dfs(0, 0);
    }
};
