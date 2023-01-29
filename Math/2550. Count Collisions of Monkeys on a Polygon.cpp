class Solution {
public:
    
    int mod = 1e9+7;
    long fpow(long a, int b) {
        long res = 1;
        while (b) {
            if (b & 1) res = res*a%mod;
            a = a*a%mod;
            b >>= 1;
        }
        return res;
    }
    
    int monkeyMove(int n) {
        // goal: find the number of ways move, such that monkey are collision
        // idea:
        // each monkey will have 2 way
        // 2^n, only two way will not collision
        return ((fpow(2, n) - 2) + mod) % mod;
    }
};
