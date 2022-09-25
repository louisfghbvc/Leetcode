class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // goal: find the longest subarray length that has maximum bitwise and
        // idea: find the maximum value,
        // and calculate the maximum value length
        
        int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        
        int ans = 0;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && nums[j] == mx) j++;
            int len = j-i;
            ans = max(ans, len);
            if (len == 0) j++;
        }
        return ans;
    }
};
