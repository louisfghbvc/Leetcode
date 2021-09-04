// Two Pointers. O(N)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        for(int r = 0, l = 0, zero = 0; r < nums.size(); ++r){
            zero += nums[r] == 0;
            while(zero > 1) zero -= nums[l++] == 0;
            res = max(r - l + 1, res);
        }
        return res;
    }
};
