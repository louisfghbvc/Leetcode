// no need to do same work time. very fast.
// easy to implement.
class Solution {
public:
    int col[15];
    vector<int> arr;
    int res, k;
    int dfs(int i, int cur){
        if(cur >= res) return res;
        if(i == arr.size()) return res = cur;
        unordered_set<int> vis;
        for(int j = 0; j < k; ++j){
            if(!vis.insert(col[j]).second) continue;
            col[j] += arr[i];
            dfs(i+1, max(cur, col[j]));
            col[j] -= arr[i];
        }
        return res;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        arr = jobs;
        this->k = k;
        res = INT_MAX;
        return dfs(0, 0);
    }
};

// O(N3^N). Dp. precalculate maximum work time.
// add person. and compute minimum work time. I like this dp.
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        
        vector<vector<int>> dp(k+1, vector<int>(1<<n));
        
        for(int S = 0; S < 1<<n; ++S){
            int sum = 0;
            for(int i = 0; i < n; ++i){
                if(S>>i&1) sum += jobs[i];
            }
            dp[1][S] = sum;
        }
        
        for(int i = 2; i <= k; ++i){
            for(int S = 1; S < 1<<n; ++S){
                dp[i][S] = dp[i-1][S];
                for(int T = S;  T; T = (T-1)&S){
                    // add one person. i-1, 1.
                    dp[i][S] = min(dp[i][S], max(dp[1][T], dp[i-1][S^T]));
                }
            }
        }
        
        return dp[k][(1<<n)-1];
    }
};
