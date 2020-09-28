// Simple sliding window, when window size > k. cur left.
// O(N). 

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        int val = 1;
        for(int r = 0, l = 0; r < n; ++r){
            val *= nums[r];
            while(l <= r && val >= k) val /= nums[l++];
            res += (r-l+1);
        }
        return res;
    }
};
