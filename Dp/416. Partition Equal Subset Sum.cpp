// just very simple O(n*sum).
// just 0/1 knapsack. you only need to know sum/2 is exist or not.
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if(tot & 1) return false;
        vector<bool> dp(tot/2+1);
        dp[0] = 1;
        for(int x: nums){
            for(int w = tot/2; w >= x; --w)
                dp[w] = dp[w]|dp[w-x];
        }
        return dp[tot/2];
    }
};

// O(N). use bitset. think bitset as a bitinteger.
// so just shift. and bitset is useful and fast.
// say array =[1, 5]. so dp[0] = 1.
// and dp |= dp << 1. dp become 11.
// dp << 5 means dp + 5.
// and dp |= dp << 5. dp become 1100011. means have 0, 1, 5, 6.

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if(tot & 1) return false;
        bitset<10001> dp = 1;
        for(int x: nums)
            dp |= dp << x;
        return dp[tot/2];
    }
};
