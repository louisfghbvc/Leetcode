// dimension reduction!
// It is easy to think abount O(n^4) how to speed up?

class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        // goal: split the grid, maximum the price you can get
        // idea: dp 
        // cut from left to right, up to down
        // how to remove no use rectangle?
        
        // dp[r][c]: maximum value that current rectangle is rxc
        // each pieces split to two rectangle
        
        // dp[r][c] = max of (prices[i] + dp[r-hi][c] + [hi][c-wi]) -> TLE
        // dp[3][5] = max of (7 + dp[1][5] + dp[2][3]...)
        
        // dp[r][c] = max(dp[r1][c] + dp[r-r1][c]) where r1 <= r. horization
        
        vector<vector<long>> dp(m+1, vector<long>(n+1, -1));
        
        vector<vector<long>> g(201, vector<long>(201));
        for (auto &p: prices) {
            long h = p[0], w = p[1], cost = p[2];
            g[h][w] = cost;
        }
        
        // O(r*c*r + r*c*c) 
        auto dfs = [&](const auto &self, int r, int c) -> long {
            if (r == 0 || c == 0) return 0;
            
            long &res = dp[r][c];
            if (res != -1) return res;
            res = g[r][c]; // just setting current grid
            
            for (int h = 0; h <= r; ++h) {
                res = max(res, self(self, r-h, c) + self(self, h, c)); // hori
            }
            for (int w = 0; w <= c; ++w) {
                res = max(res, self(self, r, w) + self(self, r, c-w)); // ver
            }
            
            return res;
        };
        
        return dfs(dfs, m, n);
    }
};
