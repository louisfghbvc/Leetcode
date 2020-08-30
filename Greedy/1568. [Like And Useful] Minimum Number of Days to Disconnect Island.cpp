// 0 or 1 or 2
// at most 2. think about if a edge cell connect to land at most 2 bridge right? QQ
// thats why greedy...
// O(N^4)

class Solution {
public:
    vector<vector<int>> g;
    int n, m;
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    void dfs(int x, int y){
        g[x][y] = 0;
        for(int k = 0; k < 4; ++k){
            int nx = x+dir[k][0], ny = y+dir[k][1];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || !g[nx][ny]) continue;
            dfs(nx, ny);
        }
    }
    
    int cntIsland(){
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(g[i][j]){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        return cnt;
    }
    
    int minDays(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size(), m = grid[0].size();
        if(cntIsland() > 1) return 0;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    g = grid;
                    if(cntIsland() > 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};
