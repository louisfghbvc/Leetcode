// Just go dfs. turn direction when can not go.

class Solution {
public:
    
    vector<int> res;
    vector<vector<bool>> vis;
    
    // right, down, left, up
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    void dfs(vector<vector<int>> &arr, int x, int y, int d = 0){
        vis[x][y] = 1;
        res.push_back(arr[x][y]);
        for(int k = 0; k < 4; ++k){
            int nx = x+dir[(k+d)%4][0], ny = y+dir[(k+d)%4][1];
            if(nx < 0 || nx >= arr.size() || ny < 0 || ny >= arr[0].size() || vis[nx][ny]) continue;
            dfs(arr, nx, ny, (k+d)%4);
        }
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vis = vector<vector<bool>>(matrix.size(), vector<bool>(matrix[0].size()) );
        dfs(matrix, 0, 0);
        return res;
    }
};
