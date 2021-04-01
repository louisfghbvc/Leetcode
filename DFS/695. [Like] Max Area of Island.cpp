// Simple DFS. O(RxC)

class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dfs(vector<vector<int>>&g, int x, int y){
        if(x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || !g[x][y]) return 0;
        g[x][y] = 0;
        int res = 1;
        for(int k = 0; k < 4; ++k){
            res += dfs(g, x+dir[k][0], y+dir[k][1]);
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int res = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
};
