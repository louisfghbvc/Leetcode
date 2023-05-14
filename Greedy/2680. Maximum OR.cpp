class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        // goal: find the maximum or value, do at most k time shift
        
        // idea: look as binary
        
        // greedy, choose one item move k times
        //
        
        int n = nums.size();
        
        vector<long> pre(n+1), suf(n+1);
        for (int i = 0; i < n; ++i)
            pre[i+1] = pre[i] | nums[i];
        for (int i = n-1; i >= 0; --i)
            suf[i] = suf[i+1] | nums[i];

        // iterate
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            long val = pre[i] | suf[i+1];
            long x = nums[i];
            for (int j = 0; j < k; ++j) x <<= 1;
            val |= x;
            ans = max(val, ans);
        }
        return ans;
    }
};
