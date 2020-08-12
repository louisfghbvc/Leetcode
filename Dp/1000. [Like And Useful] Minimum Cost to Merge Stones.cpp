// T: O(N^3/K) S: O(N^2) Optimal bottom-up dp.
// from 1. so first check (n-1)%(K-1).
// because when merge i times N - (K-1)*i, and last must be 1.

// the dp[i][j] is from sub dp[1, rest] or [1+K-1, rest] or [1+(K-1)*2, rest] ... to j. ohter is no use.
// and the true merge is when (j-i)%(K-1) == 0

class Solution {
public:
    
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if((n-1)%(K-1)) return -1;
    
        vector<int> pre(n+1);
        for(int i = 0; i < n; ++i)
            pre[i+1] = pre[i] + stones[i];
        
        vector<vector<int>> dp(n, vector<int>(n));
        for(int L = K; L <= n; ++L){
            for(int i = 0, j = i+L-1; j < n; ++i, ++j){
                dp[i][j] = 1e9;
                for(int k = i; k < j; k += K-1){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                }
                if((L-1)%(K-1) == 0) dp[i][j] += pre[j+1] - pre[i];
            }
        }
        
        return dp[0][n-1];
    }
};

// T: O(N^3). S:O(N^3)
// when leave 1 pile means true merge.
class Solution {
public:
    int dp[105][105][35], K;
    vector<int> pre;
    int dfs(int l, int r, int pile){
        if(l == r) return pile == 1 ? 0 : 1e9;
        if(dp[l][r][pile] != -1) return dp[l][r][pile];
        int res = 1e9;
        if(pile == 1){
            res = dfs(l, r, K) + pre[r+1] - pre[l];  
        }
        else{
            for(int t = l; t < r; ++t)
                res = min(res, dfs(l, t, 1) + dfs(t+1, r, pile-1));
        }
        // cout << l << " " << r << " " << pile << " " << res << endl;
        return dp[l][r][pile] = res;
    }
    
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if((n-1)%(K-1)) return -1;
        
        this->K = K;
        memset(dp, -1, sizeof dp);
        
        pre = vector<int>(n+1);
        for(int i = 0; i < n; ++i)
            pre[i+1] = pre[i] + stones[i];
        
        return dfs(0, n-1, 1);
    }
};

// Other Top-down dp
// use pair. maintain [min cost, window size]
