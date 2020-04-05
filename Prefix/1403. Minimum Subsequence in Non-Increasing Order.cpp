//suffix <= prefix, add it.
//28ms 24MB
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> pf(nums.size() + 1, 0);
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            pf[i+1] = pf[i] + nums[i];
        }
        int sum = 0;
        for(int j = nums.size() - 1; j >= 0; --j){
            if(sum <= pf[j+1]){
                ans.push_back(nums[j]);
                sum += nums[j];
            }
        }
        return ans;
    }
};
