// Keep row max, col max. each cell can't over that max.
// O(N^2).

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> row(n), col(n);
        
        for(int j = 0; j < n; ++j)
            for(int i = 0; i < n; ++i){
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        
        int res = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                res += min(row[i], col[j]) - grid[i][j];
        
        return res;
    }
};
