class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        // goal: find the good subset ony binary matrix
        // idea:
        // column length is small
        // good subset, we only need to calculate is length = 1, 2
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> mask(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    mask[i] |= 1 << j;
            }
        }
        
        // length 1
        for (int i = 0; i < m; ++i) {
            if (mask[i] == 0)
                return {i};
        }
        
        // legnth 2
        vector<int> vis(64, -1);
        for (int i = 0; i < m; ++i) {
            for (int can = 0; can < 1<<n; ++can) if (vis[can] != -1) {
                int intersection = can & mask[i];
                if (intersection == 0) {
                    return {vis[can], i};
                }
            }
            vis[mask[i]] = i;
        }
        
        return {};
    }
};
