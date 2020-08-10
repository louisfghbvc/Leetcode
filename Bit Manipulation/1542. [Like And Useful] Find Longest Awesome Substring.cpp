// use bitmask record the smallest index.
// and bitmask is 1<<10, because 10 digit.
// Like 1371. QQ
// and when even. if index occur before, means find a ans.
// and if bitmask digit diff 1. also is a ans.
// O(10N). 

class Solution {
public:
    int longestAwesome(string s) {
        int res = 0;
        int mask = 0;
        vector<int> dp(1024, s.size());
        dp[0] = -1;
        for(int i = 0; i < s.size(); ++i){
            mask ^= 1<<(s[i]-'0');
            res = max(res, i-dp[mask]);
            for(int j = 0; j < 10; ++j)
                res = max(res, i - dp[mask ^ (1<<j)]);
            dp[mask] = min(dp[mask], i);
        }
        return res;
    }
};
