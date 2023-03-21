class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        // goal: calculate the beautiful subarray
        // beautiful: element is zero
        // idea:
        // operation: xor should be zero
        // use prefix sum map
        
        unordered_map<int, int> mp;
        int val = 0;
        mp[0] = 1;
        long ans = 0;
        for (int x: nums) {
            val ^= x;
            ans += mp[val]++;
        }
        return ans;
    }
};
