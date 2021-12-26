// O(log_5^N)
// consider 10 = 2*5
// so just compute the numbers of min(2, 5)
// only consider 5
// consider 25 -> 5^2
// n/5 + n/25 + ... n/pow(5)
// instead of compute power 5
// use divide
// n/5 + (n/5)/5

class Solution {
public:
    int trailingZeroes(int n) {
        int zero = 0;
        while(n){
            zero += n/5;
            n /= 5;
        }
        return zero;
    }
};
