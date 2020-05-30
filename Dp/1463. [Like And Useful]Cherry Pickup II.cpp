// Brute-Search + memorize.
// sometimes just try all case and memo. 
// because dfs must duplicate num if not memo.

class Solution {
public:
    int R, C;
    int dp[75][75][75];
    int dfs(vector<vector<int>>& g, int r, int c1, int c2){
        if(r == R) return 0;
        if(dp[r][c1][c2]) return dp[r][c1][c2];
        int cherry = c1==c2 ? g[r][c1] : g[r][c1]+g[r][c2];
        int ans = 0;
        for(int i = -1; i <= 1; ++i){
            for(int j = -1; j <= 1; ++j){
                int nc1 = c1+i, nc2 = c2+j;
                if(nc1 < 0 || nc1 >= C || nc2 < 0 || nc2 >= C) continue;
                ans = max(ans, dfs(g, r+1, nc1, nc2) + cherry);
            }
        }
        return dp[r][c1][c2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        R = grid.size(), C = grid[0].size();
        return dfs(grid, 0, 0, C-1);
    }
};
