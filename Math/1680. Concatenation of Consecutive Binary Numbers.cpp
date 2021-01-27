// O(N). mod rule

class Solution {
public:
    const int mod = 1e9+7;
    int concatenatedBinary(int n) {
        long res = 0;
        for(int i = 1; i <= n; ++i){
            int t = i;
            int k = 31;
            for(; k >= 0 ; --k)
                if((1<<k) & t) break;
            for(; k >= 0; --k){
                res = res*2 + ((t>>k)&1);
                res %= mod;
            }
        }
        return res;
    }
};

// Observe. O(N). 
// f(0) = 0
// f(1) = 01 = (f(0) << 1) + 1.
// f(2) = 01010 = (f(1) << 2) + 2.
// f(3) = 11011 = (f(2) << 2) + 3. 2 = length of 3 bit
class Solution {
public:
    const int mod = 1e9+7;
    int concatenatedBinary(int n) {
        long res = 0;
        for(int i = 1; i <= n; ++i){
            int len = 0;
            for(int j = i; j > 0; j >>= 1) len++;
            res = ((res << len) % mod + i) % mod;
        }
        return res;
    }
};

// More faster. O(N)
// check pow of 2.
class Solution {
public:
    const int mod = 1e9+7;
    int concatenatedBinary(int n) {
        long res = 0, len = 0;
        for(int i = 1; i <= n; ++i){
            if((i&(i-1)) == 0) len++;
            res = ((res<<len) | i) % mod;
        }
        return res;
    }
};
