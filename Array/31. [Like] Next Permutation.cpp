// check increase pair. find minimum value of index, reverse i to end. cuz they are decreasing.
// O(N)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i = nums.size()-1;
        for(; i >= 1 && nums[i-1] >= nums[i]; i--);
        
        if(i == 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int j = nums.size()-1;
        for(; nums[i-1] >= nums[j]; j--);
        swap(nums[i-1], nums[j]);
        
        reverse(nums.begin()+i, nums.end());
        
    }
};
