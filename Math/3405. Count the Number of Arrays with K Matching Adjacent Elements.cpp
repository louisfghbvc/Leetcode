class Solution {
public:

    int mod = 1e9+7;
    long fpow(long a, long b) {
        long res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    vector<long> fac, ifac;
    long comb(long n, long m) {
        if (m < 0 || n < m) return 0;
        return fac[n] * ifac[m] % mod * ifac[n-m] % mod;
    }

    int countGoodArrays(int n, int m, int k) {
        // goal: count the good arrays such that 
        // exactly length n, and each value in [1,m]
        // where k arr[i]==arr[i-1]

        // idea:
        // n=3, m=any value, k=1
        // [1,1,m], [e,e,m]
        // [  ] [ ]   
        // [m] [e e]

        // it can divide into a subarray
        // split first 2 if equal

        // edge case: m=1
        // general case: m>1

        // each index we can not equal or equal to previous value
        // dp[i][2] = (m-1)*dp[i-1][2] + dp[i-1][1]
        // dp[i][k] = (m-1)*dp[i-1][k] + dp[i-1][k-1]

        // looking the solution
        // just the combination
        // how?
        // we choose k pairs that equal from n-1 position
        // and it's adjacent coloring problem!!
        // first group is m
        // second group is m-1, ...
        // we have n-k-1 non-equal => n-k groups

        // c(n-1,k) * m * (m-1)^(n-k-1)

        // init
        fac.resize(n+1), ifac.resize(n+1);
        fac[0] = 1;
        for (int i = 1; i <= n; ++i)
            fac[i] = fac[i-1] * i % mod;
        ifac[n] = fpow(fac[n], mod-2); // mod inverse
        for (int i = n-1; i >= 0; --i)
            ifac[i] = ifac[i+1] * (i+1) % mod;

        return comb(n-1, k) * m % mod * fpow(m-1, n-k-1) % mod;
    }
};
