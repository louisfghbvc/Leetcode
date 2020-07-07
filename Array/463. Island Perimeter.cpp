// Just Check 4 direction
class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int cnt = 4;
                if(grid[i][j] == 0) continue;
                for(int k = 0; k < 4; ++k){
                    int nx = i+dir[k][0], ny = j+dir[k][1];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 0) continue;
                    cnt--;
                }
                ans += cnt;
            }
        }
        return ans;
    }
};
