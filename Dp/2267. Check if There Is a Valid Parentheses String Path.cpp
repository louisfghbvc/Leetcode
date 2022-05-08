class Solution {
public:
    
    // O(m*n*(m+n))
    int dfs(int i, int j, int score) {
        if (i >= m || j >= n || score < 0) return 0;
        if (i == m-1 && j == n-1) return score == 0; // (())
        
        int &res = dp[i][j][score];
        if (res != -1) return res;
        
        res = 0; // init is false
        for (auto [ni, nj]: {make_pair(i+1, j), {i, j+1}}) {
            if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                res |= dfs(ni, nj, score + (g[ni][nj] == '(' ? 1 : -1));
            }
        }
        
        return res;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        // goal: find a valid path, starting from (0, 0) to (m-1, n-1)
        // idea: dp[i][j][cost] cost up to m*n, cost is the score of the parentheis, cost >= 0
        // dp[i][j][cost]: can reach i, j or not
        m = grid.size(), n = grid[0].size();
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m+n+1, -1))); // unvisited: -1, 1, 0
        g = grid;
        return dfs(0, 0, (g[0][0] == '(' ? 1 : -1));
    }
    
private:
    vector<vector<vector<int>>> dp;
    vector<vector<char>> g;
    int m, n;
};
