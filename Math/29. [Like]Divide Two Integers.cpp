//O(32), Bit Manipulation
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long res = 0, a = abs(dividend), b = abs(divisor);
        for(int x = 31; x >= 0; --x){
            if((a >> x) - b >= 0){
                res += (1<<x);
                a -= (b<<x);
            }
        }
        return (dividend > 0 ^ divisor > 0) ? -res : res;
    }
};
