class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // goal: calculate the number of grid that is not see by guards
        // idea: use extra array
        // grid[i][j] = 1 -> guard, 2 -> walls
        // grid[i][j] = 3 -> finish
        
        vector<vector<int>> grid(m, vector<int>(n, 3));
        for (auto &w: walls)
            grid[w[0]][w[1]] = 2;
        for (auto &g: guards)
            grid[g[0]][g[1]] = 1;
                
        for (int i = 0; i < m; ++i) {
            // see from left
            bool guard = false;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) guard = true;
                else if (grid[i][j] == 2) guard = false;
                else if (guard) grid[i][j] = 0;
            }
            guard = false;
            for (int j = n-1; j >= 0; --j) {
                if (grid[i][j] == 1) guard = true;
                else if (grid[i][j] == 2) guard = false;
                else if (guard) grid[i][j] = 0;
            }
        }
        
        for (int j = 0; j < n; ++j) {
            // see from top
            bool guard = false;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 1) guard = true;
                else if (grid[i][j] == 2) guard = false;
                else if (guard) grid[i][j] = 0;
            }
            guard = false;
            for (int i = m-1; i >= 0; --i) {
                if (grid[i][j] == 1) guard = true;
                else if (grid[i][j] == 2) guard = false;
                else if (guard) grid[i][j] = 0;
            }
        }
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res += grid[i][j] == 3;
            }
        }
        
        return res;
    }
};
