// O(sqrt(N)). decomposition 

class Solution {
public:
    // (l + r) * (r - l + 1) = 2*n
    // x * y
    // x + y = 2 * r + 1
    int consecutiveNumbersSum(int n) {
        n *= 2;
        int res = 0;
        for(long x = 1; x*x <= n; ++x){
            if(n % x == 0){
                long y = n/x;
                long r = (x + y - 1) / 2;
                long l = x - r;
                if(l > 0) res += (l+r)*(r-l+1) == n; // left is positive.
                if(x != y){
                    l = y-r;
                    if(l > 0) res += (l+r)*(r-l+1) == n;
                }
            }
        }
        return res;
    }
};
