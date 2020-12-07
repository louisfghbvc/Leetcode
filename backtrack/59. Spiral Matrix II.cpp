// O(N^2). just dfs. record parent direction.

class Solution {
public:
    vector<vector<int>> res;
    int n, id = 1;
    const int wk[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    // right, down, left, up.
    void dfs(int x, int y, int i){
        if(id > n*n || x < 0 || x >= n || y < 0 || y >= n) return;
        if(res[x][y]) return;
        res[x][y] = id++;
        for(int k = 0; k < 4; ++k)
            dfs(x + wk[(k+i)%4][0], y + wk[(k+i)%4][1], (k+i)%4);
    }
    
    vector<vector<int>> generateMatrix(int n) {
        this->n = n;
        res = vector<vector<int>> (n, vector<int>(n));
        dfs(0, 0, 0);
        return res;
    }
};
