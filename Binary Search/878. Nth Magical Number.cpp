// observe that, give a number can easily to compute the order
// -> num / a
// just inclusion-exclusion

class Solution {
public:
    const int mod = 1e9 + 7;
    int nthMagicalNumber(int n, int a, int b) {
        int lcm = a / __gcd(a, b) * b;
        
        long l = 0, r = (long)n * min(a, b);
        while(l < r){
            long mid = l+(r-l)/2;
            long kth = mid/a + mid/b - mid/lcm;
            if(kth >= n) r = mid;
            else l = mid+1;
        }
        
        return l % mod;
    }
};
