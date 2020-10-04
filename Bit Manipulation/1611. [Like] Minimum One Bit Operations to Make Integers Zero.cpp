// Super hard!!
// Need observe. 2^k is maximum path!!
// think 1 -> 0 = 1
// 10 -> 11 -> 01 -> 0 = 2+1
// 100 -> 101 -> 111 -> 110 -> 010 ... 0 = 4+2+1
// so we know 2^k. how to find other? so think 101 is it f(100) - f(101-100) ? yes. why not add? f(100) + f(001) ? noob, bigger than f(100)
// O(logN)
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n <= 1) return n;
        int bit = 0;
        while((1<<bit) <= n) bit++;
        return (1<<bit)-1 - minimumOneBitOperations(n - (1<<(bit-1)) );
    }
};
