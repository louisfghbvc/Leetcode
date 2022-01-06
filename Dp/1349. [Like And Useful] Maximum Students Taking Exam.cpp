class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size();
        vector<int> validity;
        for(int i = 0; i < m; ++i){
            int cur = 0;
            for(int j = 0; j < n; ++j){
                cur = cur * 2 + (seats[i][j] == '.'); 
            }
            validity.push_back(cur);
        }
        vector<vector<int>> dp(m + 1, vector<int>(1<<n, -1));
        dp[0][0] = 0;
        for(int i = 1; i <= m; ++i){
            int valid = validity[i - 1];
            for(int j = 0; j < (1<<n); ++j){
                //j is subset of valid and j not have adj
                if((j & valid) == j && !(j & (j >> 1))){
                    for(int k = 0; k < (1<<n); ++k){
                        // not upper left, not upper right and not -1
                        if(!((j>>1) & k) && !(j & (k>>1)) && dp[i - 1][k] != -1){
                            dp[i][j] = max(dp[i][j], dp[i - 1][k] + __builtin_popcount(j));
                        }
                    }
                }
            }
        }
        return *max_element(dp[m].begin(), dp[m].end());
    }
};


// Maximum bipartite algorithm.
// O(MNMN)
class Solution {
public:
    const int dir[6][2] = {{0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    
    bool dfs(int idx){
        int r = idx / n, c = idx % n;
        for(int k = 0; k < 6; k++){
            int nr = r+dir[k][0], nc = c+dir[k][1];
            if(nr < 0 || nr >= m || nc < 0 || nc >= n || vis[nr][nc]) continue;
            if(seats[nr][nc] == '.'){
                vis[nr][nc] = 1;
                if(match[nr][nc] == -1 || dfs(match[nr][nc])){
                    match[nr][nc] = r * n + c;
                    return 1;
                }
            }
        }
        return 0;
    }
    
    int maxStudents(vector<vector<char>>& seats) {
        memset(match, -1, sizeof match);
        
        m = seats.size(), n = seats[0].size();
        this->seats = seats;
        
        // max-bipartite algorithm
        int cnt = 0;
        for(int c = 0; c < n; c += 2){
            for(int r = 0; r < m; ++r){
                if(seats[r][c] == '.'){
                    memset(vis, 0, sizeof vis);
                    if(dfs(r * n + c))
                        cnt++;
                }
            }
        }
        
        int tot = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                tot += seats[i][j] == '.';
                
        return tot - cnt;
    }
    
private:
    int m, n;
    bool vis[10][10];
    int match[10][10];
    vector<vector<char>> seats;
};
