//Classic dfs
class Solution {
public:
    int m, n;
    const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(int x, int y, vector<vector<char>>& g){
        if(x < 0 || x >= m || y < 0 || y >= n || g[x][y] == '0') return;
        g[x][y] = '0';
        for(int k = 0; k < 4; ++k){
            dfs(x+dir[k][0], y+dir[k][1], g);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        m = grid.size();
        if(m == 0) return 0;
        n = grid[0].size();
        if(m == 0 || n == 0) return cnt;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1')
                    dfs(i, j, grid), cnt++;
            }
        }
        return cnt;
    }
};
