class Solution {
public:

    int F(vector<int> &nums, int k) {
        int ans = 0;
        int odd = 0;
        int n = nums.size();
        for (int r = 0, l = 0; r < n; ++r) {
            odd += nums[r] & 1;
            while (odd > k) {
                odd -= nums[l++] & 1;
            }
            ans += r-l+1;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        // goal: find the number of subarrays that has k odd numbers in it
        // idea:
        // convert the problem
        // F(k): number of subarrays at most k odd numbers
        // two pointers, when window size is greater than k odd, move left
        // else move right, -> we also have r-l+1 ans ending in r
        // ans = F(k) - F(k-1)

        return F(nums, k) - F(nums, k-1);
    }
};
