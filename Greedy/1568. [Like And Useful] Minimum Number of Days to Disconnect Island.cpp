class Solution {
public:

    int computeIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector vis(m, vector(n, false));
        auto dfs = [&](auto &self, int i, int j) -> void {
            for (auto &[ni, nj]: {make_pair(i+1,j),{i-1,j},{i,j-1},{i,j+1}}) {
                if (ni >= m || ni < 0 || nj >= n || nj < 0 || vis[ni][nj] || !grid[ni][nj]) continue;
                vis[ni][nj] = 1;
                self(self, ni, nj);
            }
        };  

        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    if (vis[i][j] == 0) {
                        vis[i][j] = 1;
                        cnt++;
                        dfs(dfs, i, j);
                    }
                }
            }
        }

        return cnt;
    }

    int minDays(vector<vector<int>>& grid) {
        // goal: find the minimum day to split grid to two components
        // idea:
        // ans is at most 2

        // ans is 0, if island > 1
        // ans is 1 ?
        // enumerate all cells if 1, remove it

        if (computeIsland(grid) > 1 || computeIsland(grid) == 0) return 0;

        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    grid[i][j] ^= 1;
                    if (computeIsland(grid) > 1 || computeIsland(grid) == 0) return 1;
                    grid[i][j] ^= 1;
                }
            }
        }

        return 2;
    }
};
