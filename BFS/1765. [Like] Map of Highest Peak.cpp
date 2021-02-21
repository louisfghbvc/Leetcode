// BFS. just like shortest path.
// O(NM).

class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> res(n, vector<int>(m, -1));
        
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(isWater[i][j]){
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        while(q.size()){
            auto [x, y] = q.front(); q.pop();
            for(int k = 0; k < 4; ++k){
                int nx = x + dir[k][0], ny = y+dir[k][1];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || res[nx][ny] != -1) continue;
                res[nx][ny] = res[x][y]+1;
                q.push({nx, ny});
            }
        }
        
        return res;
    }
};
