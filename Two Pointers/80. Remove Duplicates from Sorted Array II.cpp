// O(N). No extra space. easy to understand.
// First, think only one unique. then think at most two
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), j = 1;
        if(!n) return 0;
        bool same = false;
        for(int i = 1; i < n; ++i, ++j){
            if(nums[i] == nums[i-1]){
                if(!same) same = true;
                else j--;
            }
            else same = false;
            nums[j] = nums[i];
        }
        return j;
    }
};

