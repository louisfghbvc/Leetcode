//4ms 7.1MB.
//Classic problem
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], tmp = 0;
        for(int i = 0; i < nums.size(); ++i){
            tmp = max(nums[i], tmp + nums[i]);
            ans = max(ans, tmp);
        }
        
        return ans;
    }
};
