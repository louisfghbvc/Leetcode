// O(n*sum). Super fast!!.
// so when ans exist. if b has x, and size k.
// so c = sum-x, size n-k.
// x/k == (s-x)/(n-k) => x*n = k*s, so x = s*k/n. if fix k, get x right.?
// and use knapsack. ! so cool...
// and use bitmask. the value means the possible size.

// so dp[0] = 1, means 2^0. no size.
// so backward dp[w-a] << 1, means all size + 1 !!

// if use ord array. more fast.
// int dp[s+1];
// memset(dp, 0, sizeof dp);

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size();
        if(n == 1) return false;
        int s = 0;
        for(auto &x: A) s += x;
        vector<int> dp(s+1);
        dp[0] = 1;
        for(int a: A){
            for(int w = s; w >= a; --w){
                dp[w] |= (dp[w-a]<<1);
            }
        }
        for(int k = 1; k < n; ++k)
            if(s*k%n == 0 && dp[s*k/n] & (1<<k))
                return true;
        return false;
    }
};

// can use 2D array. len and dp.
// O(N^2*Sum)
// but TLE
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size();
        if(n == 1) return false;
        int s = 0;
        for(auto &x: A) s += x;
        vector<vector<bool>> dp(n, vector<bool>(s+1));
        dp[0][0] = 1;
        for(int a: A){
            for(int w = s; w >= a; --w){
                for(int len = n-1; len >= 1; --len)
                    if(dp[len-1][w-a]) dp[len][w] = 1;
            }
        }
        for(int k = 1; k < n; ++k)
            if(s*k%n == 0 && dp[k][s*k/n])
                return true;
        return false;
    }
};
