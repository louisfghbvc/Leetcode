// BF. O(3^N). Simple backtracking.

class Solution {
public:
    const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n, ex, ey, tot;
    vector<vector<int>> g;
    
    int dfs(int x, int y, int cnt){
        if(x == ex && y == ey) return cnt == tot;
        int res = 0;
        g[x][y] = 1;
        cnt++;
        for(int k = 0; k < 4; ++k){
            int nx = x+dir[k][0], ny = y+dir[k][1];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || g[nx][ny] == 1 || g[nx][ny] == -1) continue;
            res += dfs(nx, ny, cnt);
        }
        g[x][y] = 0;
        cnt--;
        return res;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        g = grid;
        int sx, sy;
        tot = 0;
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(g[i][j] == 1) sx = i, sy = j, tot++;
                else if(g[i][j] == 2) ex = i, ey = j;
                else if(!g[i][j]) tot++;
                
        return dfs(sx, sy, 0);
    }
};
