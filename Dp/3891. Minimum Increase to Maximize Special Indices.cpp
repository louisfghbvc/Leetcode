class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        // goal: maximum the special, min ops
        // only 2 possible
        // [x, p, p, x]

        // idea: dp

        // consider dp[i] = {max, min}
        // maximum the special indices, minimum the operation
        // [a,b,c,d,e]
        //    ^
        // i is special
        // dp[i].first = dp[i-2].first + 1
        // dp[i].second = dp[i-2].second + max(nums[i-1],nums[i+1])+1-nums[i]
        // i is not special
        // dp[i] = dp[i-1]
        
        int n = nums.size();
        vector<pair<int, long>> dp(n);
        for (int i = 1; i+1 < n; ++i) {
            // i is special
            dp[i].first = (i>1 ? dp[i-2].first : 0)+1;
            dp[i].second = (i>1 ? dp[i-2].second : 0) + max(0,max(nums[i-1],nums[i+1])+1-nums[i]);
            // i is not
            if (dp[i-1].first > dp[i].first || dp[i-1].first == dp[i].first && dp[i].second > dp[i-1].second)
                dp[i] = dp[i-1];
        }


        return dp[n-2].second;
    }
};
