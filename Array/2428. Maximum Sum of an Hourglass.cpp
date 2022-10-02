class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        // goal: find the maximum of hourglass
        
        int m = grid.size(), n = grid[0].size();
        
        int ans = 0;
        for (int i = 0; i+3 <= m; ++i) {
            for (int j = 0; j+3 <= n; ++j) {
                int sum = 0;
                sum += grid[i][j] + grid[i][j+1] + grid[i][j+2];
                sum += grid[i+1][j+1];
                sum += grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
                ans = max(ans, sum);
            }
        }
        
        return ans;
    }
};
