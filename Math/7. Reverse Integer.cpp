// So from small can reverse.
// Simple.
class Solution {
public:
    int reverse(long x) {
        if(x > INT_MAX) return 0;
        if(x < 0) return -reverse(-x);
        long rx = 0;
        while(x > 0){
            rx = rx*10 + x%10;
            x /= 10;
        }
        return rx > INT_MAX ? 0 : rx;
    }
};
