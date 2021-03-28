// 3 is better than 2. O(logN).

class Solution {
public:
    long fpow(long a, int b){
        long res = 1;
        while(b){
            if(b&1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n % 3 == 1) return 4 * fpow(3, n/3-1);
        else if(n % 3 == 2) return 2 * fpow(3, n/3);
        return fpow(3, n/3);
    }
};
