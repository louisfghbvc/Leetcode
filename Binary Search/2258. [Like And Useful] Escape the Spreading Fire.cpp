class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        // idea: binary search the minutes we can stay
        
        int m = grid.size(), n = grid[0].size();
        
        int l = 0, r = 1e9;
        int ans = -1;
        
        // overall O(M*N*logx)
        auto valid = [&](int time) {
            
            vector<vector<int>> dis(m, vector<int>(n, 1e9)); // start point to all grid shortest path
            vector<vector<int>> fire_dis(m, vector<int>(n, 1e9)); // fire to all grid shortest path
            auto tmp = grid;
        
            // bfs, push the fire
            queue<int> q;
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    if (grid[i][j] == 1)
                        q.push(i*n + j);
            // traverse the fire 
            while (q.size() && time) {
                for (int qs = q.size(); qs > 0; --qs) {
                    int idx = q.front(); q.pop();
                    int i = idx / n, j = idx % n;
                    for (auto [ni, nj] : {make_pair(i+1, j), {i-1, j}, {i, j+1}, {i, j-1}}) {
                        if (ni < 0 || nj < 0 || ni >= m || nj >= n || tmp[ni][nj]) continue;
                        tmp[ni][nj] = 1;
                        q.push(ni * n + nj);
                    }
                }
                time--;
            }
            
            
            // calculate the shortest path from fire
            while (q.size()) q.pop();
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (tmp[i][j] == 1) {
                        q.push(i*n + j);
                        fire_dis[i][j] = 0;
                    }
                }
            }
            while (q.size()) {
                for (int qs = q.size(); qs > 0; --qs) {
                    int idx = q.front(); q.pop();
                    int i = idx / n, j = idx % n;
                    for (auto [ni, nj] : {make_pair(i+1, j), {i-1, j}, {i, j+1}, {i, j-1}}) {
                        if (ni < 0 || nj < 0 || ni >= m || nj >= n || tmp[ni][nj] || fire_dis[ni][nj] <= fire_dis[i][j]+1) continue;
                        fire_dis[ni][nj] = fire_dis[i][j]+1;
                        q.push(ni * n + nj);
                    }
                }
            }
            
            // calculate from start point
            dis[0][0] = 0;
            q.push(0);
            while (q.size()) {
                for (int qs = q.size(); qs > 0; --qs) {
                    int idx = q.front(); q.pop();
                    int i = idx / n, j = idx % n;
                    for (auto [ni, nj] : {make_pair(i+1, j), {i-1, j}, {i, j+1}, {i, j-1}}) {
                        if (ni < 0 || nj < 0 || ni >= m || nj >= n || tmp[ni][nj] || dis[ni][nj] <= dis[i][j]+1) continue;
                        dis[ni][nj] = dis[i][j]+1;
                        q.push(ni * n + nj);
                    }
                }
            }
            
            
            // last shortest path to target
            q.push(0);
            while (q.size()) {
                for (int qs = q.size(); qs > 0; --qs) {
                    int idx = q.front(); q.pop();
                    int i = idx / n, j = idx % n;
                    if (i == m-1 && j == n-1) return true;
                    for (auto [ni, nj] : {make_pair(i+1, j), {i-1, j}, {i, j+1}, {i, j-1}}) {
                        if (ni < 0 || nj < 0 || ni >= m || nj >= n || tmp[ni][nj]) continue; 
                        // last position can be overlap
                        if (dis[ni][nj] < fire_dis[ni][nj] || dis[ni][nj] == fire_dis[ni][nj] && ni == m-1 && nj == n-1) {
                            tmp[ni][nj] = 1; // already visited
                            q.push(ni * n + nj);
                        }
                    }
                }
            }
            
            return false;
        };
        
        while (l <= r) {
            int mid = (l+r)/2;
            if (valid(mid)) l = mid+1, ans = mid;
            else r = mid-1;
        }
        
        return ans;
    }
};




