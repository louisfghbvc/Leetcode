class Solution {
public:
    const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    void dfs(int x, int y, vector<vector<int>>& grid, int tmp, int &mx){
        mx = max(tmp, mx);
        grid[x][y] = -grid[x][y];
        for(int k = 0; k < 4; ++k){
            int nx = x + dir[k][0], ny = y + dir[k][1];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(grid[nx][ny] <= 0) continue;
            dfs(nx, ny, grid, tmp + grid[nx][ny], mx);
        }
        grid[x][y] = -grid[x][y];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                dfs(i, j, grid, 0, res);
            }
        }
        return res;
    }
};
