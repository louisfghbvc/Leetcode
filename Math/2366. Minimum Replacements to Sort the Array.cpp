// brainteaser. reverse the array, since last never increasing, so last is fix
// O(N), greedy, want group number maximum

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        // operation: divide a nums[i] -> a+b == nums[i]
        // goal: minimum operations to make array sorted
        
        
        // idea: find the number of that greater than current x, will divide to x,x,....
        
        //  3,     8     3
        //  3, (2,3,3),   3
        //  3   ,  8,    3
        
        // two pass, left to right, main the last, last is largest -> not working
        
        // one pass -> right to left
        
        // [12,        9,       7,      6,17,19,21]
        // (3,3,3,3) (3,3,3). (3,4)    6,17,....
        //  3          2       1
        //                       6       1
        //                       3,3     
        //                     1,2
        
        reverse(nums.begin(), nums.end());
        
        long res = 0;
        int last = nums[0];
        int n = nums.size();
        
        // 6 5
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] > last) {
                int group = (nums[i]+last-1)/last;
                last = nums[i] / group;
                res += group-1;
            }
            else {
                last = nums[i];
            }
        }
        
        
        return res;
    }
};
