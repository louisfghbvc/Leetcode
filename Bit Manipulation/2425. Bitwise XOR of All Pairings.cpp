class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // goal: find the xor pair sum
        // idea: enumerate -> too slow
        // O(N+M)
        
        // observe: 
        // nums1 = [x1, x2]   nums2 = y1
        // x1 ^ x2 ^ y1 ^ y1 ^ y1 = x1 ^ x2 ^ y1
        
        int n = nums1.size();
        
        int xor_first = 0;
        for (int x: nums1) {
            xor_first ^= x;
        }
        
        int res = 0;
        for (int x: nums2) {
            if (n & 1)
                res ^= xor_first ^ x;
            else
                res ^= xor_first;
        }
        
        return res;
    }
};
