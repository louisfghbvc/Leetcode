class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = nums[0];
        
        // idea: just go through the array, and check that abs then check value
        for (int i = 1; i < nums.size(); ++i) {
            if (abs(nums[i]) < abs(ans))
                ans = nums[i];
            else if(abs(nums[i]) == abs(ans))
                ans = max(nums[i], ans);
        }
        
        return ans;
    }
};
