// simple just 2 for loop

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size(); 
        for (int i = n; i > 0; --i)
            for (int j = 0; j+1 < i; ++j)
                nums[j] = (nums[j] + nums[j+1]) % 10;
        return nums[0];
    }
};
