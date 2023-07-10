class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        // maximum subarray, length > 2
        
        // idea: brute force
        // for each position, try to extend as much as possible
        
        int n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            vector<int> arr = {nums[i]};
            for (int j = i+1, s=1; j < n; ++j, s*=-1) {
                if (nums[j] == nums[j-1]+s) {
                    arr.push_back(nums[j]);
                }
                else break;
            }
            ans = max(ans, (int)arr.size());
        }
        
        return ans == 1 ? -1 : ans;
    }
};
