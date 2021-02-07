// Concise... O(N).
// so if rotated, u need to concern the first and the last.
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0, k = 0; i < n; ++i){
            if(nums[i] > nums[(i+1)%n] && ++k > 1) return false;
        }
        return true;
    }
};
