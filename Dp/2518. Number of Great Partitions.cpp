class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        // goal: count the distinct parition
        // idea: enumerate half group
        // observe: k is small
        
        // dp[i]: sum i, number of ways
        // nums = [1,2,3,4], k = 4
        // total ways = 2^4
        // dp[0], [xxx]
        //.[xxx], dp[0]
        
        // dp[1], [xxx]
        //.[xxx], dp[1]
        
        // ...
        
        // dp[3], [xxx]
        //.[xxx], dp[3]
        
        
        long total = accumulate(nums.begin(), nums.end(), 0L);
        if (total/2 < k) return 0; // base case
        
        
        int mod = 1e9+7;
        vector<int> dp(k, 0);
        
        dp[0] = 1; // base
        for (int x: nums) { // 2,3,5
            // 0 1 2 3 4, x = 2
            // 1   1   1
            //   
            for (int i = k; i >= 0; --i) {
                if (i + x < k)
                    dp[i+x] = (dp[i+x] + dp[i])%mod;
            } 
        }
        
        int n = nums.size();
        long all_ans = 1;
        for (int i = 1; i <= n; ++i)
            all_ans = all_ans * 2 % mod;
        
        for (int i = 0; i < k; ++i)
            all_ans = ((all_ans - 2*dp[i]) % mod + mod) % mod;
        
        return all_ans;
    }
};
