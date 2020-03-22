//Ugly code. 444ms 53.5MB
class Solution {
public:
    vector<vector<bool>> vis;
    vector<vector<int>> g;
    int m, n;
    bool ok;
    void dfs(int x, int y, int px, int py){
        if(x == m - 1 && y == n - 1){
            if(g[x][y] == 1)
                if(py == y - 1 || py == y + 1) ok = 1;
            if(g[x][y] == 2)
                if(px == x - 1 || px == x + 1) ok = 1;
            if(g[x][y] == 3)
                if(py == y - 1 || px == x + 1) ok = 1;
            if(g[x][y] == 4)
                if(py == y + 1 || px == x + 1) ok = 1;
            if(g[x][y] == 5)
                if(py == y - 1 || px == x - 1) ok = 1;
            if(g[x][y] == 6)
                if(py == y + 1 || px == x - 1) ok = 1;
            return;
        }
        if(x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) return;
        vis[x][y] = 1;
        if(g[x][y] == 1){
            dfs(x, y - 1, x, y);
            dfs(x, y + 1, x, y);
        }
        else if(g[x][y] == 2){
            dfs(x - 1, y, x, y);
            dfs(x + 1, y, x, y);
        }
        else if(g[x][y] == 3){
            dfs(x, y - 1, x, y);
            dfs(x + 1, y, x, y);
        }
        else if(g[x][y] == 4){
            dfs(x, y + 1, x, y);
            dfs(x + 1, y, x, y);
        }
        else if(g[x][y] == 5){
            dfs(x, y - 1, x, y);
            dfs(x - 1, y, x, y);
        }
        else if(g[x][y] == 6){
            dfs(x, y + 1, x, y);
            dfs(x - 1, y, x, y);
        }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        if(m == 1 && n == 1) return true;
        g = grid;
        vector<vector<bool>> v(m, vector<bool> (n, 0));
        vis = v;
        ok = false;
        dfs(0, 0, 0, 0);
        return ok;
    }
};
