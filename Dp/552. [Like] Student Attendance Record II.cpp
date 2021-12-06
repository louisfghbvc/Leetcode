// memo - top down dp
// enumerate the case.

class Solution {
public:
    // dp[i][j][k] i: numbers of day, total absent, late days
    
    int n, mod = 1e9+7;
    vector<vector<vector<int>>> memo;
    int dfs(int day, int total_absent, int late){ 
        if(day == n) return 1;
        
        int &res = memo[day][total_absent][late];
        if(res != -1) return res;
        
        // present
        res = dfs(day+1, total_absent, 0);
        // absent
        if(total_absent < 1)
            res = (res + dfs(day+1, total_absent+1, 0)) % mod;
        // late
        if(late < 2)
            res = (res + dfs(day+1, total_absent, late+1)) % mod;
        
        return res;
    }
    
    int checkRecord(int n) {
        this->n = n;
        memo = vector<vector<vector<int>>>(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return dfs(0, 0, 0);
    }
};

// bottom up, derive from top down
class Solution {
public:
    
    // dp[i][j][k] i: numbers of day so far, total absent, late days
    int mod = 1e9+7;
    vector<vector<vector<int>>> dp;
    
    int checkRecord(int n) {
        dp = vector<vector<vector<int>>>(n+1, vector<vector<int>>(2, vector<int>(3)));
        
        for(int j = 0; j < 2; ++j)
            for(int k = 0; k < 3; ++k)
                dp[0][j][k] = 1;
        
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < 2; ++j){
                for(int k = 0; k < 3; ++k){
                    // present
                    dp[i][j][k] = dp[i-1][j][2];
                    // absent
                    if(j) dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-1][2]) % mod;
                    // late
                    if(k) dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k-1]) % mod;
                }
            }
        }
        
        return dp[n][1][2];
    }
};

// optimize2, reduce to O(1) space.

// optimize3, reduce to O(logN) time use matrix.
