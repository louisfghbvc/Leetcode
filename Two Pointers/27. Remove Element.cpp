// O(N). two pointer, and in-place
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(val != nums[i]) nums[l++] = nums[i];
        }
        return l;
    }
};
