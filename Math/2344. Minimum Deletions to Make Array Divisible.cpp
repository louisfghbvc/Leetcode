class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        // goal: delete the smallest number x in nums
        // such that all number in numsDivide % x == 0
        
        // idea: sort nums and simulate
        // we first compute the gcd of numsDivide
        
        // [2,2,3,3,4], gcd(numsDivide) = 6
        //      ^
        
        // O(NlogN)
        sort(nums.begin(), nums.end());
        
        int g = 0; // gcd(0, 5) = 5
        for (int x: numsDivide) g = __gcd(g, x);
        
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (g % nums[i] == 0) { // nums[i] is divisor of gcd
                return i;
            }
        }
        
        return -1;
    }
};
