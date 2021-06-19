// Think from top - down.
// And observe relation. 

class Solution {
public:
    const int mod = 1e9+7;
    
    vector<vector<long>> dp;
    
    // dp[n][k] = dp[n-1][k] + dp[n-1][k-1] ... dp[n-1][k - n + 1]
    // dp[n][k+1] = dp[n-1][k+1] + dp[n-1][k] ... dp[n-1][k - n + 2] -> similar as dp[n][k].
    
//     // build from small
//     int dfs(int n, int k){
//         // base case
//         if(n == 1) return k == 0; 
//         if(dp[n][k] != -1) return dp[n][k];
        
//         long res = 0;
//         // maiximum put from end.
//         for(int ip = 0; ip < n; ++ip){
//             if(k >= ip){
//                 res += dfs(n-1, k - ip);
//                 res %= mod;
//             }
//             else break;
//         }
        
//         return dp[n][k] = res;
//     }
    
    int kInversePairs(int n, int k) {
        dp = vector<vector<long>>(n+1, vector<long>(k+1, 0));
        
        dp[1][0] = 1;
        for(int i = 2; i <= n; ++i){
            
            vector<long> pre(k+2);
            for(int j = 1; j < k+2; ++j){
                pre[j] += pre[j-1] + dp[i-1][j-1];
                pre[j] %= mod;
            }
            
            for(int j = 0; j <= k; ++j){
                int r = j, l = max(j - (i-1), 0);
                dp[i][j] = (pre[r+1] - pre[l] + mod) % mod;
                // for(int ii = 0; ii < i && j >= ii; ++ii){
                //     dp[i][j] += dp[i-1][j-ii];
                //     dp[i][j] %= mod;
                // }
            }
        }
        
        return dp[n][k];    
    }
};
