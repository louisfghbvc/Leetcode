// O(MN). Space O(MN).
// Color from outside.

class Solution {
public:
    typedef pair<int, int> ii;
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    void color(vector<vector<int>> &dp, int c, queue<pair<int, int>> &q, vector<vector<bool>> vis,
               vector<vector<int>> &matrix){
        while(q.size()){
            auto [x, y] = q.front(); q.pop();
            if(vis[x][y]) continue;
            vis[x][y] = 1;
            dp[x][y] |= c;
            for(int k = 0; k < 4; ++k){
                int nx = x+dir[k][0], ny = y+dir[k][1];
                if(nx < 0 || nx >= dp.size() || ny < 0 || ny >= dp[0].size() || vis[nx][ny] || matrix[nx][ny] < matrix[x][y]) continue;
                q.push({nx, ny});
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(!m) return {};
        int n = matrix[0].size();
        
        vector<vector<int>> res;
        vector<vector<int>> dp(m, vector<int>(n));
        vector<vector<bool>> vis(m, vector<bool>(n));
        
        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i){
            q.push({i, 0});
        }
        for(int j = 0; j < n; ++j){
            q.push({0, j});
        }
        color(dp, 1, q, vis, matrix);
        
        for(int i = 0; i < m; ++i){
            q.push({i, n-1});
        }
        for(int j = 0; j < n; ++j){
            q.push({m-1, j});
        }
        color(dp, 2, q, vis, matrix);
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(dp[i][j] == 3) 
                    res.push_back({i, j});
            }
        }
        
        return res;
    }
};
