class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        // goal: minimized the value of partition
        // idea:
        // sort the array
        // ans is the difference of each adjcacent value
        
        
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 1; i < nums.size(); ++i)
            ans = min(ans, nums[i] - nums[i-1]);
        return ans;
    }
};
