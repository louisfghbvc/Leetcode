// BFS, Simple O(NM)
class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!mat[i][j]){
                    vis[i][j] = 1;
                    q.push({i, j});
                }    
            }
        }
        
        int level = 0;
        while(q.size()){
            level++;
            for(int qs = q.size()-1; qs >= 0; --qs){
                auto [x, y] = q.front(); q.pop();
                for(int k = 0; k < 4; ++k){
                    int nx = x + dir[k][0], ny = y + dir[k][1];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    mat[nx][ny] = level;
                    q.push({nx, ny});
                }
            }
        }
        
        return mat;
    }
};

//  4 dir Dp.
