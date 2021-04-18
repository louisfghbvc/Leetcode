// Simple. build from left.
// O(N)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        for(int i = 1; i < nums.size(); ++i){
            int need = nums[i-1]+1;
            res += max(0, need - nums[i]);
            nums[i] = max(nums[i], need);
        }

        return res;
    }
};
