class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        // goal: find the number of subarray such that the sum * the length < k
        // idea:
        // brute force - enumerate each position try to extend -> O(N^2)
        // two pointers: for each 
        
        long res = 0;
        
        // 2 1 4 3 5, 10
        // l     r
        // [     ] is valid
        //. [    ] is valid
        //.  [   ] is valid
        //.    [ ] is valid
        
        long sum = 0;
        for (int r = 0, l = 0; r < nums.size(); ++r) {
            sum += nums[r];
            while (sum * (r-l+1) >= k) {
                sum -= nums[l];
                l++;
            }
            // r-l+1, all subarray ending to r is smaller than k
            res += r-l+1;
        }
        
        return res;
    }
};
