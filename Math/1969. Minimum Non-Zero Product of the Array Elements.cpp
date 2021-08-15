// Observe. O(logX).

class Solution {
public:
    const int mod = 1e9+7;
    long fpow(long a, long b){
        long res = 1;
        while(b){
            if(b&1) res = res*(a%mod)%mod;
            b >>= 1;
            a = (a%mod)*(a%mod)%mod;
        }
        return res;
    }
    int minNonZeroProduct(int p) {
        long mask = (1L<<p)-1;
        return (mask % mod * fpow(mask-1, (mask-1)/2)) % mod;
    }
};
