// Can Be O(1) Space.
// T: O(N)
// So base = origin array.
// if can grab or not grab. if grab from n-2. if not grab from n-1.

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        
        vector<int> dp = nums;
        
        for(int i = 0; i < n; ++i){
            if(i>1) dp[i] = max(dp[i], dp[i-2]+nums[i]);
            if(i) dp[i] = max(dp[i-1], dp[i]);
        }
        
        return dp.back();
    }
};
