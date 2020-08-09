// O(N^2). Just BFS.
// watch out ans-1. because if no oranges. is 0 not -1 
// why ans-1? First, if have 2 cnt will add 1. but if only 2. ans is 0 minute

class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<int> q;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] == 2) q.push(i*m+j), grid[i][j] = 0;
        int cnt = 0;
        while(q.size()){
            for(int s = q.size()-1; s >= 0; --s){
                int id = q.front(); q.pop();
                int x = id/m, y = id%m;
                for(int k = 0; k < 4; ++k){
                    int nx = x + dir[k][0], ny = y + dir[k][1];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || !grid[nx][ny]) continue;
                    grid[nx][ny] = 0;
                    q.push(nx*m+ny);
                }
            }
            cnt++;
        }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(grid[i][j] == 1) return -1;
        return cnt > 0 ? cnt-1 : 0;
    }
};
