// DFS from edge == 'O'.
// label it, and make not label all 'X'
// O(NM)

class Solution {
public:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;
    void dfs(int x, int y, vector<vector<char>>& g){
        if(x < 0 || x >= m || y < 0 || y >= n) return;
        if(g[x][y] == 'X' || g[x][y] == 'W') return;
        g[x][y] = 'W';
        for(int k = 0; k < 4; ++k){
            dfs(x+dir[k][0], y+dir[k][1], g);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(!board.size()) return;
        m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; ++i){
            dfs(i, 0, board);
            dfs(i, n-1, board);
        }
            
        for(int j = 0; j < n; ++j){
            dfs(0, j, board);
            dfs(m-1, j, board);
        }
            
        
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                board[i][j] = (board[i][j] == 'W') ? 'O' : 'X';
            
    }
};
