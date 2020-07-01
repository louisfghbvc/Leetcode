// Brute Force.
class Solution {
public:
    int arrangeCoins(int n) {
        int i;
        for(i = 1; n > 0 && n >= i; ++i){
            n -= i;
        }
        return i-1;
    }
};

// Can Use Math, (1+k)k <= 2*n.
// not fun.
