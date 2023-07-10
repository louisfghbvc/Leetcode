class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        // goal: build the maximum subarray that is non-decreasing in nums3
        
        // idea: greedy -> fail
        // each position choose the minimum
        
        // dp[i][0]: maximum length is ending in nums1
        // dp[i][0] = 1 + dp[i-1][1] or dp[i-1][0]
        
        int n = nums1.size();
        vector dp(n, vector(2, 1));
        for (int i = 1; i < n; ++i) {
            if (nums1[i] >= nums1[i-1])
                dp[i][0] = max(dp[i][0], dp[i-1][0]+1);
            if (nums1[i] >= nums2[i-1])
                dp[i][0] = max(dp[i][0], dp[i-1][1]+1);
            if (nums2[i] >= nums1[i-1])
                dp[i][1] = max(dp[i][1], dp[i-1][0]+1);
            if (nums2[i] >= nums2[i-1])
                dp[i][1] = max(dp[i][1], dp[i-1][1]+1);
        }
        
        int ans = 0;
        for (auto &d: dp) {
            ans = max(ans, d[0]);
            ans = max(ans, d[1]);
        }
        return ans;
    }
};
