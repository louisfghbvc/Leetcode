class Solution {
public:

    long fpow(long a, long b, long m=1e9+7) {
        long res = 1;
        while (b) {
            if (b & 1) res = res * a % m;
            a = a*a%m;
            b >>= 1;
        }
        return res;
    }

    int numberOfWays(int n, int x, int y) {
        // goal: find the numer of ways
        // idea:
        // convert the problem
        // consider we fix the player
        // each time we can choose x stage
        // dp(i, x) => x * dp(i+1, x)
        // choose a new stage
        // dp(i, x) => dp(i+1, x+1)

        // we can easily get the number!
        // we can do reverse
        // dp(i, x) => dp(i-1, x-1) + x * dp(i-1, x)

        // after compute dp
        // we can use comb to find the x
        // and y 

        // we need to care the order of x!
        // x=2, [1,2] or [2,1] is different

        int mod = 1e9+7;
        vector dp(n+1, vector<long>(x+1, -1));
        auto dfs = [&](auto &self, int i, int j) -> long {
            if (i == 0 && j == 0) return 1;
            if (i == 0 || j == 0) return 0;

            auto& res = dp[i][j];
            if (res != -1) return res;

            res = self(self, i-1, j) * j % mod;
            res = (res + self(self, i-1, j-1)) % mod;
            return res;
        };

        vector comb(x+1, vector<long>(x+1, 0));
        for (int i = 0; i <= x; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % mod;
            }
        }

        long ans = 0;
        long perm = 1;
        for (int j = 1; j <= min(x, n); ++j) {
            perm = perm * j % mod;
            ans += dfs(dfs, n, j) * comb[x][j] % mod * fpow(y, j) % mod * perm % mod;
            ans %= mod;
        }

        return ans;
    }
};
