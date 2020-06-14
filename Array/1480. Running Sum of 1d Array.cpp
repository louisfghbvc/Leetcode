// partial sum. O(N)
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans = nums;
        int sum = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            sum += nums[i];
            ans[i] = sum;
        }
        return ans;
    }
};
