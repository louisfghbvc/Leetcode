// Number theory 3 base.

class Solution {
public:
    bool checkPowersOfThree(int n) {
        long base = 1;
        while(base <= n) base *= 3;
        while(base > 0){
            if(n >= base) n -= base;
            base /= 3;
        }
        return n == 0;
    }
};
