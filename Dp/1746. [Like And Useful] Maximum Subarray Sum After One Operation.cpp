// T: O(N), S: O(N).
// case thinking. same as maximum subarray.

class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2));
        
        // base case. i = 0
        dp[0][0] = nums[0]; dp[0][1] = nums[0]*nums[0];
        
        int res = dp[0][1];
        for(int i = 1; i < n; ++i){
            // append or new one.
            dp[i][0] = max(nums[i], dp[i-1][0] + nums[i]);
            // 3 case.
            dp[i][1] = max({nums[i] * nums[i], dp[i-1][0] + nums[i] * nums[i], nums[i] + dp[i-1][1]});
            res = max(dp[i][1], res);
        }
        
        return res;
    }
};
