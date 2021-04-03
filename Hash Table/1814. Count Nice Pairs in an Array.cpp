// Prefix map. O(NlgX).

class Solution {
public:
    const int mod = 1e9+7;
    
    long rev(int x){
        long res = 0;
        while(x){
            res = res*10 + x%10;
            x /= 10;
        }
        return res;
    }
    
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        long res = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i){
            res += mp[nums[i] - rev(nums[i])]++;
        }
        return res % mod;
    }
};
