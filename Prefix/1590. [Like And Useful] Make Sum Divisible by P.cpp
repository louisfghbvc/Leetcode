// Prefix map. so that total sum is %p. and just make total = 0.
// so find a prefix sum, can make total = 0.
// O(N).

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        
        int tot = 0;
        for(int x: nums) tot = (tot + x) % p;
        if(tot == 0) return 0;
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        int ans = n, sum = 0;
        for(int i = 0; i < n; ++i){
            sum = (sum + nums[i]) % p;
            int need = (sum - tot + p) % p;
            if(mp.count(need)){
                ans = min(i-mp[need], ans);
            }
            mp[sum] = i;
        }
        
        return ans == n ? -1 : ans;
    }
};
