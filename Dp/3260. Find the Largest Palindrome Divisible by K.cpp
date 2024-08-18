class Solution {
public:
    string largestPalindrome(int n, int k) {
        // goal: find the palindrome
        // idea:
        // enumerate
        // 1,3,9 -> 9999...
        // 2 -> 8, 88, 8999..9998
        // 4 -> 8, 88, 888, 8888, 88999...988
        // 5 -> 5, 55, 59..95
        // 6 -> 6, 66, 8?8, 89?98

        // idea2: using dp
        // for each index, we can using mod = 0
        // try to put from 9-0
        // check if possible

        string ans(n, '0');
        vector dp(n+1, vector(k+1, -1)); 

        vector<int> pow10(n+1, 1);
        for (int i = 1; i <= n; ++i)
            pow10[i] = (pow10[i-1] * 10) % k;

        auto dfs = [&](auto &self, int i, int m) -> int {
            if (i == (n+1)/2)
                return m == 0;

            int& res = dp[i][m];
            if (res != -1) return res;   

            res = 0;
            for (int d = 9; d >= (i == 0 ? 1 : 0); --d) {
                int nmod;
                if (n % 2 && i == n/2) { // odd and last index
                    nmod = (m + d * pow10[i]) % k;
                }
                else { // put i ... i
                    // left
                    nmod = (m + d * pow10[n-i-1]) % k;
                    // right
                    nmod = (nmod + d * pow10[i]) % k;
                }
                if (self(self, i+1, nmod)) {
                    ans[i] = ans[n-i-1] = '0'+d;
                    return res = 1;
                }
            }

            return res;
        };

        dfs(dfs, 0, 0);
        return ans;
    }
};
