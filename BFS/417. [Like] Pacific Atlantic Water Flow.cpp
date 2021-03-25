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


// More clean dfs.
class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(!m) return {};
        int n = matrix[0].size();
        
        vector<vector<int>> res;
        vector<vector<int>> vis(m, vector<int>(n));
        
        function<bool(int,int,int)> dfs = [&](int x, int y, int color){
            if((vis[x][y] & color)) return true;
            vis[x][y] |= color;
            if(vis[x][y] == 3) res.push_back({x, y});
            
            for(int i = 0; i < 4; ++i){
                int nx = x+dir[i][0], ny = y+dir[i][1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || matrix[x][y] > matrix[nx][ny]) continue;
                dfs(nx, ny, color);
            }
            return false;
        };
        
        for(int i = 0; i < m; ++i){
            dfs(i, 0, 1);
            dfs(i, n-1, 2);
        }
        for(int i = 0; i < n; ++i){
            dfs(0, i, 1);
            dfs(m-1, i, 2);
        }
        
        return res;
    }
};
