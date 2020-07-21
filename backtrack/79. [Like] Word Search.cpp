// just dfs.
// Simple backtracking.

class Solution {
public:
    vector<vector<char>> g;
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool dfs(string &word, int i, int x, int y){
        if(i == word.size()) return true;
        if(x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || g[x][y] != word[i]) return false;
        char c = g[x][y];
        g[x][y] = '0';
        for(int k = 0; k < 4; ++k){
            int nx = x + dir[k][0], ny = y + dir[k][1];
            if(dfs(word, i+1, nx, ny)){
                g[x][y] = c;
                return true;
            }
        }
        g[x][y] = c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        g = board;
        for(int i = 0; i < g.size(); ++i){
            for(int j = 0; j < g[0].size(); ++j){
                if(dfs(word, 0, i, j)) return true;
            }
        }
        return false;
    }
};
