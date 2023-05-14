class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        // goal: find the maximum move, starting from first column
        // idea: dp
        // dp[i][j] -> max of (dp[i][j-1], dp[i-1][j-1], dp[i+1][j-1]) + 1
        
        int m = grid.size();
        int n = grid[0].size();
        
        
        vector dp(m, vector(n, 1));
        int ans = 1;
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                int mx = 0;
                if (i-1 >= 0 && grid[i-1][j-1] < grid[i][j]) mx = max(mx, dp[i-1][j-1]);
                if (i+1 < m && grid[i+1][j-1] < grid[i][j]) mx = max(mx, dp[i+1][j-1]);
                if (grid[i][j-1] < grid[i][j]) mx = max(mx, dp[i][j-1]);
                if (mx == 0) dp[i][j] = 0;
                else dp[i][j] = mx + 1;
                ans = max(dp[i][j], ans);
            }
        }
        
        return ans - 1;
    }
};
