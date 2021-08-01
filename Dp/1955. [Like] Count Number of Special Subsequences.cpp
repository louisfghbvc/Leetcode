// O(N). O(1) space
// think about just 0,1
class Solution {
public:
    const int mod = 1e9+7;
    int countSpecialSubsequences(vector<int>& nums) {
        long cnt[3] = {};
        for(int x: nums){
            if(x == 0) // append, not append, new one
                cnt[x] = cnt[x] + cnt[x] + 1;
            else
                cnt[x] = cnt[x] + cnt[x] + cnt[x-1];
            cnt[x] %= mod;
        }
        return cnt[2] % mod;
    }
};
