// O(MN). color from edge
// since edge must not be cover
// so remain island will be the answer.

class Solution {
public:
    
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(int x, int y, int color){
        if(x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || g[x][y] == color) return;
        g[x][y] = color;
        for(int i = 0; i < 4; ++i){
            int nx = x+dir[i][0], ny = y+dir[i][1];
            dfs(nx, ny, color);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        g = grid;
        for(int i = 0; i < g.size(); ++i){
            dfs(i, 0, 1);
            dfs(i, g[0].size()-1, 1);
        }
        for(int j = 0; j < g[0].size(); ++j){
            dfs(0, j, 1);
            dfs(g.size()-1, j, 1);
        }
        
        int cnt = 0;
        for(int i = 0; i < g.size(); ++i){
            for(int j = 0; j < g[i].size(); ++j){
                if(g[i][j] == 0){
                    dfs(i, j, 1);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
private:
    vector<vector<int>> g;
};
