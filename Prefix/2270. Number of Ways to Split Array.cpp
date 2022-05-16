class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // goal: calculate the number of index such that the left sum >= right sum, split i
        // idea: use prefix sum
        
        long tot = accumulate(nums.begin(), nums.end(), 0L);
        long left = 0;
        int valid = 0;
        for (int i = 0; i+1 < nums.size(); ++i) {
            left += nums[i];
            tot -= nums[i];
            valid += left >= tot;
        }
        return valid;
    }
};
