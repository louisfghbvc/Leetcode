// Dp + Memorazation.

class Solution {
public:
    vector<string> g = {
        "123",
        "456",
        "789",
        "*0#"
    };
    const int mod = 1e9+7;
    const int dir[8][2] = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}};
    
    int dp[4][3][5005];
    
    int dfs(int x, int y, int i, int n){
        if(i == n) return 1;
        if(dp[x][y][i] != -1) return dp[x][y][i];
        int res = 0;
        for(int k = 0; k < 8; ++k){
            int nx = x + dir[k][0], ny = y + dir[k][1];
            if(nx < 0 || nx >= 4 || ny < 0 || ny >= 3 || !isdigit(g[nx][ny])) continue;
            res = (res + dfs(nx, ny, i+1, n))%mod;
        }
        return dp[x][y][i] = res;
    }
    
    int knightDialer(int n) {
        memset(dp, -1, sizeof dp);
        int res = 0;
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 3; ++j){
                if(!isdigit(g[i][j])) continue;
                res = (res + dfs(i, j, 1, n)) % mod;
            }
        }
        return res;
    }
};
