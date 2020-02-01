class Solution {
    vector<int> arr;
    int maxquery(int i, int j){
        int maxv = -1;
        for(int k = i; k <= j; ++k){
            maxv = max(maxv, arr[k]);
        }
        return maxv;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d > n) return -1;
        arr = jobDifficulty;
        vector<vector<int>> dp(d + 2, vector<int>(n + 2, 1e6));
        
        for(int i = 0; i < n; ++i)
            dp[1][i] = maxquery(i, n - 1); //base
        
        for(int da = 2; da <= d; ++da){
            for(int i = 0; i < n; ++i){
                for(int j = i; j < n; ++j){
                    dp[da][i] = min(dp[da][i], maxquery(i, j) + dp[da - 1][j + 1]);
                }    
            }
        }
        
        return dp[d][0];
    }
};
