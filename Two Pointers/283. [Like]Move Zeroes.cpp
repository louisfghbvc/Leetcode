class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int j = 0, i = 0; j < nums.size(); ++j){
            while(i < nums.size() && nums[i]) i++;
            if(i < nums.size() && i < j) swap(nums[i], nums[j]);
        }
    }
};
