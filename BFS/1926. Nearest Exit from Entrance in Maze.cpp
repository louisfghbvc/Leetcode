// Go from current. O(NM).
class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n, m;
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& in) {
        n = maze.size();
        m = maze[0].size();
        
        queue<pair<vector<int>, int> > q; // pos, cost
        q.push({{in[0], in[1]}, 0});
        maze[in[0]][in[1]] = '+';
        
        while(q.size()){
            auto [cur, cost] = q.front(); q.pop();
            int x = cur[0], y = cur[1];
            if(cur != in && (x == 0 || x == n-1 || y == 0 || y == m-1)) return cost;
            for(int k = 0; k < 4; ++k){
                int nx = x + dir[k][0], ny = y + dir[k][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || maze[nx][ny] == '+') continue;
                maze[nx][ny] = '+';
                q.push({{nx, ny}, cost+1});
                
            }
        }
        
        return -1;
    }
};


// Go from side. i am noob =.=
class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n, m;
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& in) {
        n = maze.size();
        m = maze[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        
        queue<pair<vector<int>, int> > q; // pos, cost
        for(int i = 0; i < n; ++i){
            vector<int> v;
            v = {i, 0};
            if(maze[i][0] == '.' && v != in){
                dp[i][0] = 0;
                q.push({v, 0});
            }
            v = {i, m-1};
            if(maze[i][m-1] == '.' && v != in){
                dp[i][m-1] = 0;
                q.push({v, 0});
            }
        }
        for(int j = 0; j < m; ++j){
            vector<int> v;
            v = {0, j};
            if(maze[0][j] == '.' && v != in){
                dp[0][j] = 0;
                q.push({v, 0});
            }
            v = {n-1, j};
            if(maze[n-1][j] == '.' && v != in){
                dp[n-1][j] = 0;
                q.push({v, 0});
            }
        }
        
        
        while(q.size()){
            auto [cur, cost] = q.front(); q.pop();
            int x = cur[0], y = cur[1];
            if(dp[x][y] < cost) continue;
            dp[x][y] = cost;
            for(int k = 0; k < 4; ++k){
                int nx = x + dir[k][0], ny = y + dir[k][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || maze[nx][ny] == '+') continue;
                if(dp[nx][ny] > cost+1){
                    dp[nx][ny] = cost+1;
                    vector<int> nxt = {nx, ny}; 
                    q.push({nxt, dp[nx][ny]});
                }
            }
        }
        
        return dp[in[0]][in[1]] >= 1e9 ? -1 : dp[in[0]][in[1]];
    }
};
