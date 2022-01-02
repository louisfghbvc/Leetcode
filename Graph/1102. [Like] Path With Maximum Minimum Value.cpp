// dijkstra algorithm
// O(MNlogMN)

class Solution {
public:
    
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        priority_queue<pair<int, int>> pq;
        vector<vector<int>> dp(m, vector<int>(n));
        
        dp[0][0] = grid[0][0];
        pq.push({grid[0][0], 0});
        
        while(pq.size()){
            auto [cost, idx] = pq.top(); pq.pop();
            int x = idx/n, y = idx%n;
            if(cost < dp[x][y]) continue;
            
            for(int k = 0; k < 4; ++k){
                int nx = x+dir[k][0], ny = y+dir[k][1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int ncost = min(cost, grid[nx][ny]);
                if(dp[nx][ny] < ncost){
                    dp[nx][ny] = ncost;
                    pq.push({ncost, nx * n + ny});
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};

// sort by val, then union find
