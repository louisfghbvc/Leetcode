// O(NM). just dfs + memo

class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    vector<vector<int>> matrix;
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int dfs(int x, int y){
        if(dp[x][y] != -1) return dp[x][y];
        int res = 1;
        for(int k = 0; k < 4; ++k){
            int nx = x + dir[k][0], ny = y + dir[k][1];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || matrix[x][y] >= matrix[nx][ny]) continue;
            res = max(res, 1 + dfs(nx, ny));
        }
        
        return dp[x][y] = res;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        m = matrix.size(), n = matrix[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        
        int res = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                res = max(res, dfs(i, j));
            }
        }
        return res;
    }
};
