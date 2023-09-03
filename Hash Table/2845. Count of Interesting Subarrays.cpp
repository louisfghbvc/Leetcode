class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        // goal: count the subarray such that the range nums[i] is modulo = k
        
        // 1 <= nums <= 10^5
        // 1 <= nums[i], modulo <= 10^9
        // k < modulo
        
        // [1,0,0,1,1], 2,1
        //  1 0 0,1,1
        //  
        
        // idea:
        // brute force -> TC: O(n^2)
        // subarray sum % mod = k
        // preR - preL-1 == k
        // convert array to 0,1
        // 0 -> nums[i] % mod != k
        
        for (auto &x: nums)
            x = (x % modulo == k);
        
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        long ans = 0;
        long pre = 0;
        for (auto &x: nums) {
            pre += x;
            pre %= modulo;
            int target = ((pre-k)%modulo+modulo)%modulo;
            if (mp.count(target))
                ans += mp[target];
            mp[pre]++;
        }
        
        return ans;
    }
};
