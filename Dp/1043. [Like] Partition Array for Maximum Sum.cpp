// Top down Dp. O(NK).

class Solution {
public:
    int n;
    vector<int> arr;
    int k;
    vector<int> dp;
    
    int dfs(int i){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int res = 0;
        int mx = 0;
        for(int j = 0; j < k && i + j < n; ++j){ // each can be maintain or new one
            mx = max(arr[i + j], mx);
            res = max(mx * (j+1) + dfs(i+j+1), res); 
        }
        return dp[i] = res;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        this->arr = arr;
        this->k = k;
        dp = vector<int>(n, -1);
        return dfs(0);
    }
};
