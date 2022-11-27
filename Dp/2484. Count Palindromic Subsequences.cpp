// enumerate the half palindrome
// count the number of ways, update the dp from back (avoid duplicate)
// dp[i][j] -> number of ways that match first i, ending in j
// if match p[i], dp[i][j] += dp[i-1][j-1] -> rolling dp

// TC: O(100 * n), SC: O(1)

class Solution {
public:
    int countPalindromes(string s) {
        string d = "0123456789";
        int mod = 1e9+7;
        
        long ans = 0;
        for (char c1: d) for (char c2: d) {
            long dp[5] = {};
            for (char c: s) {
                if (c == c1) dp[4] += dp[3];
                if (c == c2) dp[3] += dp[2];
                dp[2] += dp[1];
                if (c == c2) dp[1] += dp[0];
                if (c == c1) dp[0]++;
                for (auto &x: dp) x %= mod;
            }   
            ans = (ans + dp[4]) % mod;
        }
        
        return ans;
    }
};
