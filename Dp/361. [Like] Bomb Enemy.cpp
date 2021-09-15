// Enumerate 4 direction
// O(MN).
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // 4 direction
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(m, vector<int>(n)));
            
        for(int i = 0; i < m; ++i){
            // left
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 'W') continue;
                dp[0][i][j] = (grid[i][j] == 'E');
                if(j) dp[0][i][j] += dp[0][i][j-1];
            }
            // right
            for(int j = n-1; j >= 0; --j){
                if(grid[i][j] == 'W') continue;
                dp[1][i][j] = (grid[i][j] == 'E');
                if(j != n-1) dp[1][i][j] += dp[1][i][j+1];
            }
        }
        
        for(int j = 0; j < n; ++j){
            // up
            for(int i = 0; i < m; ++i){
                if(grid[i][j] == 'W') continue;
                dp[2][i][j] = (grid[i][j] == 'E');
                if(i) dp[2][i][j] += dp[2][i-1][j];
            }
            // down
            for(int i = m-1; i >= 0; --i){
                if(grid[i][j] == 'W') continue;
                dp[3][i][j] = (grid[i][j] == 'E');
                if(i != m-1) dp[3][i][j] += dp[3][i+1][j];
            }
        }
        
        int res = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != '0') continue;
                int left = j ? dp[0][i][j-1] : 0;
                int right = j!=n-1 ? dp[1][i][j+1] : 0;
                int up = i ? dp[2][i-1][j] : 0;
                int down = i!=m-1 ? dp[3][i+1][j] : 0;
                res = max(res, left + right + up + down);
            }
        }
        
        return res;
    }
};

// O(MN), only do the head, tricky
class Solution {
public:
    
    int kill_cols(vector<vector<char>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        while(i < m && grid[i][j] != 'W'){
            res += grid[i][j] == 'E';
            i++;
        }
        return res;
    }
    
    int kill_rows(vector<vector<char>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        while(j < n && grid[i][j] != 'W'){
            res += grid[i][j] == 'E';
            j++;
        }
        return res;
    }
    
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<int> cols_hit(n);
        int rows, res = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(j == 0 || grid[i][j-1] == 'W'){
                    rows = kill_rows(grid, i, j);
                }
                if(i == 0 || grid[i-1][j] == 'W'){
                    cols_hit[j] = kill_cols(grid, i, j);
                }
                if(grid[i][j] == '0')
                    res = max(res, rows + cols_hit[j]);
            }
        }

        return res;
    }
};
