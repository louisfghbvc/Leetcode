class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // goal: count the good string where the length is between low and high
        // idea: dp
        // dp[i]: number of ways that the length is i
        
        const int mod = 1e9+7;
        vector dp(high+1, 0L);
        dp[0] = 1;
        
        for (int i = 0; i <= high; ++i) {
            if (i + one <= high)
                dp[i + one] = (dp[i + one] + dp[i]) % mod;
            if (i + zero <= high)
                dp[i + zero] = (dp[i + zero] + dp[i]) % mod;
        }
        
        long ans = 0;
        for (int i = low; i <= high; ++i)
            ans = (ans + dp[i]) % mod;
        return ans;
    }
};
