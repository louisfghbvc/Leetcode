// maintain a min and max dp.
// top down is dirty. O(MN).
class Solution {
public:
    int m, n;
    const int mod = 1e9+7;
    vector<vector<int>> g;
    long dp[20][20][2];
    bool vis[20][20][2];
    long dfs(int x, int y, bool pos = 1){
        if(x == m-1 && y == n-1) return g[x][y];
        if(vis[x][y][pos]) return dp[x][y][pos];
        long res1, res2;
        if(pos){
            res1 = res2 = LLONG_MIN;
            if(x+1 < m){
                res1 = g[x][y] * dfs(x+1, y, 1);
                res1 = max(res1, g[x][y] * dfs(x+1, y, 0));
            }
            if(y+1 < n){
                res2 = g[x][y] * dfs(x, y+1, 1);
                res2 = max(res2, g[x][y] * dfs(x, y+1, 0));
            }
            vis[x][y][pos] = 1;
            return dp[x][y][pos] = max(res1, res2);
        }
        else{
            res1 = res2 = LLONG_MAX;
            if(x+1 < m){
                res1 = g[x][y] * dfs(x+1, y);
                res1 = min(res1, g[x][y] * dfs(x+1, y, 0));
            }
            if(y+1 < n){
                res2 = g[x][y] * dfs(x, y+1);
                res2 = min(res2, g[x][y] * dfs(x, y+1, 0));
            }
            vis[x][y][pos] = 1;
            return dp[x][y][pos] = min(res1, res2);
        }
    }
    int maxProductPath(vector<vector<int>>& grid) {
        g = grid;
        m = grid.size(); n = grid[0].size();
        memset(vis, 0, sizeof vis);
        long res = dfs(0, 0, 1);
        return res < 0 ? -1 : res%mod;
    }
};


// Bottom up.
