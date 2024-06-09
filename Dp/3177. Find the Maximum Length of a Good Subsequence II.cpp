class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        // goal: find the maximum length such that subsequence at most k different
        // idea: dp
        // dp(i, last, k) = max of  
        // 1. skip i : dp(i+1, last, k)
        // 2. choose i: 1 + dp(i+1, nums[i], k + (nums[i]!=last))
        
        // improve:
        // dp(i, c) : starting from index i, last choose is i, at most c diff
        // dp(i, c) -> 1 + dp(j, c), where j>i
        
        // nc at most increase 1
        // 1. nc = c
        // 2. nc = c+1
        // we can record maximum suffix
        // do from back
        
        int n = nums.size();

        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i)
            mp[nums[i]] = i;
        
        vector dp(n+1, vector(k+1, 1)); 
        vector suf(n, vector(k+1, 0));
        vector suf_mx(k+1, 0);
        for (int i = n - 1; i >= 0; --i) {          
            auto next_mx = suf_mx;
            for (int c = 0; c <= k; ++c) {
                // for (int j = i + 1; j < n; ++j) {
                //     int nc = c + (nums[j] != nums[i]);
                //     if (nc <= k) {
                //         dp[i][c] = max(dp[i][c], 1 + dp[j][nc]);
                //     }
                // }

                // 1.nums[j]==nums[i]
                dp[i][c] = max(dp[i][c], 1 + suf[mp[nums[i]]][c]);
                // 2. nums[j]!=nums[i], c+1
                if (c+1 <= k) 
                    dp[i][c] = max(dp[i][c], 1 + suf_mx[c+1]);
                
                // update suf
                suf[mp[nums[i]]][c] = max(suf[mp[nums[i]]][c], dp[i][c]);
                next_mx[c] = max(next_mx[c], dp[i][c]);
            }
            
            swap(suf_mx, next_mx);
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c <= k; ++c)
                res = max(res, dp[i][c]);
        }
        return res;
    }
};
