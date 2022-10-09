class Solution {
public:
    
    int mod = 1e9+7;
    void add(int &a, int b) {
        a += b;
        a %= mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        // idea: dp[i][j][k]: number of ways divisible by k
        
        int m = grid.size(), n = grid[0].size();
        
        vector dp(m+1, vector(n+1, vector(k, 0)));
        dp[0][0][0] = 1;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int l = 0; l < k; ++l) {
                    add(dp[i][j+1][(l+grid[i][j])%k], dp[i][j][l]);
                    add(dp[i+1][j][(l+grid[i][j])%k], dp[i][j][l]);
                }
            }
        }
        
        return dp[m][n-1][0];
    }
};
