class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        // goal: find the max pooling of 3x3
        
        int n = grid.size();
        
        vector<vector<int>> res;
        
        for (int i = 1; i+1 < n; ++i) {
            vector<int> col;
            for (int j = 1; j+1 < n; ++j) {
                int mx = 0;
                for (int ii = -1; ii <= 1; ++ii)
                    for (int jj = -1; jj <= 1; ++jj)
                        mx = max(mx, grid[i+ii][j+jj]);
                col.push_back(mx);
            }
            res.push_back(col);
        }
        
        return res;
    }
};
