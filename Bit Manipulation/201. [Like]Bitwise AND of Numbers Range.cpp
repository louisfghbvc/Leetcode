//m != n means has different 0 or 1, last digit must 0 
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while(m != n){
            m >>= 1;
            n >>= 1;
            i++;
        }
        return m << i;
    }
};


// find msb not zero
// and if bit not equal break
// O(1).
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res;
        int i;
        for(i = 30; i >= 0 && (right >> i & 1) == 0; --i);
        
        for(; i >= 0; i--){
            if((left >> i & 1) != (right >> i & 1)) break;
            if(left & (1<<i))
                res |= 1<<i;
        }
        return res;
    }
};
