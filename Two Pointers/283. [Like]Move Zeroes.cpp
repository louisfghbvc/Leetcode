//O(N)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int j = 0, i = 0; j < nums.size(); ++j){
            if(nums[j]){
                swap(nums[i++], nums[j]);   
            }
        }
    }
};
