// 0-1 bfs !!!
// O(mn)

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        // goal: remove the minimum obstacles such that we can go from (0, 0) -> (m-1, n-1)
        // idea: bfs O(m*n)
        
        // 0 1 1 
        // 1 1 0
        // 1 1 0
        
        // 0 2 1
        // 2 1 0
        // 2 1 0
        
        // first start from upper left corner, calculate the distance to each obstacle
        // dp[i][j]: minimum removal to reach from (0, 0) to (i, j)
        
        int m = grid.size(), n = grid[0].size();
        deque<array<int, 3>> dq; // removal, (0, 0)
        
        dq.push_back({0, 0, 0});
        vector<vector<int>> dis(m, vector<int>(n, 1e9));
        dis[0][0] = 0;
        
        while (dq.size()) {
            auto [cost, i, j] = dq.front(); dq.pop_front();
            if (dis[i][j] < cost) continue;
            for (auto &[ni, nj]: {make_pair(i+1, j), {i-1, j}, {i, j-1}, {i, j+1}}) {
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (grid[ni][nj]) {
                    if (dis[ni][nj] > cost + grid[ni][nj]) {
                        dis[ni][nj] = cost + grid[ni][nj];
                        dq.push_back({dis[ni][nj], ni, nj});
                    }
                }
                else {
                    if (dis[ni][nj] > cost) {
                        dis[ni][nj] = cost;
                        dq.push_front({dis[ni][nj], ni, nj});
                    }
                }
            }
        }
        
        return dis[m-1][n-1];
    }
};

// Dijkstra, 
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        // goal: remove the minimum obstacles such that we can go from (0, 0) -> (m-1, n-1)
        // idea: bfs O(m*n)
        
        // 0 1 1 
        // 1 1 0
        // 1 1 0
        
        // 0 2 1
        // 2 1 0
        // 2 1 0
        
        // first start from upper left corner, calculate the distance to each obstacle
        // dp[i][j]: minimum removal to reach from (0, 0) to (i, j)
        
        int m = grid.size(), n = grid[0].size();
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq; // removal, (0, 0)
        
        pq.push({0, 0, 0});
        vector<vector<int>> dis(m, vector<int>(n, 1e9));
        dis[0][0] = 0;
        
        while (pq.size()) {
            auto [cost, i, j] = pq.top(); pq.pop();
            if (dis[i][j] < cost) continue;
            for (auto &[ni, nj]: {make_pair(i+1, j), {i-1, j}, {i, j-1}, {i, j+1}}) {
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (cost + grid[ni][nj] < dis[ni][nj]) {
                    dis[ni][nj] = cost + grid[ni][nj];
                    pq.push({dis[ni][nj], ni, nj});
                }
            }
        }
        
        return dis[m-1][n-1];
    }
};
