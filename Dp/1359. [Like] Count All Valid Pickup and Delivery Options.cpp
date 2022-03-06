//0ms 8.3MB
typedef long long LL;
class Solution {
public:
    const int mod = 1e9 + 7;
    LL sum(int n){
        return (1 + n) * n / 2;
    }
    int countOrders(int n) {
        int res = 1;
        for(int i = 0, c = 1; i < n; ++i, c += 2){
            res = (res%mod * sum(c)%mod) % mod;
        }
        return res;
    }
};

// 0ms, 5.9MB
// Time: O(N), space O(1)
// think about the subproblem, first place can put n candidates
// after that, d can put any place, and reduce to problem to countOrders(n-1)
class Solution {
public:
    int countOrders(int n) {
        const int mod = 1e9+7;
        // 1: (p1, d1)
        // 2: (p1, d1, p2, d2) -> 3
        // 2(p), _ _ _
        // dp[2] = n*3*dp[1] = 6
        // dp[3] = 3*(2*3-1)*dp[2] = 90
        int dp0 = 1, dp = 1;
        for(int i = 2; i <= n; ++i){
            dp = 1LL*i*(2*i-1)%mod*dp0%mod;
            dp0 = dp;
        }
        return dp;
    }
};
