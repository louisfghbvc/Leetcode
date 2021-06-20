// So, dfs grid2. and just see that grid1 exist or not.

class Solution {
public:
    
    int m, n;
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool dfs(vector<vector<int>>& g1, vector<vector<int>>& g2, int x, int y){
        if(x < 0 || x >= m || y < 0 || y >= n || g2[x][y] == 0) return true;
        g2[x][y] = 0;
        bool res = g1[x][y];
        for(int k = 0; k < 4; ++k){
            int nx = x+dir[k][0], ny = y+dir[k][1];
            res = res & dfs(g1, g2, nx, ny);
        }
        return res;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        
        int res = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid2[i][j]){
                    res += dfs(grid1, grid2, i, j);
                }
            }
        }
        
        return res;
    }
};
