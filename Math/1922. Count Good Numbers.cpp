// Find pattern. O(logn).

class Solution {
public:
    const int mod = 1e9+7;
    
    long fpow(long a, long b){
        long res = 1;
        while(b){
            if(b & 1) res = res*a%mod;
            a = a*a%mod;
            b >>= 1;
        }
        return res;
    }
    
    int countGoodNumbers(long long n) {
        return fpow(5, (n+1)/2) * fpow(4, n/2) % mod; 
    }
};
