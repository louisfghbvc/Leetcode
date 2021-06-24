// Just memo. Simple. O(NMD).

class Solution {
public:
    const int mod = 1e9+7;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int m, n;
    int dp[55][55][55];
    int dfs(int x, int y, int dep){
        if(x < 0 || x >= m || y < 0 || y >= n) return 1;
        if(dep == 0) return 0;
        if(dp[x][y][dep] != -1) return dp[x][y][dep];
        long res = 0;
        for(int k = 0; k < 4; ++k){
            res += dfs(x + dir[k][0], y + dir[k][1], dep-1);
            res %= mod;
        }
        return dp[x][y][dep] = res;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof dp);
        this->m = m;
        this->n = n;
        return dfs(startRow, startColumn, maxMove);
    }
};
