// After understanding the problem.
// Observe that u want 3 more and more. O(logN).

class Solution {
public:
    const int mod = 1e9+7;
    long fpow(long a, long b){
        long res = 1;
        while(b){
            if(b&1) res = res*a%mod;
            a = a*a%mod;
            b >>= 1;
        }
        return res;
    }
    int maxNiceDivisors(int primeFactors) {
        if(primeFactors <= 4) return primeFactors;
        if(primeFactors%3 == 1){
            return (long)4 * fpow(3, primeFactors/3-1) % mod;
        }
        else if(primeFactors%3 == 2){
            return (long)2 * fpow(3, primeFactors/3) % mod;
        }
        return fpow(3, primeFactors/3);
    }
};
