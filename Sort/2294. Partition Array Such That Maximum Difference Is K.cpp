// O(nlogn)

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        // goal: minimum the number of sequence such that each sequence max - min at most k
        // idea: sort the array
        
        // and just use two pointers
        
        sort(nums.begin(), nums.end());
        
        int res = 0;
        int prev = -1;
        for (int r = 0; r < nums.size(); ++r) {
            if (prev == -1) prev = nums[r], res++; // set the minimum value
            else {
                if (nums[r] - prev > k) {
                    prev = nums[r];
                    res++;
                }
            }
        }

        return res;
    }
};
