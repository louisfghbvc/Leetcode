class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        // goal: choose k size subarray decrease by 1, make all zero
        
        // idea:
        
        // [2,2,3,1,1,0]
        // [2,2,2,0,0,0]
        
        // choose the minimum to decrease
        
        // [0,0,0,0,0,0] -> add k subarray to make it to nums
        //  2 2 2
        //      1 1 1
        
        // +2     -2
        //      +1   -1
        //       
        
        // from left to right, add the subarray value=nums[i]
        // prefix sum
        
        int n = nums.size();
        vector<int> diff(n);
        
        for (int i = 0; i < n; ++i) {
            if (i) diff[i] += diff[i-1];
            
            if (diff[i] > nums[i])
                return false;
            
            int add = nums[i]-diff[i];
            diff[i] += add;
            if (add != 0 && i+k > n) return false;
            if (i+k < n)
                diff[i+k] -= add;
        }
        
        return true;
    }
};
