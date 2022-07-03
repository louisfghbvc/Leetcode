// O(MNlogMN)

class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        // goal: find the number of lis in the grid
        // idea: use dp, starting from the smallest value
        // dp[i][j]: number of lis so far
        // dp[i][j] = from sum of 4 dir
        
        const int mod = 1e9+7;
        
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<long>> dp(m, vector<long>(n));
        
        // we need the order of traverse
        vector<vector<int>> order;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                order.push_back({grid[i][j], i, j});
        
        sort(order.begin(), order.end());
        
        for (auto &o: order) {
            int val = o[0], i = o[1], j = o[2];
            dp[i][j] = 1;
            if (i && val > grid[i-1][j]) {
                dp[i][j] += dp[i-1][j];
            }
            if (j && val > grid[i][j-1]) {
                dp[i][j] += dp[i][j-1];
            }
            if (i+1 < m && val > grid[i+1][j]) {
                dp[i][j] += dp[i+1][j];
            }
            if (j+1 < n && val > grid[i][j+1]) {
                dp[i][j] += dp[i][j+1];
            }
            dp[i][j] %= mod;
        }
        
        
        long ans = 0;
        for (auto &r: dp)
            for (auto &c: r)
                ans = (ans + c) % mod;
        
        return ans;
    }
};


// Top down memo, no need to sort
// O(MN)
