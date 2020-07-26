// O(1). trick, hard to think
// Math proof
// if n == 0, return 0
// if n % 9 == 0, return 9
// or return n%9.
// why? 
// 10 = 9*1 + 1
// 100 = 9*11 + 1
// 100 = 9*111 + 1
// ...
// n = d0 + d1*(9 * 1 + 1) + d2*(9 * 11 + 1) ... dk(9 * 11k + 1)
// n = (d0 + d1 + .. dk) + 9*(d1*1 + d2*11 + ....)
// so mod 9.

class Solution {
public:
    int addDigits(int num) {
        return 1 + (num-1) % 9;
    }
};

// Simple Recursive
class Solution {
public:
    int addDigits(int num) {
        while(num > 9){
            int tmp = num;
            int nxt = 0;
            while(tmp > 0){
                nxt += tmp%10;
                tmp /= 10;
            }
            num = nxt;
        }
        return num;
    }
};
