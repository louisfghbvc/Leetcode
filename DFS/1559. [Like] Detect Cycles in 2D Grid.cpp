// O(M*N). so if from different path and go to back, exist cycle.
// just like tree. record parent.
// Q RRR.
class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;
    vector<vector<char>> tmp;
    vector<vector<bool>> vis;
    bool dfs(int x, int y, char c, int px, int py){
        // cout << x << " " << y << "\n";
        if(vis[x][y]) return true;
        vis[x][y] = 1;
        for(int k = 0; k < 4; ++k){
            int nx = x+dir[k][0], ny = y + dir[k][1];
            if((nx == px && ny == py) || nx < 0 || nx >= m || ny < 0 || ny >= n || tmp[nx][ny] != c) continue;
            if(dfs(nx, ny, c, x, y)) return true;
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        // for(auto &r: grid){
        //     for(auto &c: r)
        //         cout << c << " ";
        //     cout << "\n";
        // }
        vis = vector<vector<bool>> (m, vector<bool>(n));
        tmp = grid;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(vis[i][j]) continue;
                if(dfs(i, j, tmp[i][j], i, j)) return true;
            }
        }
        return false;
    }
};
