// O(NK). prefix + dp
// top-down hard to think the prefix dp...
// bottom-up is easy code.
// so two case dp[i][j]. from dp[i-1][j].
// or from dp[i][j+1] = dp[i-1][j] + dp[i-2][j] + ... + dp[0][j]
// so use prefix sum. 
// this is dp of dp.

class Solution {
public:
    const int mod = 1e9+7;
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(n, vector<int>(k+1));
        vector<int> pre(k);
        
        dp[0][0] = 1;
        pre[0] = 1;
        
        for(int i = 1; i < n; ++i){
            for(int j = 0; j <= k; ++j)
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            
            for(int j = 0; j < k; ++j)
                dp[i][j+1] = (dp[i][j+1] + pre[j]) % mod;
            
            for(int j = 0; j < k; ++j)
                pre[j] = (pre[j] + dp[i][j]) % mod;
        }
        
        return dp[n-1][k];
    }
};

// O(N). Math.
