// O(1). One line use n&(n-1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n&(n-1));
    }
};

// Normal solution
class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i = 0; i < 32; ++i){
            if(n == (1LL<<i)) return true;
        }
        return false;
    }
};
