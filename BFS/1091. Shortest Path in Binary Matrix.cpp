// O(NlogN). bfs. shortest path problem. awesome use grid.
// set grid.

class Solution {
public:
    typedef pair<int, int> ii;
    int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        // cost, index
        if(grid[0][0]) return -1;
        pq.push({1, 0});
        while(pq.size()){
            auto [cost, index] = pq.top(); pq.pop();
            int x = index / m, y = index % m;
            if(x == n-1 && y == m-1) return cost;
            for(int i = 0; i < 8; ++i){
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny]) continue;
                grid[nx][ny] = 1;
                pq.push({cost+1, nx*m + ny});
            }
        }        
        
        return -1;
    }
};

// use extra space . dp. same
class Solution {
public:
    typedef pair<int, int> ii;
    /**
    0 0 0
    1 1 0
    1 1 1
    **/
    int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e6));
        
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        // cost, index
        if(grid[0][0]) return -1;
        pq.push({1, 0});
        while(pq.size()){
            auto [cost, index] = pq.top(); pq.pop();
            int x = index / m, y = index % m;
            if(x == n-1 && y == m-1) return cost;
            dp[x][y] = cost;
            for(int i = 0; i < 8; ++i){
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny]) continue;
                if(dp[nx][ny] > dp[x][y] + 1){
                    dp[nx][ny] = dp[x][y] + 1;
                    pq.push({dp[nx][ny], nx*m + ny});
                }
            }
        }        
        
        return -1;
    }
};
