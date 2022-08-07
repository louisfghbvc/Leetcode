// O(N), dp
// greedy can not work. since condition 3 is overlap condition 1 and 2

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        // goal: split the array such that each subarray satisfied all condition
        
        // idea: from left to right build the array
        // we only care the operation 3
            
        // each position we can split or not
        
        int n = nums.size();
        vector dp(n+1, false);
        dp[0] = 1;
        
        // shift 1
        // dp[i]: first length that can partition
        for (int i = 2; i <= n; ++i) {
            if (nums[i-1] == nums[i-2] && dp[i-2]) {
                dp[i] = true;
            }
            if (i >= 3) {
                if (nums[i-1] == nums[i-2] && nums[i-2] == nums[i-3] && dp[i-3]) {
                    dp[i] = true;
                }
                if (nums[i-3]+1 == nums[i-2] && nums[i-2]+1 == nums[i-1] && dp[i-3]) {
                    dp[i] = true;
                }
            }
        }
        
        return dp[n];
    }
};
