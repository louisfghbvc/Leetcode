// O(1) space

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        // goal: find the minimum flips that can make nums to all 1
        // idea: line sweep, for each position
        // try to see the prefix difference accumulate
        // if current is 0, prefix is even -> flip
        // if current is 1, prefix is odd -> flip
        
        // state 2: nums[i] is flipped
        
        int pre = 0;
        int ops = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - k >= 0 && nums[i - k] == 2)
                pre--;
            if ((nums[i] + pre) % 2 == 0) {
                if (i + k > nums.size()) return -1;
                pre++;
                ops++;
                nums[i] = 2;
            }
        }
        
        return ops;
    }
};
