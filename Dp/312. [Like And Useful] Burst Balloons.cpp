// Interval dp. like matrix chain
// so choose k as last burst, means bound are k.
// so can divide the left and the right.
// O(N^3).

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n+2, 1);
        for(int i = 0; i < n; ++i)
            arr[i+1] = nums[i];
        
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        
        function<int(int, int)> dfs;
        dfs = [&](int l, int r){
            if(l+1 == r) return 0;
            if(dp[l][r] != -1) return dp[l][r];
            int res = 0;
            for(int k = l+1; k < r; ++k)
                res = max(res, arr[l]*arr[k]*arr[r] + dfs(l, k) + dfs(k, r));
            return dp[l][r] = res;
        };
        
        return dfs(0, n+1);
    }
};
