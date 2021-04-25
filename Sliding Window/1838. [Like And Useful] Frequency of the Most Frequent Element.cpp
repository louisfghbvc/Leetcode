// O(N). this only bigger. and just like window. u change to same value.

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int res = 0;
        long sum = 0;
        for(int r = 0, l = 0; r < n; ++r){
            sum += nums[r];
            while(k < (long)nums[r] * (r - l + 1) - sum){
                sum -= nums[l++];
            }
            res = max(r - l + 1, res);
        }
        
        return res;
    }
};
