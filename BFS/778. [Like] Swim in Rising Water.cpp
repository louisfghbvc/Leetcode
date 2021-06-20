// BFS + dp. O(N^4)? 
class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        queue<array<int, 3>> q;
        q.push({0, 0, grid[0][0]});
        dp[0][0] = grid[0][0];
        
        while(q.size()){
            auto [x, y, cost] = q.front(); q.pop();
            if(dp[x][y] < cost) continue;
            dp[x][y] = cost;
            for(int k = 0; k < 4; ++k){
                int nx = x + dir[k][0], ny = y + dir[k][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                int nxt = max(cost, grid[nx][ny]);
                if(dp[nx][ny] > nxt){
                    dp[nx][ny] = nxt;
                    q.push({nx, ny, nxt});
                }
                
            }
        }
        return dp[n-1][n-1];
    }
};

// Dijkstra. O(N^2logN).
class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    typedef array<int, 3> ar;
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        
        priority_queue<ar, vector<ar>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        dp[0][0] = grid[0][0];
        
        while(pq.size()){
            auto [cost, x, y] = pq.top(); pq.pop();
            if(dp[x][y] < cost) continue;
            dp[x][y] = cost;
            for(int k = 0; k < 4; ++k){
                int nx = x + dir[k][0], ny = y + dir[k][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                int nxt = max(cost, grid[nx][ny]);
                if(dp[nx][ny] > nxt){
                    dp[nx][ny] = nxt;
                    pq.push({nxt, nx, ny});
                }
            }
        }
        
        return dp[n-1][n-1];
    }
};


// Binary Search(Guess Time) + BFS.
