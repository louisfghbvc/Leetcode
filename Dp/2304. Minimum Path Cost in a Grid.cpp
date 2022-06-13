class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        // goal: min sum of path start from the first row to last row
        // idea: dp
        // dp[i][j]: j-col so far to index i minimum cost
        // dp[i+1][j1]: from all dp[i][j] + moveCost[grid[i][j]][j1] + grid[i][j], j=0~n-1
        
        int m = grid.size(), n = grid[0].size();
        
        vector<int> dp = grid[0];
        
        for (int i = 1; i < m; ++i) {
            vector<int> ndp(n, INT_MAX);
            for (int j1 = 0; j1 < n; ++j1) {
                for (int j = 0; j < n; ++j) {
                    ndp[j1] = min(ndp[j1], grid[i][j1] + dp[j] + moveCost[grid[i-1][j]][j1]);
                }
            }
            dp = move(ndp); // rolling dp
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};
