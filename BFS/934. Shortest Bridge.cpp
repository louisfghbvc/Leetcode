// DFS color, BFS calculate shortest path.
class Solution {
public:
    // first color land.
    // second, use bfs to extand.
    
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(int color, int x, int y, vector<vector<int>> &A){
        if(x < 0 || y < 0 || x >= A.size() || y >= A[0].size() || A[x][y] != 1) return;
        A[x][y] = color;
        for(int i = 0; i < 4; ++i){
            int nx = x+dir[i][0], ny = y+dir[i][1];
            dfs(color, nx, ny, A);
        }
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        int n = A.size(); 
        int m = A[0].size();
        bool first = false;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(A[i][j]){
                    if(!first) dfs(-1, i, j, A);
                    else dfs(2, i, j, A);
                    first = true;
                }
            }
        }
        
        // x, y, id
        // use set to save target points
        set<pair<int, int>> st;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(A[i][j]){
                    if(A[i][j] == -1) q.push({i, j});
                    else st.insert({i, j});
                }
            }
        }
        
        int dep = 0;
        while(q.size()){
            for(int k = q.size()-1; k >= 0; --k){
                auto [x, y] = q.front(); q.pop();
                if(st.count({x, y})) return dep-1;
                A[x][y] = -1;
                for(int i = 0; i < 4; ++i){
                    int nx = x+dir[i][0], ny = y+dir[i][1];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && A[nx][ny] != -1){
                        A[nx][ny] = -1;
                        q.push({nx, ny});
                    }
                }
            }
            dep++;
        }
        
        return dep;
    }
};
