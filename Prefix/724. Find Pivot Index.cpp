// cnt total.
// and cnt if left == right part.
// T: O(N). S: O(1).
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < n; ++i){
            l += nums[i];
            if(l-nums[i] == r - l) return i;
        }
        return -1;
    }
};
