class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // goal: find the longest nice subarray
        // nice: pairwise AND are all zero
        // > a subarray can not have common digit -> nice
        
        // idea: sliding window
        
        vector<int> bit(30);
        
        auto add = [&](int x) {
            for (int i = 0; i < 30; ++i)
                bit[i] += x>>i&1;
        };
        auto remove = [&](int x) {
            for (int i = 0; i < 30; ++i)
                bit[i] -= x>>i&1;
        };
        auto nice = [&]() {
            for (int i = 0; i < 30; ++i) 
                if (bit[i] > 1) return false;
            return true;
        };
        
        int ans = 0;
        // O(30*n)
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            add(nums[r]);
            while (!nice()) {
                remove(nums[l++]);
            }
            ans = max(ans, r-l+1);
        }
        
        return ans;
    }
};
