class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // goal: find the perimeter of triangle
        // idea: sort from desending
        
        sort(nums.rbegin(), nums.rend());
        
        int n = nums.size();
        for (int i = 0; i+2 < n; ++i) {
            if (nums[i+1] + nums[i+2] > nums[i])
                return nums[i]+nums[i+1]+nums[i+2];
        }
        
        return 0;
    }
};
