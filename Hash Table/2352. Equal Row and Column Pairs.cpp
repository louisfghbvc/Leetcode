// TC: O(N^3)

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // goal: find the number of pairs
        // such that they are equal
        // idea: enumerate the row and col
        
        int n = grid.size();
            
        auto check = [&](int r, int c) {
            
            for (int i = 0; i < n; ++i) {
                if (grid[r][i] != grid[i][c])
                    return false;
            }
            
            return true;
        };
        
        
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (check(i, j)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
