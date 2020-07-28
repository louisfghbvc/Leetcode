// O(N^4). Brute Force. Remember. use visited or whatever is good.
// 684ms
class Solution {
public:
    vector<vector<int>> g;
    int m, n;
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int dfs(int x, int y){
        if(x < 0 || x >= m || y < 0 || y >= n || g[x][y] == 0) return 0;
        int res = 1;
        g[x][y] = 0;
        for(int i = 0; i < 4; ++ i){
            res += dfs(x + dir[i][0], y + dir[i][1]);
        }
        return res;
    }
    int largestIsland(vector<vector<int>>& grid) {
        g = grid;
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j){
                if(g[i][j] == 0){
                    g[i][j] = 1;
                    res = max(res, dfs(i, j));
                }
                g = grid;
            }
        return res == 0 ? m*n : res;
    }
};

// O(N^2). So many duplicate... use map and set is good!!
// make color be the key.
// 44ms.
class Solution {
public:
    vector<vector<int>> g;
    int n;
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int dfs(int x, int y, int color){
        if(x < 0 || x >= n || y < 0 || y >= n || g[x][y] != 1) return 0;
        g[x][y] = color;
        int res = 1;
        for(int i = 0; i < 4; ++i)
            res += dfs(x + dir[i][0], y + dir[i][1], color);
        return res;
    }
    int largestIsland(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size();
        int res = 0, color = 2;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(g[i][j] == 1){
                    int size = dfs(i, j, color);
                    mp[color++] = size;
                }
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1) continue;
                int tmp = 1;
                unordered_set<int> st;
                for(int k = 0; k < 4; k++){
                    int x = i+dir[k][0], y = j+dir[k][1];
                    if(x < 0 || x >= n || y < 0 || y >= n || st.count(g[x][y])) continue;
                    st.insert(g[x][y]);
                    tmp += mp[g[x][y]];
                }
                res = max(res, tmp);
            }
        }
        
        return res == 0 ? n*n : res;
    }
};
