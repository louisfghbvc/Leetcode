// Post-sum + Memorize. Enum.
// O(k*r*c), Trick
// try to enum every case, caculate cut number > 0. merge.
class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<int>> pre;
    int memo[55][55][12];
    int r, c; 
    
    int dfs(int x, int y, int cut){
        if(pre[x][y] == 0) return 0;
        if(cut == 0) return 1;
        if(memo[x][y][cut]) return memo[x][y][cut];
        
        int res = 0;
        // cut horizontal
        for(int nr = x+1; nr < r; ++nr){
            int sum = pre[x][y] - pre[nr][y];
            if(sum == 0) continue;
            res += dfs(nr, y, cut-1);
            res %= mod;
        }
        // cut vertical
        for(int nc = y+1; nc < c; ++nc){
            int sum = pre[x][y] - pre[x][nc];
            if(sum == 0) continue;
            res += dfs(x, nc, cut-1);
            res %= mod;
        }
        return memo[x][y][cut] = res;
    }
    
    int ways(vector<string>& pizza, int k) {
        r = pizza.size(), c = pizza[0].size();
        pre.resize(r+1);
        for(int i = 0; i <= r; ++i) pre[i].resize(c+1);
        for(int i = r-1; i >= 0; --i){
            for(int j = c-1; j >= 0; --j){
                pre[i][j] = pre[i+1][j] + pre[i][j+1] - pre[i+1][j+1] + ((pizza[i][j] == 'A') ? 1 : 0);
            }
        }
        return dfs(0, 0, k-1);
    }
};
