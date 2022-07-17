class Solution {
public:
    int maximumSum(vector<int>& nums) {
        // goal: find the maximum nums[i] + nums[j], where sum of digits is equal
        // idea: record each digits
        // TC: O(N), SC: O(N)
        
        unordered_map<int, int> digit_mx; // sum of digits -> maximum number
        int ans = -1;
        
        for (int x: nums) {
            int t = x;
            int digit_sum = 0;
            while (t) {
                digit_sum += t%10;
                t /= 10;
            }
            
            if (digit_mx.count(digit_sum)) {
                ans = max(ans, digit_mx[digit_sum] + x);
            }
            digit_mx[digit_sum] = max(x, digit_mx[digit_sum]);
            
        }
        
        return ans;
    }
};
