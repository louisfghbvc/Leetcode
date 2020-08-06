// use value as index. and mark negative. when a num not negative means not have.
// O(N). Space O(1).
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(auto &x: nums){
            int val = abs(x)-1;
            if(nums[val] > 0) nums[val] = -nums[val];
        }
        for(int i = 0; i < nums.size(); ++i) if(nums[i] > 0) res.push_back(i+1);
        return res;
    }
};
