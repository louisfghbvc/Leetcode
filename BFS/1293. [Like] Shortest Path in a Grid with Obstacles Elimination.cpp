// Shortest path.
class Solution {
public:
    typedef array<int, 3> iii;
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, 1e9)));
        dp[0][0][0] = 0;
        priority_queue<iii, vector<iii>, greater<iii>> pq;
        pq.push({0, 0, 0}); // cost, k, id
        while(pq.size()){
            auto [cost, cur_k, id] = pq.top(); pq.pop();
            int x = id / n, y = id % n;
            if(x == m-1 && y == n-1) return cost;
            for(int i = 0; i < 4; ++i){
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if(!grid[nx][ny]){
                    if(cost+1 < dp[nx][ny][cur_k]){
                        dp[nx][ny][cur_k] = cost+1;
                        pq.push({cost+1, cur_k, nx*n + ny});
                    }
                }
                else{
                    if(cur_k < k && cost+1 < dp[nx][ny][cur_k+1]){
                        dp[nx][ny][cur_k+1] = cost+1;
                        pq.push({cost+1, cur_k+1, nx*n + ny});
                    }
                }
            }
        }
        
        int res = 1e9;
        for(int i = 0; i < k; ++i)
            res = min(res, dp[m-1][n-1][k]);
        return res == 1e9 ? -1 : res;
    }
};

// Just bfs and visited O(MNK).
class Solution {
public:
    typedef pair<int, int> ii;
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(k+1)));
        queue<ii> q;
        q.push({0, 0}); // k, id
        vis[0][0][0] = 1;
        int dis = 0;
        while(q.size()){
            int sz = q.size();
            for(int i = 0; i < sz; ++i){
                auto [cur_k, id] = q.front(); q.pop();
                int x = id / n, y = id % n;
                if(x == m-1 && y == n-1) return dis;
                for(int i = 0; i < 4; ++i){
                    int nx = x + dir[i][0], ny = y + dir[i][1];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if(!grid[nx][ny]){
                        if(!vis[nx][ny][cur_k]){
                            vis[nx][ny][cur_k] = 1;
                            q.push({cur_k, nx*n + ny});
                        }
                    }
                    else{
                        if(cur_k < k && !vis[nx][ny][cur_k+1]){
                            vis[nx][ny][cur_k+1] = 1;
                            q.push({cur_k+1, nx*n + ny});
                        }
                    }
                }
            }
            dis++;
        }
        
        return -1;
    }
};
